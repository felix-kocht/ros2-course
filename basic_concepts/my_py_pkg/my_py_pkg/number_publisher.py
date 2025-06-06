#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64
 
 
class PublisherNode(Node): 
    def __init__(self):
        super().__init__("number_publisher") 

        self.publisher = self.create_publisher(Int64, "number", 10)
        self.timer = self.create_timer(1,self.publish_numbers)
        self.get_logger().info("Number publisher is running")
    
    def publish_numbers(self):
        num = Int64()
        num.data = 5
        self.publisher.publish(num) 
 
 
def main(args=None):
    rclpy.init(args=args)
    node = PublisherNode() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
