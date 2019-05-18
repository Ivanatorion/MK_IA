#ifndef USORCERERS_H
#define USORCERERS_H

#include <string>
#include "Unit.h"

class USorcerers : public Unit{
  public:
    USorcerers();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
