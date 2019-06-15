#include<iostream>
#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{
    public:
        Matrix(int r, int c);
        friend ostream& operator<<(ostream& cout, const Matrix& m);
        friend istream& operator>>(istream& cin, Matrix& m);
        float get_entry(int r, int c);
        int get_row_dimension();
        int get_column_dimension();
        void row_switching(int i, int j);
        void row_multiplication(int i, float k);
        void row_addition(int i, int j, float k);
        void transpose();
        friend Matrix operator+(const Matrix & m1, const Matrix & m2);
        friend Matrix operator*(const Matrix & m, const float c);
        friend Matrix operator*(const float c, const Matrix & m);
        friend Matrix operator*(const Matrix & m1,const Matrix & m2);
        Matrix operator-() const;


    private:
        int row;
        int column;
        float** entries;

};

ostream& operator<<(ostream& cout, const Matrix& m);
istream& operator>>(istream& cin, Matrix& m);
Matrix operator+(const Matrix & m1, const Matrix & m2);
Matrix operator*(const Matrix & m, const float c);
Matrix operator*(const float c, const Matrix & m);
Matrix operator*(const Matrix & m1,const Matrix & m2);

#endif // MATRIX_H
