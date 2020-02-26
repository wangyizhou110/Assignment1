#include <iostream>
#include "readarray.h"
#include "calculate.h"

using namespace std;

// A small main program to demonstrate the way the read_int_as_array
// function works. The program reads a long integer from the keyboard,
// and then displays the contents of the array.


int main()
{
	const int MAXSIZE = 50;
	int num1[MAXSIZE], num2[MAXSIZE], num3[MAXSIZE];
	bool success;
	int numdigits1, numdigits2;
	int count1, count2, count = 0 ;

	// initialise array entries to 0
	for (int i = 0; i < MAXSIZE; i++)
	{
		num3[i] = 0;
	}

	cout << "Enter a positive integer:" << endl;
	read_int_as_array(num1, MAXSIZE, numdigits1, success);

	if (success)
	{
		cout << "Valid input" << endl;
	}
	else
	{
		cout << "Invalid input" << endl;
	}

	count1 = numdigits1 - 1;

	cout << "Enter a positive integer:" << endl;
	read_int_as_array(num2, MAXSIZE, numdigits2, success);

	if (success)
	{
		cout << "Valid input" << endl;
	}
	else
	{
		cout << "Invalid input"  << endl;
	}

	count2 = numdigits2 - 1;
	//Judging whether the calculation result is positive or negative
	//If the length of the first array is greater than the second, the result is a positive number
	if (numdigits1 > numdigits2)
	{
		cout << "the result is: ";
		calculate(count,count1, count2, num1, num2, num3);
	}
	//If the length of the first array is less than the second array, the result is negative
	if (numdigits1 < numdigits2)
	{
		cout << "the result is: "<< "-";
		calculate(count,count2, count1, num2, num1, num3);
	}
	//If the two arrays are equal in length, 
	//the size of the numbers in the corresponding positions of the two arrays needs to be started from the highest bit.
	if(numdigits1 == numdigits2)
	{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (num1[i] > num2[i])
				break;
			if (num1[i] < num2[i])
			{
				cout << "the result is: " << "-";
				calculate(count,count2, count1, num2, num1, num3);
				return 0;
			}
		}
		cout << "the result is: ";
		calculate(count,count1, count2, num1, num2, num3);
	}
	return 0;
}

