#include "../../../include/Cards/ActionCards/ACStamina.h"

ACStamina::ACStamina(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
  this->choicesStrong = 0;
  this->basic = true;
}

std::string ACStamina::getName(){
  return "Stamina";
}

void ACStamina::playCardWeak(STATE *s){
  givePlayerMove(s, 2);
}

void ACStamina::playCardStrong(STATE *s){
  givePlayerMove(s, s->ConcentrationStrong ? 6 : 4);
}
