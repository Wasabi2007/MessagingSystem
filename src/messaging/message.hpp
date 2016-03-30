//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_MESSAGE_HPP
#define MESSAGINGSYSTEM_MESSAGE_HPP

#include "message_types.hpp"

namespace messaging {

	//improvment? don't make derrived types add data pointer
	class message {
	public:
		message(message_types type):type(type){}
		virtual ~message() = 0;
		const message_types type;
	};
	inline message::~message() { }
}
#endif //MESSAGINGSYSTEM_MESSAGE_HPP
