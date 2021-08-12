#ifndef CMAKE_MATRIXCLASS_HPP
#define CMAKE_MATRIXCLASS_HPP

#include <vector>
using namespace std;

template<typename T>
class Matrix {
private:
	unsigned rows, cols;
	vector< vector<T> > v;
public:
	unsigned get_rows() const;
	unsigned get_cols() const;

	//constructors
	Matrix();
	Matrix(unsigned _rows, unsigned _cols);
	Matrix(const Matrix<T>& matrix);

	//to get individual elements
	T& operator()(const unsigned& row, const unsigned& col);
	const T& operator()(const unsigned& row, const unsigned& col) const;

	//assigment matrix
	Matrix<T>& operator=(const Matrix<T>& matrix);

	// printing values
	void print_values() const;

	// multiplication by * symbol
	Matrix<T> operator*(const Matrix<T>& matrix);

	//standart multiplication
	Matrix<T> matmul(const Matrix<T>& mat1, const Matrix<T>& mat2);

	//filing diagonal with ones. Function needed for compute_grad function.
	void fill_diagonal();

	//compute_grad function
	Matrix<T> compute_grad(const Matrix<T>& matX, const Matrix<T>& matY);

};

#include "CMake_MatrixClass.cpp"
#endif
