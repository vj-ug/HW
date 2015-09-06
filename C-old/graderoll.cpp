
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


// This program reads records from a file.  The file contains the
// following: student's name, two test grades and final exam grade. 
// It then prints this information to the screen.


const int NAMESIZE = 15;
const int MAXRECORDS = 50;
struct Grades                             // declares a structure
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int finals;
	char letter;

};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.


void readIt(ifstream& indata, gradeType gradeRec, int &total);

// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.

int main()

{
	ifstream indata;
	indata.open("graderoll.dat");
	int numRecord;                // number of records read in
	gradeType studentRecord;

	if (!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	readIt(indata, studentRecord, numRecord);   // CALLING THE FUNCTION

	// output the information 
	for (int count = 0; count < numRecord; count++)
	{
		cout << studentRecord[count].name << setw(10)
			<< studentRecord[count].test1
			<< setw(10) << studentRecord[count].test2;
		cout << setw(10) << studentRecord[count].finals << setw(10) << studentRecord[count].letter << endl;
		
	}
	char test;
	cin >> test;
	return 0;
}

//**************************************************************
//					readIt
//
//  task:	  This procedure reads records into an array of 
//            records from an input file and keeps track of the 
//		      total number of records
//  data in:  data file containing information to be placed in
//            the array
//  data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream& indata, gradeType gradeRec, int& total)


{
	total = 0;
	indata.get(gradeRec[total].name, NAMESIZE);
	while (indata)
	{  	indata >> gradeRec[total].test1;    // FILL IN THE CODE TO READ test1
		indata >> gradeRec[total].test2;    // FILL IN THE CODE TO READ test2
		indata >> gradeRec[total].finals;   // FILL IN THE CODE TO READ final


		total++;     // add one to total

		indata.ignore();   
		
		indata.get(gradeRec[total].name, NAMESIZE);  
	}

}

