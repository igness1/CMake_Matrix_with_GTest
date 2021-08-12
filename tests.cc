#include <gtest/gtest.h>
#include "CMake_MatrixClass.hpp"


TEST(MatrixTest, Matrix_Assignment) {

	Matrix<int> m(2, 2);
	m(0, 0) = 2;
	m(0, 1) = 1;
	m(1, 0) = 3;
	m(1, 1) = -1;

	Matrix<int> b = m;
	for (unsigned i = 0; i < b.get_rows(); i++) {
		for (unsigned j = 0; j < b.get_cols(); j++) {
			EXPECT_EQ(m(i, j), b(i, j));
		}
	}
}
TEST(MatrixTest, Get_Individual_Element) {
	Matrix<int> m(2, 2);
	m(0, 0) = 2;
	m(0, 1) = 1;
	m(1, 0) = 3;
	m(1, 1) = -1;

	EXPECT_EQ(m(0, 0), 2);
	EXPECT_EQ(m(0, 1), 1);
	EXPECT_EQ(m(1, 0), 3);
	EXPECT_EQ(m(1, 1), -1);
}

TEST(MatrixTest, Multiplication_By_Star) {
	Matrix<double> m(1, 2);
	m(0, 0) = 4.0;
	m(0, 1) = 1.5;

	Matrix<double> a(2, 1);
	a(0, 0) = 9.1;
	a(1, 0) = 1.0;

	Matrix<double> c = m * a;

	EXPECT_EQ(c(0, 0), 37.9);

}

TEST(MatrixTest, Multiplication_Like_Matmul) {
	Matrix<double> m(1, 2);
	m(0, 0) = 4.0;
	m(0, 1) = 1.5;

	Matrix<double> a(2, 1);
	a(0, 0) = 9.1;
	a(1, 0) = 1.0;

	Matrix<double> c = c.matmul(m, a);

	EXPECT_EQ(c(0, 0), 37.9);
}

TEST(MatrixTest, Compute_Grad) {
	Matrix<double> m(1, 2);
	m(0, 0) = 4.0;
	m(0, 1) = 1.5;

	Matrix<double> a(2, 1);
	a(0, 0) = 9.1;
	a(1, 0) = 1.0;

	Matrix<double> c = c.matmul(m, a);

	Matrix<double> compute_grad_m = compute_grad_m.compute_grad(m, a);

	EXPECT_EQ(compute_grad_m(0, 0), 9.1);
	EXPECT_EQ(compute_grad_m(1, 0), 1.0);
}

