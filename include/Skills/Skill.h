#ifndef SKILL_H
#define SKILL_H

#include <string>
#include "../defines.h"

enum SKILL_CD {ONCE_A_TURN, ONCE_A_ROUND};

class Skill{
  public:
    virtual void onPlayed(STATE *s) = 0;
    SKILL_CD getCooldown(){return this->cooldown;}
    std::string getName(){return this->name;}
    bool isOnCooldown(){return this->onCD;}
    void setOnCooldown(bool cd){this->onCD = cd;}

  protected:
    std::string name;
    SKILL_CD cooldown;
    bool onCD;
};

#endif
