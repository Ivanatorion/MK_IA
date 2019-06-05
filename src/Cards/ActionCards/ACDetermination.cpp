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
      s->avAttack = s->avAttack + 2;
      break;
    case 1:
      s->avBlock = s->avBlock + 2;
      break;
  }
}

void ACDetermination::playCardStrong(STATE *s){
  s->avBlock = s->avBlock + 5;

  if(s->ConcentrationNextCard)
    s->avBlock = s->avBlock + 2;
}
