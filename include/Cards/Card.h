#ifndef CARD_H
#define CARD_H

#include <string>
#include "../defines.h"

enum COLOR {RED, GREEN, BLUE, WHITE, GOLD, BLACK, NONE}; //NONE for Artifacts

class Card{
  public:
    virtual std::string getName() = 0;          //Returns the name of the Card
    virtual void playCardWeak(STATE *s) = 0;    //Affects the state with the "Weak" Card effect.
    virtual void playCardStrong(STATE *s) = 0;  //Affects the state with the "Strong" Card effect.
    COLOR getColor(){return color;}             //Returns the color of the Card.

  protected:
    COLOR color;
};

#endif
