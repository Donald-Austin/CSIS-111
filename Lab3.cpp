// Lab 3 - Temperature Data
// Donald Austin CSIS - 111

#include <iostream>
#include <fstream>

using namespace std;

void main() {

	// Create file object and variables for measuring average, change, and taking in data
	ofstream tempdata;
	float x{ 0 }, y{ 0 }, z{ 0 };

	// Open or create file for writing
	tempdata.open("tempdata.dat");
	tempdata << "Temp\tDifference" << endl;
	cout << "Donald Austin CSIS -- 111" << endl;

	// Loop through user input and write to file
	for (int i = 1; i <= 12; i++) {
		cout << "Please enter temperature #" << i << ": ";

		cin >> x;
		cout << "Entered Temp: " << x;
		tempdata << x;

		if (y != 0) {
			cout << endl << "Temperature Difference: " << x - z;
			tempdata << "\t" << x - z;
		}
		cout << endl;
		tempdata << endl;

		y += x;
		z = x;
	}

	// Close the file pipe and output temperature average
	tempdata.close();
	cout << endl << "The average temperature is: " << y / 12 << endl;
	system("pause");
	return;

}