#ifndef SINE_WAVE_PUBLISHER
#define SINE_WAVE_PUBLISHER

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

/**
 * Publishes a sine wave to the /sine_wave topic
 * Applied Robotics
 * Author: Garrison Johnston
 */
class SineWavePublisher : public rclcpp::Node
{
public:
    // constructor
    SineWavePublisher();

    // destructor
    ~SineWavePublisher() = default;

    // publishes the sine wave
    void publishSineWave();

private:
    // publisher object
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;

    // output message
    std_msgs::msg::Float32 msg_ = std_msgs::msg::Float32();
    
    // Time at start of node
    rclcpp::Time start_time_; 
};

#endif // SINE_WAVE_PUBLISHER