#include "Matrices.h"
namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;

		a.resize(rows);
		for (size_t i = 0; i < rows; i++)
		{
			a.at(i).resize(cols, 0);
		}
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		// if we get here, then teh dimensions must match
		Matrix c(a.getRows(), a.getCols());
		// loop through each cell, assign each sum to cij
		for (int i = 0; i < a.getRows() - 1; i++)
		{
			for (int j = 0; a.getCols() - 1; j++)
			{
				c(i, j) = a(i, j) + b(i, j);
			}
		}

		return c;
	}
	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		return Matrix(0, 0);
	}
	bool operator==(const Matrix& a, const Matrix& b)
	{
		return false;
	}
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return false;
	}
	ostream& operator<<(ostream& os, const Matrix& a)
	{
		return os;
	}
}