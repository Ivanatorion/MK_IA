#include "../../../../include/Cards/ActionCards/Advanced/ACFireBolt.h"

#include "../../../../include/Player/Player.h"

ACFireBolt::ACFireBolt(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACFireBolt::getName(){
	return "FireBolt";
}

void ACFireBolt::playCardWeak(STATE *s){
	if(s->playerCrystalsRed < 3)
    s->playerCrystalsRed++;
}

void ACFireBolt::playCardStrong(STATE *s){
	s->avRangedFireAttack = s->avRangedFireAttack + 3;

  if(s->ConcentrationStrong)
    s->avRangedFireAttack = s->avRangedFireAttack + 2;
}
