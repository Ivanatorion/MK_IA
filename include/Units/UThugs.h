#ifndef UTHUGS_H
#define UTHUGS_H

#include <string>
#include "Unit.h"

class UThugs : public Unit{
  public:
    UThugs();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
