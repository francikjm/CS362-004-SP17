//randomtestcard2.c
//Testing steward

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

int AfterSteward(struct gameState* state, int player, int past_handCount, int choice, int past_coins){
   printf("Pre-hand count = %d\n", past_handCount);
   printf("Post-hand count = %d\n", state->handCount[player]);
   printf("Pre-coin count = %d\n", past_coins);
   printf("Post-coin count = %d\n", state->coins);
   printf("Pre-discard count = %d\n", past_handCount);
   printf("Post-discard count = %d\n", state->handCount[player]);
   printf("Choice was %d\n", choice);

   if(choice == 1){
      if(state->handCount[player] != (past_handCount + 2)){
         printf("TEST FAILED: 2 cards were not added to player's hand.\n");
         return 0;
      }
   }
   if(choice == 2){
      if(state->coins != (past_coins + 2)){
         printf("TEST FAILED: 2 coins were not added to player.\n");
         return 0;
      }
   }
   if(choice == 3){
      if(state->handCount[player] != (past_handCount - 2)){
         printf("TEST FAILED: 2 cards were not discarded from the player's hand.\n");
         return 0;
      }
   }
   
   return 1;
}

int main() {
   int r, i, players, handCount, deckCount, seed, choice, coins;

   int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};

   struct gameState G;

   for(i = 0; i < MAX_TESTS; i++){
      players = rand() % (MAX_PLAYERS - 1) + 2;
      choice = rand() % 3 + 1;
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
      coins = G.coins;

      if(nextPlayer > (G.numPlayers -1)){
         nextPlayer = 0;
      }

      cardEffect(steward, choice, 1, 1, &G, 1, 1);
      myAssert(AfterSteward(&G, currentPlayer, handCount, choice, coins), "bug!!");
      printf("Re-check post hand count = %d\n", G.handCount[currentPlayer]);
   } 

   printf("Tests Complete\n");

   return 0;
}

