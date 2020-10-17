#include "Item.h"
#include <ctime>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

Drink::Drink(std::string nm, double v, int c) : volume(v)
{
	name = nm;
	count = c;

	srand((unsigned int)time(NULL));

	int ir = rand() % 500 + 150;
	price = float(ir);
}

Drink::~Drink()
{
}

std::string Drink::getName()
{
	return name;
}

double Drink::getPrice()
{
	return price;
}

int Drink::getCount()
{
	return count;
}

double Drink::getVolume()
{
	return volume;
}

void Drink::setVolume(double v)
{
	volume = v;
}
