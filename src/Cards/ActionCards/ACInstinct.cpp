#include "../../../include/Cards/ActionCards/ACInstinct.h"

#include "../../../include/Player/Player.h"

ACInstinct::ACInstinct(){
	this->color = RED;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 1;
  this->choicesStrong = 1;
	this->basic = true;
}

std::string ACInstinct::getName(){
	return "Instinct";
}

void ACInstinct::playCardWeak(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Move 2");
	choices.push_back("Influence 2");
	choices.push_back("Attack 2");
	choices.push_back("Block 2");
	int choice = s->player->chooseOption(choices);

	switch (choice) {
		case 0:
			givePlayerMove(s, 2);
			break;
		case 1:
			s->avInfluence = s->avInfluence + 2;
			break;
		case 2:
			s->avAttack = s->avAttack + 2;
			break;
		case 3:
			s->avBlock = s->avBlock + 2;
			break;
	}
}

void ACInstinct::playCardStrong(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Move 4");
	choices.push_back("Influence 4");
	choices.push_back("Attack 4");
	choices.push_back("Block 4");
	int choice = s->player->chooseOption(choices);

	switch (choice) {
		case 0:
			givePlayerMove(s, s->ConcentrationStrong ? 6 : 4);
			break;
		case 1:
			givePlayerInfluence(s, s->ConcentrationStrong ? 6 : 4);
			break;
		case 2:
			givePlayerAttack(s, s->ConcentrationStrong ? 6 : 4);
			break;
		case 3:
			givePlayerBlock(s, s->ConcentrationStrong ? 6 : 4);
			break;
	}
}
