#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SlowSolution : public rclcpp::Node {
 public:
  SlowSolution();
 private:
  // your code here
  void measured_callback(const ArrayMsg::SharedPtr msg);
  rclcpp::Publisher<ArrayMsg>::SharedPtr publisher_;
  rclcpp::Subscription<ArrayMsg>::SharedPtr subscriber_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
