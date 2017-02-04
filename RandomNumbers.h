/******************************************************************************
* AUTHORS     : Jesus Sanchez & Michael Tuquero
* STUDENT IDS : 1024834 & 1035860
* LAB #1      : Random Numbers
* CLASS       : CS1C
* SECTION     : MW: 1:30pm
* DUE DATE    : 01/23/2017
* ****************************************************************************/

#ifndef RANDOMNUMBERS_H_
#define RANDOMNUMBERS_H_

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef int randomInts;

/******************************************************************************
 * CONSTANTS
 * ----------------------------------------------------------------------------
 * MAX_INTEGERS - The number of integers to be used
 * MAX_RAND     - The upper boundary of the random numbers generated
 *****************************************************************************/
const int MAX_INTEGERS = 25;
const int MAX_RAND     = 99;

/******************************************************************************
 * GenerateRandomNums
 *    This function generates 25 random integers between 1 and 99 and stores
 *    them in the randomNums array.
 *****************************************************************************/
void GenerateRandomNums(int randomNums[]);

/******************************************************************************
 * SortRandomNums
 *    This function sorts the numbers in the randomNums array in ascending
 *    numerical order.
 *****************************************************************************/
void SortRandomNums(int randomNums[]);

/******************************************************************************
 * ConvertIntToString
 *    This function converts the integers in randomNums to strings by using
 *    stringstream and stores them in the reverseNums array.
 *****************************************************************************/
void ConvertIntToString(int randomNums[], string reverseNums[]);

/******************************************************************************
 * ReverseNums
 *    This function reverses the digits of the numbers stored in the reverseNums
 *    array.
 *****************************************************************************/
void ReverseNums(int randomNums[], string reverseNums[]);

/******************************************************************************
 * SumDigits
 *    This function sums the digits of each of the numbers in the randomNums
 *    array.
 *****************************************************************************/
void SumDigits(int randomNums[], int digitSums[]);

/******************************************************************************
 * PrintArrays
 *    This function outputs the contents of all three arrays.
 *****************************************************************************/
void PrintArrays(int randomNums[], string reverseNums[], int digitSums[]);

#endif
