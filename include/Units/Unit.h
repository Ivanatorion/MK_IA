#ifndef UNIT_H
#define UNIT_H

#include <string>
#include "../defines.h"

class Unit{
  public:
    virtual std::string getName() = 0;
    virtual void playEffect(STATE *s) = 0;
    int getInfluenceCost(){return influenceCost;}
    int getArmor(){return armor;}
    bool hasPhysResistance(){return pRes;}
    bool hasFireResistance(){return fRes;}
    bool hasIceResistance(){return iRes;}
    bool isWounded(){return wounded;}
    int getChoices(){return playChoices;}

  protected:
    int influenceCost;           //Cost to recruit
    int armor;                   //Armor value
    int playChoices;             //How many choices the Player has to make when using this unit.
    bool pRes, fRes, iRes;       //Resistances
    bool wounded;                //If Unit is wounded
};

#endif
