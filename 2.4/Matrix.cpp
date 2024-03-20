#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {
	size = 4;
	arr = new int* [size];
	for (int i = 0;i < size;i++) {
		arr[i] = new int[size];
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			arr[i][j] = rand() % 15;
		}
	}
}
Matrix::Matrix(int size) {
	this->size = size;
	arr = new int* [size];
	for (int i = 0;i < size;i++) {
		arr[i] = new int[size];
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			arr[i][j] = rand() % 15;
		}
	}
}
Matrix::Matrix(int size, int** array) {
	this->size = size;
	arr = new int* [size];
	for (int i = 0;i < size;i++) {
		arr[i] = new int[size];
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			arr[i][j] = array[i][j];
		}
	}
}
Matrix::Matrix(const Matrix& m) {
	this->size = m.size;
	arr = new int* [size];
	for (int i = 0;i < size;i++) {
		arr[i] = new int[size];
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			this->arr[i][j] = m.arr[i][j];
		}
	}
}
Matrix::~Matrix() {
	for (int i = 0;i < size;i++) {
		delete []arr[i];
	}
	delete[]arr;
}
Matrix::operator string () const {
	string str = "";
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			str += to_string(arr[i][j]) + " ";
		}
		str += "\n";
	}
	return str;
}
ostream& operator << (ostream& out, const Matrix& m) {
	for (int i = 0;i < m.size;i++) {
		for (int j = 0;j < m.size;j++) {
			out << m.arr[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, Matrix& m) {
	for (int i = 0;i < m.size;i++) {
		for (int j = 0;j < m.size;j++) {
			cout << "Matrix[" << i << "][" << j << "]=";
			in >> m.arr[i][j];
		}
	}
	return in;
}
bool operator == (Matrix& m1, Matrix& m2) {
	if (m1.size != m2.size) {
		return false;
	}
	for (int i = 0;i < m1.size;i++) {
		for (int j = 0;j < m1.size;j++) {
			if (m1.arr[i][j] != m2.arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
Matrix& Matrix::operator ++ () {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			++arr[i][j];
		}
	}
	return*this;
}
Matrix& Matrix::operator -- () {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			--arr[i][j];
		}
	}
	return*this;
}
Matrix Matrix::operator ++ (int) {
	Matrix m = Matrix(*this);
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			++arr[i][j];
		}
	}
	return m;
}
Matrix Matrix::operator -- (int) {
	Matrix m = Matrix(*this);
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			--arr[i][j];
		}
	}
	return m;
}
Matrix& Matrix::operator = (const Matrix& m) {
	if (this == &m) {
		return *this;
	}
	for (int i = 0;i < size;i++) {
		delete[]arr[i];
	}
	delete[]arr;
	this->size = m.size;
	arr = new int* [size];
	for (int i = 0;i < size;i++) {
		arr[i] = new int[size];
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			this->arr[i][j] = m.arr[i][j];
		}
	}
	return *this;
}
Matrix Matrix::operator-(const Matrix& m) {
	if (size == m.size) {
		Matrix res = Matrix(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				res.arr[i][j] = arr[i][j] - m.arr[i][j];
			}
		}
		return res;
	}
	Matrix res = Matrix();
	return res;
}

int Matrix::Norma() {
	int min = arr[0][0];
	int max = arr[0][0];
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	return abs(max - min);
}
int Matrix::getSize() {
	return size;
}
int* Matrix::operator[](int index) {
	return arr[index];
}