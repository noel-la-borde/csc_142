#include <iostream>
using namespace std;

// enum class Operation 
enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

int main() {
    
    Operation op = Operation::Add;

    if (op == Operation::Add) {
        cout << "Operation is Addition" << endl;
    }

    return 0;
}