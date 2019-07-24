#include "concreteritual.h"

Darkritual::Darkritual(): Ritual{"Dark Ritual", 0, 1, 5} {
	activationCost = 1;
	charge = 5;
}

std::vector<std::string> Darkritual::getoutput(){
	std::vector<std::string> temp {display_ritual("Dark Ritual", 0, activationCost, "At the start of your turn, gain 1 magic", charge)};
	return temp;
}


Auraofpower::Auraofpower(): Ritual{"Aura of Power", 1, 1, 4} {
	activationCost = 1;
	charge = 4;
}

std::vector<std::string> Auraofpower::getoutput(){
	std::vector<std::string> temp {display_ritual("Aura of Power", 1, activationCost, "Whenever a minion enters play under your control, it gains +1/+1", charge)};
	return temp;
}


Standstill::Standstill(): Ritual{"Standstill", 3, 2, 4} {
	activationCost = 2;
	charge = 4;
}

std::vector<std::string> Standstill::getoutput(){
	std::vector<std::string> temp {display_ritual("Standstill", 3, activationCost, "Whenever a minion enters play, destroy it", charge)};
	return temp;
}
