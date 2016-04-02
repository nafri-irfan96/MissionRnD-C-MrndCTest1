/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL)
		return NULL;

	int diff;
	float mul = 0;
	int i = 0;
	int result[6];
	for (i = 0; i < 6; i++)
	{
		result[i] = -1;

	}

	int j = 0, k = 0;
	int startIndex = 0; int endIndex = 1;
	int a = 4, b = 5;
	for (i = 0; i < len; i++)
	{
		if ((i + 1)<len)
			diff = arr[i + 1] - arr[i];
		if ((arr[i + 2] - arr[i + 1]) == diff && (i + 2) < len)
		{
			result[startIndex] = i;
			startIndex = 2;
			j = i; k = i + 1;
			while ((arr[k] - arr[j] == diff) && k<len)
			{
				k++;
				j++;
			}
			result[endIndex] = j;
			i = j-1;
			endIndex = 3;
			j = 0;
			k = 0;
		}
		if ((i + 1) < len)
		{
			mul = arr[i + 1] / arr[i];
		}
		if((arr[i + 2] / arr[i + 1]) == mul && (i + 2) < len)
		{
			result[a] = i;
			j = i; k = i + 1;
			while ((arr[k] / arr[j] == mul) && k < len)
			{
				k++;
				j++;
			}
			result[b] = j;
			j = 0;
			k = 0;
		}
	}
	return result;
}