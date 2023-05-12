#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int16.hpp>
#include <memory>
#include <chrono>

int16_t global_bad = 0;

class MyNode : public rclcpp::Node
{
public:
  MyNode() : Node("my_node")
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int16>("motor_subscriber", 10);
    subscriber_ = this->create_subscription<std_msgs::msg::Int16>(
        "encoder_publisher", 10, std::bind(&MyNode::callback, this, std::placeholders::_1));

    // Create a timer to publish messages every second
    timer_ = this->create_wall_timer(std::chrono::microseconds(500000),
                                     std::bind(&MyNode::publishMessage, this));
  }

private:
  void callback(const std_msgs::msg::Int16::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Received: %d", msg->data);
    global_bad = msg->data;
  }

  void publishMessage()
  {
    auto message = std_msgs::msg::Int16();
    if (global_bad >= 50){message.data = 1000;}
    else {message.data = 0;};

    publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "Published: %d", message.data);
  }

  rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyNode>());
  rclcpp::shutdown();

  return 0;
}
