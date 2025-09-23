#include "spin_slow_update.h"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SlowSolution>());
  rclcpp::shutdown();
  return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution") {
  // RCLCPP_INFO(this->get_logger(), "Remove this statement from spin_slow_update.cpp");
  // your code here
  publisher_ = this->create_publisher<ArrayMsg>("/predictedpos", 10);
  subscriber_ = this->create_subscription<ArrayMsg>(
    "/measuredpos", 10,
    std::bind(&SlowSolution::measured_callback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "SlowSolution node started");
}

// your code here
void SlowSolution::measured_callback(const ArrayMsg::SharedPtr msg) {
  publisher_->publish(*msg);
}