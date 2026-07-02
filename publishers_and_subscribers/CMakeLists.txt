cmake_minimum_required(VERSION 3.8)
project(publishers_and_subscribers)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_executable(sine_wave_publisher src/sine_wave_publisher.cpp)
add_executable(sine_wave_subscriber src/sine_wave_subscriber.cpp)

ament_target_dependencies(sine_wave_publisher rclcpp std_msgs)
ament_target_dependencies(sine_wave_subscriber rclcpp std_msgs)

install(TARGETS sine_wave_publisher
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS sine_wave_subscriber
  DESTINATION lib/${PROJECT_NAME})

ament_package()
