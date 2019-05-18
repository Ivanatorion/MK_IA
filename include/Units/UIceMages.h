#ifndef UICEMAGES_H
#define UICEMAGES_H

#include <string>
#include "Unit.h"

class UIceMages : public Unit{
  public:
    UIceMages();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
