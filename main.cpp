/******************************************************************************
* AUTHORS     : Jesus Sanchez & Michael Tuquero
* STUDENT IDS : 1024834 & 1035860
* LAB #1      : Random Numbers
* CLASS       : CS1C
* SECTION     : MW: 1:30pm
* DUE DATE    : 01/23/2017
* ****************************************************************************/

#include "RandomNumbers.h"

/******************************************************************************
 * RANDOM NUMBERS
 *-----------------------------------------------------------------------------
 * This program will generate 25 random integers between 1 and 99. Then, it will
 * sort the numbers in ascending numerical order and store them in an array.
 * After that, the numbers will be reversed and the reversed numbers will be
 * stored in an array. The sum of the digits in the arrays will then be
 * calculated and stored in another array. Finally, the three arrays will be
 * printed.
 *-----------------------------------------------------------------------------
 * INPUTS:
 *    There are no inputs.
 *
 * OUTPUTS:
 *    randomNums  - Array holding the 25 random integers in ascending numerical
 *    				order.
 *    reverseNums - Array holding the reverse of the 25 random integers.
 *    digitSums   - Array holding the sums of each of the digits in numberAr.
 *****************************************************************************/
int main()
{
	randomInts randomNums[MAX_INTEGERS], digitSums[MAX_INTEGERS];
	string     reverseNums[MAX_INTEGERS] = {""};

	srand(time(NULL));

	GenerateRandomNums(randomNums);

	SortRandomNums(randomNums);

	ReverseNums(randomNums, reverseNums);

	SumDigits(randomNums, digitSums);

	PrintArrays(randomNums, reverseNums, digitSums);

	return 0;
}
