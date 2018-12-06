// Donald Austin - Lab 9: Battleship
// CSIS 111 - C++ Programming

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Fire(int x, int y, char ocean[][25]);
bool FleetSunk(char ocean[][25]);




int main() {
	int x{ 0 }, y{ 0 };
	char exiter = 'N';
	char ocean[25][25] = { "~" };
	ifstream OceanFile{ "ocean.txt" };
	string wave, report;

	// Populate the ocean from the file
	if (!OceanFile) cout << "File not found!" << endl;
	for (int i = 0; i < 25; i++) {
			getline(OceanFile, wave);
			for (int j = 0; j < 25; j++) {
				ocean[i][j] = wave[j];
			}
	}


	// Take in and validate user input until all ships are sunk
	while (FleetSunk(ocean) && exiter != 'Y') {
		cout << "Enter x,y coordinates  separated by a space to fire or negative coordinates to exit:" << endl;
		cin >> x >> y;
		if (!cin.fail() && x >= 0 && x < 25 && y >= 0 && y < 25) {
			report = Fire(x, y, ocean);
			if (report == "HIT") {
				ocean[x][y] = 'H';
			}
			cout << report << endl;
		}
		else if (!cin.fail() && x < 0 || y < 0) {
			cout << "Would you like to exit? (Y/N)" << endl;
			cin >> exiter;

			// Secret function to view current game status
			if (exiter == 'P') {
				for (int i = 0; i < 25; i++) {
					for (int j = 0; j < 25; j++) {
						cout << ocean[i][j];
					}
					cout << endl;
				}
			}
		}
		else {
			cout << "Please enter two coordinates between 0 and 24 separated by a space." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	OceanFile.close();
	system("Pause");
	return 0;
}


string Fire(int x, int y, char ocean[][25]) {
	string report = "MISS";
	char c = ocean[x][y];
	if (c == '#') {
		report = "HIT";
	} else if(c == 'H') {
		report = "HIT AGAIN";
	}

	return report;
}


bool FleetSunk(char ocean[][25]) {

	bool boats = false;

	// Iterate through the ocean looking for ships
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			// Calculate character offset and check for unsunk ships
			if (char(ocean[i][j]) == '#') {
				boats = true;
			}
		}
	} 

	if (!boats) {
		cout << "The fleet was destroyed." << endl;
	}

	return boats;
}