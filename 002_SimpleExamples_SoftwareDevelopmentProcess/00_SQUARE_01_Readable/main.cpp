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
#include <iostream>
#include <iomanip>
using namespace std;

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
	void input( ) {
		cout << "Enter the side length of a square:" << endl;
		cin >> sideLength; 
		cout << "The side length:" << sideLength << endl;
	}
	void computeArea( ) { 
		area = sideLength*sideLength; 
		cout << "Area:\t" << area << endl; 
	}
	void computePerimeter( ) { 
		perimeter = 4*sideLength; 
		cout << "Perimeter:\t" << perimeter << endl; 
	}
};

int main( )
{
	SQUARE a;
	a.input( );
	a.computeArea( );
	a.computePerimeter( );
	system("pause");
	return 0;
}


// - How do you know the input are processed correctly?
// Show/Visualize the entire process stage
//