#ifndef UALTEMGUARDIANS_H
#define UALTEMGUARDIANS_H

#include <string>
#include "Unit.h"

class UAltemGuardians : public Unit{
  public:
    UAltemGuardians();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
