#include "../../../include/Cards/ActionCards/ACSwiftness.h"

ACSwiftness::ACSwiftness(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
}

std::string ACSwiftness::getName(){
  return "Swiftness";
}

void ACSwiftness::playCardWeak(STATE *s){
  s->avMove = s->avMove + 2;
}

void ACSwiftness::playCardStrong(STATE *s){
  s->avRangedAttack = s->avRangedAttack + 3;
}
