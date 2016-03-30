cmake_minimum_required(VERSION 3.4)
project(MessagingSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

include_directories(src)

set(SOURCE_FILES src/main.cpp src/messaging/messaging_system.hpp src/messaging/message.hpp src/messaging/message_types.hpp src/messaging/message_bus.hpp src/messaging/message_bus.cpp src/example_systems/output_system.hpp src/example_systems/print_message.hpp src/example_systems/random_system.hpp src/example_systems/random_message.hpp src/example_systems/input_system.hpp src/example_systems/input_system.hpp)
add_executable(MessagingSystem ${SOURCE_FILES})