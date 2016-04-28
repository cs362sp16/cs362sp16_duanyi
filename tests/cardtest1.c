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
	effcouncil_room(council_room, GS, 1, 0);
	asserttrue(GS->handCount[0], 4);
	asserttrue(GS->numBuys, 1);
	asserttrue(GS->handCount[1], 1);
	return 0; 
}
/*
void effcouncil_room(int card, struct gameState *state, int handPos, int currentPlayer){
  //+4 Cards
  int i;
  for (i = 0; i < 4; i++)
  {
    drawCard(currentPlayer, state);
  }
      
  //+1 Buy
  state->numBuys++;
      
  //Each other player draws a card
  for (i = 0; i < state->numPlayers; i++)
  {
    if ( i != currentPlayer )
      {
        drawCard(i, state);
      }
  }
      
  //put played card in played card pile
  discardCard(handPos, currentPlayer, state, 0);
}*/
