#ifndef UHEROESBLUE_H
#define UHEROESBLUE_H

#include <string>
#include "Unit.h"

class UHeroesBlue : public Unit{
  public:
    UHeroesBlue();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
