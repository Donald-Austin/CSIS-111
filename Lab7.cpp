// Donald Austin - Lab 7: Fibonaccii
// CSIS 111 - 11/09/2018

#include <iostream>

using namespace std;

void Fib(int x);

int main() {
	int fibber{ 0 };
	bool steve = true;

	// Get input from user
	while(steve) {
		cout << "Please enter a positive integer: " << endl;
		cin >> fibber;
	// Validate input will not produce negative results and is an integer
	// Inputs great than 46 will produce negative integers and cause overflows
		if (!cin.fail() && fibber >= 0 && fibber <= 46) { steve = false; }
		else {
			cin.clear();
			cin.ignore(256, '\n');
			fibber = 0;
		}
	}


	Fib(fibber);

	system("pause");
	return 0;
}

void Fib(int x) {

	// Setup variables for Fibonacci sequence
	int z{ 0 }, y{ 1 }, c{ 0 };

	cout << "The Fibonacci sequence for " << x << " is ";
	for (int i = 1; i < x; ++i)
	{
		// Print out initial numbers and calculte fibonacci
		if (i == 1) { cout << z << " "; }
		if (i == 2) { cout << y << " "; }
		c = z + y;
		z = y;
		y = c;

		// Printout Fibonacci
		cout << c << " ";
	}
	cout << endl;
}