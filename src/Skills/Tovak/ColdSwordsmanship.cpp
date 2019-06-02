#include "../../../include/Skills/Tovak/ColdSwordsmanship.h"

#include "../../../include/Player/Player.h"

ColdSwordsmanship::ColdSwordsmanship(){
  this->name = "ColdSwordsmanship";
  this->cooldown = ONCE_A_TURN;
}

void ColdSwordsmanship::onPlayed(STATE *s){
  if(s->gameScene != BATTLE_ATTACK)
    return;

  std::vector<std::string> choices;
  choices.push_back("Attack 2");
  choices.push_back("Ice Attack 2");

  int choice = s->player->chooseOption(choices);

  if(choice == 0)
    s->avAttack = s->avAttack + 2;
  if(choice == 1)
    s->avIceAttack = s->avIceAttack + 2;
}
