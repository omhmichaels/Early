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
#include <cmath>

using namespace std;

// UNUSED Rounding function for extremely large ints
int rounder(int number) {
	number = number * .00001;
	number = round(number);
	return int(number);

}

// UNUSED Function to calculate number of digits
int numDigits(int i){
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

// User Input
int getInput() {
	int userInput;
	cout << "To check for the nth number of the sequence,\n input a positive integer between 1 - 100: \n";
	cin >> userInput;
	return abs(userInput-1);
}

// Pull nth Number
unsigned long long int findNthNumber(int nthNumber, unsigned long long int *arraySequence) {
	return arraySequence[nthNumber];
}
// Build Finobachi Array
unsigned long long int * finobachiSequence() {
	cout << "WARNING: Numbers exceeding 20 digits are rounded to contain 19-20 digits";
	unsigned long long int  f1 = 1;
	unsigned long long int  f2 = 1;
	unsigned long long int  next = 0;
	const int ARRAY_SIZE = 100;
	static unsigned long long int *storageArray = new unsigned long long int [100] ;

/* DEBUGGER
	printf("f1 is %i, f2 is %i , i is %i, next is %i, storageArray[i] is %i \n____________\n", f1, f2, next, storageArray);
*/

	storageArray[0] = 1;
	for (int i = 1; i <= ARRAY_SIZE; i++) {

		next = f1 + f2;
		f1 = f2;
		f2 = next;
		
		storageArray[i] = f1;
	
	/* Error Check
		printf("#2_______________\nf1 is %i, f2 is %i , i is %i, next is %i, storageArray[i] is %i \n____________\n", f1, f2,i, next, storageArray[i]);
	*/
	}/*
	for (int i = 0; i <= ARRAY_SIZE; i++) {
		cout << storageArray[i] << endl << "____\n"<< i << endl;
	}*/
	return storageArray;
}





// MAIN PROGRAM
int main(){
	unsigned long long int * finobachiArray;
	finobachiArray = finobachiSequence();

	int  userInput = getInput();
	unsigned long long int nthNumber = findNthNumber(userInput, finobachiArray);
	cout << "The " << userInput+1 << "nth number of the sequence is " << nthNumber << endl;
/*
	// Check to ensure proper storage of values
	for (int i = 0; i <= 100; i++) {
		cout << finobachiArray[i] << endl;
	}
*/
	return (0);
}