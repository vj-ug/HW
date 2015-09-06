//Header File with class inheritance

#include <iostream>
#include <string>
using namespace std;

class Ship  // Ship Class as base class
{
	string shipName;
	string shipYear;
public:
	Ship(string n = "Titanic", string y = "1919")
	{
		shipName = n;	//Constructors
		shipYear = y;	//Constructors
	}
	void setShipName(string n)				//Mutator for Shipyear
	{
		shipName = n;
	}
	void setShipYear(string y)				//Mutator for ShipYear
	{
		shipYear = y;
	}
	string getShipName() const				//Accessor for ShipName
	{
		return shipName;
	}
	string getShipYear() const				//Accessor for ShipYear
	{
		return shipYear;
	}
	virtual void print() const				//Print function to display Ship name and ship year
	{ 
		cout << "Name: " << shipName << endl
			<< "Year Built: " << shipYear << endl;
	}
};

class Cruiseship : public Ship
{
	int max_pas;
public:
	Cruiseship(int max_pas) : Ship("Titanic", "1919")   //Inherited class
	{
		this->max_pas = max_pas;
	}
	void setmax_pas(int num) 
		{
			max_pas = num;			//Mutator 
		}
	int getmax_pas() const
		{ return max_pas;			//Accessor for Maximum Passengers
		}
	void print() const		//Overridden Print function for Ship name and maximum passengers
	{
		cout << "Ship Name:		  " << getShipName() << endl << "Maximum Passengers:      " << getmax_pas() << endl;
	}
};

class CargoShip : public Ship
{
	int Capacity;
public:
	CargoShip(int Capacity) : Ship("Titanic", "1919")
	{
		this->Capacity = Capacity;
	}
	void setCapacity(int c)    //Mutator, Function to set Cargo capacity
	{ 
		Capacity = c; 
	}
	int getCapacity() const  //Accessor, Function to display Cargo capacity
	{ 
		return Capacity; 
	}
	void print() const		//Overridden Print function to display Ship Name and Cargo Capacity
	{
		cout << "Ship Name:    " << getShipName() << endl << "Ship Cargo Capacity:   " << getCapacity();
	}
};
