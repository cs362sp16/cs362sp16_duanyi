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
	g.supplyCount[province] = 0;
	asserttrue(1, isGameOver(&g));
	g.supplyCount[province] = 1;
	int i;
	for(i = 0; i < 21; i++){
		g.supplyCount[i] = 1;
	}
	for(i = 21; i < 25; i++){
		g.supplyCount[i] = 0;
	}
	asserttrue(1, isGameOver(&g));
	for(i = 0; i < 25; i++){
		g.supplyCount[i] = 2;
	}
	asserttrue(0, isGameOver(&g));
	return 0; 
}

/*int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}*/