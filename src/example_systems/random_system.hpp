//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_RANDOM_SYSTEM_HPP
#define MESSAGINGSYSTEM_RANDOM_SYSTEM_HPP

#include <messaging/messaging_system.hpp>
#include <messaging/message_bus.hpp>
#include <random>
#include <messaging/message.hpp>
#include "random_message.hpp"
#include "print_message.hpp"

class random_system: public messaging::messaging_system{

public:
	random_system(messaging::message_bus &bus) : messaging_system(bus),generator(random_device_()) { }

	virtual void handle_message(const messaging::message *msg) override {
		if(msg->type == messaging::message_types::random_number){
			auto random_info = static_cast<const random_message*>(msg);
			std::uniform_int_distribution<int> dist(random_info->min,random_info->max);
			std::string number = std::to_string(dist(generator));
			bus_.post_message<print_message>(number);
		}
	}

private:
	std::random_device random_device_;
	std::mt19937 generator;

};
#endif //MESSAGINGSYSTEM_RANDOM_SYSTEM_HPP
