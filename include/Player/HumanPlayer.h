#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
  public:
    HumanPlayer();
    void takeAction(STATE state, ACTION *rAction, int *rParam);

};

#endif
