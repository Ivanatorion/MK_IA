#include "../../../include/Skills/Tovak/DoubleTime.h"

#include "../../../include/Player/Player.h"

DoubleTime::DoubleTime(){
  this->name = "DoubleTime";
  this->cooldown = ONCE_A_TURN;
}

void DoubleTime::onPlayed(STATE *s){
  s->avMove = s->avMove + (s->isDayNight ? 2 : 1);
}
