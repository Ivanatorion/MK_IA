#ifndef UHEROESRED_H
#define UHEROESRED_H

#include <string>
#include "Unit.h"

class UHeroesRed : public Unit{
  public:
    UHeroesRed();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
