//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_PRINT_MESSAGE_HPP
#define MESSAGINGSYSTEM_PRINT_MESSAGE_HPP

#include <messaging/message.hpp>
#include <string>
class print_message: public messaging::message{

public:
	std::string msg_;
	print_message(std::string msg):messaging::message(messaging::message_types::print),msg_(msg) { }

	virtual ~print_message() {

	}
};
#endif //MESSAGINGSYSTEM_PRINT_MESSAGE_HPP
