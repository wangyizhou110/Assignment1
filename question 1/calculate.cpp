#include "calculate.h"



//the function to calculate the difference, num1[] is minuend, num2[] is subtracter, num3[] is the result. 
void calculate(int &count, int count1, int count2, int num1[], int num2[], int num3[])
{
	// k is the position of number in the array num3[].  borrow is the borrow digit.
	int k = 0, borrow = 1, a = 1;
	//When the number of calculations in one of the arrays runs out, the calculation ends.
	while (count1 >= 0 && count2 >= 0)
	{
		//Calculate from the least significant bit.
		// When the number of the least significant bit in the first 
		//array is greater than or equal to the number of the corresponding position in the second array, subtract directly.
		if (num1[count1] >= num2[count2])
		{
			//The result is placed in the least significant bit of the third array
			num3[k] = num1[count1] - num2[count2];
		}
		else
		{
			//When the second number is greater than the first, 
			//the number above is borrowed one digit forward, 
			//if the previous number is 0, it continues to borrow forward.
			while (num1[count1 - borrow] == 0)
			{
				borrow++;
			}
			//After borrowing, 10 plus original deductible as deductible。
			num3[k] = 10 - num2[count2] + num1[count1];
			//If the borrowed number is not zero, it minus 1.
			num1[count1 - borrow] = num1[count1 - borrow] - 1;
			//Where the number is 0, change 0 to 9
			while (a != borrow)
			{
				num1[count1 - a] = 9;
				a++;
			}
		}
		//Calculate the next digit.
		count1--; count2--, k++;
	}

	//When the calculation of the short size array is finished, 
	//the remaining numbers of the long size array are placed in the remaining positions of the result array.
	while (count1 >= 0)
	{
		num3[k] = num1[count1];
		k++; count1--;
	}

	//Exclude meaningless numbers 0 before results
	int i = k;
	while (num3[i] == 0)
	{
		i--;
	}

	//Print the results. 
	while (i >= 0)
	{
		cout << num3[i];
		i--;
	}

	return;
}
