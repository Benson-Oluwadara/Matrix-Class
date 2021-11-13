#include"Matrix.h"
#include"Matrix.cpp"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<vector<double>> t = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<double>> x = { {3,2,1},{6,5,4},{9,8,7} };
    Matrix<double> c(t);
    Matrix<double> d(x);
    Matrix<double> e;

    cout << endl << "Printed Matrix C:" << endl;
    print(c);
    cout << endl << "Printed Matrix D:" << endl;
    print(d);
    cout << "\nAddition of matrix\n";
    e = c + d;
    print(e);

    cout << "\nSubtraction of matrix\n";
    e = c - d;
    print(e);

    cout << "\nDiagonal Vector\n";
    e.diag_vec(c);

    cout << "\nMultiplication of Matrix\n";
    
    e = c * d;
    print(e);

    cout << "\n addition and equal to\n";
    c += d;
    print(c);

    cout << "\n subtraction and equal to\n";
    c -= d;
    print(c);

	return  0;
}