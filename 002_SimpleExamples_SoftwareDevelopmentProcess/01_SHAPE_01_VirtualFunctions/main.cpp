//
// Abstract class
//
#include <iostream>
#include <iomanip>
using namespace std;

#define PI	3.141592654

//SHAPE is an abstract class
//as it has at least one function which is undefined.
class SHAPE {
private:
protected:
	double area;		// children can use area
	double perimeter;	// children can use perimeter
public:
	SHAPE( ) { }
	virtual double input( ) = 0;
	virtual double computeArea( ) = 0;
	virtual double computePerimeter( ) = 0;
};

class SQUARE : public SHAPE {
private:
	double sideLength;

public:
	SQUARE( ) {
		sideLength = 0.0;
		area = 0.0;
		perimeter = 0.0;
	}
	double input( ) {
		cout << "Enter the side length of a square:" << endl;
		cin >> sideLength; 
		cout << "Side length:" << sideLength << endl; //why is this important?
		return sideLength;
	}
	double computeArea( ) { 
		area = sideLength*sideLength; 
		cout << "Square area:\t" << area << endl; 
		return area;
	}
	double computePerimeter( ) { 
		perimeter = 4*sideLength; 
		cout << "Square perimeter:\t" << perimeter << endl; 
		return perimeter;
	}
};

class CIRCLE : public SHAPE {
private:
	double radius;

public:
	CIRCLE( ) {
		radius = 0.0;
		area = 0.0;
		perimeter = 0.0;
	}
	double input( ) {
		cout << "Enter the radius of a circle:" << endl;
		cin >> radius; 
		cout << "Radius:" << radius << endl; //why is this important?
		return radius;
	}
	double computeArea( ) { 
		area = radius*radius*PI; 
		cout << "Circle area:\t" << area << endl; 
		return area;
	}
	double computePerimeter( ) { 
		perimeter = 2*radius*PI; 
		cout << "Circle perimeter:\t" << perimeter << endl; 
		return perimeter;
	}
};

//
int main( )
{
	SQUARE a;

	while ( a.input( ) > 0.0 ) {
		a.computeArea( );
		a.computePerimeter( );
	}
	cout << "Thanks for playing..." << endl;
	system("pause");
	return 0;
}
