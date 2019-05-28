#ifndef SKILL_H
#define SKILL_H

#include <string>

enum SKILL_CD {ONCE_A_TURN, ONCE_A_ROUND};

class Skill{
  public:
    Skill();
    virtual void onPlayed() = 0;
    SKILL_CD getCooldown(){return this->cooldown;}
    std::string getName(){return this->name;}

  protected:
    std::string name;
    SKILL_CD cooldown; //True = Round, False = Turn
};

#endif
