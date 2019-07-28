#include "concretespell.h"

Banish::Banish(): Spell{"Banish", 2} {}

std::vector<std::string> Banish::getoutput(){
	std::vector<std::string> temp {display_spell("Banish", 2, "Destroy target minion or ritual")};
	return temp;
}
void Banish::playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual){
	if (onme) {
		playedby->getactiveRitual().clear();
	} else {
		opponent->getactiveRitual().clear();
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}

void Banish::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	if (onme) {
		(playedby->getminionslot())[t - 1]->toGraveyard(playedby, t);
	} else {
		(opponent->getminionslot())[t - 1]->toGraveyard(opponent, t);
	}
	// trigger effects
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
    playedby->trigger(GameStage::minionLeave, nullptr, opponent);
    opponent->trigger(GameStage::minionLeave, nullptr, playedby);

}

Unsummon::Unsummon(): Spell{"Unsummon", 1} {}

std::vector<std::string> Unsummon::getoutput(){
	std::vector<std::string> temp {display_spell("Unsummon", 1, "Return target minion to its owner's hand")};
	return temp;
}

void Unsummon::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	if (onme) {
		std::shared_ptr<Card> temp{(playedby->getminionslot())[t - 1]};
		(playedby->getminionslot()).erase(playedby->getminionslot().begin() + t - 1);
		playedby->gethand().emplace_back(temp);
	} else {
		std::shared_ptr<Card> temp{(opponent->getminionslot())[t - 1]};
		(opponent->getminionslot()).erase(opponent->getminionslot().begin() + t - 1);
		opponent->gethand().emplace_back(temp);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
	// trigger effects
	playedby->trigger(GameStage::minionLeave, nullptr, opponent);
	opponent->trigger(GameStage::minionLeave, nullptr, playedby);
}

Recharge::Recharge(): Spell{"Recharge", 1} {}

std::vector<std::string> Recharge::getoutput(){
	std::vector<std::string> temp {display_spell("Recharge", 1, "Your ritual gains 3 charges")};
	return temp;
}

void Recharge::playCard(Player * playedby, Player * opponent, int i){
	playedby->getactiveRitual()[0]->setcharge(playedby->getactiveRitual()[0]->getcharge() + 3);
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}


Disenchant::Disenchant(): Spell{"Disenchant", 1} {}

std::vector<std::string> Disenchant::getoutput(){
	std::vector<std::string> temp {display_spell("Disenchant", 1, "Destroy the top enchantment on target minion")};
	return temp;
}

void Disenchant::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::shared_ptr<Card> mini;
	if (onme) {
		if (playedby->getminionslot()[t - 1]->getEnchantmentadded().size() == 0){
			playedby->gethand().erase(playedby->gethand().begin() + i - 1);
			return;
		}
		mini = playedby->getminionslot()[t - 1];
	} else {
		if (opponent->getminionslot()[t - 1]->getEnchantmentadded().size() == 0){
			playedby->gethand().erase(playedby->gethand().begin() + i - 1);
			return;
		}
		mini = opponent->getminionslot()[t - 1];
	}
	// remove enchantment
	int index = mini->getEnchantmentadded().size() - 1;
	std::string s = mini->getEnchantmentadded()[index];
	const int att = mini->getattackval();
	const int def = mini->getdefenceval();
	if (s == "Giant Strength"){
		mini->setattackval(att - 2);
		mini->setdefenceval(def - 2);
	} else if (s == "Enrage"){
		mini->setattackval(att / 2);
		mini->setdefenceval(def / 2);
	} else if (s == "Haste"){
		const int curr = mini->getactioneachturn();
		mini->setactioneachturn(curr - 1);
	} else if (s == "Magic Fatigue"){
		const int curr = mini->getabilityCost();
		mini->setabilityCost(curr - 2);
	} else if (s == "Silence"){
		mini->setcanuse(true);
	}

	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
	mini->getEnchantmentadded().erase(mini->getEnchantmentadded().begin() + index);
	// trigger effects
	if (mini->getdefenceval() <= 0){
		playedby->trigger(GameStage::minionLeave, nullptr, opponent);
		opponent->trigger(GameStage::minionLeave, nullptr, playedby);
	}

}

Raisedead::Raisedead(): Spell{"Raise Dead", 1} {}

std::vector<std::string> Raisedead::getoutput(){
	std::vector<std::string> temp {display_spell("Raise Dead", 1, "Resurrect the top minion in your graveyard and set its defence to 1")};
	return temp;
}

void Raisedead::playCard(Player * playedby, Player * opponent, int i){
	const int gravesize = playedby->getgraveyard().size();
	if (gravesize == 0) {
		InvalidPosition e {"Your graveyard is empty."};
		throw e;
	}
	std::shared_ptr<Card> temp{(playedby->getgraveyard())[gravesize - 1]};
	(playedby->getgraveyard()).erase(playedby->getgraveyard().begin() + gravesize - 1);
	temp->setdefenceval(1);
	playedby->getminionslot().emplace_back(temp);
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
	// trigger effect. enter play
	playedby->trigger(GameStage::curNewMinion, temp, opponent);
	opponent->trigger(GameStage::oppNewMinion, temp, playedby);
}

Blizzard::Blizzard(): Spell{"Blizzard", 3} {}

std::vector<std::string> Blizzard::getoutput(){
	std::vector<std::string> temp {display_spell("Blizzard", 3, "Deal 2 damage to all minions")};
	return temp;
}

void Blizzard::playCard(Player * playedby, Player * opponent, int i){
	for (auto i: playedby->getminionslot()){
		i->takeDamage(2);
	}
	for (auto j: opponent->getminionslot()){
		j->takeDamage(2);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
	// trigger effect
	playedby->trigger(GameStage::minionLeave, nullptr, opponent);
	opponent->trigger(GameStage::minionLeave, nullptr, playedby);
}

