#include "../../../../include/Cards/ActionCards/Advanced/ACIceShield.h"

#include "../../../../include/Player/Player.h"

ACIceShield::ACIceShield(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACIceShield::getName(){
	return "IceShield";
}

void ACIceShield::playCardWeak(STATE *s){
	s->avIceBlock = s->avIceBlock + 3;
}

void ACIceShield::playCardStrong(STATE *s){
	s->avIceBlock = s->avIceBlock + 3;
  s->IceShieldStrong = true;

  if(s->ConcentrationNextCard)
    s->avIceBlock = s->avIceBlock + 2;
}
