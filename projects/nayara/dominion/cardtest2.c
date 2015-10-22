// int adventurerEffect(int player, struct gameState *state);


/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int dummyCard = 8;
    int testCard = 7;
    
    printf ("TESTING adventurerEffect():\n");
    
    printf("Testing silver\n");
    for (p = 0; p < numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;
        G.deckCount[p] = MAX_DECK;

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            G.discardCount[p]= 0;
            G.deckCount[p] = MAX_DECK;
            int i;
            for (i=0; i<MAX_DECK; i++)
            {
                G.deck[p][i] = dummyCard;
            }

            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            G.hand[p][0] = dummyCard;
            G.deck[p][MAX_DECK-1] = silver;
            G.deck[p][MAX_DECK-2] = dummyCard;
            G.deck[p][MAX_DECK-3] = silver;

#if (NOISY_TEST == 1)
            printf("***Test for player %d with silver card\n",p);
#endif
            
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",500,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == 500);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for adventurer card. Expected %d, received %d\n",dummyCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == dummyCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
#if (NOISY_TEST == 1)
            printf("*Calling adventurer Function\n");
#endif
            adventurerEffect(p, &G);
            
#if (NOISY_TEST == 1)
            printf("Checking for first silver card. Expected %d, received %d\n",silver, G.hand[p][G.handCount[p] -1]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == silver);
#if (NOISY_TEST == 1)
            printf("Checking for second silver card. Expected %d, received %d\n",silver, G.hand[p][G.handCount[p] -2]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == silver);

#if (NOISY_TEST == 1)
            printf("Checking for new hand count:  Expected %d, received %d\n",G.handCount[p],handCount +2);
#endif
            assert(G.handCount[p] == handCount+2);
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",497,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == MAX_DECK-3);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
            printf("\n");
        }
    }
  
    printf("Testing gold\n");
    for (p = 0; p < numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;
        G.deckCount[p] = MAX_DECK;
        
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            G.discardCount[p]= 0;
            G.deckCount[p] = MAX_DECK;
            int i;
            for (i=0; i<MAX_DECK; i++)
            {
                G.deck[p][i] = dummyCard;
            }
            
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            G.hand[p][0] = dummyCard;
            G.deck[p][MAX_DECK-1] = gold;
            G.deck[p][MAX_DECK-2] = dummyCard;
            G.deck[p][MAX_DECK-3] = gold;
            
#if (NOISY_TEST == 1)
            printf("***Test for player %d with gold card\n",p);
#endif
            
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",500,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == 500);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for adventurer card. Expected %d, received %d\n",dummyCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == dummyCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
#if (NOISY_TEST == 1)
            printf("*Calling adventurer Function\n");
#endif
            adventurerEffect(p, &G);
            
#if (NOISY_TEST == 1)
            printf("Checking for first gold card. Expected %d, received %d\n",gold, G.hand[p][G.handCount[p] -1]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == gold);
#if (NOISY_TEST == 1)
            printf("Checking for second gold card. Expected %d, received %d\n",gold, G.hand[p][G.handCount[p] -2]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == gold);
            
#if (NOISY_TEST == 1)
            printf("Checking for new hand count:  Expected %d, received %d\n",G.handCount[p],handCount +2);
#endif
            assert(G.handCount[p] == handCount+2);
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",497,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == MAX_DECK-3);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
            printf("\n");
        }
    }
    
    printf("Testing copper\n");
    for (p = 0; p < numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;
        G.deckCount[p] = MAX_DECK;
        
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            G.discardCount[p]= 0;
            G.deckCount[p] = MAX_DECK;
            int i;
            for (i=0; i<MAX_DECK; i++)
            {
                G.deck[p][i] = dummyCard;
            }
            
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            G.hand[p][0] = dummyCard;
            G.deck[p][MAX_DECK-1] = copper;
            G.deck[p][MAX_DECK-2] = dummyCard;
            G.deck[p][MAX_DECK-3] = copper;
            
#if (NOISY_TEST == 1)
            printf("***Test for player %d with gold card\n",p);
#endif
            
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",500,G.deckCount[p]);
#endif
            assert(G.deckCount[P] == 500);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for adventurer card. Expected %d, received %d\n",dummyCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == dummyCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
#if (NOISY_TEST == 1)
            printf("*Calling adventurer Function\n");
#endif
            adventurerEffect(p, &G);
            
#if (NOISY_TEST == 1)
            printf("Checking for first copper card. Expected %d, received %d\n",copper, G.hand[p][G.handCount[p] -1]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == copper);
#if (NOISY_TEST == 1)
            printf("Checking for second copper card. Expected %d, received %d\n",copper, G.hand[p][G.handCount[p] -2]);
#endif
            assert(G.hand[p][G.handCount[p] -2] == copper);
            
#if (NOISY_TEST == 1)
            printf("Checking for new hand count:  Expected %d, received %d\n",G.handCount[p],handCount +2);
#endif
            assert(G.handCount[p] == handCount+2);
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",497,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == MAX_DECK-3);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
            printf("\n");
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}