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
	double a;
	double b;
	double c;
public:
	SQUARE( ) {
		a = 0.0;
	}
	void x( ) { cin >> a; }
	void k( ) { b = a*a; cout << b << endl; }
	void g( ) { c = 4*a; cout << c << endl; }
};

int main( )
{
	SQUARE a;
	a.x( );
	a.k( );
	a.g( );
	system("pause");
	return 0;
}

// Good for competition?
