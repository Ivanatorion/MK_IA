#ifndef UDELPHANAM_H
#define UDELPHANAM_H

#include <string>
#include "Unit.h"

class UDelphanaMasters : public Unit{
  public:
    UDelphanaMasters();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
