#ifndef CMAKE_MATRIXCLASS_CPP
#define CMAKE_MATRIXCLASS_CPP
#include "CMake_MatrixClass.hpp"

template<typename T>
unsigned Matrix<T>::get_rows() const { return this->rows; }
template<typename T>
unsigned Matrix<T>::get_cols() const { return this->cols; }

//constructors 
template<typename T>
Matrix<T>::Matrix() {}

template<typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _cols) {

	v.resize(_rows);
	for (unsigned i = 0; i < v.size(); i++) {
		v[i].resize(_cols);
	}
	rows = _rows;
	cols = _cols;

}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) {
	rows = matrix.get_rows();
	cols = matrix.get_cols();
	v = matrix.v;
}


//to get individual elements
template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
	return this->v[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const {
	return this->v[row][col];
}

//matrix assignment 
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
	if (&matrix == this)
		return *this;

	unsigned _rows = matrix.get_rows();
	unsigned _cols = matrix.get_cols();
	v.resize(_rows);
	for (unsigned i = 0; i < v.size(); i++) {
		v[i].resize(_cols);
	}
	for (unsigned i = 0; i < _rows; i++) {
		for (unsigned j = 0; j < _cols; j++) {
			v[i][j] = matrix(i, j);
		}
	}
	rows = _rows;
	cols = _cols;
	return *this;
}

// printing values
template<typename T>
void Matrix<T>::print_values() const {
	for (int i = 0; i < this->get_rows(); i++) {
		for (int j = 0; j < this->get_cols(); j++) {
			cout << v[i][j] << "  ";
		}
		cout << endl;
	}
}

// multiplication by * symbol
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matrix) {
	unsigned rows1 = matrix.get_rows();
	unsigned cols1 = matrix.get_cols();

	try {
		if (this->cols != rows1) {
			cout << "These matrices cannot be multiplied.";

		}
		else {
			Matrix matrix_after_mul(rows, cols1);

			for (unsigned i = 0; i < rows; i++) {
				for (unsigned j = 0; j < cols1; j++) {
					for (unsigned k = 0; k < rows1; k++) {
						matrix_after_mul(i, j) += this->v[i][k] * matrix(k, j);
					}
				}
			}
			return matrix_after_mul;
		}
	}
	catch (exception& e) {
		cout << "Exepcion was raised: " << e.what() << endl;
	}
	

}

//standart multiplication
template<typename T>
Matrix<T> Matrix<T>::matmul(const Matrix<T>& mat1, const Matrix<T>& mat2)
{
	unsigned rows1 = mat1.get_rows();
	unsigned cols1 = mat1.get_cols();
	unsigned rows2 = mat2.get_rows();
	unsigned cols2 = mat2.get_cols();

	try {
		if (cols1 != rows2) {
			cout << "These matrices cannot be multiplied.";

		}
		else {
			Matrix matrix_after_mul(rows1, cols2);

			for (unsigned i = 0; i < rows1; i++) {
				for (unsigned j = 0; j < cols2; j++) {
					for (unsigned k = 0; k < rows2; k++) {
						matrix_after_mul(i, j) += mat1(i, k) * mat2(k, j);

					}
				}
			}
			return matrix_after_mul;
		}
	}
	catch (exception& e) {
		cout << "Exepcion was raised: " << e.what() << endl;
	}
	

}

//filing diagonal with ones. Function needed for compute_grad function.
template<typename T>
void Matrix<T>::fill_diagonal() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			if (i == j) {
				this->v[i][j] = 1;
			}
			else {
				this->v[i][j] = 0;
			}
		}
	}
}

//compute_grad function
template<typename T>
Matrix<T> Matrix<T>::compute_grad(const Matrix<T>& matX, const Matrix<T>& matY)
{
	unsigned cols2 = matY.get_cols();
	//diagonal matrix
	Matrix diagonal_matY(cols2, cols2);
	diagonal_matY.fill_diagonal();
	cout << "Diagonal matrix: " << endl;
	diagonal_matY.print_values();

	Matrix delta_matmul_value_divide_by_delta_matX = matmul(matY, diagonal_matY);

	return delta_matmul_value_divide_by_delta_matX;

}


#endif
