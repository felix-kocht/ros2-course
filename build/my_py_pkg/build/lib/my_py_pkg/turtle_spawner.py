#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial

from turtlesim.srv import Spawn
 
 
class PublisherNode(Node): 
    def __init__(self):
        super().__init__("turtle_spawner") 

        self.timer = self.create_timer(7,self.spawn_turtle)
        self.get_logger().info("Turtle spawner is running")

    
    def spawn_turtle(self):
        self.client = self.create_client(Spawn, "spawn")
        while not self.client.wait_for_service(2.0):
            self.get_logger().warn("Waiting for server spawn...")
        req = Spawn.Request()
        req.x = 7.0 #change later
        req.y = 5.0
        req.theta = 0.0
        #req.name = "turtle1"
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
