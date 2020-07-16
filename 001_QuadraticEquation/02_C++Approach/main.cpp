//
// Write a class to wrap up the essential (related) components 
// Backup before a demo!!!
//
// 
#include <iostream>
#include <iomanip>
using namespace std;

class QuadraticEqSolver
{
public:
	double a, b, c;
	double d2;	// determinant
public:
	QuadraticEqSolver( ) { }

	void input( ) {
		cout << "Please enter the coefficients of a quadratic equation, (a,b,c):" << endl;


		cin >> a >> b >> c;
		/////////////////////
		//Show the equation
		/////////////////////
		cout << "The equation is:" << endl;
		cout << "(" << a << "\t," << b << "\t," << c << ")" << endl; 
	}
	void computeDeterminant( ) 
	{
		d2 = b*b - 4*a*c;
	}

	void computeRoots( )
	{
		if (d2 >=0) {
			cout << "There are real roots." << endl;
			double d = sqrt( d2 );
			double r1 = (-b - d)/(2*a);
			double r2 = (-b + d)/(2*a);
			cout << "Root:" << setprecision(2) << r1 << endl;
			cout << "Root:" << r2 << endl;

		} else {
			cout << "There are no real roots." << endl;
		}
	}
	void solve( ) {
		input( );
		computeDeterminant( );
		computeRoots( );
	}
};

class EqSolver {
public:
	EqSolver( ) {
	}
	void solve( int num )	//function overloading
	{

		QuadraticEqSolver a;
		int counter = 0;
		while ( counter != num ) {
			a.solve( );
			++counter;
		}
	}

	void solve( ) {
		int num;
		cout << "Please enter the number of quadratic equations to solve:" << endl;
		cin >> num;
		solve( num );
	}
};
int main( )
{
	QuadraticEqSolver a; 
	a.a = 0; // a is a private data member

	system("pause");
	return 0;
}


// The problem:
// - What if we want to solve another quadratic equation?
// - Run the program again? 
// - Use a while infinite loop?
//		while (true) {
//		...
//		}
// - may be too messy to do so
//
// ......
// Convert our main source into a class!
//