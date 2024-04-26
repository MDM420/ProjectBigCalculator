#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

bool mustbenumber(string mustnum) {
	for (char variable : mustnum) {
		if (isdigit(variable)) {
			return false;
		}
	}
}

int main() {

	 string option1;
	
	do {
		cout << "Pick an Option: \n";
		cout << "1- Simple Calculator \n";
		cout << "2- Advance Calculator \n";
		cin >> option1;
		if (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 3) {
			cout << "Please choose a number that is 1 or 2." << endl;
		}
	} while (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 3);

	cout << "This just for experiments";
	return 0;
}
