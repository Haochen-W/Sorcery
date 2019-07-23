#include "player.h"

Player::Player(std::string playerName, int playerNum): 
  playerName{playerName}, playerNum{playerNum}, life{20}, magic{3}, activeRitual{nullptr} {
  	// ctor textdisplay
  	// attach observer
}


std::vector<std::string> & Player::getplayercard(){
	return display_player_card(playerNum, playerName, life, magic);
}

