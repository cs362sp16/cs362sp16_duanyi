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
		g.whoseTurn = 1;
		int i = 0;
		effsmithy(smithy, &g, 1, 1, i);
		//asserttrue(g.handCount[1], 2);
}
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