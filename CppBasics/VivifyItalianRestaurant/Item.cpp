#include "Item.h"
#include <ctime>
#include <cstdlib>

Item::~Item()
{
}

Food::~Food()
{
}

BaseFood::BaseFood(std::string nm) :name(nm)
{
	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

BaseFood::~BaseFood()
{
}

std::string BaseFood::getName()
{
	return name;
}

void BaseFood::setName(std::string n)
{

	name = n;
}

double BaseFood::getPrice()
{
	return price;
}

void BaseFood::setPrice(double p)
{
	price = p;
}

FoodDecorator::FoodDecorator(std::string n) :nameDec(n)
{
	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(20) + (rand() / (RAND_MAX / (100 - 20)));
	priceDec = float(fr);
}

FoodConcreteDecorator::FoodConcreteDecorator(Food* baseFood, FoodDecorator* decoratorFood) 
	:FoodDecorator(decoratorFood->getName()), p_Food(baseFood), p_Decorator(decoratorFood)
{
}
