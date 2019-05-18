#ifndef UCATAPULTS_H
#define UCATAPULTS_H

#include <string>
#include "Unit.h"

class UCatapults : public Unit{
  public:
    UCatapults();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
