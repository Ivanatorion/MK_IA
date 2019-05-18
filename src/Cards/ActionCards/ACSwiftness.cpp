#include "../../../include/Cards/ActionCards/ACSwiftness.h"

ACSwiftness::ACSwiftness(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
  this->choicesStrong = 0;
}

std::string ACSwiftness::getName(){
  return "Swiftness";
}

void ACSwiftness::playCardWeak(STATE *s){
  s->avMove = s->avMove + 2;
}

void ACSwiftness::playCardStrong(STATE *s){
  s->avRangedAttack = s->avRangedAttack + 3;

  if(s->ConcentrationNextCard)
    s->avRangedAttack = s->avRangedAttack + 2;
}
