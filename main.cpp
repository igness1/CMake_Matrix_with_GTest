#include "CMake_MatrixClass.hpp"
#include <iostream>
using namespace std;

void main() {

	Matrix<int> mat1(2, 3);
	Matrix<int> mat2(3, 2);
	mat1(0, 0) = 2;
	mat1(0, 1) = 1;
	mat1(0, 2) = 3;
	mat1(1, 0) = -1;
	mat1(1, 1) = 2;
	mat1(1, 2) = 4;

	mat2(0, 0) = 1;
	mat2(0, 1) = 3;
	mat2(1, 0) = 2;
	mat2(1, 1) = -2;
	mat2(2, 0) = -1;
	mat2(2, 1) = 4;


	cout << "Hello, this is matrix_1: " << endl;
	mat1.print_values();
	cout << "Hello, this is matrix_2: " << endl;
	mat2.print_values();

	Matrix<int> mat3;
	mat3 = mat3.matmul(mat1, mat2);

	cout << "Hello, this is result of multiplication of matrix_1(first input) with matrix2(second input)." << endl;
	mat3.print_values();


	Matrix<int> dZ_d_matrix1, dZ_d_matrix2;

	dZ_d_matrix1 = mat3.compute_grad(mat1, mat2);
	cout << "Hello, this is result of:  Partial derivatives of matrices multiplication" << endl;
	cout << " operation in regard to first input of matrix multiplication." << endl;

	dZ_d_matrix1.print_values();

	dZ_d_matrix2 = mat3.compute_grad(mat2, mat1);
	cout << "Hello, this is result of:  Partial derivatives of matrices multiplication" << endl;
	cout << " operation in regard to second input of matrix multiplication." << endl;

	dZ_d_matrix2.print_values();



	system("pause>0");
}