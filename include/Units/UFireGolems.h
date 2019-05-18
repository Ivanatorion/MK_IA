#ifndef UFIREGOLEMS_H
#define UFIREGOLEMS_H

#include <string>
#include "Unit.h"

class UFireGolems : public Unit{
  public:
    UFireGolems();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
