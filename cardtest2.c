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
	int k[10] = {council_room, smithy, great_hall, ambassador, adventurer, remodel, village, feast, gardens, mine};
	initializeGame(2, k, 5, &g);
	g.whoseTurn = 1;
	int i = 0;
	effsmithy(smithy, &g, 1, 1, i);
	asserttrue(g.handCount[1], 2);
	return 0; 
}
/*
void effsmithy(int card, struct gameState *state, int handPos, int currentPlayer, int i){
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
      
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
}  */