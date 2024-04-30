#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

//To do list:
// 1. a repeat that when you finish everything an option will pop up ask do you wanna start again from the start.
// 2. advance calc.
// 3. other calculation
// 4. add more to the 4 option in main menu funtion
// 5. decorate eveyrthing (optional).
// Already done:
// 1. simple calc- done
//*************The main menu funtion***************
static bool mustbenumber(string mustnum) {
	for (char variable1 : mustnum) {
		if (isdigit(variable1)) {
			return false;
		}
	}
}
static void biooption(string bioop) {
	bool repeat1{};
	cout << "1- Simple Calculator: \n";
	cout << "- Only uses +, -, *, / variables and that's it. \n";
	cout << "2- Advance Calculator: \n";
	cout << "3- Other Calculations: \n";
	cout << "Do you wanna go back to the start (1 for Yes and 0 for No). \n";
}
//*************The main menu Funtion************

//*************Select Menu Funtion***************
static void simplecalculator() {
	cout << "Leave this here just in case.";
}
int main() {
//*************Select Menu***************

	//*************The main menu***************
	 string option1;
	 bool repeat{};
	
	do {
		cout << "Pick an Option: \n";
		cout << "1- Simple Calculator \n";
		cout << "2- Advance Calculator \n";
		cout << "3- Other Calculations \n";
		cout << "4- Bio of the Options (Except Quit and Don't ask Why) \n";
		cout << "5- Quit \n";
		cin >> option1;
		if (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 6) {
			cout << "Please choose a number that is 1 or 5." << endl;
		} else if (stoi(option1) == 4) {
			biooption(option1);
			cin >> repeat;
		} else if (stoi(option1) == 5) {
			cout << "Quitting no more actions will be procced. \n";
		}
	} while (mustbenumber(option1) || stoi(option1) <= 0 || stoi(option1) >= 6 || repeat);
	//*************The main menu***************
	
	//*************Select Menu***************
	double num1 = 0, num2 = 0, result1 = 0.0, add1;
	char symbol;
	bool addmore = false, restart1{};

	switch (stoi(option1)) {
	case 1:
		cout << "Simple Calculator \n";

		do {
			if (!addmore) {
				cout << "Enter the symbol that shown below: \n";
				cout << "Remember you can only use +, -, *, / because this is simple math. \n";
				cin >> symbol;
				cout << "Enter your 1 number: \n";
				cin >> num1;
				cout << "Enter your 2 number: \n";
				cin >> num2;
			}
			else {
				num1 = result1;
				cout << "Enter the symbol that shown below: \n";
				cout << "Remember you can only use +, -, *, / because this is simple math. \n";
				cin >> symbol;
				cout << "Enter your 2 number: \n";
				cin >> num2;
			}
			switch (symbol) {
			case '+':
				result1 = num1 + num2;
				cout << "Result: " << num1 << " + " << num2 << " = " << result1 << '\n';
				break;
			case '-':
				result1 = num1 - num2;
				cout << "Result: " << num1 << " + " << num2 << " = " << result1 << '\n';
				break;
			case '*':
				result1 = num1 * num2;
				cout << "Result: " << num1 << " + " << num2 << " = " << result1 << '\n';
				break;
			case '/':
				if (num2 == 0 || num1 == 0) {
					result1 = 0;
					cout << "Result: " << num1 << " + " << num2 << " = " << result1 << '\n';
				}
				break;
			default:
				cout << "Error (Repeat or Restart the Program). \n" << endl;
				break;
			}
			cout << "Want to add more to your result (1 for yes and 0 for no): \n";
			cin >> add1;
			if (add1 == 1) {
				addmore = true;
			} else {
				addmore = false;
				cout << "Want to restart the calculation from the top, (1 for yes and 0 for no), (the result you had will be erased). \n";
				cin >> restart1;
			}
		} while (addmore || restart1 || num1 || num2);
		cout << "Program has finish, please restart if you wanna keep calculating." << endl;
		break;
	case 2:
		cout << "Advance Calculator";
			break;
	case 3:
		cout << "Other Calculations";
		break;
	default:
		cout << "If you see this it means you quitted the program.";
	}
	//*************Select Menu***************
	return 0;
}
