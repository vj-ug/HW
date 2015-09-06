#include <iostream>
#include <string>
using namespace std;

#include "header.h"   //Including the class header file

int main()
{
	const int NUM_SHIPS = 3;
	Ship *ships[NUM_SHIPS] =		//Pointer array with each class 
	{
		new Ship,
		new Cruiseship(2050),
		new CargoShip(950)
	};
	for (int i = 0; i<3; i++)			//For loop to display
	{
		ships[i]->print();
		cout << endl;
	}
	char ch;
	cin >> ch;
}
