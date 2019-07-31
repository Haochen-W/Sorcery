#include "textdisplay.h"
#include "concreteenchantment.h"

TextDisplay::TextDisplay(): outputDisplay(){}

void TextDisplay::displayBoard(){
	std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	for(unsigned int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;

	// first row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// second row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot1[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// centre graphic
	for(unsigned int i = 0; i < CENTRE_GRAPHIC.size(); i++){
		std::cout << CENTRE_GRAPHIC[i] << std::endl;
	}
	// third row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayMinionSlot2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}
	// fourth row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		for(int j = 0; j < 5; j++){
			std::cout << displayPlayer2[j][i];
		}
		std::cout << EXTERNAL_BORDER_CHAR_UP_DOWN << std::endl;
	}

	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
	for(unsigned int i = 0; i < 165; i++){
		std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << std::endl;
}

void TextDisplay::displayHand(Player * player){
	if(player->getplayerNum() == 1){
		for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand1[j][i];
			}
			std::cout << std::endl;
		}
	} else if(player->getplayerNum() == 2){
		for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				std::cout << displayHand2[j][i];
			}
			std::cout << std::endl;
		}
	}
}

void TextDisplay::displayMagic(Player * player){
	if(player->getplayerNum() == 1){
		displayMagic1 = "";
		for(int i = 0; i < player->getmagic(); i++){
			displayMagic1 += "o ";
		}
		std::cout << "Magic: " << displayMagic1 << std::endl;
	} else if(player->getplayerNum() == 2){
		displayMagic2 = "";
		for(int i = 0; i < player->getmagic(); i++){
			displayMagic2 += "o ";
		}
		std::cout << "Magic: " << displayMagic2 << std::endl;
	}
}

void TextDisplay::inspectCard(Player * player, int num){
	if(num > static_cast<int>((player->getminionslot()).size()) || num <= 0){
		InvalidPosition e{"No minion is placed in this position."};
		throw e;
	}
	std::vector<std::string> temp{(player->getminionslot()[num - 1])->getoutput()};
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		std::cout << temp[i] << std::endl;
	}

	std::vector<std::string> enchantsName{player->getminionslot()[num - 1]->getEnchantmentadded()};
	std::vector<std::shared_ptr<Card>> enchants;
	for(unsigned int i = 0; i < enchantsName.size(); i++){
		std::string s{enchantsName[i]};
		if (s == "Giant Strength"){
			std::shared_ptr<Giantstrength> p = std::make_shared<Giantstrength>(nullptr);
			enchants.emplace_back(p);
		} else if (s == "Enrage"){
			std::shared_ptr<Enrage> p = std::make_shared<Enrage>(nullptr);
			enchants.emplace_back(p);
		} else if (s == "Haste"){
			std::shared_ptr<Haste> p = std::make_shared<Haste>(nullptr);
			enchants.emplace_back(p);
		} else if (s == "Magic Fatigue"){
			std::shared_ptr<Magicfatigue> p = std::make_shared<Magicfatigue>(nullptr);
			enchants.emplace_back(p);
		} else if (s == "Silence"){
			std::shared_ptr<Silence> p = std::make_shared<Silence>(nullptr);
			enchants.emplace_back(p);
		}
	}
	std::vector<std::vector<std::string>> enchantsoutput;
	for(unsigned int i = 0; i < enchants.size(); i++){
		enchantsoutput.emplace_back(enchants[i]->getoutput());
	}
	int rounds;

	if (enchants.size() % 5 == 0){
		rounds = enchants.size() / 5;
	} else {
		rounds = enchants.size() / 5 + 1;
	}
	for (int q = 0; q < rounds; q++){
		for(int k = 0; k < static_cast<int>(CARD_TEMPLATE_BORDER.size()); k++){
			for(int j = 0; j < 5 && q * 5 + j < static_cast<int>(enchants.size()); j++){
				std::cout << enchantsoutput[q * 5 + j][k];
			}
			std::cout << std::endl;
		}
	}
	
}

void TextDisplay::endgame(Player * player){
	if(player->getplayerNum() == 1){
		for(unsigned int i = 0; i < P1WINNER.size(); i++){
			std::cout << P1WINNER[i] << std::endl;
		}
	} else if(player->getplayerNum() == 2){
		for(unsigned int i = 0; i < P2WINNER.size(); i++){
			std::cout << P2WINNER[i] << std::endl;
		}
	}
}

void TextDisplay::tie(){
	for(unsigned int i = 0; i < TIE.size(); i++){
		std::cout << TIE[i] << std::endl;
	}
}
