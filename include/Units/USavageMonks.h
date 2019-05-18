#ifndef USAVAGEMONK_H
#define USAVAGEMONK_H

#include <string>
#include "Unit.h"

class USavageMonks : public Unit{
  public:
    USavageMonks();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
