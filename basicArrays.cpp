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
# Arrays:
   Arrays are initialized with a size, and the size cannot be modified (Vectors, on the other hand, can be dynamically sized).
   C data type, and all elements in the array must be of this data type.

*/

/*
# Matrixs:
   A matrix (array defined by rows and columns) can also be created in the same way by adding a second set of square brackets where required (dataType[rows][columns]).
*/

// int array example
// Initialize to the size 
int size = 3;
int testArray[3]; 

// Matrix array example
int testMatrix[3][3];


int main() {
	testArray[0] = 1;
	testArray[1] = 2;
	testArray[2] = 3;
	testArray[3] = 4;
	for (int i = 0; i <= 3; i++) {
		cout << testArray[i];
	}
	
	for (int a,b = 0; a <= 3;a++) {
			b++;
			testMatrix[a][a] = b;
		//	cout << testMatrix[a][a] << endl;
		}
	cout << testMatrix;
	return (0);
}