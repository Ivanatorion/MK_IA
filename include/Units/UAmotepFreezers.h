#ifndef UAMOTEPFREEZERS_H
#define UAMOTEPFREEZERS_H

#include <string>
#include "Unit.h"

class UAmotepFreezers : public Unit{
  public:
    UAmotepFreezers();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
