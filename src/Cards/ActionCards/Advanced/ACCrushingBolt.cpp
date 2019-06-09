#include "../../../../include/Cards/ActionCards/Advanced/ACCrushingBolt.h"

#include "../../../../include/Player/Player.h"

ACCrushingBolt::ACCrushingBolt(){
  this->color = GREEN;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACCrushingBolt::getName(){
	return "CrushingBolt";
}

void ACCrushingBolt::playCardWeak(STATE *s){
	if(s->playerCrystalsGreen < 3)
    s->playerCrystalsGreen++;
}

void ACCrushingBolt::playCardStrong(STATE *s){
	s->avSiegeAttack = s->avSiegeAttack + 3;

  if(s->ConcentrationStrong)
    s->avSiegeAttack = s->avSiegeAttack + 2;
}
