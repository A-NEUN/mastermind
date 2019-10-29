#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "randnum.h"

using namespace std;

int randnum::randint(int low, int high) {
	int randomnum;
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		rand() % high;
	}
	while (true) {
		randomnum = rand() % high;
		if (randomnum > low) {
			break;
		}
		else {
		}
	}
	return(randomnum);
}
