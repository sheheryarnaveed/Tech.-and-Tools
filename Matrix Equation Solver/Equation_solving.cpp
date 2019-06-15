#include <cmath>
#include "Equation_solving.h"

using namespace std;


void Display_equation(Matrix m)
{
  for(int r = 0; r < m.get_row_dimension(); r ++)
  {
    bool first = true;
    for (int c = 0; c < m.get_column_dimension() - 1; c ++)
    {
      if (m.get_entry(r,c) != 0)
      {
        if (first)
        {
          cout << m.get_entry(r,c) << "*x" << (c + 1);
        }
        else
        {
          cout << " ";
          if (m.get_entry(r,c) > 0)
          {
            cout << "+ " << m.get_entry(r,c) << "*x" << (c + 1);
          }
          else if (m.get_entry(r,c) < 0)
          {
            cout << "- " << abs(m.get_entry(r,c)) << "*x" << (c + 1);
          }
        }
      }
      first = false;
    }
    cout << " = " << m.get_entry(r, m.get_column_dimension() - 1) << endl;
  }
}

void Gaussian_elimination(Matrix& m)
{
  int i = 0, j = 0;
  while (i < m.get_row_dimension() && j < m.get_column_dimension())
  {
    int max_i = i;
    for (int k = i + 1; k < m.get_row_dimension(); k ++)
    {
      if (abs(m.get_entry(k, j)) > abs(m.get_entry(max_i, j)))
        max_i = k;
    }
    if (m.get_entry(max_i, j) != 0)
    {
      m.row_switching(max_i, i);
      m.row_multiplication(i, 1 / m.get_entry(i,j));
      for (int u = i + 1; u < m.get_row_dimension(); u ++)
      {
        m.row_addition(u, i, -1 * m.get_entry(u,j));
      }
      i = i + 1;
    }
    j = j + 1;
  }
}

void Solution(Matrix m)
{
  float * solution = new float [m.get_row_dimension()];
  for (int r = m.get_row_dimension() - 1; r >= 0; r --)
  {
    float sum = 0;
    for (int c = m.get_column_dimension() - 2; c > r; c --)
    {
      sum += solution[c] * m.get_entry(r,c);
    }
    solution[r] = m.get_entry(r, m.get_column_dimension() - 1) - sum;
  }
  for (int r = 0; r < m.get_row_dimension(); r ++)
  {
    cout << "x" << (r + 1) << " = " << solution[r] << "  ";
  }
  delete [] solution;
}

