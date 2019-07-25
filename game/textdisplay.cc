#include <iostream>
#include "textdisplay.h"
#include "ascii_graphics.h"

TextDisplay::TextDisplay(){
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(PLAYER_1_TEMPLATE);
	displayPlayer1.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer1.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot1.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand1.emplace_back(CARD_TEMPLATE_BORDER);

	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(PLAYER_2_TEMPLATE);
	displayPlayer2.emplace_back(CARD_TEMPLATE_EMPTY);
	displayPlayer2.emplace_back(CARD_TEMPLATE_BORDER);

	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);
	displayMinionSlot2.emplace_back(CARD_TEMPLATE_BORDER);

	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
	displayHand2.emplace_back(CARD_TEMPLATE_BORDER);
}


void TextDisplay::notify(Player & whoNotified){
	if(whoNotified.getplayerNum() == 1){
		// update player row
		if(whoNotified.getactiveRitual()) displayPlayer1[0] = (whoNotified.getactiveRitual())->getoutput();
		displayPlayer1[2] = whoNotified.getplayerCard();
		if(!(whoNotified.getgraveyard()).empty()) displayPlayer1[4] = ((whoNotified.getgraveyard()).back())->getoutput();

		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot1[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot1[i] = CARD_TEMPLATE_BORDER;
		}

		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand1[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand1[i] = CARD_TEMPLATE_BORDER;
		}

	} else if(whoNotified.getplayerNum() == 2){
		// update player row
		if(whoNotified.getactiveRitual()) displayPlayer2[0] = (whoNotified.getactiveRitual())->getoutput();
		displayPlayer2[2] = whoNotified.getplayerCard();
		if(!(whoNotified.getgraveyard()).empty()) displayPlayer2[4] = ((whoNotified.getgraveyard()).back())->getoutput();
		
		// update minion slot
		for(int i = 0; i < (whoNotified.getminionslot()).size(); i++){
			displayMinionSlot2[i] = ((whoNotified.getminionslot())[i])->getoutput();
		}
		for(int i = (whoNotified.getminionslot()).size(); i < 5; i++){
			displayMinionSlot2[i] = CARD_TEMPLATE_BORDER;
		}
		
		// update hand
		for(int i = 0; i < (whoNotified.gethand()).size(); i++){
			displayHand2[i] = ((whoNotified.gethand())[i])->getoutput();
		}
		for(int i = (whoNotified.gethand()).size(); i < 5; i++){
			displayHand2[i] = CARD_TEMPLATE_BORDER;
		}
	}
}

void TextDisplay::displayBoard(){
	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;

	// first row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// second row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// centre graphic
	for(int i = 0; i < CENTRE_GRAPHIC.size(); i++){
		std::cout << CENTRE_GRAPHIC[i] << std::endl;
	}
	// third row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// fourth row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
	for(int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << std::endl;
}

void TextDisplay::displayHand(Player * player){
	if(player->getplayerNum() == 1){
		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand1[j][i];
			}
			std::cout << std::endl;
		}
	} else if(player->getplayerNum() == 2){
		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand2[j][i];
			}
		}
	}
}

void TextDisplay::inspectCard(Player * player, int num){
	if(num >= 5){
		throw InvalidPosition e{"There are only 5 minion slots."}
	}
	if(num >= (player->getminionslot()).size()){
		throw InvalidPosition e{"No minion is placed in this position."};
	}
	std::vector<std::string> temp{(player->getminionslot()[num])->getoutput()};
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << temp[i] << std::endl;
	}
	std::cout << std::endl;
}

