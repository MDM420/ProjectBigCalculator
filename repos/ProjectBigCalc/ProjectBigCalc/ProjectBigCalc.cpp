#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

//To do list:
// 1. a repeat that when you finish everything an option will pop up ask do you wanna start again.
// 2. advance calc.
// 3. other calculation
// 4. add more to the 4 option in main menu funtion
// 5. decorate eveyrthing (optional).
//*************The main menu funtion***************
static bool mustbenumber(string mustnum) {
	for (char variable : mustnum) {
		if (isdigit(variable)) {
			return false;
		}
	}
}
static void biooption(string bioop) {
	bool repeat1{};
	cout << "Simple Calculator: \n";
	cout << "Only uses +, -, *, / variables and that's it. \n";
	cout << "Advance Calculator: \n";
	cout << "Other Calculations: \n";
	cout << "Do you wanna go back to the start (1 for Yes and 0 for No). \n";
}
//*************The main menu Funtion************

//*************Select Menu Funtion***************
static void simplecalculator() {
	
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
	double num1, num2;
	char symbol;
	bool repeat2{};

	switch (stoi(option1)) {
	case 1:
		cout << "Simple Calculator \n";

		do {
			cout << "Enter the symbol that shown below: \n";
			cout << "Remember you can only use +, -, *, / because this is simple math. \n";
			cin >> symbol;
			//DO NOT PUT A LETTER ON NUM1 AND NUM2 IT WILL PUT AN INFITE ERROR LOOP!
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
			cin >> repeat2;
		} while (repeat2);
		cout << "Program has finish, please restart if you wanna keep calculating.";
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
