
// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;


float hours;
int main()
{
	ifstream payFile;  	// Fill in the code to define payfile as an input file
	float gross;
	float net;
	
	float payRate;
	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;

	fstream payroll;
	payFile.open("payFile.txt");
	payroll.open("payroll.dat", ios::out | ios::app);
	while (!payFile.eof()) 
	{
		char ch;
		payFile.get(ch);
		payroll.put(ch);
	}
	// FILL IN THE CODE TO OPEN payfile AND ATTACH IT TO THE PHYSICAL FILE
		// NAMED payroll.dat


	if (!payFile)  // TO CHECK IF FILE EXISTS
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	cout << "payRate      Hours    Gross Pay       Net Pay" << endl << endl;
	payFile >> payRate;    // FILL IN CODE TO PRIME THE READ FOR THE payfile FILE.
	while (payFile)
		// FILL IN CODE TO WRITE A LOOP CONDITION TO RUN WHILE payfile HAS MORE 
		// DATA TO PROCESS.
	{
		payFile >> payRate >> stateTax >> fedTax;
		gross = payRate * hours;
		net = gross - (gross * stateTax) - (gross * fedTax);
		cout << payRate << setw(15) << hours << setw(12) << gross
			<< setw(12) << net << endl;
		payFile >> gross >> net; // FILL IN THE CODE TO FINISH THIS WITH THE APPROPRIATE  
		// VARIABLE TO BE INPUT
	}
	payFile.close();
	return 0;
}
