#include "../../../include/Cards/ActionCards/ACDetermination.h"

ACDetermination::ACDetermination(){
  this->color = BLUE;
  this->cardtype = ACTIONCARD;
}

std::string ACDetermination::getName(){
  return "Determination";
}

void ACDetermination::playCardWeak(STATE *s){

}

void ACDetermination::playCardStrong(STATE *s){

}
