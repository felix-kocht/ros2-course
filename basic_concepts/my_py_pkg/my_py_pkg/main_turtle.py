 #!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial

from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from my_robot_interfaces.srv import Location
from my_robot_interfaces.msg import AliveTurtles, OneTurtle
from math import atan2, pi
 
 
class Controller(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("main_turtle") # MODIFY NAME
        self.latest_x = 5.544445
        self.latest_y = 5.544445
        self.latest_theta = 0
        self.target = OneTurtle()
        self.subscriber = self.create_subscription(AliveTurtles, "alive_turtles", self.select_target, 10)
        self.subscriber2 = self.create_subscription(Pose, "turtle1/pose", self.use_position, 2)
        self.publisher = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.get_logger().info("Controller is running")

    #select closest turtle as target to follow and use its location to call follow_turtle function
    def select_target(self, msg):
        min_distance = 1000
        for turtle in msg.turtlelist:
            distance = (turtle.x-self.latest_x)**2 + (turtle.y-self.latest_y)**2
            if distance < min_distance:
                min_distance = distance
                self.target = turtle
        self.get_logger().info("Target position: x = " + str(self.target.x) + ", y = " + str(self.target.y))

    #callback function to write down latest x & y values of turtle1
    def use_position(self, msg):
        self.latest_x = msg.x
        self.latest_y = msg.y
        self.latest_theta = msg.theta
        #if distance to target is less than 1, call function to catch target
        #if distance to target is more than 1, call function to move towards target
        distance = ((self.latest_x - self.target.x)**2 + (self.latest_y - self.target.y)**2)**0.5
        if distance < 1:
            self.catch_target()
            self.target.x = 5.544445
            self.target.y = 5.544445
        else:
            self.follow_turtle()

    #function to move towards target
    def follow_turtle(self):
        msg = Twist()
        if self.target.x == 5.544445 and self.target.y == 5.544445:
            msg.linear.x = 0.0
        else:
            msg.linear.x = 1.0
        #calculating angle to target
        angle = 0
        if self.target.x != self.latest_x:
            angle = atan2((self.target.y - self.latest_y), (self.target.x - self.latest_x))
        deviation = - self.latest_theta + angle
        if deviation > pi:
            deviation -= 2*pi
        if deviation < -pi:
            deviation += 2*pi
        msg.angular.z = deviation*2
        self.publisher.publish(msg)

    #function to catch target
    def catch_target(self):
        client = self.create_client(Location, "catch_turtle")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for catching server...")
        request = Location.Request()
        request.location.x = self.target.x
        request.location.y = self.target.y
        future = client.call_async(request)
        future.add_done_callback(partial(self.catch_response))

    def catch_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info("Turtle caught")
            else:
                self.get_logger().info("No turtle within 1 meter")
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))


 
def main(args=None):
    rclpy.init(args=args)
    node = Controller() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()

