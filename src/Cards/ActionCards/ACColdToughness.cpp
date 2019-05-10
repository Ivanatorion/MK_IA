#include "../../../include/Cards/ActionCards/ACColdToughness.h"

#include "../../../include/Player/Player.h"

ACColdToughness::ACColdToughness(){
	this->color = BLUE;
	this->cardtype = ACTIONCARD;
}

std::string ACColdToughness::getName(){
	return "ColdToughness";
}

void ACColdToughness::playCardWeak(STATE *s){

}

void ACColdToughness::playCardStrong(STATE *s){

}
