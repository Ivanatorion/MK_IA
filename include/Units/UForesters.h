#ifndef UFORESTERS_H
#define UFORESTERS_H

#include <string>
#include "Unit.h"

class UForesters : public Unit{
  public:
    UForesters();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
