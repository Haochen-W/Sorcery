#include "graphicdisplay.h"
#include "concreteenchantment.h"

GraphicDisplay::GraphicDisplay(): outputDisplay(){}

void GraphicDisplay::displayBoard(){
	w.fillRectangle(10, 10, 1350, 620, Xwindow::White);
	w.fillRectangle(20, 20, 1300, 2, Xwindow::Black);
	w.fillRectangle(20, 20, 2, 600, Xwindow::Black);
	w.fillRectangle(1320, 20, 2, 600, Xwindow::Black);

	// first row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 40 + i * 10, displayPlayer1[j][i]);
		}
	}
	// second row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 155 + i * 10, displayMinionSlot1[j][i]);
		}
	}

	w.fillRectangle(20, 270, 1300, 2, Xwindow::Black);

	int s = 50;

	// s
	w.fillRectangle(400 + s, 290, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(400 + s, 310, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(400 + s, 330, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(400 + s, 300, 10, 10, Xwindow::Black);
	w.fillRectangle(430 + s, 320, 10, 10, Xwindow::Black);

	// o
	w.fillRectangle(470 + s, 290, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(470 + s, 330, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(470 + s, 290, 10, 10 * 4, Xwindow::Black);
	w.fillRectangle(500 + s, 290, 10, 10 * 4, Xwindow::Black);

	// r
	w.fillRectangle(540 + s, 290, 10, 10 * 5, Xwindow::Black);
	w.fillRectangle(550 + s, 290, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(550 + s, 310, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(570 + s, 300, 10, 10, Xwindow::Black);
	w.fillRectangle(550 + s, 320, 10, 10, Xwindow::Black);
	w.fillRectangle(560 + s, 330, 10 * 2, 10, Xwindow::Black);

	// c
	w.fillRectangle(610 + s, 290, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(610 + s, 330, 10 * 4, 10, Xwindow::Black);
	w.fillRectangle(610 + s, 300, 10, 10 * 3, Xwindow::Black);

	// e
	w.fillRectangle(690 + s, 290, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(690 + s, 310, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(690 + s, 330, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(680 + s, 290, 10, 10 * 5, Xwindow::Black);

	// r
	w.fillRectangle(750 + s, 290, 10, 10 * 5, Xwindow::Black);
	w.fillRectangle(760 + s, 290, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(760 + s, 310, 10 * 3, 10, Xwindow::Black);
	w.fillRectangle(780 + s, 300, 10, 10, Xwindow::Black);
	w.fillRectangle(760 + s, 320, 10, 10, Xwindow::Black);
	w.fillRectangle(770 + s, 330, 10 * 2, 10, Xwindow::Black);

	// y
	w.fillRectangle(820 + s, 290, 10, 10 * 2, Xwindow::Black);
	w.fillRectangle(850 + s, 290, 10, 10 * 2, Xwindow::Black);
	w.fillRectangle(830 + s, 310, 10 * 2, 10, Xwindow::Black);
	w.fillRectangle(835 + s, 320, 10, 10 * 2, Xwindow::Black);
	
	w.fillRectangle(20, 360, 1300, 2, Xwindow::Black);

	// third row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 390 + i * 10, displayMinionSlot2[j][i]);
		}
	}
	// fourth row
	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 505 + i * 10, displayPlayer2[j][i]);
		}
	}

	w.fillRectangle(20, 620, 1300, 2, Xwindow::Black);
}

void GraphicDisplay::displayHand(Player * player){
	if(player->getplayerNum() == 1){
		w.fillRectangle(10, 630, 130, 30, Xwindow::White);
		w.fillRectangle(10, 655, 1350, 130, Xwindow::White);
		w.drawString(44, 650, "Player1's Hand:");

		for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				w.drawString(44 + j * 264, 670 + i * 10, displayHand1[j][i]);
			}
		}
	} else if(player->getplayerNum() == 2){
		w.fillRectangle(10, 630, 130, 30, Xwindow::White);
		w.fillRectangle(10, 655, 1350, 130, Xwindow::White);
		w.drawString(44, 650, "Player2's Hand:");

		for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				w.drawString(44 + j * 264, 670 + i * 10, displayHand2[j][i]);
			}
		}
	}
}

void GraphicDisplay::displayMagic(Player * player){
	if(player->getplayerNum() == 1){
		w.fillRectangle(140, 630, 1100, 30, Xwindow::White);
		displayMagic1 = "";
		for(int i = 0; i < player->getmagic(); i++){
			displayMagic1 += "o ";
		}
		w.drawString(150, 650, displayMagic1);
	} else if(player->getplayerNum() == 2){
		w.fillRectangle(140, 630, 1100, 30, Xwindow::White);
		displayMagic2 = "";
		for(int i = 0; i < player->getmagic(); i++){
			displayMagic2 += "o ";
		}
		w.drawString(150, 650, displayMagic2);
	}
}

void GraphicDisplay::inspectCard(Player * player, int num){
	if(num > static_cast<int>((player->getminionslot()).size()) || num <= 0){
		w.drawString(44, 40, "No minion is placed in this position.");
		InvalidPosition e{"No minion is placed in this position."};
		throw e;
	}
	std::vector<std::string> temp{(player->getminionslot()[num - 1])->getoutput()};
	
	w.fillRectangle(10, 10, 1350, 900, Xwindow::White);
	w.drawString(44, 40, "Minion at position " + std::to_string(num) + " : ");

	for(unsigned int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		w.drawString(44, 60 + i * 10, temp[i]);
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
				w.drawString(44 + j * 264, 175 + k * 10 + q * 115, enchantsoutput[q * 5 + j][k]);
			}
		}
	}
}

void GraphicDisplay::endgame(Player * player){
	w.fillRectangle(10, 10, 1350, 900, Xwindow::White);

	int s = 20;
	int h = 350;
	int v = 175;
	
	// w
	w.fillRectangle(h, v, s, s, Xwindow::Black);
	w.fillRectangle(h, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 120, v, s, s, Xwindow::Black);
	w.fillRectangle(h + 120, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 60, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 60, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 100, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 100, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 40, v + 80, s, s, Xwindow::Black);
	w.fillRectangle(h + 80, v + 80, s, s, Xwindow::Black);

	// i
	w.fillRectangle(h + 160, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 180, v + 20, s, s * 3, Xwindow::Black);
	w.fillRectangle(h + 160, v + 80, s * 3, s, Xwindow::Black);

	// n
	w.fillRectangle(h + 240, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 320, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 260, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 280, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 300, v + 60, s, s, Xwindow::Black);

	// n
	w.fillRectangle(h + 360, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 440, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 380, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 400, v + 40, s, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 60, s, s, Xwindow::Black);

	// e
	w.fillRectangle(h + 500, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 500, v + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 500, v + 80, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 480, v, s, s * 5, Xwindow::Black);

	// r
	w.fillRectangle(h + 580, v, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 600, v, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 600, v + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 640, v + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 600, v + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 620, v + 80, s * 2, s, Xwindow::Black);

	// i
	w.fillRectangle(h + 270, v + 140, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 290, v + 160, s, s * 3, Xwindow::Black);
	w.fillRectangle(h + 270, v + 220, s * 3, s, Xwindow::Black);

	// s
	w.fillRectangle(h + 350, v + 140, s * 4, s, Xwindow::Black);
	w.fillRectangle(h + 350, v + 180, s * 4, s, Xwindow::Black);
	w.fillRectangle(h + 350, v + 220, s * 4, s, Xwindow::Black);
	w.fillRectangle(h + 350, v + 160, s, s, Xwindow::Black);
	w.fillRectangle(h + 410, v + 200, s, s, Xwindow::Black);

	// p
	w.fillRectangle(h + 40, v + 280, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 40, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 20, v + 280, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 80, v + 280 + 20, s, s, Xwindow::Black);

	// l
	w.fillRectangle(h + 120, v + 280, s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 140, v + 280 + 80, s * 3, s, Xwindow::Black);

	// a
	w.fillRectangle(h + 240, v + 280, s * 2, s, Xwindow::Black);
	w.fillRectangle(h + 240, v + 280 + 40, s * 2, s, Xwindow::Black);
	w.fillRectangle(h + 220, v + 280 + 20, s, s * 4, Xwindow::Black);
	w.fillRectangle(h + 280, v + 280 + 20, s, s * 4, Xwindow::Black);

	// y
	w.fillRectangle(h + 320, v + 280, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 380, v + 280, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 350, v + 280 + 60, s, s * 2, Xwindow::Black);
	w.fillRectangle(h + 320, v + 280 + 40, s * 4, s, Xwindow::Black);


	// e
	w.fillRectangle(h + 440, v + 280, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 440, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 440, v + 280 + 80, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 280, s, s * 5, Xwindow::Black);

	// r
	w.fillRectangle(h + 520, v + 280 , s, s * 5, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 , s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 + 40, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 580, v + 280 + 20, s, s, Xwindow::Black);
	w.fillRectangle(h + 540, v + 280 + 60, s, s, Xwindow::Black);
	w.fillRectangle(h + 560, v + 280 + 80, s * 2, s, Xwindow::Black);

	if(player->getplayerNum() == 1){
		// 1
		w.fillRectangle(h + 640, v + 280, s * 2, s, Xwindow::Black);
		w.fillRectangle(h + 640, v + 280 + 80, s * 3, s, Xwindow::Black);
		w.fillRectangle(h + 660, v + 280 + 20, s, s * 3, Xwindow::Black);
	} else if(player->getplayerNum() == 2){
		// 2
		w.fillRectangle(h + 640, v + 280, s * 3, s, Xwindow::Black);
		w.fillRectangle(h + 640, v + 280 + 40, s * 3, s, Xwindow::Black);
		w.fillRectangle(h + 640, v + 280 + 80, s * 3, s, Xwindow::Black);
		w.fillRectangle(h + 640, v + 280 + 60, s, s, Xwindow::Black);
		w.fillRectangle(h + 680, v + 280 + 20, s, s, Xwindow::Black);
	}
}

void GraphicDisplay::tie(){
	w.fillRectangle(10, 10, 1350, 900, Xwindow::White);
	int s = 20;
	int h = 350;
	int v = 175;
	
	// t
	w.fillRectangle(h + 220, v + 140, s * 4, s, Xwindow::Black);
	w.fillRectangle(h + 250, v + 160, s, s * 4, Xwindow::Black);

	// i
	w.fillRectangle(h + 320, v + 140, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 340, v + 160, s, s * 3, Xwindow::Black);
	w.fillRectangle(h + 320, v + 220, s * 3, s, Xwindow::Black);

	// e
	w.fillRectangle(h + 420, v + 140, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 180, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 420, v + 220, s * 3, s, Xwindow::Black);
	w.fillRectangle(h + 400, v + 140, s, s * 5, Xwindow::Black);
}
