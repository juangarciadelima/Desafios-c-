#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void doAdd(int leftNumberAddition, int rightNumberAddition) {
	cout << "\n Result of addition: " << (leftNumberAddition + rightNumberAddition) << endl;
}

void doSub(int leftNumberSubtraction, int rightNumberSubtraction) {
	cout << "\n Result of subtraction: " << (leftNumberSubtraction + rightNumberSubtraction) << endl;
}

void doMulti(int leftNumberMultiplication, int rightNumberMultiplication) {
	cout << "\n Result of multiplication: " << (leftNumberMultiplication + rightNumberMultiplication) << endl;
}

void doDivide(int leftNumberDivision, int rightNumberDivision) {
	cout << "\n Result of division: " << (leftNumberDivision + rightNumberDivision) << endl;
}

int main() {
	int leftNumber, rightNumber;
	//Variables to declare the numbers of the operation

	string operationChoosed;
	//String to define the choosed operation

	const char* operations[4]
		= { "add", "sub", "multi", "divide" };
	//array of the operations

	cout << "\n  Type the first number: ";

	cin >> leftNumber;

	if (cin.fail()) {
		cout << "Your input is invalid, try again later!!";
		return 1;
	}

	cout << "\n  Type the other number: ";

	cin >> rightNumber;

	if (cin.fail()) {
		cout << "Your input is invalid, try again later!!";
		return 1;
	}

	cout << "\n Choose one of the operations in the calculator. \n Examples: (add, multi, divide...) ";

	cin >> operationChoosed;

	unordered_map<string, void(*)(int, int)> operationsMap = {
		{"add", doAdd},
		{"sub", doSub},
		{"multi", doMulti},
		{"divide", doDivide},
	};

	//map that mounts a array that the first item is the key, and the second is the function to be executed

	auto operationToExecuteFunction = operationsMap.find(operationChoosed);
	if (operationToExecuteFunction != operationsMap.end()) {
		operationToExecuteFunction->second(leftNumber, rightNumber);
	}
	else {
		cout << "Invalid operation. Please choose one of the specified options." << endl;
	}

	//basically, this code, finds the item in the array based in the operationChoosed, with the find, and if is different
	//from the end of the array, it executes the function that is defined by the second, passing the leftNumber and rightNumber passed
	//in the cin

	return 0;
}
