//randomtestadventurer.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

#define MAX_TESTS 10

int myAssert(int result, char *s){
  if(result){
    printf("Test PASS\n");
    //return 0;
    }else{
    printf("Test FAIL\n result: %s\n", s);
    //return 1;
    }
}

int AfterDrewAdventurerCard(struct gameState*state, int player, int past_handCount){
	if(state->handCount[player] - 2 != past_handCount){ 
		 printf("TEST FAILED: Player didn't draw 2 cards.\n");
		 return 0;
	}
	
	else if(state->hand[player][state->handCount[player] - 1] != copper &&
		state->hand[player][state->handCount[player] - 1] != silver &&
		state->hand[player][state->handCount[player] - 1] != gold){
			
		printf("TEST FAILED: Player's didn't get first treasure card.\n");
		 return 0;	
			}
	
	else if(state->hand[player][state->handCount[player] - 2] != copper &&
		state->hand[player][state->handCount[player] - 2] != silver &&
		state->hand[player][state->handCount[player] - 2] != gold){
			
		printf("TEST FAILED: Player's didn't get second treasure card.\n");
		 return 0;	
			}
			
		return 1;
}

int main () {

  int r, i, players, handCount, deckCount, seed;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  for(i=0; i< MAX_TESTS; i++) {

     players = 2;//rand() % (MAX_PLAYERS - 1) + 2; //set number of players between 2-4
     seed = 1;//random(); //pick random seed

     initializeGame(2, k, 1, &G);
     assert(r == 0);

     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;
     int origdrawntreasure=0;
     int drawntreasure=0;
     int cardDrawn;
    
     G.deckCount[currentPlayer] = rand() % MAX_DECK;
     G.discardCount[currentPlayer] = rand() % MAX_DECK;
     G.handCount[currentPlayer] = rand() % MAX_HAND;

     handCount = G.handCount[currentPlayer];
     deckCount = G.deckCount[currentPlayer];
   

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }

     cardEffect(adventurer, 1, 1, 1, &G, 1, 1);
     myAssert(AfterDrewAdventurerCard(&G, currentPlayer, handCount), "bug!!");

/////////////////////////////////////////
     /*printf("Testing drawntreasure increments when treasure is drawn\n");
         cardDrawn = silver;
     if (cardDrawn != copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }

       if((assertEqual(drawntreasure, origdrawntreasure + 1)) == 0){
         printf("Silver increments drawntreasure\n");
       }else
         printf("Silver failed to increment drawntreasure\n");

     cardDrawn = gold;

     if (cardDrawn != copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }

       if((assertEqual(drawntreasure, origdrawntreasure + 2)) == 0){
         printf("Gold increments drawntreasure\n");
       }else
          printf("Gold failed to increment drawntreasure\n");

     cardDrawn = copper;

     if (cardDrawn != copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }
          if((assertEqual(drawntreasure, origdrawntreasure + 3)) == 0){
          printf("Copper increments drawntreasure\n");
       }else
          printf("Copper failed to increment drawntreasure\n");*/
///////////////////////////////////////////
  }

  printf("Tests Complete\n");
  
  
  return 0;
}

