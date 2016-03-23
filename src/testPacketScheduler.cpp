#include <iostream>
#include "packetScheduler.hpp"

int main()
{
	std::string input("C:/Users/gtuser/Desktop/demo_packet_schedulers/packets.dat");

	try{
		PacketScheduler ps(input);
		ps.print();
		ps.run();	
	}
	catch(std::runtime_error& e)
	{
		std::cout << "Encounter runtime error while running the simulator: \n"
		          << "  " << e.what() << std::endl;
	}


	return 0;

}