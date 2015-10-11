1. Smithy
	Once the smithy card is played, the player who played that card will gain 3 cards to their hand. A for loop is used to complete this task by running 3 times, calling drawCard each time. Once the for loop is done, the card is discarded into their played hand pile, which is done by calling the discardCard function. 
	
2. Adventurer
	The adventurer card is used to add 2 treasure cards to the players hands. This is done by using a while loop that runs until 2 treasures are drawn. In the while loop, it first checks to see if the player has less than 1 card in their hand. If the deck is empty, we shuffle the discard pile and add the card to the deck. If the player does not have an empty deck, then the drawCard function is called, and the players handCount is decreased by 1 (since the top card was just drawn). An if else statement is used to check if the card is treasure or not. If it is, then we increase drawntreasure so the while loop knows when to end. If the card is not a treasure card, then the temp hand is set to the card that was drawn, and we increase z (how many cards the player is holding that is drawn but is not a treasure card). After the treasure cards are found, the while loop ends. We then run another while loop to discard the cards that were drawn, but were not treasure cards. The while loop loops through the temp hand until there are no more cards.
	
3. discardCard()
	The discardCard() function will discard a card from the current players hand when the function is called. By doing this, it first checks to see if the trashFlag is set. If it is not, the card is added to the current players hand, and we increase how many cards the player has in their hand. After this, the played card hand is set to -1. Then an if/else if/else statement is run to remove the card from the players hand. If the last card in the array is played, then we decrease the players hand count. If there is only one card in the players hand, then we also decrease the players hand count. In the else part, we first replace the discarded card with the last card in the hand. Then, we set the last card to -1 and we decrease the number of cards in the players hand. 			
	
4. updateCoins()
	The updateCoins() function uses a for loop to add coins to the players hand. Before the loop, we reset the count for the coins, as we do not want to keep adding to what the player previously had from the last round. Then, in the for loop, the loop runs until all the cards have been checked. Inside the loop, there are if statements. If the card is copper, then we add 1 to the count. Else, if the card is silver, we add 2 to the count. Else, if the card is gold, we add 3 to the count. Once we go through all of the cards, we add the bonus to the total amount of coins. 
		