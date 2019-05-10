#include "../../../include/Cards/ActionCards/ACCrystallize.h"

#include "../../../include/Player/Player.h"

ACCrystallize::ACCrystallize(){
	this->color = BLUE;
	this->cardtype = ACTIONCARD;
}

std::string ACCrystallize::getName(){
	return "Crystallize";
}

void ACCrystallize::playCardWeak(STATE *s){
	COLOR manaColor = s->player->chooseBasicManaColor();

	switch (manaColor) {
		case RED:
			if(s->playerTokensRed > 0 && s->playerCrystalsRed < 3){
				s->playerTokensRed--;
				s->playerCrystalsRed++;
			}
			break;
		case BLUE:
			if(s->playerTokensBlue > 0 && s->playerCrystalsBlue < 3){
				s->playerTokensBlue--;
				s->playerCrystalsBlue++;
			}
			break;
		case GREEN:
			if(s->playerTokensGreen > 0 && s->playerCrystalsGreen < 3){
				s->playerTokensGreen--;
				s->playerCrystalsGreen++;
			}
			break;
		case WHITE:
			if(s->playerTokensWhite > 0 && s->playerCrystalsWhite < 3){
				s->playerTokensWhite--;
				s->playerCrystalsWhite++;
			}
			break;
	}

}

void ACCrystallize::playCardStrong(STATE *s){
	COLOR manaColor = s->player->chooseBasicManaColor();

	switch (manaColor) {
		case RED:
			if(s->playerCrystalsRed < 3)
				s->playerCrystalsRed++;
			break;
		case BLUE:
		if(s->playerCrystalsBlue < 3)
			s->playerCrystalsBlue++;
			break;
		case GREEN:
		if(s->playerCrystalsGreen < 3)
			s->playerCrystalsGreen++;
			break;
		case WHITE:
		if(s->playerCrystalsWhite < 3)
			s->playerCrystalsWhite++;
			break;
	}
}
