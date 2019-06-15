#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include<string>
using namespace std;

Matrix::Matrix(int r, int c)
{
    if(r<=0 || c<=0){
        cout << "Invalid number of rows or columns!" << endl;
        exit(0);
    }
    row = r;
    column = c;
    entries = new float*[row];
    for(int i = 0; i < row; i++){
        entries[i] = new float[column];
    }

    for(int i = 0; i < row; i++){
        for(int w = 0; w < column; w++){
            entries[i][w] = 0;
        }
    }


}

ostream& operator<<(ostream& cout, const Matrix& m){
    for(int i = 0; i < m.row; i++){
        for(int w = 0; w < m.column; w++){
            cout << m.entries[i][w];
            if(w != m.column-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return cout;
}

istream& operator>>(istream& cin, Matrix& m){
    string s;
    getline(cin, s);
    string temp="";
    int space = 0;
    for(int k=0; k<int(s.length()); k++){
        if(s[k] == ' '){
            space+=1;
        }
    }
    string* arr = new string[space+1];
    int i=0;
    for(int k=0; k<int(s.length()); k++){
        if(s[k] == ' '){
            arr[i]=temp;
            temp="";
            i++;
        }
        else{
            temp+=s[k];
        }
    }
    arr[i] = temp;
    int k = 0;
    for(int i = 0; i < m.row; i++){
        for(int w = 0; w < m.column; w++){
            m.entries[i][w] = stof(arr[k]);
            k++;
        }
    }
    return cin;
}


float Matrix::get_entry(int r, int c){
    if(row <= r || r < 0 || column <= c || c < 0){
        cout << "Index out of range!" << endl;
        exit(0);
    }
    return entries[r][c];
}

int Matrix::get_row_dimension(){
    return row;
}

int Matrix::get_column_dimension(){
    return column;
}


void Matrix::row_switching(int i, int j){
    if(row <= i || i < 0 || row <= j || j < 0){
        cout << "Index out of range!" << endl;
        exit(0);
    }

    float *temp = new float[column];
    for(int k = 0; k<column; k++){
        temp[k] = entries[i][k];
    }
    for(int k = 0; k<column; k++){
        entries[i][k] = entries[j][k];
    }
    for(int k = 0; k<column; k++){
        entries[j][k] = temp[k];
    }

}

void Matrix::row_multiplication(int i, float k){
    if(row <= i || i < 0){
        cout << "Index out of range!" << endl;
        exit(0);
    }

    if(k == 0){
        cout << "Cannot be multiplied by a zero constant!" << endl;
        exit(0);
    }

    for(int c = 0; c<column; c++){
        entries[i][c] = (entries[i][c])*k;
    }
}

void Matrix::row_addition(int i, int j, float k){
    if(row <= i || i < 0 || row <= j || j < 0){
        cout << "Index out of range!" << endl;
        exit(0);
    }

    if(i == j){
        cout << "Cannot be the same row!" << endl;
        exit(0);
    }

    float *temp = new float[column];
    for(int c = 0; c<column; c++){
        temp[c] = entries[j][c]*k;
    }

    for(int c = 0; c<column; c++){
         entries[i][c] += temp[c];
    }

}

void Matrix::transpose(){
    float** temp = new float*[row];
    for(int i = 0; i < row; i++){
        temp[i] = new float[column];
    }

    for(int i = 0; i < row; i++){
        for(int w = 0; w < column; w++){
            temp[i][w] = entries[i][w];
        }
    }

    for(int i = 0; i < row; i++){
        delete[] entries[i];
    }
    delete[] entries;

    entries = new float*[column];
    for(int i = 0; i < column; i++){
        entries[i] = new float[row];
    }

    for(int i = 0; i < column; i++){
        for(int w = 0; w < row; w++){
            entries[i][w] = temp[w][i];
        }
    }

    for(int i = 0; i < row; i++){
        delete[] temp[i];
    }
    delete[] temp;

    int t = column;
    column = row;
    row = t;
}

Matrix operator+(const Matrix & m1, const Matrix & m2){

    if(m2.row != m1.row || m2.column != m1.column){
        cout << "Cannot do the matrix addition!" << endl;
        exit(0);
    }

    Matrix x = Matrix(m1.row, m1.column);
    for(int i = 0; i < m1.row; i++){
        for(int w = 0; w < m1.column; w++){
            x.entries[i][w] = m1.entries[i][w] + m2.entries[i][w];
        }
    }

    return x;
}


Matrix operator*(const float c, const Matrix & m){

    Matrix x = Matrix(m.row, m.column);

    for(int i = 0; i < m.row; i++){
        for(int w = 0; w < m.column; w++){
            x.entries[i][w] = m.entries[i][w]*c;
        }
    }

    return x;
}

Matrix operator*(const Matrix & m, const float c){

    Matrix x = Matrix(m.row, m.column);

    for(int i = 0; i < m.row; i++){
        for(int w = 0; w < m.column; w++){
            x.entries[i][w] = m.entries[i][w]*c;
        }
    }

    return x;
}

Matrix operator*(const Matrix & m1,const Matrix & m2){

    if(m2.row != m1.column){
        cout << "Cannot do the matrix multiplication!" << endl;
        exit(0);
    }

    Matrix x = Matrix(m1.row, m2.column);

    int r = 0;
    int c = 0;
    float value = 0;
    for(int i = 0; i < x.row; i++){
            r = i;
        for(int w = 0; w < x.column; w++){
            c = w;
            for(int k = 0; k < m1.column; k++){
                value += m1.entries[r][k] * m2.entries[k][c];
            }
            x.entries[i][w] = value;
            value=0;
        }
    }

    return x;
}

Matrix Matrix::operator-() const{
    Matrix x = Matrix(row, column);

    for(int i = 0; i < row; i++){
        for(int w = 0; w < column; w++){
            x.entries[i][w] = entries[i][w] * -1;
        }
    }
    return x;
}


