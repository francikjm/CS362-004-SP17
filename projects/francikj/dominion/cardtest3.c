//Card test 3: Steward

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

  printf("Testing steward with choice1 == 1\n"); 
  
  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  r = initializeGame(2, k, 1, &G);

  assert(r == 0);
     
     int currentPlayer = whoseTurn(&G);
     int nextPlayer = currentPlayer + 1;
     int choice1 = 1;
     int choice2 = 1;
     int choice3 = 1;

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }
 
     int preHandCount = G.handCount[currentPlayer];  
 
      if (choice1 == 1){
	drawCard(currentPlayer, &G);
        drawCard(currentPlayer, &G);
        }
      else if (choice1 == 2)
        {
        G.coins = G.coins + 2;
        }
      else
        {
          discardCard(choice2, currentPlayer, &G, 1);
          discardCard(choice3, currentPlayer, &G, 1);
        }

      if((assertEqual(G.handCount[currentPlayer], preHandCount + 2)) == 0){
	printf("Steward correctly adds 2 cards to current player's hand when choice1 = 1\n");
      }else
	printf("Steward doesn't add 2 cards to current player's hand when choice1 = 1\n");

printf("Testing steward with choice1 == 2\n");

  r = initializeGame(2, k, 1, &G);

  assert(r == 0);

     currentPlayer = whoseTurn(&G);
     nextPlayer = currentPlayer + 1;
     choice1 = 2;
     choice2 = 1;
     choice3 = 1;

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }

     int preCoins = G.coins;

      if (choice1 == 1){
        drawCard(currentPlayer, &G);
        drawCard(currentPlayer, &G);
        }
      else if (choice1 == 2)
        {
        G.coins = G.coins + 2;
        }
      else
        {
          discardCard(choice2, currentPlayer, &G, 1);
          discardCard(choice3, currentPlayer, &G, 1);
        }

      if((assertEqual(G.coins, preCoins + 2)) == 0){
        printf("Steward correctly adds 2 coins to current player when choice1 = 2\n");
      }else
        printf("Steward doesn't add 2 coins to current player when choice1 = 2\n");  

     printf("Testing steward with choice1 == 3\n");

     r = initializeGame(2, k, 1, &G);
     assert(r == 0);

     currentPlayer = whoseTurn(&G);
     nextPlayer = currentPlayer + 1;
     choice1 = 3;
     choice2 = 1;
     choice3 = 1;

     if (nextPlayer > (G.numPlayers - 1)){
        nextPlayer = 0;
     }

     preHandCount = G.handCount[currentPlayer];

      if (choice1 == 1){
        drawCard(currentPlayer, &G);
        drawCard(currentPlayer, &G);
        }
      else if (choice1 == 2)
        {
        G.coins = G.coins + 2;
        }
      else
        {
          discardCard(choice2, currentPlayer, &G, 1);
          discardCard(choice3, currentPlayer, &G, 1);
        }

      if((assertEqual(G.handCount[currentPlayer], preHandCount -2)) == 0){
        printf("Steward correctly discards 2 cards from current player when choice1 = 3\n");
      }else
        printf("Steward doesn't discard 2 cards from current player when choice1 = 3\n");


return 0;
}
