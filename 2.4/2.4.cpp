#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	Matrix m1;
	cout << "Matrix 1:" << endl << m1;
	Matrix m2;
	cout << "Matrix 2:" << endl << m2;
	Matrix m3 = m1 - m2;
	cout << "m1-m2:" << endl << m3;

	cout << "Inputting values for a matrix:" << endl;
	Matrix m4(3);
	cin >> m4;
	cout << "Matrix m4:" << endl << m4;

	cout << "++m:" << endl << ++m4 << endl;
	cout << "--m:" << endl << --m4 << endl;
	cout << "m++:" << endl << m4++ << endl;
	cout << "m--:" << endl << m4-- << endl;

	cout << "m1 and m2 are " << (m1 == m2 ? "equal" : "not equal") << endl;

	cout << "Norma of matrix: " << m1.Norma() << endl;

	cout << "Comparison:" << endl;
	cout << "m1 == m2: " << (m1 == m2 ? "true" : "false") << endl;

	return 0;
}