#pragma once
#include <iostream>
#include <string>

using namespace std;
class Matrix
{
private:
	int size;
	int** arr;
public:
	Matrix();
	Matrix(int size);
	Matrix(int size, int** arr);
	Matrix(const Matrix&);
	~Matrix();
	Matrix& operator ++ ();
	Matrix& operator -- ();
	Matrix operator ++ (int);
	Matrix operator -- (int);
	Matrix& operator = (const Matrix&);
	friend bool operator == (Matrix&, Matrix&);
	operator string () const;
	friend ostream& operator << (ostream&, const Matrix&);
	friend istream& operator >> (istream&, Matrix&);
	Matrix operator -(const Matrix&);
	int Norma();
	int getSize();
	int* operator[](int index);
};