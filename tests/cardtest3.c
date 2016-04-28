#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void asserttrue(int a, int b){
	if(a == b){
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	else{
		printf("TEST FAILED\n");
	}
}

int main(){
	struct gameState *GS;
	GS->whoseTurn = 1;
	int kc[10] = {council_room, smithy, great_hall, ambassador, adventurer, remodel, village, feast, gardens, mine};
	initializeGame(2, kc, 3, GS);
	int bonus[1];
	cardEffect(great_hall, 0, 0, 0, GS, 1, bonus);
	asserttrue(2, GS->numActions);
	asserttrue(1, GS->handCount[0]);
	return 0; 
}
/*
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
 case great_hall:
      //+1 Card
      drawCard(currentPlayer, state);
			
      //+1 Actions(1)
      state->numActions++;
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
      */