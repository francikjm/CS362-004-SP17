//Unit Test 4

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

  r = initializeGame(2, k, 1, &G);

  //printf ("initializeGame(4, k, 1, &G) = %d\n", r);
  assert(r == 0);

  printf("Testing isGameOver() ends the game when three supply piles are at 0\n");  

  G.supplyCount[feast] = 0;
  G.supplyCount[gardens] = 0;
  G.supplyCount[mine] = 0;

  r = isGameOver(&G);

  assertEqual(r,1);

  printf("Testing isGameOver()ends the game when Province is empty\n");

  r = initializeGame(2, k, 1, &G);

  //printf ("initializeGame(4, k, 1, &G) = %d\n", r);
  assert(r == 0);

  G.supplyCount[province] = 0;

  r = isGameOver(&G);

  assertEqual(r, 1);
  
  return 0;
}
