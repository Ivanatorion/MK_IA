#ifndef USHOCKTROOPS_H
#define USHOCKTROOPS_H

#include <string>
#include "Unit.h"

class UShockTroops : public Unit{
  public:
    UShockTroops();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
