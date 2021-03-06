/*
    adventurerEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus):
        Calls from switch statement in cardEffect(). Implimented independently with same code provided. Independent call
        to whoseTurn() to retrieve current player. Not-so-subtle Bug: Change 'foundTreasures < 3'  to 'foundTreasures <= 3', this will result
        in a third treasure being found on each adventurer card.
    outpostEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus):
        Calls from switch statement in cardEffect(). Implimented independently with same code provided. Independent call
        to whoseTurn() to retrieve current player.
    salvagerEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus):
        Calls from switch statement in cardEffect(). Implimented independently with same code provided. Independent call
        to whoseTurn() to retrieve current player. Not-so-subtle Bug: Does not remove chosen card from hand.
    sea_hagEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus):
        Calls from switch statement in cardEffect(). Implimented independently with same code provided. Independent call
        to whoseTurn() to retrieve current player. Not-so-subtle Bug: Puts a "cutpurse" card on top of each players deck, not a "curse" card.
    smithyEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus):
        Calls from switch statement in cardEffect(). Implimented independently with same code provided. Independent call
        to whoseTurn() to retrieve current player.  Not-so-subtle Bug: Discards at handPos + 1, meaning it does not remove itself from your hand
        once it has been played (the next card in your hand is removed instead).


*/
