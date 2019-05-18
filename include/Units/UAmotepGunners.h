#ifndef UAMOTEPGUNNERS_H
#define UAMOTEPGUNNERS_H

#include <string>
#include "Unit.h"

class UAmotepGunners : public Unit{
  public:
    UAmotepGunners();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
