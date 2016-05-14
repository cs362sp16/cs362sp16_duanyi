#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_TEST_NUM 20

void asserttrue(int a, int b){
	if(a == b){
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	else{
		printf("TEST FAILED\n");
	}
}

int main(int argc, char *argv[]){
	struct gameState g;
	int players, seed, i;
	int k[10] = {council_room, smithy, great_hall, ambassador, adventurer, remodel, village, feast, gardens, mine};
	for(i = 0; i < MAX_TEST_NUM; i++){
		players = rand() % 3 + 2;
		if(argc >= 2)
			seed = atoi(argv[1]);
		else
			seed = rand();
		initializeGame(players, k, seed, &g);
	  	g.whoseTurn = 0;
		effcouncil_room(council_room, &g, 1, 0);
		asserttrue(g.handCount[0], 8);
		asserttrue(g.numBuys, 2);
		asserttrue(g.handCount[1], 1);
	}
	

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
