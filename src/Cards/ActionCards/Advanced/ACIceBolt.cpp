#include "../../../../include/Cards/ActionCards/Advanced/ACIceBolt.h"

#include "../../../../include/Player/Player.h"

ACIceBolt::ACIceBolt(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACIceBolt::getName(){
	return "IceBolt";
}

void ACIceBolt::playCardWeak(STATE *s){
	if(s->playerCrystalsBlue < 3)
    s->playerCrystalsBlue++;
}

void ACIceBolt::playCardStrong(STATE *s){
	s->avRangedIceAttack = s->avRangedIceAttack + 3;

  if(s->ConcentrationStrong)
    s->avRangedIceAttack = s->avRangedIceAttack + 2;
}
