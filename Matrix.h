#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
class Matrix {
private:
	unsigned rows;
	unsigned cols;
	vector<vector<T>> mat;
public:
	Matrix();
	Matrix(unsigned rows_, unsigned cols_, T init);
	Matrix(const Matrix& m);
	Matrix(const vector<vector<T>>& vect);
	~Matrix();

	class AnError {};

	unsigned get_rows() const;//return number of rows
	unsigned get_cols() const;//return number of columns

	vector<T>& diag_vec(Matrix& m);//diagonal vector of a matrix
	Matrix<T>& transpose();//matrix/vector transpose

	//Matrix Mathematical Operation
	Matrix<T>& operator+(Matrix& m); //Addition
	Matrix<T>& operator-(Matrix& m); //subtraction
	Matrix<T>& operator=(Matrix& m);  //equal to
	Matrix<T>& operator*(const Matrix& m); //multiplication
	Matrix<T>& operator*=(Matrix& m); //multiplication
	Matrix<T>& operator+=(Matrix& m);  //addition and equal to
	Matrix<T>& operator-=(Matrix& m);  //subtraction and equal to

	//Scalar Operation
	Matrix<T>& operator+(const int& a); //Addition
	Matrix<T>& operator-(const int& a); //subtraction
	Matrix<T>& operator*(const int& a); //multiplication
	Matrix<T>& operator/(const int& a); //division
	
	friend void print(Matrix& m) {
		for (int i = 0; i < m.get_rows(); i++) {
			for (int j = 0; j < m.get_cols(); j++) {
				cout << m.mat[i][j] << " ";
			}
			cout << endl;
		}
	}
	
};

#endif // !MATRIX_H

