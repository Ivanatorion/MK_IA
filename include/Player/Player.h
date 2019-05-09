#ifndef PLAYER_H
#define PLAYER_H

#include "../defines.h"

class Player{
  public:
    virtual void takeAction(STATE state, ACTION *rAction, int *rParam) = 0;

};

#endif
