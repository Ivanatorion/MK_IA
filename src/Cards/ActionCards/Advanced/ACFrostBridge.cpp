#include "../../../../include/Cards/ActionCards/Advanced/ACFrostBridge.h"

#include "../../../../include/Player/Player.h"

ACFrostBridge::ACFrostBridge(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 0;
  this->basic = false;
}

std::string ACFrostBridge::getName(){
	return "FrostBridge";
}

void ACFrostBridge::playCardWeak(STATE *s){
  s->FrostBridgeWeak = true;
  givePlayerMove(s, 2);
}

void ACFrostBridge::playCardStrong(STATE *s){
  s->FrostBridgeStrong = true;
  givePlayerMove(s, s->ConcentrationStrong ? 6 : 4);
}
