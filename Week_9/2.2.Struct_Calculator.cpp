#include <iostream>
using namespace std;

enum class Operation { Add, Subtract, Multiply, Divide };

struct Calculator {
    Operation op;

    // Constructor 
    Calculator(Operation operation) : op(operation) {}

    // Method to perform the operation 
    static double calculate(double a, double b, Operation op) {
        switch (op) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                if (b != 0) {
                    return a / b;
                } else {
                    cout << "Error: Division by zero!" << endl;
                    return 0; 
                }
            default:
                cout << "Unknown operation!" << endl;
                return 0;
        }
    }
};

int main() {
    // Perform calculations 
    cout << "Addition Result: " << Calculator::calculate(5, 3, Operation::Add) << endl;
    cout << "Multiplication Result: " << Calculator::calculate(5, 3, Operation::Multiply) << endl;
    cout << "Subtraction Result: " << Calculator::calculate(5, 3, Operation::Subtract) << endl;
    cout << "Division Result: " << Calculator::calculate(5, 3, Operation::Divide) << endl;

    return 0;
}