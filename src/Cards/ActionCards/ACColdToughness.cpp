#include "../../../include/Cards/ActionCards/ACColdToughness.h"

#include "../../../include/Player/Player.h"

ACColdToughness::ACColdToughness(){
	this->color = BLUE;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 1;
  this->choicesStrong = 0;
	this->basic = true;
}

std::string ACColdToughness::getName(){
	return "ColdToughness";
}

void ACColdToughness::playCardWeak(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Attack 2");
	choices.push_back("Ice Block 3");
	int choice = s->player->chooseOption(choices);

  switch (choice) {
    case 0:
      s->avAttack = s->avAttack + 2;
      break;
    case 1:
      s->avIceBlock = s->avIceBlock + 3;
      break;
  }
}

void ACColdToughness::playCardStrong(STATE *s){

}
