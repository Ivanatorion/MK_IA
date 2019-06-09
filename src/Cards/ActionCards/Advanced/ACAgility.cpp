#include "../../../../include/Cards/ActionCards/Advanced/ACAgility.h"

#include "../../../../include/Player/Player.h"

ACAgility::ACAgility(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACAgility::getName(){
	return "Agility";
}

void ACAgility::playCardWeak(STATE *s){
	s->AgilityWeak = true;
  givePlayerMove(s, 2);
}

void ACAgility::playCardStrong(STATE *s){
  s->AgilityStrong = true;
	givePlayerMove(s, s->ConcentrationNextCard ? 6 : 4);
}
