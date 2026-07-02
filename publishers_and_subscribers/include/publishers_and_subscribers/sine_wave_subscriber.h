#ifndef SINE_WAVE_SUBSCRIBER
#define SINE_WAVE_SUBSCRIBER

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

/**
 * Subscribes to /sine_wave topic and prints to terminal
 * Applied Robotics
 * Author: Garrison Johnston
 */
class SineWaveSubscriber : public rclcpp::Node
{
public:
    SineWaveSubscriber();
    ~SineWaveSubscriber() = default;

private:
    // runs automatically when sine wave topic updates
    void sineWaveCallback(const std_msgs::msg::Float32 & msg);

    // Publishers/subscribers
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscriber_;
};

#endif // SINE_WAVE_SUBSCRIBER