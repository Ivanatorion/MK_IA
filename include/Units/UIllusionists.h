#ifndef UILLUSIONISTS_H
#define UILLUSIONISTS_H

#include <string>
#include "Unit.h"

class UIllusionists : public Unit{
  public:
    UIllusionists();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
