#ifndef UHEROESWHITE_H
#define UHEROESWHITE_H

#include <string>
#include "Unit.h"

class UHeroesWhite : public Unit{
  public:
    UHeroesWhite();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
