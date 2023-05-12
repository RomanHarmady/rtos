#include <iostream>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"

class LogSubscriber : public rclcpp::Node {
public:
  LogSubscriber() : Node("log_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::Int16>(
      "log_publisher", 1,
      [this](const std_msgs::msg::Int16::SharedPtr msg) {
        logMessage(msg->data);
      }
    );

    logFile_.open("log.txt", std::ios::app); // Open log file in append mode
  }

private:
  rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscription_;
  std::ofstream logFile_;

  void logMessage(int value) {
    logFile_ << "Velocity: " << value << std::endl;
    RCLCPP_INFO(get_logger(), "Logged velocity: %d", value);
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LogSubscriber>());
  rclcpp::shutdown();
  return 0;
}
