#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "randnum.h"
#include "difficulty.h"

using namespace std;

int main() {
	difficulty dc;
	string difficulty;
	cout << "Welcome to Mastermind" << endl << "Copyright Tilden Windsor 2019" << endl;
	cout << "The aim of the game is to guess a random number that the computer has chosen" << endl;
	cout << "Easy mode uses four digit numbers, and hard mode uses 5 digit numbers" << endl;
	cout << "Easy or Hard? (E/H)";
	cin >> difficulty;
	for_each(difficulty.begin(), difficulty.end(), [](char& c)
		{
			c = tolower(c);
		});
	if (difficulty == "e") {
		dc.easy();
	}
	if (difficulty == "h") {
		dc.hard();
	}
}
