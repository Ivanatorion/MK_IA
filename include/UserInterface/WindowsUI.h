#ifdef _WIN32
#ifndef WNDUINTFACE
#define WNDUINTFACE

#include "UserInterface.h"

enum TextColor {TGREY = 7, TBLACK, TBLUE, TGREEN, TINDIGO, TRED, TPULPLE, TYELLOW, TWHITE};

class WindowsUI : public UserInterface {
  public:
    WindowsUI();
    void printState(STATE state);
  private:
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
