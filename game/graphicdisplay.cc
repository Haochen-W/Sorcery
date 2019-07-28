#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(): outputDisplay(){}

void GraphicDisplay::displayBoard(){
	w.fillRectangle(10, 10, 1350, 530, Xwindow::White);
	w.fillRectangle(20, 20, 1300, 2, Xwindow::Black);
	w.fillRectangle(20, 20, 2, 510, Xwindow::Black);
	w.fillRectangle(1320, 20, 2, 510, Xwindow::Black);

	// first row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 40 + i * 10, displayPlayer1[j][i]);
		}
	}
	// second row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 155 + i * 10, displayMinionSlot1[j][i]);
		}
	}

	w.fillRectangle(20, 270, 1300, 2, Xwindow::Black);
	w.fillRectangle(20, 280, 1300, 2, Xwindow::Black);

	// third row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 310 + i * 10, displayMinionSlot2[j][i]);
		}
	}
	// fourth row
	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		for(int j = 0; j < 5; j++){
			w.drawString(44 + j * 264, 425 + i * 10, displayPlayer2[j][i]);
		}
	}

	w.fillRectangle(20, 530, 1300, 2, Xwindow::Black);
}

void GraphicDisplay::displayHand(Player * player){
	if(player->getplayerNum() == 1){
		w.fillRectangle(10, 560, 1350, 150, Xwindow::White);
		w.drawString(44, 580, "Player1's Hand:");

		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				w.drawString(44 + j * 264, 600 + i * 10, displayHand1[j][i]);
			}
		}
	} else if(player->getplayerNum() == 2){
		w.fillRectangle(10, 560, 1350, 150, Xwindow::White);
		w.drawString(44, 580, "Player2's Hand:");

		for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
			for(int j = 0; j < 5; j++){
				w.drawString(44 + j * 264, 600 + i * 10, displayHand2[j][i]);
			}
		}
	}
}

void GraphicDisplay::displayMagic(Player * player){}

void GraphicDisplay::inspectCard(Player * player, int num){
	if(num > (player->getminionslot()).size() || num <= 0){
		w.drawString(44, 580, "No minion is placed in this position.");
		InvalidPosition e{"No minion is placed in this position."};
		throw e;
	}
	std::vector<std::string> temp{(player->getminionslot()[num - 1])->getoutput()};
	
	w.fillRectangle(10, 560, 1350, 150, Xwindow::White);
	w.drawString(44, 580, "Minion at position " + std::to_string(num) + " : ");

	for(int i = 0; i < CARD_TEMPLATE_BORDER.size(); i++){
		w.drawString(44, 600 + i * 10, temp[i]);
	}
}

