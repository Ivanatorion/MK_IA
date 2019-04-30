#ifndef CARD_H
#define CARD_H

#include <string>
#include "../defines.h"

enum COLOR {RED, GREEN, BLUE, WHITE, GOLD, BLACK};

class Card{
  public:
    virtual std::string getName() = 0;
    COLOR getColor(){return color;}

  protected:
    COLOR color;
};

#endif
