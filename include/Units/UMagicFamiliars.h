#ifndef UMAGICFAMILIARS_H
#define UMAGICFAMILIARS_H

#include <string>
#include "Unit.h"

class UMagicFamiliars : public Unit{
  public:
    UMagicFamiliars();
    std::string getName();
    void playEffect(STATE *s);

  private:

};

#endif
