#include "../../../include/Skills/Tovak/ShieldMastery.h"

#include "../../../include/Player/Player.h"

ShieldMastery::ShieldMastery(){
  this->name = "ShieldMastery";
  this->cooldown = ONCE_A_TURN;
}

void ShieldMastery::onPlayed(STATE *s){
  if(s->gameScene != BATTLE_BLOCK)
    return;

  std::vector<std::string> choices;
  choices.push_back("Block 3");
  choices.push_back("Fire Block 2");
  choices.push_back("Ice Block 2");

  int choice = s->player->chooseOption(choices);
  switch (choice) {
    case 0:
      s->avBlock = s->avBlock + 3;
      break;
    case 1:
      s->avFireBlock = s->avFireBlock + 2;
      break;
    case 2:
      s->avIceBlock = s->avIceBlock + 2;
      break;
  }
}
