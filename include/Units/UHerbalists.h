#ifndef UHERBALISTS_H
#define UHERBALISTS_H

#include <string>
#include "Unit.h"

class UHerbalists : public Unit{
  public:
    UHerbalists();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
