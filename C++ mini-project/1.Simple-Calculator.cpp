// Program: Console-based Simple Calculator
// Author: Priyansh Pundir
// Date: 20-06-2025
// Description: Performs basic arithmetic operations using switch-case in a loop.

#include<iostream>
using namespace std;

int main() {
    int choice;
    float num1, num2, result;

    while (true) {
        cout << "\n========== Simple Calculator ==========\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1 - 5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result = " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Result = " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Result = " << result << endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result = " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
