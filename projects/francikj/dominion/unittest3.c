//Unit Test 3

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

  assert(r == 0);

  printf("Testing that supplyCount corretly returns count\n");

  G.supplyCount[curse] = 20;
  r = supplyCount(curse, &G);
  assertEqual(r, 20);
    
  return 0;
}

