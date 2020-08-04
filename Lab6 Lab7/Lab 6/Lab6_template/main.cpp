#include <iostream>
#include <fstream>
#include "Vector.cpp"

using namespace std;
int main()
{
	ifstream inFile;
	inFile.open("input.txt");
	
	if (!inFile)
	{
		cout << "Read input.txt error" << endl;
		exit(1);//error ,leave
	}

	int testCase;
	inFile >> testCase;
	while (testCase > 0)
	{
		char op;
		inFile >> op;

		Vector v1 , v2 , v3;

		switch (op)
		{
			case '+':
				cout << "v1 + v2" << endl;
				inFile >> v1;
				inFile >> v2;
				cout << "v1:" << v1 << endl;
				cout << "v2:" << v2 << endl;
				v3 = v1 + v2;
				cout << v3 << endl;
				break;
			case '-':
				cout << "v1 - v2" << endl;
				inFile >> v1;
				inFile >> v2;
				cout << "v1:" << v1 << endl;
				cout << "v2:" << v2 << endl;
				v3 = v1 - v2;
				cout << v3 << endl;
				break;
			case '*':
				cout << "v1 * v2" << endl;
				inFile >> v1;
				inFile >> v2;
				cout << "v1:" << v1 << endl;
				cout << "v2:" << v2 << endl;
				cout << v1 * v2 << endl;
				break;
			case 'L':
				cout << "Length of v1" << endl;
				inFile >> v1;
				cout << "v1:" << v1 << endl;
				cout << v1.length() << endl;
				break;
			case 'N':
				cout << "Normalize of v1" << endl;
				inFile >> v1;
				cout << "v1:" << v1 << endl;
				cout << v1.normalize() << endl;
				break;
			default:
				break;
		}
		cout << endl;
		testCase--;
	}

	system("pause");

	return 0;
}