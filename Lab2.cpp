// Lab2 -- Calculates the possible group permutations between student group combinations
// CSIS 111 - 001

#include <iostream>
#include <iomanip>

using namespace std;

double factorial(double x);
double permutations(double n, double r);

int main() {
	double n, r;
	cout << "Donald Austin -- CSIS 111" << endl;

	// Collect function variables from the user
	cout << "Please enter the number of students: ";
	cin >> n;
	cout << "Pleae enter number of groups: ";
	cin >> r;

	cout << endl << "Factorial of Students: " << factorial(n) << endl;
	cout << "Factorial of Groups: " << factorial(r) << endl << endl;

	// Print out final program result
	cout << "There are " <<  permutations(n, r) << " possible teams." << endl;

	system("pause");
	return 0;

}

// Function for determining the factorial calculation
double factorial(double x) {
	double y = 1;
	for (double i = x; i > 1; i--) {
		y += y * (i - 1);
	}
	return y;
}

// Actual permutations function
double permutations(double n, double r) {
	double x = n - r;
	return factorial(n) / (factorial(r) * factorial(x));
}