#ifdef _WIN32
#ifndef WNDUINTFACE
#define WNDUINTFACE

#include "UserInterface.h"

enum TextColor {TGREY = 7, TBLACK, TBLUE, TGREEN, TINDIGO, TRED, TPURPLE, TYELLOW, TWHITE};

class WindowsUI : public UserInterface {
  public:
    WindowsUI();
    void printState(STATE state);
  private:
    void printCrystals(STATE *s);
    void printSpecial(STATE *s);
    void printPlayerHand(STATE *s);
    void printSource(STATE *s);
    void printSkills(STATE *s);

    void printEnemiesSelection(STATE *s);

    void printStateBattle(STATE *s);
    void printStateBattleRanged(STATE *s);
    void printStateBattleBlock(STATE *s);
    void printStateBattleAssing(STATE *s);
    void printStateBattleAttack(STATE *s);
    void printStateMoveExplore(STATE *s);

    void textcolor(COLOR c);
    void textcolor(TextColor t);
};

#endif
#endif
