// Donald Austin - CSIS 111
// Lab 6 - ROT13
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Rot13(char& c);
void WriteTranslatedChar(char& c, ofstream& outFile);

int main() {

	ifstream filo;
	ofstream outFile{ "output.rot13" };
	string otis, fileLine;
	char c;
	bool loop = true;

	// Get file from user and verify it
	while (loop) {
		cout << "Please enter the filename you'd like to open: ";
		cin >> otis;

		filo.open(otis);
		if (!filo) {
			cout << endl << otis << " is not a valid filename." << endl << endl;
			filo.close();
		}
		else { loop = false; }
	}

	// Pull data from file and run through ROT13
	while (!filo.eof()) {
		getline(filo, fileLine);
		for (int i = 0; i <= fileLine.length(); i++) {
			c = (int) fileLine[i];
			Rot13(c);
			cout << c;
			WriteTranslatedChar(c, outFile);
		}
		outFile << "\n";
		cout << endl;
	}

	filo.close();
	system("pause");
	return 0;
}

void Rot13(char& c) {

	// Check isUpper() and shift
	if (c >= 65 && c <= 90) {
		if (c <= 90 && c > 77) {
			c -= 26;
		}
		c += 13;
	}

	// Check isLower() and shift
	else if	(c >= 97 && c <= 122) {
		if (c <= 122 && c > 109) {
			c -= 26; 
		}
		c += 13;
	}
	return;
}

void WriteTranslatedChar(char& c, ofstream& outFile) {
	outFile << c;
	return;
}