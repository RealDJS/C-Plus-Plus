#include <iostream>
using namespace std;

// Hello World
int main()
{
	cout << "Hello World!" << endl << endl;

	bool myBool = true;

	int myAge = 35;
	cout << "I am " << myAge << " years old." << endl << endl;

	//Numeric types
	/*int x, y;
	int sum;
	cout << "Type a number: ";
	cin >> x;
	cout << "Type another number: ";
	cin >> y;
	sum = x + y;
	cout << "Sum is: " << sum;*/

	//Scientific
	/*float f1 = 35e3;
	double d1 = 12e4;
	cout << f1<< endl;
	cout << d1<< endl;*/

	//bool isThisABool = true;
	//cout << isThisABool << endl; // Displays a 1

	int* ptr = &myAge;

	cout << ptr << "\n";// Outputs memory address.
	cout << *ptr << "\n";// Outputs value at pointer.


	return 0;

}