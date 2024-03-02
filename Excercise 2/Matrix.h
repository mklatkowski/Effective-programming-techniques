#include <iostream>
#include<string>

class Matrix {
public:
	Matrix();
	Matrix(int i_x, int i_y);
	void fillMatrixWith(int i_value);
	void print();
	Matrix operator+(const Matrix& pcOther);

private:
	int** i_matrix;
	int x;
	int y;
};
