/*
 *
 * # Title: Arrays and Vectors
 * # Description:
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 4-15-19
 */



#include <iostream>
#include <stdio.h>
#include <ctime>
#include <array>
#include <vector>


using namespace std;

/*
 # Vectors:
  A vector is similar to an array, in a sense where a series of elements are stored with the same variable name. Unlike arrays, vectors are dynamically sized, which is a major advantage.
*/

int size = 10;
int value = 2;

// First you must initialize the vector 
vector<int> testVector;

// You can also initialize the vector with a size
vector<int> sizedTestVector(size);

int main( ){
		// Add item to a vector
		testVector.push_back(value);

		// Accessing an index of vector
		cout << testVector[0] << endl;

		// Changing a value at a certain index
		testVector[4] = 20;
		cout << testVector[4] << endl;

		return (0);
	}