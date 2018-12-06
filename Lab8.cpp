// Donald Austin - Lab 8: Enum Planets
// CSIS 111 - 11/16/2018

#include <iostream>
#include <string>

using namespace std;

enum Planet { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO };


double calcWeight(int x, double w);

int main() {

	double weight, w;
	Planet p;
	string planetName;
	bool loop{ false };

	//  Get user's weight and verify input
	while (!loop) {
		cout << "Please enter you weight: " << endl;
		cin >> w;
		loop = true;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			loop = false;
		}
	}

	cout << endl << "Enter the name of a planet: " << endl;

	// Take and Validate planet name from user
	while (loop)
	{

		cin >> planetName;

		loop = false;
		if (planetName == "Mercury")
			p = MERCURY;
		else if (planetName == "Venus")
			p = VENUS;
		else if (planetName == "Earth")
			p = EARTH;
		else if (planetName == "Moon")
			p = MOON;
		else if (planetName == "Mars")
			p = MARS;
		else if (planetName == "Jupiter")
			p = JUPITER;
		else if (planetName == "Saturn")
			p = SATURN;
		else if (planetName == "Uranus")
			p = URANUS;
		else if (planetName == "Neptune")
			p = NEPTUNE;
		else if (planetName == "Pluto")
			p = PLUTO;
		else {
			cout << endl << "You have not entered a valid planet name. Please enter a valid planet." << endl;
			loop = true;
		}
	}

	weight = calcWeight(p, w);

	// Output users calculated weight on a given planet
	cout << endl << "Your weight on heavenly body " << planetName << " is: " << weight << endl;

	system("pause");
	return 0;
}


// Take in planet number, and user's entered weight and calculate weight on planet
double calcWeight(int x, double w) {

	double weight;

	switch (x) {
	case(0):
		weight = w * 0.4155;
		break;
	case(1):
		weight = w * 1.8975;
		break;
	case(2):
		weight = w * 1.0;
		break;
	case(3):
		weight = w * 0.166;
		break;
	case(4):
		weight = w * 0.3507;
		break;
	case(5):
		weight = w * 2.5374;
		break;
	case(6):
		weight = w * 1.0677;
		break;
	case(7):
		weight = w * 0.8947;
		break;
	case(8):
		weight = w * 1.1794;
		break;
	case(9):
		weight = w * 0.0899;
		break;
	default:
		cout << "This should never print because it would indicate an error." << endl;
		break;
	}

	return weight;
}