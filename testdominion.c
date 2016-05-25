#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define MAX_TEST_NUM 20

int checksamecard(int k[10], int kcard){
  int i, result = 0;
  for(i = 0; i < 10; i++){
    if(kcard == k[i])
      result = 1;
  }
  return result;
}


int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int seed;
  if(argv[1])
    seed = atoi(argv[1]);
  if(!argv[1])
    seed = 42;
  int k[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  //srand(time(NULL));
  srand(seed);
  int j = 0, h, kcard;
  for(j = 0; j < 10; j++){
    kcard = adventurer + rand() % 20;
    while(checksamecard(k, kcard))
      kcard = adventurer + rand() % 20;
    k[j] = kcard;
  }
  printf ("Starting game.\n");
  
  int players;
  players = rand() % 3 + 2;
  int m;
  for(m = 0; m < 10; m++)
    printf("%d\n", k[m]);
  
  m = initializeGame(players, k, seed, p);
  printf("m: %d\n", m);

  int money = 0;
  int actionpos = -1;
  int i=0;

  int numSmithies = 0;
  int numAdventurers = 0;
  int currentplayer;
  int flag;

  while (!isGameOver(p)) {
    money = 0;
    currentplayer = whoseTurn(p);
    printf("current player is %d\n", currentplayer);
    printf("Action phase:\n");
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
        money++;
      else if (handCard(i, p) == silver)
        money += 2;
      else if (handCard(i, p) == gold)
        money += 3;
      else if (handCard(i, p) >= adventurer && handCard(i, p) <= treasure_map)
        actionpos = i;
    }

    
      int actionnumbers;
      printf("%d\n", actionpos);
      int actioncard = handCard(actionpos, p);
      if(actioncard == 7 || actioncard == 8 || actioncard == 10 || actioncard == 13 || 
        actioncard == 14 || actioncard == 16 || actioncard == 19 || actioncard == 21 || 
        actioncard == 23 ||actioncard == 25 ||actioncard == 26)
        {
          flag = playCard(actionpos, -1, -1, -1, p);
          //cardEffect(actioncard, -1, -1, -1, p, actionpos, 0) < 0;
        }
        else if(actioncard == 9)
          flag = playCard(actionpos, 0, -1, -1, p);
        else if(actioncard == 11)
          flag = playCard(actionpos, copper, silver, -1, p);
        else if(actioncard == 12)
          flag = playCard(actionpos, copper, estate, -1, p);
        else if(actioncard == 15)
          flag = playCard(actionpos, 0, -1, -1, p);
        else if(actioncard == 17)
          flag = playCard(actionpos, 1, -1, -1, p);
        else if(actioncard == 18)
          flag = playCard(actionpos, 2, -1, -1, p);
        else if(actioncard == 20)
          flag = playCard(actionpos, 0, 0, -1, p);
        else if(actioncard == 22)
          flag = playCard(actionpos, 0, -1, -1, p);
        else if(actioncard == 24)
          flag = playCard(actionpos, 0, -1, -1, p); 
        if(flag == -1)
          printf("Failed to play a card\n");
        else if(flag == 0){
          printf("Player %d played card %d\n", currentplayer, actionpos);
        }

      printf("Buy phase:\n");

      int Boughtcard;
      Boughtcard = rand() % 27;
      flag = buyCard(Boughtcard, p);
      if(flag == -1){
        printf("Failed buying card\n");
      }
      //else
      //  printf("Player bought card %d\n", Boughtcard);

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
      
  } 

  printf ("Finished game.\n");
  int pl;
  printf("%d\n", players);
  for(pl = 0; pl < players; pl++){
    printf ("Player %d: %d\n", pl, scoreFor(pl, p));
  }
  

  return 0;
}
