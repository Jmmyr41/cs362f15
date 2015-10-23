/* Rachael McConnell
 * CS362 Fall 2015
 * Unit Test 4: discardCard()
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testDiscardCard(struct gameState *gs, int player, int trashFlag){
  
  int handPos = 0;
  int handCount=5;
  
  printf("BEFORE DISCARD\n");
  printf("discardPile: %d\n", gs->discardCount[player]);
  printf("playedCards: %d\n", gs->playedCardCount);
  printf("handCount: %d\n", gs->handCount[player]);
  discardCard(handPos, player, gs, trashFlag);
  printf("AFTER DISCARD\n");
  printf("discardPile: %d\n", gs->discardCount[player]);
  printf("playedCards: %d\n", gs->playedCardCount);
  printf("handCount: %d\n", gs->handCount[player]);
  assert(gs->handCount[player] == handCount-1);
  if(trashFlag == 0)
    assert(gs->playedCardCount == 1);
  else
    assert(gs->playedCardCount == 0);
  return 0;
}

int main(){
  struct gameState gs;
  int player;
  int trashFlag;
  int returned=0; 
  int numPlayers = 2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int test1[5] = { copper, copper, copper, copper, copper };
  int test2[5] = { copper, silver, estate, duchy, silver };
  int kingdom[10]= { adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, tribute };
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test2, sizeof(int)*handCount);
  memcpy(gs.hand[1], test1, sizeof(int)*handCount);
  gs.handCount[0]=5;
  gs.handCount[1]=5;

  printf("\nTesting player 0 (Trash Flag set)\n");
  player=0;
  trashFlag=1;
  returned = testDiscardCard(&gs, player, trashFlag);

  printf("\nTesting player 1 (Trash Flag not set)\n");
  player=1;
  trashFlag=0;
  returned += testDiscardCard(&gs, player, trashFlag);
  if(returned == 0)
    printf("\nAll discardCard tests passed!\n");
  else
    printf("\nSome discardCard tests failed.\n");
  return 0;
}

