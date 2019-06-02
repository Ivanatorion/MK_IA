#ifndef TVKIDGAD_H
#define TVKIDGAD_H

#include "../Skill.h"

class IDontGiveADamn : public Skill{
  public:
    IDontGiveADamn();
    void onPlayed(STATE *s);
};

#endif
