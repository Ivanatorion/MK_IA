#include "../../../include/Cards/ActionCards/ACDetermination.h"

#include "../../../include/Player/Player.h"

ACDetermination::ACDetermination(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 1;
  this->choicesStrong = 0;
  this->basic = true;
}

std::string ACDetermination::getName(){
  return "Determination";
}

void ACDetermination::playCardWeak(STATE *s){
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

void ACDetermination::playCardStrong(STATE *s){
  givePlayerBlock(s, s->ConcentrationNextCard ? 7 : 5);
}
