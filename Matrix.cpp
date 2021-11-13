#include"Matrix.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
unsigned Matrix<T>::get_rows() const {
	return this->rows;
}
template<class T>
unsigned Matrix<T>::get_cols() const {
	return this->cols;
}

template<class T>
Matrix<T>::Matrix() {
	this->rows = 0;
	this->cols = 0;
	this->mat.resize(rows, vector<T>(cols, 0.0));
}

template<class T>
Matrix<T>::Matrix(unsigned rows_, unsigned cols_, T init) {
	this->rows = rows_;
	this->cols = cols_;
	this->mat.resize(rows, vector<double>(cols, init));
}

template<class T>
Matrix<T>::Matrix(const Matrix& m) {
	this->rows = m.get_rows();
	this->cols = m.get_cols();
	this->mat = m.mat;
}
template<class T>
Matrix<T>::Matrix(const vector<vector<T>>& vect) {
	this->mat.resize(vect.size(), vector<T>(vect[0].size(), 0.0));
	this->rows = vect.size();
	this->cols = vect[0].size();
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j < vect[0].size(); j++) {
			this->mat[i][j] = vect[i][j];
		}
	}
}
template<class T>
Matrix<T>::~Matrix() {
	this->mat.clear();
}

template<class T>
vector<T>& Matrix<T>::diag_vec(Matrix& m) {
	try {
		if (m.get_rows() == m.get_cols()) {
			vector<T> result(m.get_rows(), 0.0);
			for (int i = 0; i < m.get_rows(); i++) {
				//result.m[i]=a.m[i][i];

				result[i] = m.mat[i][i];
				cout << m.mat[i][i];
				cout << "\n";
			}
			return result;
		}
		else {
			throw AnError();
		}
	}

	catch (AnError a) {
		cout << "Columns and Row do not match";
	}


}

template<class T>
Matrix<T>& Matrix<T>::transpose() {
	// cout<<"TRanspose is:"<<endl;
	vector<vector<double>> ab;
	for (int i = 0; i < this->get_cols(); ++i) {
		for (int j = 0; j < this->get_rows(); ++j) {
			//cout<<this->mat[j][i]<<" ";
		}
		//cout<<endl;

	}
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix& m) {


	try {
		if (this->rows == m.get_rows() && this->cols == m.get_cols()) {
			Matrix result(m.get_rows(), m.get_cols(), 0.0);
			T temp;
			for (int i = 0; i < this->get_rows(); i++) {
				for (int j = 0; j < this->get_cols(); j++) {
					temp = this->mat[i][j] + m.mat[i][j];
					result.mat[i][j] = temp;
				}
			}
			return *this = result;

			//result=this+m;
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix& m) {

	try {
		if (this->rows == m.get_rows() && this->cols == m.get_cols()) {
			Matrix result(m.get_rows(), m.get_cols(), 0.0);
			T temp;
			for (int i = 0; i < this->get_rows(); i++) {
				for (int j = 0; j < this->get_cols(); j++) {
					temp = this->mat[i][j] - m.mat[i][j];
					result.mat[i][j] = temp;
				}
			}
			return *this = result;
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix& m) {
	if (this->mat == m.mat) {
		//  cout<<endl<<"Same data function"<<endl;
		return *this;
	}
	this->mat.clear();
	//cout<<endl<<"Not Same data function"<<endl;
	unsigned new_rows = m.get_rows();
	unsigned new_cols = m.get_cols();
	mat.resize(new_rows);

	for (unsigned i = 0; i < mat.size(); i++) {
		this->mat[i].resize(new_cols);
	}
	this->rows = new_rows;
	this->cols = new_cols;


	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			this->mat[i][j] = m.mat[i][j];
			//cout<<mat[i][j]<<" ";
		}
		//cout<<endl;
	}


	return *this = m;
}
template<class T>
Matrix<T>& Matrix<T>::operator*(const Matrix& m) {

	try {
		if (this->mat[0].size() == m.mat.size()) {
			Matrix result(this->mat.size(), m.mat[0].size(), 0);
			const int N = this->mat[0].size();
			for (int i = 0; i < this->mat.size(); i++) {
				T total = 0;
				for (int j = 0; j < m.mat[0].size(); j++) {
					total = 0;
					for (int k = 0; k < this->mat[0].size(); k++) {
						total += this->mat[i][k] * m.mat[k][j];
					}
					result.mat[i][j] = total;
					cout << total << " ";
				}
				cout << endl;
			}
			return *this = result;
			//this->mat.clear();
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}

}

template<class T>
Matrix<T>& Matrix<T>::operator*=(Matrix& m) {
	try {
		if (this->mat[0].size() == m.mat.size()) {
			Matrix result(this->mat.size(), m.mat[0].size(), 0);
			const int N = this->mat[0].size();
			for (int i = 0; i < this->mat.size(); i++) {
				T total = 0;
				for (int j = 0; j < m.mat[0].size(); j++) {
					total = 0;
					for (int k = 0; k < this->mat[0].size(); k++) {
						total += this->mat[i][k] * m.mat[k][j];
					}
					result.mat[i][j] = total;
					//cout << total << " ";
				}
				//cout << endl;
			}
			return (*this = result);
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(Matrix& m) {
	try {
		if (this->get_rows() == m.get_rows() && this->get_cols() == m.get_cols()) {
			for (int i = 0; i < this->get_rows(); i++) {
				for (int j = 0; j < this->get_cols(); j++) {
					this->mat[i][j] += m.mat[i][j];	
				}
			}
			return *this;
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(Matrix& m) {
	try {
		if (this->get_rows() == m.get_rows() && this->get_cols() == m.get_cols()) {
			for (int i = 0; i < this->get_rows(); i++) {
				for (int j = 0; j < this->get_cols(); j++) {
					this->mat[i][j] -= m.mat[i][j];
					
				}
			}
			return *this;
		}
		else {
			throw AnError();
		}
	}
	catch (AnError a) {
		cout << "Columns and Row do not match";
	}
}

//Scalar Operations
template<class T>
Matrix<T>& Matrix<T>::operator+(const int& a) {
	for (int i = 0; i < this->get_rows(); i++) {
		for (int j = 0; j < this->get_cols(); j++) {
			this->mat[i][j] += a;
		}
	}
	return *this;
} //Addition
template<class T>
Matrix<T>& Matrix<T>:: operator-(const int& a) {
	for (int i = 0; i < this->get_rows(); i++) {
		for (int j = 0; j < this->get_cols(); j++) {
			this->mat[i][j] -= a;
			//cout<<this->mat[i][j]<<" ";
		}
		//cout<<endl;
	}
	return *this;

}//subtraction
template<class T>
Matrix<T>& Matrix<T>::operator*(const int& a) {
	for (int i = 0; i < this->get_rows(); i++) {
		for (int j = 0; j < this->get_cols(); j++) {
			this->mat[i][j] *= a;
			//cout<<this->mat[i][j]<<" ";
		}
		//cout<<endl;
	}
	return *this;

} //multiplication
template<class T>
Matrix<T>& Matrix<T>::operator/(const int& a) {

	for (int i = 0; i < this->get_rows(); i++) {
		for (int j = 0; j < this->get_cols(); j++) {
			this->mat[i][j] /= a;
			//cout<<this->mat[i][j]<<" ";
		}
		//cout<<endl;
	}
	return *this;
}
