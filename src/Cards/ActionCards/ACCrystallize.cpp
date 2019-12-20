#include "../../../include/Cards/ActionCards/ACCrystallize.h"

#include "../../../include/Player/Player.h"

ACCrystallize::ACCrystallize(){
	this->color = BLUE;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 1;
	this->choicesStrong = 1;
	this->basic = true;
}

std::string ACCrystallize::getName(){
	return "Crystallize";
}

void ACCrystallize::playCardWeak(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Red");
	choices.push_back("Blue");
	choices.push_back("Green");
	choices.push_back("White");

	int manaColor = s->player->chooseOption(choices);

	switch (manaColor) {
		case 0:
			if(s->playerTokensRed > 0 && s->playerCrystalsRed < 3){
				s->playerTokensRed--;
				s->playerCrystalsRed++;
			}
			break;
		case 1:
			if(s->playerTokensBlue > 0 && s->playerCrystalsBlue < 3){
				s->playerTokensBlue--;
				s->playerCrystalsBlue++;
			}
			break;
		case 2:
			if(s->playerTokensGreen > 0 && s->playerCrystalsGreen < 3){
				s->playerTokensGreen--;
				s->playerCrystalsGreen++;
			}
			break;
		case 3:
			if(s->playerTokensWhite > 0 && s->playerCrystalsWhite < 3){
				s->playerTokensWhite--;
				s->playerCrystalsWhite++;
			}
			break;
	}

}

void ACCrystallize::playCardStrong(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Red");
	choices.push_back("Blue");
	choices.push_back("Green");
	choices.push_back("White");

	int manaColor = s->player->chooseOption(choices);

	switch (manaColor) {
		case 0:
			if(s->playerCrystalsRed < 3)
				s->playerCrystalsRed++;
			break;
		case 1:
			if(s->playerCrystalsBlue < 3)
				s->playerCrystalsBlue++;
			break;
		case 2:
			if(s->playerCrystalsGreen < 3)
				s->playerCrystalsGreen++;
			break;
		case 3:
			if(s->playerCrystalsWhite < 3)
				s->playerCrystalsWhite++;
			break;
	}
}
