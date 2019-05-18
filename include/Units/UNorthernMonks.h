#ifndef UNORTHMONK_H
#define UNORTHMONK_H

#include <string>
#include "Unit.h"

class UNorthernMonks : public Unit{
  public:
    UNorthernMonks();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
