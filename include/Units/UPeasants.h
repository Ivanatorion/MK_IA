#ifndef UPEASANTS_H
#define UPEASANTS_H

#include <string>
#include "Unit.h"

class UPeasants : public Unit{
  public:
    UPeasants();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
