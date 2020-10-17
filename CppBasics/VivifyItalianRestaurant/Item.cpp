#include "Item.h"
#include <ctime>
#include <cstdlib>

Item::~Item()
{
}

std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

int Item::getCount()
{
	return count;
}
