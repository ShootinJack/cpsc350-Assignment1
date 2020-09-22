#include <iostream>
#include "Dna.h"
using namespace std;


int main(int argc, char** argv) {
	string filename;
	ifstream test;
	if (argv[1] != NULL) {
		filename = argv[1];
	}
	else
	{
		cout << "Please enter your filename: ";
		cin >> filename;
	}
	do {
		test.open(filename);
		if (test.good() == true) {
			continue;
		}
		else {
			cout << "Invalid filename\nEnter Another: ";
			cin >> filename;
		}
	} while (test.good() != true);

	Dna dnaProcessor(filename);
	system("pause");
	return 0;
}