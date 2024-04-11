 #!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool
 
 
class CounterNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("number_counter") # MODIFY NAME
        self.count = 0
        self.serviice = self.create_service(SetBool, "reset_counter", self.callback_reset)
        self.subscriber = self.create_subscription(Int64, "number", self.callback, 10)
        self.publisher = self.create_publisher(Int64, "number_count", 10) 
        self.get_logger().info("Number counter is running")

    def callback_reset(self, request, response):
        if request.data:
            self.count = 0
            self.get_logger().info("Counter has been reset")
            self.publish_count()
            #esponse.success = True
        return response

    def callback(self, msg):
        self.count += msg.data 
        self.get_logger().info(str(self.count))
        self.publish_count()

    def publish_count(self):
        msg = Int64()
        msg.data = self.count
        self.publisher.publish(msg)
 
 
def main(args=None):
    rclpy.init(args=args)
    node = CounterNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()

