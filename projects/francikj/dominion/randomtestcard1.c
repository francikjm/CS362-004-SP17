//randomtestcard1.c
//testing Smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

#define MAX_TESTS 100

int myAssert(int result, char *s){
   if(result == 1){
      printf("Test PASS\n");
      return 0;
   }else{
   printf("Test FAIL\n result: %s\n", s);
   return 1;
   }
}

int AfterSmithy(struct gameState* state, int player, int past_handCount){
  printf("Pre-hand count = %d\n", past_handCount);
  printf("Post-hand count = %d\n", state->handCount[player]); 
  if(state->handCount[player] - 2 != past_handCount){
      printf("TEST FAILED: 3 cards were not added to player's hand.\n");
      return 0;
   }
   return 1;
}

int main() {
   int r, i, players, handCount, deckCount, seed;

   int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};

   struct gameState G;

   for(i = 0; i < MAX_TESTS; i++){
      players = rand() % (MAX_PLAYERS - 1) + 2;
      seed = random();

      r = initializeGame(players, k, 1, &G);
      assert(r ==0);

      int currentPlayer = whoseTurn(&G);
      int nextPlayer = players + 1;
      int cardDrawn;

      G.deckCount[currentPlayer] = rand() % MAX_DECK;
      G.discardCount[currentPlayer] = rand() % MAX_DECK;
      G.handCount[currentPlayer] = rand() % MAX_DECK;

      handCount = G.handCount[currentPlayer];
      deckCount = G.deckCount[currentPlayer];

      if(nextPlayer > (G.numPlayers -1)){
         nextPlayer = 0;
      }

      cardEffect(smithy, 1, 1, 1, &G, 1, 1);
      myAssert(AfterSmithy(&G, currentPlayer, handCount), "bug!!");
   } 

   printf("Tests Complete\n");

   return 0;
}
