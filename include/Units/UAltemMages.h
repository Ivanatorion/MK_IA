#ifndef UALTEMMAGES_H
#define UALTEMMAGES_H

#include <string>
#include "Unit.h"

class UAltemMages : public Unit{
  public:
    UAltemMages();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
