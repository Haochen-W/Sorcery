#include <iostream>
#include "ascii_graphics.h"

int main()
{
	std::vector<std::string> rit {display_ritual("hello", 3, 4, "hello", 2)}; 

	for(int i = 0; i < rit.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		std::cout << rit[i] << std::endl;
	}

	std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT << std::endl;
	
	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT << std::endl;
	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;
	return 0;


}
