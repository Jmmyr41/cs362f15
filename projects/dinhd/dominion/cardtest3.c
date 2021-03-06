/*
This program tests the smithyCard function.
The parameters for this function are:
int currentPlayer, struct gameState *state, int handPos

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int i;

    //initialize the game
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    initializeGame(2, k, 2, &G);

    //replace all cards in hand with a adventurer card
    for (i = 0; i < numHandCards(&G); i++)
    {
        G.hand[0][i] = smithy;
    }
    


    // check state of game before calling function
    // printState(&G);
    //  printSupply(&G);
    // // printScores(&G);
    // printHand(0, &G);
    // // printPlayed(0, &G);
    // printDeck(0, &G);
    // printf ("Number of cards in hand %i \n", numHandCards(&G));


    printf("* * * * * * * * * * * * * * * * Testing smithy card * * * * * * * * * * * * * * * * \n");

    //keeps track of played cards
    int playedCards = 0;
    int cardsInHand = G.handCount[0];

    i = 4;
    playCard(i, -1, -1, -1, &G);


    //check to see if adventurer card goes into discard
    //printPlayed(0, &G);
    //printHand(0, &G);
    //make sure card is discarded
    assert (G.hand[4][i] != smithy);
    
    //make sure there are + 2 cards in hand 
    printf ("################################################### \n Error: incorrect number of cards in hand left after Smithy played. \n ################################################### \n");
    // assert (numHandCards(&G) == cardsInHand + 2);
    
    //make sure that smithy was discarded. 
    assert (G.playedCards[playedCards] == smithy);
    playedCards++;

    // printState(&G);
    
    // printPlayed(0, &G);
    // printDeck(0, &G);
    

    printf("All tests passed!\n");

    
    
    return 0;
}
