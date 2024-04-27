#i#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
//*************The main menu funtion***************
bool mustbenumber(string mustnum) {
	for (char variable : mustnum) {
		if (isdigit(variable)) {
			return false;
		}
	}
}
//*************The main menu funtion***************

void simplecalculator() {
	
}
int main() {

	//*************The main menu***************
	 string option1;
	
	do {
		cout << "Pick an Option: \n";
		cout << "1- Simple Calculator \n";
		cout << "2- Advance Calculator \n";
		cout << "3- Quit \n";
		cin >> option1;
		if (stoi(option1) == 3) {
			cout << "Quitting no more actions will be procced. \n";
		}
		if (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 4) {
			cout << "Please choose a number that is 1 or 2." << endl;
		}
	} while (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 4);
	//*************The main menu***************
	
	//*************Select Menu***************
	double num1, num2;
	char symbol;
	bool repeat;

	switch (stoi(option1)) {
	case 1:
		cout << "Simple Calculator \n";

		do {
			cout << "Enter the symbol: \n";
			cout << "Remember you only use +, -, *, / because this is simple math. \n";
			cin >> symbol;
			cout << "Enter your 1 number: \n";
			cin >> num1;
			cout << "Enter your 2 number: \n";
			cin >> num2;
			switch (symbol) {
			case '+':
				cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
				break;
			case '-':
				cout << "Result: " << num1 << " + " << num2 << " = " << num1 - num2 << "\n";
				break;
			case '*':
				cout << "Result: " << num1 << " + " << num2 << " = " << num1 * num2 << "\n";
				break;
			case '/':
				cout << "Result: " << num1 << " + " << num2 << " = " << num1 / num2 << "\n";
				break;
			default:
				cout << "Error (Repeat or Restart the Program). \n";
			}
			cout << "Do you wanna repeat (1 for Yes and 0 for No) \n";
			cin >> repeat;
		} while (repeat);
		cout << "Program has finish, please restart if you wanna keep calculating.";
		break;
	case 2:
		cout << "Advance Calculator";

			break;
	default:
		cout << "If you see this it means you quitted the program.";
	}
	//*************Select Menu***************
	return 0;
}
