//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_OUTPUT_SYSTEM_HPP
#define MESSAGINGSYSTEM_OUTPUT_SYSTEM_HPP

#include <messaging/messaging_system.hpp>
#include <messaging/message.hpp>
#include <iostream>
#include "print_message.hpp"

class output_system: public messaging::messaging_system{

public:
	output_system(messaging::message_bus &bus) : messaging_system(bus) { }

	virtual void handle_message(const messaging::message *msg) {
		if(msg->type == messaging::message_types::print){
			auto to_print = static_cast<const print_message*>(msg);
			std::cout << to_print->msg_ << std::endl;
		}
	}
};

#endif //MESSAGINGSYSTEM_OUTPUT_SYSTEM_HPP
