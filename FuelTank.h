#pragma once


class FuelTank
{
public:
	FuelTank();								// default constructor (capacity = 0.0, level = 0.0)
	FuelTank(double cap);					// construct setting fuel capacity (level = 0.0)
	FuelTank(double cap, double lvl);		// construct setting fuel capacity and level

	void	setCapacity(double amt);		// set or change capacity
	double	addFuel(double amt);			// add to level - return amount added
	double	useFuel(double amt);			// subtract from level - return amount used
	double	fillUp();						// return amount used

	double	getCapacity()			const;	// return fuel tank capacity
	double	getLevel()				const;	// return current fuel level in tank
	double	getUnusedCapacity()		const;	// return available (unused) fuel capacity

	void	displayFuelTankInfo()	const;	// show capacity, current level, unused capacity

private:
	bool	isFull()				const;	// return true if tank is full, else false
	bool	isEmpty()				const;	// return true if tank is empty, else false	

	double	capacity;						// maximum capacity of fuel tank - gallons
	double	level;							// current level of fuel in tank - gallons
};

