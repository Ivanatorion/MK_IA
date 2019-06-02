#include "../../../include/Skills/Tovak/IFeelNoPain.h"

#include "../../../include/Player/Player.h"

#include "../../../include/Cards/Card.h"

IFeelNoPain::IFeelNoPain(){
  this->name = "IFeelNoPain";
  this->cooldown = ONCE_A_TURN;
}

void IFeelNoPain::onPlayed(STATE *s){
  if(s->gameScene == BATTLE_RANGED || s->gameScene == BATTLE_BLOCK || s->gameScene == BATTLE_ASSIGN || s->gameScene == BATTLE_ATTACK)
    return;

  for(int i = 0; i < s->playerHand.size(); i++){
    if(s->playerHand[i]->getCardType() == WOUND){
      delete s->playerHand[i];
      s->playerHand[i] = s->playerDeedDeck.drawCard();
      return;
    }
  }
}
