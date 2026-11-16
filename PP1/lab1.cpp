#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
using namespace std;

// Computes the value for the given x, performs no checks
// Assumes x is in the domain of f(x)
double f(double x) {
	return cos(23.0 / 51) - 15 * numbers::pi + 55 * numbers::e * 7 / ((x + 15) * (x - 14))
		+ 11 * atan(x - 8) + 1 / sqrt(x - 5);
}

// Returns true if x is in the domain of f(x)
bool IsInDomain(double x) {
	return x > 5 && x != 14;
}

// Reads x, prints f(x) if x is in the domain of f(x) 
// Otherwise prints "undefined"
int main() {
	cout << "Author: Sofiia Demchenko" << endl;
	cout << "This program calculates the value of an expression by given x." << endl;
	cout << "Variant 164." << endl;
	cout << "Enter x (x > 5, x != 14): ";
	double x;
	cin >> x;
	if (cin.fail()) {
		cout << endl << "wrong input" << endl;
	}
	else {
		cout << endl << "***** do calculations ...";
		const bool defined = IsInDomain(x);
		double value = 0.0;
		if (defined) {
			value = f(x);
		}
		cout << " done" << endl;

		cout << fixed << setprecision(5);
		cout << "for x = " << x << endl;
		cout << setprecision(9);
		if (defined) {
			cout << "result = " << value << endl;
		}
		else {
			cout << "result = undefined" << endl;
		}
	}
}
