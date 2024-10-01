#include <iostream>
using namespace std;



class GeometricObject {
public:
	void myMethod() {
		cout << "Hello World!";
	}
};


// Hello World
int main()
{
	GeometricObject shape;

	shape.myMethod();

	return 0;
}