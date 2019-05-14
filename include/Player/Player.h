#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "../defines.h"

class Player{
  public:
    virtual void takeAction(STATE state, ACTION *rAction, int *rParam) = 0;
    virtual int chooseOption(std::vector<std::string> choices) = 0;
};

#endif
