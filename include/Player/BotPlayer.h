#ifndef BOT_PLAYER_H
#define BOT_PLAYER_H

#include "Player.h"

class BotPlayer : public Player{
  public:
    BotPlayer(bool verb);
    void takeAction(STATE state, ACTION *rAction, int *rParam);
    int chooseOption(std::vector<std::string> choices);

  private:
    bool verbose;
    int numTurnsToPlay;

    std::string actionToString(ACTION action);

    void takeActionBattle(STATE state, ACTION *rAction, int *rParam);
    void takeActionBattleAssign(STATE state, ACTION *rAction, int *rParam);
    void takeActionMoveExplore(STATE state, ACTION *rAction, int *rParam);
};

#endif
