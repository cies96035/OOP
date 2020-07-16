//
//
// What are the problems of this program?
//
//
/*
Write a program to ask the user to input a quadratic equation and solve the quadratic equation. 
If there are real roots, show them. Otherwise, show “no real roots”.

	a x^2 + b x + c = 0
	
	root1 = (-b - sqrt( b^2 – 4ac ) ) / 2a
	root2 = (-b + sqrt( b^2 – 4ac ) ) / 2a

*/
#include <iostream>

using namespace std;

int main( )
{
	cout << "Please enter the coefficients of a quadratic equation, (a,b,c):" << endl;
	
	double a, b, c;
	cin >> a >> b >> c;
    
    //a x^2 + b x + c = 0
	//root1 = (-b - sqrt( b^2 – 4ac ) ) / 2a
	//root2 = (-b + sqrt( b^2 – 4ac ) ) / 2a

	double d2;	// determinant
	d2 = b*b - 4*a*c;
	if (d2 >=0) {
		cout << "There are real roots." << endl;
		double d = sqrt( d2 );
		double r1 = (-b - d)/(2*a);
		double r2 = (-b + d)/(2*a);
		cout << "Root:" << r1 << endl;
		cout << "Root:" << r2 << endl;
	} else {
		cout << "There are no real roots." << endl;
	}
	system("pause");
	return 0;
}


// The problems:
// - How do you know the input are processed correctly?
// - What if we want to solve another quadratic equation?
// - How do you know the computed determinant is correct?
// - How do you know the entire program is correct?

// Solution:
// Show/Visualize the entire process stage
//