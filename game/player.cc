#include "player.h"
#include "ascii_graphics.h"

Player::Player(std::string playerName, int playerNum): 
  playerName{playerName}, playerNum{playerNum}, life{20}, magic{3}, activeRitual{nullptr} {
  	// ctor textdisplay
  	// attach observer
}


int Player::getplayernum() {
	return playerNum;
}

int Player::getlife() {
	return life;
}

int Player::getmagic() {
	return magic;
}

std::vector<Card *> & getdeck() {
	return deck;
}

std::vector<Card *> & Player::gethand() {
	return hand;
}

std::vector<Card *> & Player::getminionslot() {
	return minionslot;
}

std::vector<Card *> & Player::getgraveyard() {
	return graveyard;
}

Card * Player::getactiveRitual() {
	return activeRitual;
}

std::vector<std::string> Player::getplayercard() const {
	return {display_player_card(playerNum, playerName, life, magic)};
}

void Player::setplayerNum(int nplayerNum){
	playerNum = nplayerNum;
}

void Player::setlife (int nlife){
	life = nlife;
}

void Player::setmagic (int nmagic){
	magic = nmagic;
}

void Player::setdeck (std::vector<Card *> ndeck){
	deck = ndeck;
}

void Player::sethand (std::vector<Card *> nhand){
	hand = nhand;
}

void Player::setminionslot (std::vector<Card *> nminionslot){
	minionslot = nminionslot;
}

void Player::setgraveyard (std::vector<Card *> ngraveyard){
	graveyard = ngraveyard;
}

void Player::setactiveRitual (Card * nactiveRitual){
	activeRitual = nactiveRitual;
}

void Player::setplayerCard (std::vector<std::string> nplayerCard){
	playerCard = nplayerCard;
}
