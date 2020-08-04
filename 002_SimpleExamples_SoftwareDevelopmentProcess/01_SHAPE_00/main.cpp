//
//
// SQUARE
//
// What are the problems?
// How to improve the program quality?
// - readability
// - user friendly
// - maintenance
//
// Make the input return the side length
//
#include <iostream>
#include <iomanip>
using namespace std;

class SHAPE {
private:
public:
	SHAPE( ) { }
	double input( ) { }
	double computeArea( ) { }
	double computePerimeter( ) { }
};

class SQUARE {
private:
	double sideLength;
	double area;
	double perimeter;
public:
	SQUARE( ) {
		sideLength = 0.0;
		area = 0.0;
		perimeter = 0.0;
	}
	double input( ) {
		cout << "Enter the side length of a square:" << endl;
		cin >> sideLength; 
		cout << "The side length:" << sideLength << endl; //why is this important?
		return sideLength;
	}
	double computeArea( ) { 
		area = sideLength*sideLength; 
		cout << "Area:\t" << area << endl; 
		return area;
	}
	double computePerimeter( ) { 
		perimeter = 4*sideLength; 
		cout << "Perimeter:\t" << perimeter << endl; 
		return perimeter;
	}
};

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


// - How do you know the input are processed correctly?
// Show/Visualize the entire process stage
//