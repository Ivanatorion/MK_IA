#ifndef UICEGOLEMS_H
#define UICEGOLEMS_H

#include <string>
#include "Unit.h"

class UIceGolems : public Unit{
  public:
    UIceGolems();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
