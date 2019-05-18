#ifndef USCOUTS_H
#define USCOUTS_H

#include <string>
#include "Unit.h"

class UScouts : public Unit{
  public:
    UScouts();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
