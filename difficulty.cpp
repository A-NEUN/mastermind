#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "randnum.h"
#include "difficulty.h"

using namespace std;

void difficulty::easy() {
	string reset;
	cout << "Do you want to reset the high score?(Y/N)";
	cin >> reset;
	for_each(reset.begin(), reset.end(), [](char& c) {
		c = tolower(c);
		});
	if (reset == "y") {
		ofstream reset("scorelow.txt");
		reset.close();
	}
	int count = 1;
	ifstream file;
	file.open("scorelow.txt");
	string fileread;
	getline(file, fileread);
	cout << "High Score: " << fileread << endl;
	file.close();
	int low = 1000;
	int high = 9999;
	randnum rn;
	int randomnum1 = rn.randint(low, high);
	//cout << to_string(randomnum1) << endl;
	string guess;
	while (true) {
		file.open("scorelow.txt");
		int filereadint;
		getline(file, fileread);
		if (fileread == "") {
			filereadint = 1874919423;
		}
		else {
			filereadint = stoi(fileread);
		}
		file.close();
		cout << "Guess: ";
		cin >> guess;
		try {
			if (stoi(guess) == randomnum1) {
				cout << "Correct Answer" << endl;
				if (count < filereadint) {
					ofstream filewrite("scorelow.txt");
					filewrite << to_string(count);
					filewrite.close();
					cout << "You beat the high score with a score of " << count << endl;
				}
				else {
					cout << "Your score is " << count << endl;
					cout << "You did not beat the high score." << endl;
				}
				break;
			}
			else if (guess.length() != 4) {
				cout << "Enter a 4 digit Number" << endl;
			}
			else if (stoi(guess) < randomnum1) {
				cout << "Too Low" << endl << "Try Again" << endl;
				count++;
			}
			else if (stoi(guess) > randomnum1) {
				cout << "Too High" << endl << "Try Again" << endl;
				count++;
			}
		}
		catch (...) {
			cout << "Enter a number" << endl;
		}

	}
}
void difficulty::hard() {
	string reset;
	cout << "Do you want to reset the high score?(Y/N)";
	cin >> reset;
	for_each(reset.begin(), reset.end(), [](char& c) {
		c = tolower(c);
		});
	if (reset == "y") {
		ofstream reset("scorehigh.txt");
		reset.close();
	}
	int count = 1;
	ifstream file;
	file.open("scorehigh.txt");
	string fileread;
	getline(file, fileread);
	cout << "High Score: " << fileread << endl;
	file.close();
	int low = 10000;
	int high = 99999;
	randnum rn;
	int randomnum1 = rn.randint(low, high);
	//cout << to_string(randomnum1) << endl;
	string guess;
	while (true) {
		file.open("scorehigh.txt");
		int filereadint;
		getline(file, fileread);
		if (fileread == "") {
			filereadint = 1874919423;
		}
		else {
			filereadint = stoi(fileread);
		}
		file.close();
		try {
			cout << "Guess: ";
			cin >> guess;
			if (stoi(guess) == randomnum1) {
				cout << "Correct Answer" << endl;
				if (count < filereadint) {
					ofstream filewrite("scorehigh.txt");
					filewrite << to_string(count);
					filewrite.close();
					cout << "You beat the high score with a score of " << count << endl;
				}
				else {
					cout << "Your score is " << count << endl;
					cout << "You did not beat the high score." << endl;
				}
				break;
			}
			else if (guess.length() != 5) {
				cout << "Enter a 5 digit Number" << endl;
			}
			else if (stoi(guess) < randomnum1) {
				cout << "Too Low" << endl << "Try Again" << endl;
				count++;
			}
			else if (stoi(guess) > randomnum1) {
				cout << "Too High" << endl << "Try Again" << endl;
				count++;
			}
		}
		catch (...) {
			cout << "Enter a number" << endl;
		}
	}
}