#include "../../../include/Cards/ActionCards/ACStamina.h"

ACStamina::ACStamina(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
}

std::string ACStamina::getName(){
  return "Stamina";
}

void ACStamina::playCardWeak(STATE *s){
  s->avMove = s->avMove + 2;
}

void ACStamina::playCardStrong(STATE *s){
  s->avMove = s->avMove + 4;
  
  if(s->ConcentrationNextCard)
    s->avMove = s->avMove + 2;
}
