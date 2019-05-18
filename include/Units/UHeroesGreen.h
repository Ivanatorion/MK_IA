#ifndef UHEROESGREEN_H
#define UHEROESGREEN_H

#include <string>
#include "Unit.h"

class UHeroesGreen : public Unit{
  public:
    UHeroesGreen();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
