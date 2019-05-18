#include "../../include/Units/UPeasants.h"

#include "../../include/Player/Player.h"

UPeasants::UPeasants(){
  this->influenceCost = 4;
  this->armor = 3;
  this->level = 1;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UPeasants::getName(){
  return "Peasants";
}

void UPeasants::playEffect(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Move 2");
	choices.push_back("Influence 2");
	choices.push_back("Attack 2");
	choices.push_back("Block 2");
	int choice = s->player->chooseOption(choices);

	switch (choice) {
		case 0:
			s->avMove = s->avMove + 2;
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
