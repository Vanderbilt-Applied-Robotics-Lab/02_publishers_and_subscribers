#include <publishers_and_subscribers/sine_wave_subscriber.h>

SineWaveSubscriber::SineWaveSubscriber() : Node("sine_wave_subscriber")
{
    // create subscribers
    subscriber_ = this->create_subscription<std_msgs::msg::Float32>("/sine_wave", 10, 
        std::bind(&SineWaveSubscriber::sineWaveCallback, this, std::placeholders::_1));
}

void SineWaveSubscriber::sineWaveCallback(const std_msgs::msg::Float32 & msg)
{
    std::cout << "Sine Wave Value: " << msg.data << std::endl;
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of class
    auto node = std::make_shared<SineWaveSubscriber>();

    // MAIN LOOP
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
