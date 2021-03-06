#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

// Test the 'handCard(int handCard, struct gameState *state)' function

int main () {
    int i, j, k, n, x;  // initialize integers used in testing
	       
    struct gameState G;
    
    // start random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*
        Initialize a random gameState, but the player number is important. 
        MAX_PLAYERS = 4
        
    */
    
    
    
    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() % 256; // fill the gameState with random bytes, 0 to 255
        }
        for (j = 0; j < 4; j++) {
            G.whoseTurn = j;
            x = (rand() % MAX_HAND);
            k = handCard(x, &G);
            assert (k == G.hand[j][x]);
        }
    }
    
    printf ("All %d tests passed\n", n);
    
    return 0;
}
