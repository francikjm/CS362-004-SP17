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

void checkDrawCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;
  r = drawCard (p, post);
  if (pre.deckCount[p] <= 0){
    assertEqual(r,-1);
  }
  if (pre.deckCount[p] > 0) {
    pre.handCount[p]++;
    pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p]-1];
    pre.deckCount[p]--;
    assertEqual(r,0);
  } else if (pre.discardCount[p] > 0) {
    memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
    memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
    pre.hand[p][post->handCount[p]-1] = post->hand[p][post->handCount[p]-1];
    pre.handCount[p]++;
    pre.deckCount[p] = pre.discardCount[p]-1;
    pre.discardCount[p] = 0;
    assertEqual(r,0);
  }

  assertEqual(memcmp(&pre, post, sizeof(struct gameState)), 0);
  
}

int main () {

  int p; 

  struct gameState G;

    printf("Testing with cards\n");
    p = 2;
    G.deckCount[p] = 250;
    G.discardCount[p] = 250;
    G.handCount[p] = 150;
    checkDrawCard(p, &G);

    printf("Testing with no cards available\n");
    p = 2;
    G.deckCount[p] = 0;
    G.discardCount[p] = 0;
    G.handCount[p] = 0;
    checkDrawCard(p, &G);

  return 0;
}

