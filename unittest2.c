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
	g.hand[1][3] = 3;
	asserttrue(3, handCard(3, &g));
	return 0; 
}

/*
int handCard(int handPos, struct gameState *state) {
  int currentPlayer = whoseTurn(state);
  return state->hand[currentPlayer][handPos];
}
*/