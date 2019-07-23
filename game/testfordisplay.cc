#include <iostream>
#include <vector>
#include "ascii_graphics.h"

int main()
{
	std::vector<std::string> rit {display_ritual("hello", 3, 4, "hello", 2)}; 
	std::vector<std::string> minion1 {display_minion_no_ability("hello", 3, 4, 2)};
	std::vector<std::string> minion2 {display_minion_no_ability("hello", 3, 4, 2)};
	std::vector<std::string> minion3 {display_minion_no_ability("hello", 3, 4, 2)};
	std::vector<std::string> minion4 {display_minion_no_ability("hello", 3, 4, 2)};
	std::vector<std::string> minion5 {display_minion_no_ability("hello", 3, 4, 2)};
	std::vector<std::string> player1 {display_player_card(1, "player1", 4, 2)};
	std::vector<std::string> player2 {display_player_card(2, "player2", 4, 2)};


	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;

	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}

	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;

	for(int i = 0; i < rit.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		std::cout << rit[i];
		for(int i = 0; i < 33; i++){
			std::cout << " ";
		}
		std::cout << player1[i];
		for(int i = 0; i < 33; i++){
			std::cout << " ";
		}
		std::cout << minion1[i];
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	for(int i = 0; i < minion1.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		std::cout << minion1[i];
		std::cout << minion2[i];
		std::cout << minion3[i];
		std::cout << minion4[i];
		std::cout << minion5[i];
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	for(int i = 0; i < CENTRE_GRAPHIC.size(); i++){
		std::cout << CENTRE_GRAPHIC[i] << std::endl;
	}

	for(int i = 0; i < minion1.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		std::cout << minion1[i];
		std::cout << minion2[i];
		std::cout << minion3[i];
		std::cout << minion4[i];
		std::cout << minion5[i];
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	for(int i = 0; i < rit.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		std::cout << rit[i];
		for(int i = 0; i < 33; i++){
			std::cout << " ";
		}
		std::cout << player1[i];
		for(int i = 0; i < 33; i++){
			std::cout << " ";
		}
		std::cout << minion1[i];
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<std::vector<std::string>> displayPlayer; // each player's board
	
	displayPlayer.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer.emplace_back(PLAYER_1_TEMPLATE);
	displayPlayer.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer.emplace_back(CARD_TEMPLATE_BORDER);


	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;

	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}

	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

}
