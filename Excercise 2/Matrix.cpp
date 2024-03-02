#include "Matrix.h";
#include <iostream>;
#include <string>;

Matrix::Matrix() {
	x = 1;
	y = 1;
	i_matrix = new int*[x];
}

Matrix::Matrix(int i_x, int i_y) {
    if (i_x < 1 || i_y < 1) {
        std::cout << "Zle dane" << std::endl;
    }
    else {
        x = i_x;
        y = i_y;
        i_matrix = new int* [x];
        for (int ii = 0; ii < x; ii++) {
            i_matrix[ii] = new int[y];
        }
    }
}

Matrix Matrix::operator+(const Matrix& pcOther) {
    if (x != pcOther.x || y != pcOther.y) {
        std::cout << "Niekompatybilne rozmiary" << std::endl;
    }
    else {
        int** i_result;
        i_result = new int* [x];
        for (int ii = 0; ii < x; ii++) {
            i_result[ii] = new int[y];
        }

        for (int ii = 0; ii < x; ii++) {
            for (int jj = 0; jj < y; jj++) {
                i_result[ii][jj] = i_matrix[ii][jj] + pcOther.i_matrix[ii][jj];

            }
        }
        Matrix m_result(x, y);
        m_result.i_matrix = i_result;
        return m_result;
    }
}

void Matrix::fillMatrixWith(int i_value) {
    for (int ii = 0; ii < x; ii++) {
        for (int jj = 0; jj < y; jj++) {
            i_matrix[ii][jj] = i_value;
      
        }
    }
}

void Matrix::print() {
    for (int ii = 0; ii < x; ii++) {
        for (int jj = 0; jj < y; jj++) {
            std::cout << i_matrix[ii][jj];
        }
        std::cout << " " << std::endl;
    }
    std::cout << " " << std::endl;
}