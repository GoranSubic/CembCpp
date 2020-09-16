#include "Item.h"
#include <ctime>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>


Drink::Drink(std::string nm, double v) :name(nm), volume(v)
{
	srand((unsigned int)time(NULL));

	int ir = rand() % 500 + 150;
	setPrice(float(ir));
}

Drink::~Drink()
{
}

std::string Drink::getName()
{
	return name;
}

void Drink::setName(std::string n)
{
	name = n;
}

double Drink::getPrice()
{
	return price;
}

void Drink::setPrice(double p)
{
	price = p;
}

double Drink::getVolume()
{
	return volume;
}

void Drink::setVolume(double v)
{
	volume = v;
}
