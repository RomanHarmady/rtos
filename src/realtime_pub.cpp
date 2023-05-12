/*#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int16.hpp>
#include <realtime_tools/realtime_publisher.h>
#include <memory>
#include <chrono>

class RealtimePublisherNode : public rclcpp::Node
{
public:
  RealtimePublisherNode() : Node("realtime_publisher_node")
  {
    // Create a real-time publisher for std_msgs::msg::Int16
    realtime_publisher_ = std::make_shared<realtime_tools::RealtimePublisher<std_msgs::msg::Int16>>(
        this, "my_topic", 10);

    // Initialize the message
    message_.data = 42;
  }

  void publishMessage()
  {
    if (realtime_publisher_->trylock())
    {
      realtime_publisher_->msg_ = message_;
      realtime_publisher_->unlockAndPublish();
    }
  }

private:
  std_msgs::msg::Int16 message_;
  std::shared_ptr<realtime_tools::RealtimePublisher<std_msgs::msg::Int16>> realtime_publisher_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<RealtimePublisherNode>();

  // Run the publish loop in real-time
  rclcpp::Rate rate(5);  // Adjust the desired publish rate (e.g., 100 Hz)

  while (rclcpp::ok())
  {
    node->publishMessage();
    rate.sleep();
  }

  rclcpp::shutdown();
  return 0;
}
*/