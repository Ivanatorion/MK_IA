#include "../../../../include/Cards/ActionCards/Advanced/ACPathFinding.h"

#include "../../../../include/Player/Player.h"

ACPathFinding::ACPathFinding(){
  this->color = GREEN;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACPathFinding::getName(){
	return "PathFinding";
}

void ACPathFinding::playCardWeak(STATE *s){
	s->PathFindingWeak = true;
  givePlayerMove(s, 2);
}

void ACPathFinding::playCardStrong(STATE *s){
  s->PathFindingStrong = true;
  givePlayerMove(s, s->ConcentrationStrong ? 6 : 4);
}
