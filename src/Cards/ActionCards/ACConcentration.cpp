#include "../../../include/Cards/ActionCards/ACConcentration.h"

#include "../../../include/Player/Player.h"

ACConcentration::ACConcentration(){
	this->color = GREEN;
	this->cardtype = ACTIONCARD;
}

std::string ACConcentration::getName(){
	return "Concentration";
}

void ACConcentration::playCardWeak(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Blue Token");
	choices.push_back("White Token");
	choices.push_back("Red Token");
	int choice = s->player->chooseOption(choices);

	switch (choice) {
		case 0:
			s->playerTokensBlue++;
			break;
		case 1:
			s->playerTokensWhite++;
			break;
		case 2:
			s->playerTokensRed++;
			break;
	}
}

void ACConcentration::playCardStrong(STATE *s){
	s->ConcentrationNextCard = true;
}
