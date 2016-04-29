#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
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
	g.handCount[whoseTurn(&g)] = 3;
	asserttrue(3, numHandCards(&g));
	return 0; 
}

/*
int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}

int handCard(int handPos, struct gameState *state) {
  int currentPlayer = whoseTurn(state);
  return state->hand[currentPlayer][handPos];
}
*/