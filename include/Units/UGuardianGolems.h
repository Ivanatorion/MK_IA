#ifndef UGUARDGOLEM_H
#define UGUARDGOLEM_H

#include <string>
#include "Unit.h"

class UGuardianGolems : public Unit{
  public:
    UGuardianGolems();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
