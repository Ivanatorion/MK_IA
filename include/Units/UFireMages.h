#ifndef UFIREMAGES_H
#define UFIREMAGES_H

#include <string>
#include "Unit.h"

class UFireMages : public Unit{
  public:
    UFireMages();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
