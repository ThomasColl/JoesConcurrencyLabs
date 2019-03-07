#include "Event.h"
#include <iostream>
#include <stdlib.h>

Event::Event(){
	b = 'a' + rand()%26;
	std::cout << b;
}

void Event::Consume(){
	char newB = b-32;
	std::cout << newB;

	
}
