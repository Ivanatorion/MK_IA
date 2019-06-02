#ifdef  __linux__
#ifndef UBNTINTFACE
#define UBNTINTFACE

#include "UserInterface.h"

class UbuntuUI : public UserInterface {
  public:
    UbuntuUI();
    void printState(STATE state);
  private:
    void printStateBattle(STATE *s);
    void printStateBattleRanged(STATE *s);
    void printStateBattleBlock(STATE *s);
    void printStateBattleAssing(STATE *s);
    void printStateBattleAttack(STATE *s);
    void printStateMoveExplore(STATE *s);

    void printPlayerHand(STATE *s);
    void printPlayerMana(STATE *s);
    void printSource(STATE *s);

    void printColored(std::string s, COLOR c);
};

#endif
#endif
