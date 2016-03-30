//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_RANDOM_MESSAGE_HPP
#define MESSAGINGSYSTEM_RANDOM_MESSAGE_HPP

#include <messaging/message.hpp>

class random_message: public messaging::message{

public:
	const int min;
	const int max;
	random_message(int min,int max):messaging::message(messaging::message_types::random_number),min(min),max(max) { }

	virtual ~random_message() {

	}
};
#endif //MESSAGINGSYSTEM_RANDOM_MESSAGE_HPP
