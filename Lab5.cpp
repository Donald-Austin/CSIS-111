#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void printTemp(int x);
void printStars(int x);
void printHeader();

int main() {
	
	ifstream filo;
	filo.open("data.txt");
	if (filo) {

		printHeader();

		for (int i = 24; i > 0; i--) {
			int temp;
			filo >> temp;
			printTemp(temp);
			printStars(temp);
			cout << endl;
		}

	}
	else { cout << "File not found!" << endl; }

	system("pause");
	return 0;
}



void printTemp(int x) {
	cout << setw(5) << right << x;
	return;
}

void printStars(int x) {
	int l = ceil(abs(x) / 3);
	string stars = "";

	if (x < 0) {
		for (l; l > 0; l--) {
			stars += "*";
		}
		cout << setw(10) << right << stars << "|";
	}
	else {
		cout << setw(10) << " " << "|";
		for (l; l > 0; l--) {
			stars += "*";
		}
		cout << left << stars;
	}

	return;
}

void printHeader() {
	cout << "Temperatures are for 24 hours:" << endl;
	cout << setw(5) << " " << setw(10) << left << "-30" << setw(10) << "0";
	cout << setw(10) << "30" << setw(10) << "60" << setw(10);
	cout << setw(10) << "90" << setw(10) << "120" << endl;
	return;
}