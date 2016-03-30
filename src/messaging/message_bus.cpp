//
// Created by jerry on 30.03.16.
//

#include "message_bus.hpp"
#include "messaging_system.hpp"

namespace messaging {


	message_bus::message_bus():head_(0),tail_(0) {

	}

	void message_bus::tick() {
		if(tail_ == head_) return; // nothing to do

		auto tail = tail_; // run to last known tail. in favor for multithreading

		while(tail != head_){
			auto msg = messages_[head_].get();
			for(auto& system : systems_){
				system->handle_message(msg);
			}
			messages_[head_] = nullptr;
			head_ = (head_+1)%maxbuffer;
		}
	}


}