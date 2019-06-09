#include "../../../../include/Cards/ActionCards/Advanced/ACRefreshingWalk.h"

#include "../../../../include/Player/Player.h"

ACRefreshingWalk::ACRefreshingWalk(){
  this->color = GREEN;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACRefreshingWalk::getName(){
	return "RefreshingWalk";
}

void ACRefreshingWalk::playCardWeak(STATE *s){
	givePlayerMove(s, 2);
  givePlayerHeal(s, 1);
}

void ACRefreshingWalk::playCardStrong(STATE *s){
	givePlayerMove(s, s->ConcentrationNextCard ? 6 : 4);
  givePlayerHeal(s, 2);
}
