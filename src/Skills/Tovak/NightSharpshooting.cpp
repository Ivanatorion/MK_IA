#include "../../../include/Skills/Tovak/NightSharpshooting.h"

#include "../../../include/Player/Player.h"

NightSharpshooting::NightSharpshooting(){
  this->name = "NightSharpshooting";
  this->cooldown = ONCE_A_TURN;
}

void NightSharpshooting::onPlayed(STATE *s){
  if(s->gameScene != BATTLE_RANGED && s->gameScene != BATTLE_ATTACK)
    return;

  s->avRangedAttack = s->avRangedAttack + (s->isDayNight ? 1 : 2);
}
