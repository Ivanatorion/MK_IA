#ifndef UUTEMSWORD_H
#define UUTEMSWORD_H

#include <string>
#include "Unit.h"

class UUtemSwordsmen : public Unit{
  public:
    UUtemSwordsmen();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
