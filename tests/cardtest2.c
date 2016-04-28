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
	int i;
	effsmithy(smithy, GS, 1, 0, i);
	asserttrue(GS->handCount[0], 3);
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