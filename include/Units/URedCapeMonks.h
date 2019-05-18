#ifndef UREDCAPEMONK_H
#define UREDCAPEMONK_H

#include <string>
#include "Unit.h"

class URedCapeMonks : public Unit{
  public:
    URedCapeMonks();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
