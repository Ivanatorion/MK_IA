#ifndef TVKMOTIVATION_H
#define TVKMOTIVATION_H

#include "../Skill.h"

class TvkMotivation : public Skill{
  public:
    TvkMotivation();
    void onPlayed(STATE *s);
};

#endif
