#ifndef UUTEMCROSS_H
#define UUTEMCROSS_H

#include <string>
#include "Unit.h"

class UUtemCrossbowmen : public Unit{
  public:
    UUtemCrossbowmen();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
