#ifndef RAGE_H
#define RAGE_H

#include <string>
#include "../Card.h"

class ACRage : public Card{
  public:
    ACRage(){this->color = RED;}
    std::string getName(){return "Rage";}
  private:

};

#endif
