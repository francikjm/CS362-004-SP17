//Card test 4

//salvager

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

  printf("Testing salvager with choice1 == 3\n");

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  r = initializeGame(2, k, 1, &G);

  assert(r == 0);

     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;
     int choice1 = 4;
     int handPos = 1;     

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }
    
     int preNumBuys = G.numBuys;
     
     //+1 buys
     G.numBuys++;
     if((assertEqual(G.numBuys, preNumBuys + 1)) == 0){
        printf("Salvager correctly adds 1 card to numBuys\n");
      }else
        printf("Salvager doesn't add 1 card to numBuys\n"); 
   
     if (choice1)
        {
         int preCoins = G.coins;
         printf("PreCoins = %d\n", preCoins);
         r = handCard(choice1, &G);
         printf("Handcard = %d\n", r);

         int cost = getCost( handCard(choice1, &G));
         printf("Cost = %d\n", cost);
         
	 //gain coins equal to trashed card 
         G.coins = (G.coins + getCost( handCard(choice1, &G) ));
         printf("Coins = %d\n", G.coins);
         if((assertEqual(G.coins, (preCoins + cost))) == 0){
           printf("Salvager correctly adds coins\n");
          }else
           printf("Salvager doesn't add coinsnumBuys\n");
         
         //trash card
         discardCard(choice1, currentPlayer, &G, 1);
        }
        //discard card
        discardCard(handPos, currentPlayer, &G, 0);
      return 0;
}
