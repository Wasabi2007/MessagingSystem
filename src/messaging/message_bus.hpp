//
// Created by jerry on 30.03.16.
//

#ifndef MESSAGINGSYSTEM_MESSAGE_BUS_HPP
#define MESSAGINGSYSTEM_MESSAGE_BUS_HPP

#include <vector>
#include <queue>
#include <memory>
#include <utility>
#include "message.hpp"

namespace messaging {
	class messaging_system;
	class message_bus{
	public:
		message_bus();
		void tick();

		template <typename T, typename ... ARGS>
		void emplace_system(ARGS&& ... args){
			systems_.emplace_back(std::make_unique<T>(*this,std::forward<ARGS>(args)...));
		}

		template <typename M, typename ... ARGS>
		void post_message(ARGS&& ... args){
			if((tail_+1)%maxbuffer == head_){
				throw std::runtime_error("message queue full");
			}

			messages_[tail_] = std::make_unique<M>(std::forward<ARGS>(args)...);
			tail_ = (tail_+1)%maxbuffer;
		}

	private:
		static constexpr unsigned long maxbuffer = 1024;
		std::vector<std::unique_ptr<messaging_system>> systems_; //replace with sheared_ptr if needed
		std::array<std::unique_ptr<message>,maxbuffer> messages_;
		unsigned long head_;
		unsigned long tail_;
	};
};
#endif //MESSAGINGSYSTEM_MESSAGE_BUS_HPP
