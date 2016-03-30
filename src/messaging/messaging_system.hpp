//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_MESSAGING_SYSTEM_HPP
#define MESSAGINGSYSTEM_MESSAGING_SYSTEM_HPP

namespace messaging {
	class message;
	class message_bus;
	class messaging_system {
	public:
		messaging_system(message_bus& bus):bus_(bus){}
		virtual void handle_message(const message* msg) = 0;

	protected:
		message_bus& bus_;
	};
}


#endif //MESSAGINGSYSTEM_MESSAGING_SYSTEM_HPP
