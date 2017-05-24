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
    return 0;
    }else{
    printf("Test FAIL\n result: %s\n", s);
    return 1;
    }
}

int AfterDrewAdventurerCard(struct gameState*state, int player, int past_handCount){
	printf("Pre-hand count = %d\n", past_handCount);
        printf("Post-hand count = %d\n", state->handCount[player]);
        //if(state->handCount[player] - 2 != past_handCount || state->handCount[player] - 1 != past_handCount){ 
	if(state->handCount[player] - 2 != past_handCount){	 
                 printf("TEST FAILED: Player didn't add 2 cards to their hand.\n");
		 return 0;
	}
	
	if(state->hand[player][state->handCount[player] - 1] != copper &&
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

     players = rand() % (MAX_PLAYERS - 1) + 2; //set number of players between 2-4
     seed = random(); //pick random seed

     r = initializeGame(players, k, 1, &G);
     assert(r == 0);

     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;

    
     G.deckCount[currentPlayer] = rand() % MAX_DECK;
     G.discardCount[currentPlayer] = rand() % MAX_DECK;
     G.handCount[currentPlayer] = rand() % MAX_HAND;

     handCount = G.handCount[currentPlayer];
     //printf("Pre-hand count = %d\n", handCount);
     deckCount = G.deckCount[currentPlayer];
   

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }

     cardEffect(adventurer, 1, 1, 1, &G, 1, 1);
     myAssert(AfterDrewAdventurerCard(&G, currentPlayer, handCount), "bug!!");
  }

  printf("Tests Complete\n");
  
  
  return 0;
}

