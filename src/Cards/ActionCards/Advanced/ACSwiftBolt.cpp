#include "../../../../include/Cards/ActionCards/Advanced/ACSwiftBolt.h"

#include "../../../../include/Player/Player.h"

ACSwiftBolt::ACSwiftBolt(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACSwiftBolt::getName(){
	return "SwiftBolt";
}

void ACSwiftBolt::playCardWeak(STATE *s){
	if(s->playerCrystalsWhite < 3)
    s->playerCrystalsWhite++;
}

void ACSwiftBolt::playCardStrong(STATE *s){
	s->avRangedAttack = s->avRangedAttack + 4;

  if(s->ConcentrationNextCard)
    s->avRangedAttack = s->avRangedAttack + 2;
}
