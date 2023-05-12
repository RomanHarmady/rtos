#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <std_msgs/msg/int16.hpp>

using std::placeholders::_1;

class NormalSubscriber : public rclcpp::Node
{
  public:
    NormalSubscriber()
    : Node("encoder_position_subscriber")
    {
      subscriber_ = this->create_subscription<std_msgs::msg::Int16>("log_publisher", 1, std::bind(&NormalSubscriber::subscribe_message, this, _1));
      
    }

  private:
    void subscribe_message(const std_msgs::msg::Int16::SharedPtr message) const
    {
      //RCLCPP_INFO(this->get_logger(), " Velocity : '%d'", message->data);


    }
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr subscriber_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NormalSubscriber>());
  rclcpp::shutdown();
  return 0;
}