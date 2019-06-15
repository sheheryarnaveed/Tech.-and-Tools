#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
  Matrix m1 = Matrix(3,4);
  Matrix m2 = Matrix(4,2);
  Matrix m3 = Matrix(3,2);
  cin >> m1 >> m2;
  cout << (m1 * -m2 * 0.5 + 1 * m3) << endl;
  return 0;
}

