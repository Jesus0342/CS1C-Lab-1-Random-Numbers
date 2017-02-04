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
 * GenerateRandomNums
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums - The numbers in the array do not have to be previously
 *      			 defined.
 * POST-CONDITIONS:
 *      This function will generate 25 random integers and store them in an
 *      array.
 *****************************************************************************/
void GenerateRandomNums(int randomNums[])
{
	/*************************************************************************
	 * PROCESSING - This for loop calls the rand() function in order to
	 * 				generate a random integer and stores that integer in the
	 * 				current index of the array being accessed.
	 ************************************************************************/
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		randomNums[index] = rand() % MAX_RAND + 1;
	}
} // end of GenerateRandomNums

/******************************************************************************
 * SortRandomNums
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums - The numbers in the array must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will sort the numbers in the randomNums array in
 *      ascending numerical order.
 *****************************************************************************/
void SortRandomNums(int randomNums[])
{
	int smallestIndex; // PROCESSING - Index of smallest number
	int compIndex;     // PROCESSING - Index of number being compared to
					   // 			   smallest number

	/**************************************************************************
	 * This for loop sorts the numbers in the randomNums array in ascending
	 * numerical order.
	 *************************************************************************/
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		// Assigns the current index to smallestIndex to ensure that numbers that
		// have been previously sorted to the front of the array are not
		// accessed again.
		smallestIndex = index;

		// Assigns the comparison index to the index after the current index in
		// order to ensure that smallestIndex is always compared to all
		// subsequent numbers.
		compIndex = index + 1;

		/*********************************************************************
		 * This while loop compares the number in the starting index to all
		 * subsequent numbers in order to find the smallest number.
		 ********************************************************************/
		while(compIndex < MAX_INTEGERS)
		{
			/*****************************************************************
			 * This if-else statement compares the current smallest number to
			 * the next number. If the next number is larger, the index the
			 * smallest number is compared to is incremented to the next
			 * index, else the next number becomes the new smallest number and
			 * the comparison index is incremented so that the new smallest
			 * number will be compared to the next number during the loop's
			 * next iteration and so on.
			 ****************************************************************/
			if(randomNums[smallestIndex] < randomNums[compIndex])
			{
				compIndex++;
			}
			else
			{
				swap(smallestIndex, compIndex);

				compIndex++;
			}
		}

		// Swaps the smallest number in the rest of the list with the number
		// in the current index to push the smallest number to the front of
		// the list, while still being after all numbers smaller than it.
		swap(randomNums[index], randomNums[smallestIndex]);
	}
} // end of SortRandomNums

/******************************************************************************
 * ConvertIntToString
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums  - The numbers in the array must be previously defined.
 *      reverseNums - The numbers in the array are not previously defined.
 *
 * POST-CONDITIONS:
 *      This function will convert all integers in randomNums into strings by
 *      writing the integers into a file and reading them back as strings into
 *      reverseNums.
  *****************************************************************************/
void ConvertIntToString(int randomNums[], string reverseNums[])
{
	stringstream convert; // Holds the integer value to be converted into a string

	/***************************************************************************
	 * This for loop reads the integer to be converted into the stringstream
	 * variable and assigns that integer to the reverseNums array as a string.
	 * Then, it clears the stringstream variable so that later strings do
	 * not concatenate.
	 **************************************************************************/
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		convert << randomNums[index];

		reverseNums[index] = convert.str();

		// Clears the string
		convert.str("");
	}
} // end of ConvertIntToString

/******************************************************************************
 * ReverseNums
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums  - The numbers in the array must be previously defined.
 *      reverseNums - The numbers in the array do not have to be previously
 *      			  defined.
 *
 * POST-CONDITIONS:
 *      This function will reverse the digits of the numbers in the randomNums
 *      array and store then in the reverseNums array.
 *****************************************************************************/
void ReverseNums(int randomNums[], string reverseNums[])
{
	ConvertIntToString(randomNums, reverseNums);
	/**************************************************************************
	* This for loop reverses the digits of numbers greater than 10 by
	* swaping the digits in the first and second indexes.
	*************************************************************************/
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		if(randomNums[index] >= 10)
		{
			swap(reverseNums[index][0], reverseNums[index][1]);
		}
	}
} // end of ReverseNums

/******************************************************************************
 * SumDigits
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums - The numbers in the array must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will sort the numbers in the randomNums array in
 *      ascending numerical order.
 *****************************************************************************/
void SumDigits(int randomNums[], int digitSums[])
{
	/**************************************************************************
	 * This for loop sums the digits of each of the numbers stored in the
	 * randomNums array.
	 *************************************************************************/
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		/**********************************************************************
		 * This if-else statement assigns single digit numbers directly to the
		 * digitSums array. For two-digit numbers, the number is divided by 10
		 * and moded by 10 in order to produce the digit in the tens and ones
		 * place respectively. Then, the digits are added to produce their sum
		 * and stored in the digitSums array.
		 *********************************************************************/
		if(randomNums[index] < 10)
		{
			digitSums[index] = randomNums[index];
		}
		else
		{
			digitSums[index] = ((randomNums[index] / 10) + (randomNums[index] % 10));
		}
	}
} // end of SumDigits

/******************************************************************************
 * PrintArrays
 * ----------------------------------------------------------------------------
 * PRE-CONDITIONS:
 *      randomNums  - The numbers in the array must be previously defined.
 *      reverseNums - The numbers in the array must be previously defined.
 *      sumDigits   - The numbers in the array must be previously defined.
 *
 * POST-CONDITIONS:
 *      This function will output the numbers stored in each array.
 *****************************************************************************/
void PrintArrays(int randomNums[], string reverseNums[], int digitSums[])
{
	// Outputs the sorted random numbers.
	cout << "Here are " << MAX_INTEGERS
		 << " random numbers sorted in ascending order:\n";

	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		cout << randomNums[index] << " ";
	}

	// Outputs the sorted random numbers with their digits reversed.
	cout << "\n\nHere are the numbers with their digits reversed:\n";

	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		cout << reverseNums[index] << " ";
	}

	cout << endl << endl;

	// Outputs the sums of the digits of the random numbers.
	for(int index = 0; index < MAX_INTEGERS; index++)
	{
		cout << index + 1 << ") The sum of the digits of " << randomNums[index]
			 << " is " << digitSums[index]  << "\n";
	}
} // end of PrintArrays
