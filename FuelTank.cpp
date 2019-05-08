#include "stdafx.h"
#include "FuelTank.h"
#include <iostream>
#include <iomanip>

using namespace std;



FuelTank::FuelTank()					// default constructor (capacity = 0.0, level = 0.0)
{
	capacity	= 0.0;
	level		= 0.0;
}

FuelTank::FuelTank(double cap)					// construct setting fuel capacity (level = 0.0)
{
	level		= 0.0;
	capacity	= cap;
}

FuelTank::FuelTank(double cap, double lvl)		// construct setting fuel capacity and level
{
	capacity	= cap;
	level		= lvl;
}

void	FuelTank::setCapacity(double amt)			// set or change capacity
{
	if (getLevel() > capacity)
		level = capacity;
	else
		capacity = amt;

}
double	FuelTank::addFuel(double amt) 				// add to level - return amount added
{
	double need = 0.0;

	need = getUnusedCapacity();

	if (amt > need)
	{
		level = level + need;
		return need;
	}
	else
	{
		level = level + amt;
		return amt;
	}

}
double	FuelTank::useFuel(double amt)				// subtract from level - return amount used
{
	double used = 0.0;

 	if (amt < level)
	{
		used = amt;
		level -= amt;
	}
	else
	{
		used = level;
		level = 0.0;
	}
		return used;
}

double	FuelTank::fillUp()							// return amount used
{
	double amt = 0;
	amt = getUnusedCapacity();
	level = amt + getLevel();
	return amt;
}

double	FuelTank::getCapacity()				const	// return fuel tank capacity
{
	return capacity;
}
double	FuelTank::getLevel()				const	// return current fuel level in tank
{
	return level;
}
double	FuelTank::getUnusedCapacity()		const	// return available (unused) fuel capacity
{
	return capacity - level;
}

void	FuelTank::displayFuelTankInfo()		const	// show capacity, current level, unused capacity
{
	cout << fixed << setprecision(1)<< endl;
	cout << "fuel capacity:  " << setw(6) << getCapacity() << "   "
		<< "fuel on hand:  " << setw(6) << level << "   "
		<< "remaining capacity:  " << setw(6) << getUnusedCapacity() << "   ";
	if (isFull() == true)
		cout << "FULL" << endl;
	if (isEmpty() == true)
		cout << "EMPTY" << endl;

}

bool	FuelTank::isFull()					const	// return true if tank is full, else false
{
	bool full = true;
	if ((getCapacity() == getLevel()) && (getLevel() != 0.0))
		return true;
	else
		return false;
}

bool	FuelTank::isEmpty()					const	// return true if tank is empty, else false	
{
	bool empty = true;
	if (getLevel() == 0.0)
		return true;
	else
		return false;
}