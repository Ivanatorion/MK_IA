#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
  public:
    HumanPlayer();
    void takeAction(STATE state, ACTION *rAction, int *rParam);
    int chooseOption(std::vector<std::string> choices);

  private:
    void takeActionBattle(STATE state, ACTION *rAction, int *rParam);
    void takeActionBattleAssign(STATE state, ACTION *rAction, int *rParam);
    void takeActionMoveExplore(STATE state, ACTION *rAction, int *rParam);
};

#endif
