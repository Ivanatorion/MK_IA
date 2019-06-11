#include <cstdio>
#include <cstdlib>

#include "../../include/Player/BotPlayer.h"

BotPlayer::BotPlayer(bool verb){
  this->verbose = verb;
  this->numTurnsToPlay = 10000;
}

void BotPlayer::takeAction(STATE state, ACTION *rAction, int *rParam){
  if(numTurnsToPlay <= 0){
    (*rAction) = QUIT_GAME;
    return;
  }
  else{
    numTurnsToPlay--;
  }

  switch (state.gameScene) {
    case MOVE_AND_EXPLORE:
      takeActionMoveExplore(state, rAction, rParam);
      break;
    case BATTLE_RANGED:
    case BATTLE_BLOCK:
    case BATTLE_ATTACK:
      takeActionBattle(state, rAction, rParam);
      break;
    case BATTLE_ASSIGN:
      takeActionBattleAssign(state, rAction, rParam);
      break;
  }
}

void BotPlayer::takeActionBattleAssign(STATE state, ACTION *rAction, int *rParam){
  int act = rand()%5;

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      (*rParam) = 0;
      break;
    case 1:
      (*rAction) = ASSING_DAMAGE_TO_UNIT;
      (*rParam) = 0;
      break;
    case 2:
      (*rAction) = ASSING_DAMAGE_TO_PLAYER;
      (*rParam) = 0;
      break;
    case 3:
      (*rAction) = ADVANCE_BATTLE_PHASE;
      (*rParam) = 0;
      break;
    case 4:
      if(state.BattleAttacksToAssign.size() > 0){
        (*rAction) = SELECT_ATTACK_TO_ASSING;
        (*rParam) = rand()%state.BattleAttacksToAssign.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 5:
      (*rAction) = QUIT_GAME;
      break;
  }

  if(verbose){
    printf("I choose: %s\nWith Param: %d\n", actionToString(*rAction).c_str(), *rParam);
  }
}

void BotPlayer::takeActionBattle(STATE state, ACTION *rAction, int *rParam){
  int act = rand()%9;

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      break;
    case 1:
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_WEAK;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 2:
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_STRONG;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 3:
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_SIDEWAYS;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 4:
      (*rAction) = TAKE_DIE_FROM_SOURCE;
      (*rParam) = rand()%3;
      break;
    case 5:
      if(state.BattleEnemies.size() > 0){
        (*rAction) = SELECT_ENEMY;
        (*rParam) = rand()%state.BattleEnemies.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 6:
      (*rAction) = (state.gameScene == BATTLE_BLOCK) ? BLOCK_ENEMY : ATTACK_SELECTED_ENEMIES;
      (*rParam) = 0;
      break;
    case 7:
      (*rAction) = ADVANCE_BATTLE_PHASE;
      (*rParam) = 0;
      break;
    case 8:
      if(state.SkillsObtained.size() > 0){
        (*rAction) = USE_SKILL;
        (*rParam) = rand()%state.SkillsObtained.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 9:
      (*rAction) = QUIT_GAME;
      break;
  }

  if(verbose){
    printf("I choose: %s\nWith Param: %d\n", actionToString(*rAction).c_str(), *rParam);
  }
}

void BotPlayer::takeActionMoveExplore(STATE state, ACTION *rAction, int *rParam){
  int act = rand()%13;

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      (*rParam) = 0;
      break;
    case 1:
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_WEAK;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 2:
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_STRONG;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 3:
      (*rAction) = TAKE_DIE_FROM_SOURCE;
      (*rParam) = rand()%3;
      break;
    case 4:
      (*rAction) = MOVE_TO_ADJACENT_HEX;
      (*rParam) = rand()%6;
      break;
    case 5:
      (*rAction) = END_TURN;
      (*rParam) = 0;
      break;
    case 6:
      if(state.UnitOffer.size() > 0){
        (*rAction) = RECRUIT_UNIT;
        (*rParam) = rand()%state.UnitOffer.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 7:
      (*rAction) = REVEAL_ADJEACENT_TILE;
      (*rParam) = rand()%2;
      break;
    case 8:
      (*rAction) = USE_CARD_SIDEWAYS;
      if(state.playerHand.size() > 0){
        (*rAction) = USE_CARD_SIDEWAYS;
        (*rParam) = rand()%state.playerHand.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 9:
      if(state.PlayerUnits.size() > 0){
        (*rAction) = USE_UNIT;
        (*rParam) = rand()%state.PlayerUnits.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 10:
      if(state.SkillsObtained.size() > 0){
        (*rAction) = USE_SKILL;
        (*rParam) = rand()%state.SkillsObtained.size();
      }
      else{
        (*rAction) = NOTHING;
        (*rParam) = 0;
      }
      break;
    case 11:
      (*rAction) = ATTACK_RAMPAGING_ENEMY;
      (*rParam) = rand()%6;
      break;
    case 12:
      (*rAction) = HEAL_PLAYER_WOUND;
      (*rParam) = 0;
      break;
  }

  if(verbose){
    printf("I choose: %s\nWith Param: %d\n", actionToString(*rAction).c_str(), *rParam);
  }

}

int BotPlayer::chooseOption(std::vector<std::string> choices){
  int choice = rand()%choices.size();

  if(verbose){
    printf("From: \n");
    for(int i = 0; i < choices.size(); i++)
      printf("%s\n", choices[i].c_str());
    printf("\nI choose: %s\n", choices[choice].c_str());
  }

  return choice;
}

std::string BotPlayer::actionToString(ACTION action){
  switch (action) {
    case NOTHING:
      return "Nothing";
    case USE_CARD_WEAK:
      return "UseCardWeak";
    case USE_CARD_STRONG:
      return "UseCardStrong";
    case USE_CARD_SIDEWAYS:
      return "UseCardSideways";
    case USE_UNIT:
      return "UseUnit";
    case USE_SKILL:
      return "UseSkill";
    case MOVE_TO_ADJACENT_HEX:
      return "MoveToAdjacentHex";
    case TAKE_DIE_FROM_SOURCE:
      return "TakeDieFromSource";
    case RECRUIT_UNIT:
      return "RecruitUnit";
    case REVEAL_ADJEACENT_TILE:
      return "RevealAdjacentTile";
    case ATTACK_RAMPAGING_ENEMY:
      return "AttackRampagingEnemy";
    case SELECT_ENEMY:
      return "SelectEnemy";
    case ATTACK_SELECTED_ENEMIES:
      return "AttackSelectedEnemies";
    case BLOCK_ENEMY:
      return "BlockEnemy";
    case ADVANCE_BATTLE_PHASE:
      return "AdvanceBattlePhase";
    case SELECT_ATTACK_TO_ASSING:
      return "SelectAttackToAssign";
    case ASSING_DAMAGE_TO_UNIT:
      return "AssignDamageToUnit";
    case ASSING_DAMAGE_TO_PLAYER:
      return "AssignDamageToPlayer";
    case END_TURN:
      return "EndTurn";
    case QUIT_GAME:
      return "QuitGame";
    case HEAL_PLAYER_WOUND:
      return "HealPlayerWound";
  }

  return "I DONT KNOW WHAT I DID!";
}
