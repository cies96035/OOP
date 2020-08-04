#include <iostream>
#include"Matrix.cpp"
#include<vector>

using namespace std;

int main() {

	bool Exit = false;
	int m, n;

	char op;

	while (!Exit) {
		cout << "op:";
		cin >> op;

		if (op == '+') {
			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m1(m, n);

			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m2(m, n);

			m1.Add(m2);
		}
		else if (op == '-') {
			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m1(m, n);

			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m2(m, n);

			m1.Sub(m2);
		}
		else if (op == '*') {
			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m1(m, n);

			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m2(m, n);

			matrix m3 = m1.Mul(m2);
			m3.Print();
		}
		else if (op == 'd') {
			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m1(m, n);

			m1.GetDet();
		}
		else if (op == 'i') {
			cout << "Size of matrix(m*n):";
			cin >> m >> n;
			matrix m1(m, n);

			m1.Inverse();
		}
		else if (op == 'q')
			Exit = true;

	}
//d 3 3 1 2 3 4 5 5 5 5 7
	return 0;
}
