#include <iostream>
#include <vector>
#include <numbers>
#include <iomanip>

class GeometricObject {
private:
	int identifier;// A GeometricObject's 3 digit identifier.

public:
	// Default Constructor
	GeometricObject() : identifier(1) {};

	// Parameterized Constructor
	GeometricObject(int identifier) : identifier(identifier) {setIdentifier(identifier);}

	// Virtual Destructor
	virtual ~GeometricObject() = default;

	// Getters & Setters
	int getIdentifier() const { return identifier; }

	void setIdentifier(int identifier) {
		if (identifier >= 100 && identifier <= 999) {
			this->identifier = identifier;
		}
		else if (identifier < 0) {
			throw std::invalid_argument("Identifier cannot be negative.");
		} else{
			throw std::invalid_argument("Identifier must be a 3 - digit number.");
		}
	}

	// Functions
	virtual double calcArea() const = 0;
};


class Square : public GeometricObject {
	private: 
		double side;// A square's side.
	
	public:
		// Default Constructor
		Square() : GeometricObject(), side(1) {}

		// Parameterized Constructor
		Square(int identifier, double sideLength) : GeometricObject(identifier), side(sideLength){}
		
		// Override calcArea function
		double calcArea() const override{return side * side;};
};


class Circle : public GeometricObject{
	private:
		double radius; // A circle's radius.

	public:
		// Constructor
		Circle() : GeometricObject(), radius(1) {}

		// Parameterized Constructor
		Circle(int identifier, double circleRadius): GeometricObject(identifier), radius(circleRadius){}

		// Override calcArea function
		double calcArea() const override {return radius * radius * std::numbers::pi; }
};


class RightTriangle : public GeometricObject {
	private:
		double height; // RightTriangle's height.
		double base; // Right Triangle's base length.

	public :
		// Constructor
		RightTriangle() : GeometricObject(), height(1), base(1) {}

		// Parameterized Constructor
		RightTriangle(int identifier, double triHeight, double triBase) : GeometricObject(identifier), height(triHeight), base(triBase) {}

		// Override calcArea function
		double calcArea() const override {return base * height / 2;}
};


int main()
{
	// Stores shapes polymorphically with smart pointers.
	std::vector<std::shared_ptr<GeometricObject>> shapes;

	// Creates Shapes to store in the vector.
	shapes.push_back(std::make_shared <Square>(100, 2));
	shapes.push_back(std::make_shared <Circle>(134, 3.5));
	shapes.push_back(std::make_shared<RightTriangle>(300, 4.5, 5.5));

	// Set doubles to 2 decimals.
	std::cout << std::fixed << std::setprecision(2);

	// Display
	for (const auto& shape : shapes) {
		std::cout << "Shape ID: " << shape->getIdentifier() << ", Area: " << shape->calcArea() << std::endl;
	}

	return 0;
}