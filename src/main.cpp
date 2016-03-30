#include <iostream>
#include <messaging/message_bus.hpp>
#include <example_systems/output_system.hpp>
#include <example_systems/random_system.hpp>
#include <example_systems/input_system.hpp>
#include <example_systems/input_message.hpp>

using namespace std;

int main() {
	auto bus = messaging::message_bus{};
	bus.emplace_system<output_system>();
	bus.emplace_system<random_system>();
	bus.emplace_system<input_system>();

	std::string input;
	while (true){
		bus.tick();
		getline(cin,input);
		if(input == "quit") break;
		bus.post_message<input_message>(input);
		bus.tick();
	}

	return 0;
}