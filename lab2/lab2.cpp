#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

const double a = -0.2;
const double b = 0.2;

// Function to calculate the sum of the power series; performs no checks
// Stops at the first term that is less than eps
// The first term with |term| < eps is included
double s(double x, double eps) {
	double sum = 0;
	double term = 3.0;
	int n = 0;
	const double twoX = 2 * x;
	while (term >= eps || term <= -eps) {
		sum += term;
		++n;
		term *= twoX * (2 * n + 3) * (n + 1) / (n * (n + 2));
	}
	return sum + term;
}

// Reads the number from the input stream and checks if it is a valid number
// Reads the whole line
// Throws invalid_argument if the input is not a number
double readNumber(const string& name) {
	string line;
	getline(cin, line);
	istringstream input(line);
	double value = 0;
	input >> value;
	if (input.fail() || !input.eof()) {
		throw invalid_argument("Input for " + name + " is not a number.");
	}
	return value;
}

// Reads the value of x and checks that it belongs to [-0.2; 0.2]
// Throws out_of_range if the input is not in the domain
double readX() {
	cout << "Enter the value of x from [-0.2; 0.2]: ";
	const double x = readNumber("x");
	if (!(x >= a && x <= b)) {
		throw out_of_range("x is outside of the domain [-0.2; 0.2].");
	}
	return x;
}

// Reads the value of eps from the input stream and checks if it is positive
// Throws out_of_range if the input is not positive
double readEps() {
	cout << "Enter positive eps: ";
	const double eps = readNumber("eps");
	if (!(eps > 0)) {
		throw out_of_range("eps must be positive.");
	}
	return eps;
}

// Prints the entered data and the result in the required formats
void printReport(double x, double eps, double result) {
	cout << scientific << uppercase;
	cout << setprecision(7) << "for x = " << x << endl;
	cout << setprecision(9) << "for eps = " << eps << endl;
	cout << fixed << setprecision(8);
	cout << "result = " << result << endl;
}

// Prints the author and the task, reads the input data
// Performs the calculations and prints the result
// Reports any input errors
int main() {
	cout << "The author of this program is Sofiia Demchenko" << endl;
	cout << "The program calculates the sum of a power series" << endl;
	cout << "Variant 164" << endl;
	try {
		const double x = readX();
		const double eps = readEps();
		cout << endl << "***** do calculations ...";
		const double result = s(x, eps);
		cout << " done" << endl;
		printReport(x, eps, result);
	}
	catch (const exception& error) {
		cout << endl << "***** error" << endl;
		cout << error.what() << endl;
	}
	return 0;
}
