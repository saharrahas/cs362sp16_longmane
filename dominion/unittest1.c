#include "dominion.h"
#include <stdio.h>

int failed = 0;

int myassert(int val,char* msg) {
  if (val == 0) {
    printf("FAILURE: %s\n",msg);
    failed = 1;
  }
}

void good_assert() {
  if (!failed) {
    printf ("SUCCESS!\n");
  }
}

// tests the shuffle function
int main() {

	struct gameState g,g2;
	int cards[10] = {
		estate,
		duchy,
		province,
		copper,
		silver,
		gold,
		adventurer,
		great_hall,
		minion,
		steward
    };

	initializeGame(2, cards, 3, &g);

	int tester = shuffle(0, &g);
	myassert(tester == 0, "No P1 shuffle");
	tester = shuffle(1, &g);
	myassert(tester == 0, "No P1 shuffle");

	int cards2[1] = {estate};
	initializeGame(2, cards2, 3, &g2);
	tester = shuffle(1, &g2);
	myassert(tester == -1, "NO SHUFFLE");

	good_assert();

	return 0;
}