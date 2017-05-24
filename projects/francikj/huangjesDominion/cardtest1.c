//Card Test 1: Adventurer


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

int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  r = initializeGame(2, k, 1, &G);

  assert(r == 0);

     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;
     int origdrawntreasure=0;
     int drawntreasure=0;
     int cardDrawn;
  if (nextPlayer > (G.numPlayers - 1)){
    nextPlayer = 0;
  }

     printf("Testing drawntreasure increments when treasure is drawn\n");
         cardDrawn = silver;
     if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }
     
       if((assertEqual(drawntreasure, origdrawntreasure + 1)) == 0){
         printf("Silver increments drawntreasure\n");
       }else
         printf("Silver failed to increment drawntreasure\n");
        
     cardDrawn = gold;
     
     if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }
    
       if((assertEqual(drawntreasure, origdrawntreasure + 2)) == 0){
         printf("Gold increments drawntreasure\n");
       }else
          printf("Gold failed to increment drawntreasure\n");
   
     cardDrawn = copper;
     
     if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
        drawntreasure++;
     }
          if((assertEqual(drawntreasure, origdrawntreasure + 3)) == 0){
          printf("Copper increments drawntreasure\n");
       }else
	  printf("Copper failed to increment drawntreasure\n");
       
   return 0;
}

