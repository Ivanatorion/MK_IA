#include "../../../include/Cards/ActionCards/ACRage.h"

ACRage::ACRage(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
}

std::string ACRage::getName(){
  return "Rage";
}

void ACRage::playCardWeak(STATE *s){
  s->avAttack = s->avAttack + 2;
}

void ACRage::playCardStrong(STATE *s){
  s->avAttack = s->avAttack + 4;

  if(s->ConcentrationNextCard)
    s->avAttack = s->avAttack + 2;
}
