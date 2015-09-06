#include<iostream>
#include<fstream>
using namespace std;


void selectionSortArray(int array[], int elems);
float meandisp(int array[], int len);
int binarySearch(int array[], int numElems, int value);



int main()
{
	fstream file;
	file.open("input.txt", ios::in|ios::out|ios::app);
	ofstream output;
	output.open("output.txt", ios::in | ios::out | ios::app);

	int unsorted_array[50];
	int len, val;
	int found;
	float mean;
	int sorted_array[50];
	int n=0;
	while (n <= 3)
	{
		file >> len;
		file >> val;

		for (int i = 0; i < len; i++)
		{
			file >> unsorted_array[i];
		}
		n++;
	}


	output << " Size of array     " << len << endl;
	output << " Entered array is  " << endl;
	for (int i = 0; i<len; i++)
	{
		output << unsorted_array[i] << " ";
	}
	output << endl;
	selectionSortArray(unsorted_array, len);

	output << " Sorted array is  " << endl;
	for (int i = 0; i<len; i++)
	{

		output << unsorted_array[i] << " " ;
	}
	for (int i = 0; i < len;i++)
	{
		cout << unsorted_array[i] << " ";

	}

	found = binarySearch(unsorted_array, len, val);
	output << endl;
	output << "The integer searched for is  " << val +10<< endl;
	if (found == 0)
	{
		output << "The value  " << val << "  is not in the list" << "     Position    " << -1 << endl;
	}
	else
	{
		output << "The value " << val << " is in position number " << found + 1 << " of the list" << endl;
	}

	mean = meandisp(unsorted_array, len);
	output << "Mean of the data is  " << mean;
	output << endl;

	char ch;
	cin >> ch;
}


void selectionSortArray(int array[], int elems)
{
	int seek; // array position currently being put in order int minCount; // location of smallest value found
	int minValue; // holds the smallest value found
	int minCount;
	for (seek = 0; seek < (elems - 1); seek++) // outer loop performs the swap
		// and then increments seek
	{
		minCount = seek;
		minValue = array[seek];
		for (int index = seek + 1; index < elems; index++)
		{
			// inner loop searches through array
			// starting at array[seek] searching
			// for the smallest value. When the
			// value is found, the subscript is
			// stored in minCount. The value is
			// stored in minValue.
			if (array[index] < minValue)
			{
				minValue = array[index];
				minCount = index;
			}
		}
		// the following two statements exchange the value of the
		// element currently needing the smallest value found in the
		// pass(indicated by seek) with the smallest value found
		// (located in minValue)
		array[minCount] = array[seek];
		array[seek] = minValue;
	}
}

int binarySearch(int array[], int numElems, int value)
{
	int first = 0;
	int last = numElems - 1;
	int middle;
	while (first <= last)
	{
		middle = first + (last - first) / 2;
		if (array[middle] == value)
			return middle;
		else if (array[middle] < value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return 0;
}


float meandisp(int array[], int len)
{
	float sum;
	float mean;
	sum = 0;
	for (int i = 0; i<len; i++)
	{
		sum = sum + array[i];
	}
	mean = sum / len;
	return mean;
}


	
