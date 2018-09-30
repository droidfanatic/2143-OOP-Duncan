#include <iostream>

using namespace std;

class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size);
	void pushBack(int item);
	void pushBack(int *ary, int size);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i<V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		//os<<"test"<<endl;
		return os;
	}

	// Adds each element of 2 vectors together and returns the values
	myVector operator+(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		// sets newVector index equal to larger index
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		//fills the newVector with elements from the rhsVector
		//adds elements of lhsVector to the elements of newVector
		if (max == rhsSize) {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = rhs.vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] += vPtr[i];
		}
		//fills the newVector with elements from the lhsVector
		//adds elements of rhsVector to the elements of newVector
		else {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] += rhs.vPtr[i];
		}

		return newVector;
	}

	// subtracts each element of 2 vectors together and returns the values
	myVector operator-(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		// sets newVector index equal to larger index
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		//fills the newVector with elements from the rhsVector
		//subtracts elements of lhsVector from the elements of newVector
		if (max == rhsSize){
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = rhs.vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] -= vPtr[i];
		}
		//fills the newVector with elements from the lhsVector
		//subtracts elements of rhsVector from the elements of newVector
		else {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] -= rhs.vPtr[i];
		}

		return newVector;
	}

	// multiplies each element of a vector by an integer and returns the value
	myVector operator*(int num) {
		int lhsSize = index;
		int max = lhsSize;

		myVector newVector(max);
		newVector.index = index;
		
		//fills the NewVector with elements from the lhsVector
		for (int i = 0; i < max; i++)
			newVector.vPtr[i] = vPtr[i];

		//multiplies each of the elements by an integer
		for (int i = 0; i < max; i++)
			newVector.vPtr[i] *= num;

		return newVector;
	}

	// multiplies each element of 2 vectors together and returns the values
	myVector operator*(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;


		// which vector is bigger?
		if (rhsSize > lhsSize) {
			max = rhsSize;
		}
		else {
			max = lhsSize;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		//fills the newVector with elements from the rhsVector
		//multiplies elements of newVector with the elements of lhsVector
		if (max == rhsSize) {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = rhs.vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] *= vPtr[i];
		}
		//fills the newVector with elements from the lhsVector
		//multiplies elements of newVector with the elements of rhsVector
		else {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] *= rhs.vPtr[i];
		}

		return newVector;
	}

	myVector operator/(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;


		// which vector is bigger?
		if (rhsSize > lhsSize)
			max = rhsSize;
		else
			max = lhsSize;

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		//fills the newVector with elements from the rhsVector
		//divides elements of newVector by the elements of lhsVector
		if (max == rhsSize) {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = rhs.vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] /= vPtr[i];
		}
		//fills the newVector with elements from the lhsVector
		//divides elements of newVector by the elements of rhsVector
		else {
			for (int i = 0; i < max; i++)
				newVector.vPtr[i] = vPtr[i];
			for (int i = 0; i < min; i++)
				newVector.vPtr[i] /= rhs.vPtr[i];
		}

		return newVector;
	}

	void operator=(const myVector& rhs) {

		index = rhs.index;

		//sets each element int the lhsVector to the same values as rhsVector
		for (int i = 0; i < index; i++)
			vPtr[i] = rhs.vPtr[i];
	}

	bool operator==(const myVector& rhs) {

		//Checks to see if the vectors are the same length
		if (index != rhs.index)
			return false;

		//Checks to see if all of the values are the same
		for (int i = 0; i < index; i++) {
			if (vPtr[i] != rhs.vPtr[i])
				return false;
		}

		//This returns true if and only if
		//the lengths are the same and all values are the same.
		return true;
	}
};
