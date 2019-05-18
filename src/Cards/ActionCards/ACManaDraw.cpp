#include "../../../include/Cards/ActionCards/ACManaDraw.h"

#include "../../../include/Player/Player.h"

ACManaDraw::ACManaDraw(){
	this->color = WHITE;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 0;
  this->choicesStrong = 2;
}

std::string ACManaDraw::getName(){
	return "ManaDraw";
}

void ACManaDraw::playCardWeak(STATE *s){
	s->ManaDrawWeakActive = true;
}

void ACManaDraw::playCardStrong(STATE *s){
	std::vector<std::string> choices;
	std::string dcolor;
	int c1, c2;

	for(int i = 0; i < N_DICE_IN_SOURCE; i++){
		switch (s->sourceDice[i]) {
			case RED:
				dcolor = "Red";
				break;
			case WHITE:
				dcolor = "White";
				break;
			case GREEN:
				dcolor = "Green";
				break;
			case BLUE:
				dcolor = "Blue";
				break;
			case BLACK:
				dcolor = "Black";
				break;
			case GOLD:
				dcolor = "Gold";
				break;
			case NONE:
				dcolor = "None";
				break;
		}
		choices.push_back(dcolor + " Die");
	}

	do{
		c1 = s->player->chooseOption(choices);
	}while(s->sourceDice[c1] == NONE);

	choices.clear();

	choices.push_back("Red");
	choices.push_back("Blue");
	choices.push_back("Green");
	choices.push_back("White");
	choices.push_back("Black");

	c2 = s->player->chooseOption(choices);

	switch(c2){
		case 0:
			s->sourceDice[c1] = RED;
			s->playerTokensRed = s->playerTokensRed + 2;
			break;
		case 1:
			s->sourceDice[c1] = BLUE;
			s->playerTokensBlue = s->playerTokensBlue + 2;
			break;
		case 2:
			s->sourceDice[c1] = GREEN;
			s->playerTokensGreen = s->playerTokensGreen + 2;
			break;
		case 3:
			s->sourceDice[c1] = WHITE;
			s->playerTokensWhite = s->playerTokensWhite + 2;
			break;
		case 4:
			s->sourceDice[c1] = BLACK;
			s->playerTokensBlack = s->playerTokensBlack + 2;
			break;
	}
}
