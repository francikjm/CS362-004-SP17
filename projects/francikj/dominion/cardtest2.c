//Card Test 2: Smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int assertEqual(int result, int expected){
  if(result == expected){
    printf("Test PASS\n");
    return 0;
    }else{
    printf("Test FAIL\n result: %i, expected: %i\n", result, expected);
    return 1;
    }
}

//int smithyRefactored(struct gameState *state,int);


int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  r = initializeGame(2, k, 1, &G);

  assert(r == 0);

     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;
     int handPos = 2;
  
     if (nextPlayer > (G.numPlayers - 1)){
    	nextPlayer = 0;
     }

     //+3 Cards
     int preHandCount = G.handCount[currentPlayer];
     printf("Testing Smithy\n");
     printf("Pre-Hand count = %d\n", preHandCount);
     
    smithyRefactored(&G,handPos);

     int postHandCount = G.handCount[currentPlayer];
     printf("Post-hand count = %d\n", postHandCount);
     if((assertEqual(postHandCount, preHandCount + 2)) == 0){
        printf("Smithy correctly adds 3 cards to currentPlayer's hand\n");
     }else
        printf("Smithy fails to add 3 cards to currentPlayer's hand\n");
     
     return 0;
     }
