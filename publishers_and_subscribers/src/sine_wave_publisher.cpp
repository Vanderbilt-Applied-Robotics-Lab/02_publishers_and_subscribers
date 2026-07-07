#include <publishers_and_subscribers/sine_wave_publisher.h>

SineWavePublisher::SineWavePublisher() : Node("sine_wave_publisher")
{
    publisher_ = this->create_publisher<std_msgs::msg::Float32>("/sine_wave", 10); 

    start_time_ = this->get_clock()->now();
}

void SineWavePublisher::publishSineWave()
{
    
    // time since start of node
    double t = (this->get_clock()->now() - start_time_).seconds();
    
    // calculate sine wave
    msg_.data = std::sin(t);

    // publish message
    publisher_->publish(msg_);
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of class
    auto node = std::make_shared<SineWavePublisher>();

    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(100); // Hz

    // MAIN LOOP
    while (rclcpp::ok())
    {
        node->publishSineWave();
        rclcpp::spin_some(node); // updates publishers and subscribers
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}
