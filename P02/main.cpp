/*
*Course: CMPS 2143 - OOP
*
*Purpose: uses overloaded operators to manipulate Vectors
*
*@author Daniel DayCee Duncan
*@version 1.1 10/1/18
*@github droidfanatic
*/

#include <iostream>
#include "myVector.h"

using namespace std;


int main() {
	myVector v1(10);
	myVector v2(20);
	myVector v3(10);

	v1.pushBack(8);
	// v1 contains: [8]

	v2.pushBack(10);
	v2.pushBack(20);
	v2.pushBack(30);
	// v2 contains: [10,20,30]

	// Declare some int array
	int A[] = { 1,2,3,4,5 };

	v1.pushBack(A, 5);
	// v1 contains: [8,1,2,3,4,5]

	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]

	cout << v1 << endl;
	// would print: [18,21,32,3,4,5] to standard out.

	cout << v1[2] << endl;
	// would print: 32 to standard out.

	v2 = v2 * 3;
	// v2 contains: [30,60,90]

	v3 = v2;
	// v3 contains: [30,60,90]

	v3 = v3 / v2;
	// v3 contains: [1,1,1]

	cout << v2 << endl;
	// should print: [30,60,90]

	cout << v3 << endl;
	// should print: [1,1,1]

	v3 = v3 - v1;
	// v3 contains: [17,20,31,3,4,5]

	cout << v3 << endl;
	// should print: [17,20,31,3,4,5]

	v2 = v2 * v1;
	// v2 contains: [540,1260,2880,3,4,5]

	cout << v2 << endl;
	// should print: [540,1260,2880,3,4,5]

	v2[2] = 100;
	// v2 contains: [540,1260,100,3,4,5]

	cout << v2 << endl;
	// should print: [540,1260,100,3,4,5]

	if (v2 == v1) {
		cout << "v2 and v1 are equal" << endl;
	}
	else {
		cout << "v2 and v1 are not equal" << endl;
	}

	system("pause");
}