#include "../../../include/Cards/ActionCards/ACRage.h"

ACRage::ACRage(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
}

std::string ACRage::getName(){
  return "Rage";
}

void ACRage::playCardWeak(STATE *s){

}

void ACRage::playCardStrong(STATE *s){

}
