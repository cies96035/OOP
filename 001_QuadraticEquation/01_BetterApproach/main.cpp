//
//
// Show/Visualize the entire process stage
// Make sure that everthing is performed as expected.
//
// 
#include <iostream>
#include <iomanip>
using namespace std;

int main( )
{
	cout << "Please enter the coefficients of a quadratic equation, (a,b,c):" << endl;
	
	double a, b, c;
	cin >> a >> b >> c;
	/////////////////////
	//Show the equation
	/////////////////////
	cout << "The equation is:" << endl;
	cout << "(" << a << "\t," << b << "\t," << c << ")" << endl; 

	double d2;	// determinant
	d2 = b*b - 4*a*c;
	/////////////////////
	//Show the determinant
	/////////////////////
	cout << "Determinant:" << setprecision(12) << d2 << endl;
	cout << "Determinant:" << setprecision(2) << d2 << endl;

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