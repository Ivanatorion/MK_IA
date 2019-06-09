#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

#include "Cards/Deck.h"
#include "Map.h"

#define N_DICE_IN_SOURCE 3
#define N_UNITS_IN_OFFER 3

enum COLOR {RED, GREEN, BLUE, WHITE, GOLD, BLACK, NONE}; //NONE for Artifacts
enum CARDTYPE {ACTIONCARD, SPELLCARD, ARTIFACTCARD, WOUND};
enum ACTION {NOTHING, USE_CARD_WEAK, USE_CARD_STRONG, USE_CARD_SIDEWAYS, USE_UNIT, USE_SKILL, MOVE_TO_ADJACENT_HEX,
             TAKE_DIE_FROM_SOURCE, RECRUIT_UNIT, REVEAL_ADJEACENT_TILE, ATTACK_RAMPAGING_ENEMY,
             SELECT_ENEMY, ATTACK_SELECTED_ENEMIES, BLOCK_ENEMY, ADVANCE_BATTLE_PHASE,
             SELECT_ATTACK_TO_ASSING, ASSING_DAMAGE_TO_UNIT, ASSING_DAMAGE_TO_PLAYER, END_TURN, QUIT_GAME,
             HEAL_PLAYER_WOUND};
enum GAME_SCENE {MOVE_AND_EXPLORE, BATTLE_RANGED, BATTLE_BLOCK, BATTLE_ASSIGN, BATTLE_ATTACK};

class Player;
class Unit;
class Skill;
typedef struct stado{
  bool gameRunning;        //Game is running.
  bool gameOver;           //Game should end.

  GAME_SCENE gameScene;    //The current phase of the game (Battle, Movement, Interaction...)

  //Battle Containers
  std::vector<ENEMY> BattleEnemies;
  std::vector<ENEMY> BattleEnemiesSelected;
  std::vector<ENEMY_ATTACK> BattleAttacksToAssign;
  std::vector<ENEMY_ATTACK> BattleAttacksSelected;

  //Pointer to the Hex Which Contains an enemy that should be removed if the player defeats it in battle.
  HEX *rampagingHexAttacked;

  bool assaultingSite;

  int spellsToGain;

  //Unit Containers
  std::vector<Unit*> PlayerUnits;
  std::vector<Unit*> UnitOffer;
  std::vector<Unit*> RegularUnitsDeck;
  std::vector<Unit*> EliteUnitsDeck;

  //Spells and Advanced Action Offer
  Card *spellOffer[3];
  Card *advancedActionsOffer[3];

  //Other Decks
  Deck advancedActionsDeck;
  Deck artifactsDeck;
  Deck spellsDeck;

  //Skills
  std::vector<Skill*> SkillsNotObtained;
  std::vector<Skill*> SkillsObtained;

  //Player Stuff
  std::vector<Card*> playerHand;   //Cards in the player hand.
  int playerHandMaxSize;           //Maximum cards the player can hold.
  int playerHandSizeBonus;
  int currentRound;                //Current game round.
  int playerFame;                  //The ammount of "fame" the player has.
  int playerReputation;            //The level of reputation.
  int curTile;                     //curTile = number of the tile (in game number)
  int curTileN;                    //curTileN = number of the tile (in map position)
  int curHexN;                     //Number of the Hex in the tile
  int playerArmor;
  int playerLevel;
  int playerCommandTokens;
  int playerKeepsConquered;

  //Player Decks
  Deck playerDiscardDeck;
  Deck playerDeedDeck;

  HEX *curHex;

  Map *m; //The map.

  int playerCrystalsRed, playerCrystalsWhite, playerCrystalsGreen, playerCrystalsBlue;
  int playerTokensRed, playerTokensWhite, playerTokensGreen, playerTokensBlue, playerTokensBlack;

  COLOR sourceDice[N_DICE_IN_SOURCE];
  bool diceTaken;

  bool isDayNight;         //True for day, False for night.

  int avHeal;
  int avAttack, avBlock, avMove, avInfluence; //Available Attack, Block, Move and Influence.
  int avFireAttack, avFireBlock, avIceAttack, avIceBlock, avColdFireAttack, avColdFireBlock;
  int avRangedAttack, avRangedFireAttack, avRangedIceAttack, avRangedColdFireAttack;
  int avSiegeAttack, avSiegeFireAttack, avSiegeIceAttack, avSiegeColdFireAttack;

  Player *player;

  //Special effects
  bool ManaDrawWeakActive;
  bool ConcentrationNextCard;
  bool TovakIDontGiveADamn;
  bool IceShieldStrong;
  bool AgilityWeak, AgilityStrong;

  //End Turn
  int fameToGain;
  int repToGain;
} STATE;

#endif
