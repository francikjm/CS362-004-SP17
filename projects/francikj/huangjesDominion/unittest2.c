//Unit Test 2

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void assertEqual(int result, int expected){
  if(result == expected)
    printf("Test PASS\n");
  else
    printf("Test FAIL\n result: %i, expected: %i\n", result, expected);
}


int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  
  r = initializeGame(4, k, 1, &G);

  printf ("initializeGame(4, k, 1, &G) = %d\n", r);
  assert(r == 0);

  printf("Testing that numBuys gets decremented\n");
  int supplyPos = 2;
  G.whoseTurn = 2;
  G.numBuys = 3;
  G.coins = 20;
  G.phase = 1;
  buyCard(supplyPos, &G);
  assertEqual(G.numBuys, 2);

  printf("Testing that a card cannot be purchased if the player doesn't have enough coins\n");

  supplyPos = 2;
  G.whoseTurn = 2;
  G.numBuys = 3;
  G.coins = 0;
  G.phase = 1; 
  r = buyCard(supplyPos, &G);
  assertEqual(r, -1);
    
  return 0;
}

