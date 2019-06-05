#ifndef CARD_H
#define CARD_H

#include <string>
#include "../defines.h"

class Card{
  public:
    virtual std::string getName() = 0;          //Returns the name of the Card
    virtual void playCardWeak(STATE *s) = 0;    //Affects the state with the "Weak" Card effect.
    virtual void playCardStrong(STATE *s) = 0;  //Affects the state with the "Strong" Card effect.

    COLOR getColor(){return color;}
    CARDTYPE getCardType(){return cardtype;}
    int getChoicesWeak(){return choicesWeak;}
    int getChoicesStrong(){return choicesStrong;}
    bool isBasic(){return basic;}

  protected:
    COLOR color;
    CARDTYPE cardtype;
    bool basic;
    int choicesWeak, choicesStrong;             //How many choices the Player has to make when using the effect.
};

#endif
