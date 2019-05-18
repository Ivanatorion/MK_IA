#ifndef UUTEMGUARD_H
#define UUTEMGUARD_H

#include <string>
#include "Unit.h"

class UUtemGuardsmen : public Unit{
  public:
    UUtemGuardsmen();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
