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
	int players, seed, i, z = 0;
	int k[10] = {council_room, smithy, great_hall, ambassador, adventurer, remodel, village, feast, gardens, mine};
	int temphand[MAX_HAND];// moved above the if statement
  	int drawntreasure=0;
  	int cardDrawn;
	for(i = 0; i < MAX_TEST_NUM; i++){
		players = rand() % 3 + 2;
		if(argc >= 2)
			seed = atoi(argv[1]);
		else
			seed = rand();
		initializeGame(players, k, seed, &g);
	  	g.whoseTurn = 0;
		effadventurer(adventurer, &g, 1, 0, drawntreasure, cardDrawn, temphand, z);
	}
	

	return 0; 
}

/*void effadventurer(int card, struct gameState *state, int handPos, int currentPlayer, int drawntreasure, int cardDrawn, int temphand[], int z){
  //Reveal cards from your deck until you reveal 2 Treasure cards. 
  //Put those Treasure cards into your hand and discard the other revealed cards.
  while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
}*/