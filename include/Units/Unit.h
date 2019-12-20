#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

#include "../Map.h"
#include "../defines.h"

class Unit{
  public:
    virtual ~Unit() = 0;

    virtual std::string getName() = 0;
    virtual void playEffect(STATE *s) = 0;
    virtual void tryToRecruit(STATE *s);     //Tries to recruit Unit
    int getInfluenceCost(){return influenceCost;}
    int getArmor(){return armor;}
    bool hasPhysResistance(){return pRes;}
    bool hasFireResistance(){return fRes;}
    bool hasIceResistance(){return iRes;}
    bool isWounded(){return wounded;}
    bool isReady(){return ready;}
    bool isElite(){return level > 2;}
    int getChoices(){return playChoices;}
    int getLevel(){return level;}
    void setReady(bool rd){this->ready = rd;}
    void setWounded(bool wd){this->wounded = wd;}

  protected:
    std::vector<LOCATION> recruitableLocations; //Locations in which this Unit can be recruited
    int influenceCost;           //Cost to recruit
    int armor;                   //Armor value
    int playChoices;             //How many choices the Player has to make when using this unit.
    bool pRes, fRes, iRes;       //Resistances
    bool wounded;                //If Unit is wounded
    bool ready;                  //If Unit is Ready
    int level;                   //Unit Level
};

#endif
