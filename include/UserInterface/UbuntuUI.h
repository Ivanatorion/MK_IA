#ifdef  __linux__
#ifndef UBNTINTFACE
#define UBNTINTFACE

#include "UserInterface.h"

enum TextColor {TPURPLE};

class UbuntuUI : public UserInterface {
  public:
    UbuntuUI();
    void printState(STATE state);
  private:
    void printStateMoveExplore(STATE *s);
    void printStateBattle(STATE *s);
    void printStateBattleRanged(STATE *s);
    void printStateBattleBlock(STATE *s);
    void printStateBattleAssing(STATE *s);
    void printStateBattleAttack(STATE *s);

    void printEnemiesOnMap(STATE *s);

    void printEnemiesSelection(STATE *s);

    void printAdvancedActionsOffer(STATE *s);

    void printPlayerHand(STATE *s);
    void printPlayerMana(STATE *s);
    void printSource(STATE *s);
    void printSkills(STATE *s);
    void printSpecial(STATE *s);

    void printColored(std::string s, COLOR c);
    void printColored(std::string s, TextColor c);
};

#endif
#endif
