// pascalMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
//////////////////////////////////////////
class storage {
protected:
	//number of rows
	int storRows;
	vector<int>pMatrix;

	//there's i+1 elements in each row
	//ith row times the i+1 amount of elements
	//shifting j elements to right to the element of interest
	int index(int i, int j) {
		//position of the specific element in the matrix
		return ((i * (i + 1)) / 2) + j;
	}

	/*grow the triangle vector to the new row that has the coefficient
	of interest*/
	void grow(int extraRows) {
		int nSize = extraRows * (extraRows + 1) / 2;
		//expand vector to the new elements
		pMatrix.resize(nSize);
		//the vector is now remade with the number of rows being the extra rows needed
		storRows = extraRows;
	}

public:
	//constructor
	storage(int n) : storRows(n) {
		//total amount of elements in the triangle
		int size = n * (n + 1) / 2;
		//remake the matrix with just the right amount of elements
		pMatrix.resize(size);
	}
	//return the amount of rows in storage
	int getRows() {
		return storRows;
	}

};
/////////////////////////////////////////////////////////////////////////////////////////////////////
//pascal class
class pascal : public storage {
private:
	//number of filled rows
	int numFillRows;

	//calculate the binomial coeffecient
	int biCoeff(int n, int k) {

		//if we're at the top or sides of the triangle
		int coeff = 1;

		//do this instead of double recursion; it's less taxing
		//C(n,k)=C(n,n-k) -- using the fact that choosing k elements from a set is the same as
		//not choosing n-k elements from a set
		if (k > n - k) {
			k = n - k;
		}
		//factorials
		for (int i = 0; i < k ; ++i) {
			coeff *= (n - i); //n!
			coeff /= (i + 1); // div by k!*(n-k)!
		}

		return coeff;
	}

	//sets value in storage
	void setVal(int i, int j, int val) {
		if (i < storRows && j <= i) {
			pMatrix[index(i, j)] = val;
		}
	}

	//method to get a specific value from storage
	int getVal(int i, int j) {
		if (i < storRows && j<=i) {
			return pMatrix[index(i, j)];
		}
		//invalid index
		return -1;
	}

	
public:
	//constructor
	pascal(int n) : storage(n), numFillRows(0) {
		expand(n);
	}

	//print pascal's triangle
	void print() {
		int index = 0;
		for (int i = 0; i < numFillRows; ++i) {
			for (int j = 0; j <= i; ++j) {
				cout<<getVal(i,j) << " ";
			}
			cout << endl;
		}

	}

	
	//grow the triangle to the row of interest
	void expand(int newRows) {
		if (newRows > numFillRows) {
			grow(newRows);

			//calculate the values in these new rows
			//start at the last row
			for (int i = numFillRows; i < newRows; ++i) {
				for (int j = 0; j <= i; j++) {
					setVal(i, j, biCoeff(i, j));
				}
			}

			//update the amount of rows we have
			numFillRows = newRows;
		}
	}

	//will expand the triangle until we reach the value the 
	//requested value is on, then it'll return that value
	int getCoeff(int i, int j) {
		if (i >= numFillRows) {
			//expand triangle
			expand(i + 1);
		}
		return getVal(i, j);
	}
};

/// ///////////////////


int main()
{
	int n = 3;
	pascal pascalT(n);

	pascalT.print(); 

	pascalT.getCoeff(9, 2);

	pascalT.print();
	
	return 0;
}

