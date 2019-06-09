#include "../../../include/Cards/ActionCards/ACRage.h"

#include "../../../include/Player/Player.h"

ACRage::ACRage(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 1;
  this->choicesStrong = 0;
  this->basic = true;
}

std::string ACRage::getName(){
  return "Rage";
}

void ACRage::playCardWeak(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Attack 2");
	choices.push_back("Block 2");
	int choice = s->player->chooseOption(choices);

  switch (choice) {
    case 0:
      givePlayerAttack(s, 2);
      break;
    case 1:
      givePlayerBlock(s, 2);
      break;
  }
}

void ACRage::playCardStrong(STATE *s){
  givePlayerAttack(s, s->ConcentrationStrong ? 6 : 4);
}
