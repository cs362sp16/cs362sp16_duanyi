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
	struct gameState g;
	g.whoseTurn = 1;
	int k[10] = {council_room, smithy, great_hall, outpost, adventurer, remodel, village, feast, gardens, mine};
	initializeGame(2, k, 5, &g);
	int bonus[1];
	cardEffect(outpost, 0, 0, 0, &g, 1, bonus);
	asserttrue(1, g.outpostPlayed);
	return 0; 
}
/*
        case outpost:
      //set outpost flag
      state->outpostPlayed++;
			
      //discard card
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
      */