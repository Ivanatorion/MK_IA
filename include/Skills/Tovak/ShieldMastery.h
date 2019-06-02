#ifndef TVKSHIELDMASTER_H
#define TVKSHIELDMASTER_H

#include "../Skill.h"

class ShieldMastery : public Skill{
  public:
    ShieldMastery();
    void onPlayed(STATE *s);
};

#endif
