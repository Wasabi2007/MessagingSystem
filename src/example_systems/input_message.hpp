//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_INPUT_MESSAGE_HPP
#define MESSAGINGSYSTEM_INPUT_MESSAGE_HPP

#include <messaging/message.hpp>
#include <string>
class input_message: public messaging::message{

public:
	std::string msg_;
	input_message(std::string msg):messaging::message(messaging::message_types::input),msg_(msg) { }

	virtual ~input_message() = default;
};


#endif //MESSAGINGSYSTEM_INPUT_MESSAGE_HPP
