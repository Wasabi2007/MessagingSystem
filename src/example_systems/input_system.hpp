//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_INPUT_SYSTEM_HPP
#define MESSAGINGSYSTEM_INPUT_SYSTEM_HPP

#include <messaging/messaging_system.hpp>
#include <messaging/message_bus.hpp>
#include <messaging/message_types.hpp>
#include <sstream>
#include "print_message.hpp"
#include "input_message.hpp"
#include "random_message.hpp"

class input_system: public messaging::messaging_system{

public:
	input_system(messaging::message_bus &bus) : messaging_system(bus) { }

	virtual void handle_message(const messaging::message *msg) override {
		if(msg->type == messaging::message_types::input){
			auto input = static_cast<const input_message*>(msg);
			auto split_on = input->msg_.find(' ');
			std::string type = input->msg_.substr(0,split_on);
			std::string info = input->msg_.substr(split_on+1);
			if(split_on == input->msg_.npos) info = "";
			if( type == "input"){
				bus_.post_message<input_message>(info);
			} else if(type == "random"){
				auto arguments = split(info,' ');
				auto min = (arguments.size()>0?std::stoi(arguments.at(0)):0);
				auto max = (arguments.size()>1?std::stoi(arguments.at(1)):min+6);
				bus_.post_message<random_message>(min,max);
			}else if(type == "print") {
				bus_.post_message<print_message>(info);
			}else if(type == "update") {

			} else{
				bus_.post_message<print_message>("Error: Command not found.");
			}
		}
	}

	std::vector<std::string> split(const std::string &s, char delim) {
		std::stringstream ss(s);
		std::string item;
		std::vector<std::string> tokens;
		while (getline(ss, item, delim)) {
			tokens.push_back(item);
		}
		return tokens;
	}
};
#endif //MESSAGINGSYSTEM_INPUT_SYSTEM_HPP
