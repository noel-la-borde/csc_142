#include <iostream>
using namespace std;

enum class Operation { Add, Subtract, Multiply, Divide };

struct Calculator {
    Operation op;

    // Constructor 
    Calculator(Operation operation) : op(operation) {}

    // Method to perform the operation on two integers
    int calculate(int a, int b) {
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
    // Calculator with Add operation
    Calculator calcAdd(Operation::Add);
    int result = calcAdd.calculate(10, 5);
    cout << "Addition Result: " << result << endl;

    // Calculator with Subtract operation
    Calculator calcSubtract(Operation::Subtract);
    result = calcSubtract.calculate(10, 5);
    cout << "Subtraction Result: " << result << endl;

    // Calculator with Multiply operation
    Calculator calcMultiply(Operation::Multiply);
    result = calcMultiply.calculate(10, 5);
    cout << "Multiplication Result: " << result << endl;

    // Calculator with Divide operation
    Calculator calcDivide(Operation::Divide);
    result = calcDivide.calculate(10, 5);
    cout << "Division Result: " << result << endl;

    return 0;
}