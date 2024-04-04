#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial
import random

from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from my_robot_interfaces.srv import Location
from my_robot_interfaces.msg import AliveTurtles, OneTurtle
 
 
class PublisherNode(Node): 
    def __init__(self):
        super().__init__("turtle_spawner") 
        self.declare_parameter("secs", 7) #seconds bewteen each spawn
        self.alive_turtles = AliveTurtles()
        self.alive_turtles.turtlelist = []
        self.name_counter = 2
        secs = self.get_parameter("secs").value
        self.timer = self.create_timer(secs,self.spawn_turtle)
        self.create_service(Location, "catch_turtle", self.catch_turtle)
        self.get_logger().info("Turtle spawner is running with %d seconds between each spawn" % (secs))
        self.publisher = self.create_publisher(AliveTurtles, "alive_turtles", 10)
        

    def catch_turtle(self, request, response):
        #find the closest turtle
        closest_turtle = None
        closest_distance = 1000
        for turtle in self.alive_turtles.turtlelist:
            distance = ((turtle.x - request.location.x)**2 + (turtle.y - request.location.y)**2)**0.5
            if distance < closest_distance:
                closest_distance = distance
                closest_turtle = turtle
        if closest_distance < 1.0:
            self.kill_turtle(closest_turtle.name)
            response.success = True
        else:
            response.success = False
            self.get_logger().info("No turtle within 1 meter")
        return response
        

    def kill_turtle(self, turtle_name):
        self.client = self.create_client(Kill, "kill")
        while not self.client.wait_for_service(2.0):
            self.get_logger().warn("Waiting for server kill...")
        req = Kill.Request()
        req.name = turtle_name
        for i in range(len(self.alive_turtles.turtlelist)):
            if self.alive_turtles.turtlelist[i].name == turtle_name:
                self.alive_turtles.turtlelist.pop(i)
                break
        self.publisher.publish(self.alive_turtles)
        future = self.client.call_async(req)
        future.add_done_callback(partial(self.kill_response))

    def kill_response(self, future):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().info("Service call failed %r" % (e,))

    def spawn_turtle(self):
        self.client = self.create_client(Spawn, "spawn")
        while not self.client.wait_for_service(2.0):
            self.get_logger().warn("Waiting for server spawn...")
        req = Spawn.Request()
        req.x = random.uniform(0.5, 10.5)
        req.y = random.uniform(0.5, 10.5)
        req.theta = random.uniform(0, 2*3.14159)
        req.name = "turtle" + str(self.name_counter)
        self.name_counter += 1
        new_turtle = OneTurtle()
        new_turtle.name = req.name
        new_turtle.x = req.x
        new_turtle.y = req.y
        self.alive_turtles.turtlelist.append(new_turtle)
        self.publisher.publish(self.alive_turtles)
        future = self.client.call_async(req)
        future.add_done_callback(partial(self.spawn_response))

    def spawn_response(self, future):
        try:
            response = future.result()
            self.get_logger().info(response.name)
        except Exception as e:
            self.get_logger().info("Service call failed %r" % (e,))
 
 
def main(args=None):
    rclpy.init(args=args)
    node = PublisherNode() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
