/*#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
//#include <realtime_tools/realtime_publisher.h>

using namespace std::chrono_literals;

class NormalPublisher : public rclcpp::Node
{
  public:
    NormalPublisher()
    : Node("motor_command_publisher")
    {
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motor_subscriber", 1);
      i = 0.0;
      timer_ = this->create_wall_timer(500ms, std::bind(&NormalPublisher::publish_message, this));
    }

      private:
    void publish_message()
    {
      auto message = geometry_msgs::msg::Twist();
      message.linear.x = 4.0; 
      message.angular.z = 2.0 + i;
      RCLCPP_INFO(this->get_logger(), "Sending - Linear Velocity : '%f', Angular Velocity : '%f'", message.linear.x, message.angular.z);
      publisher_->publish(message);
      i += 0.1; 
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    float i;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NormalPublisher>());
  rclcpp::shutdown();
  return 0;
}
*/