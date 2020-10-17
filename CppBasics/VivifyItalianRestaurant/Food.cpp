#include "Item.h"
#include <ctime>
#include <cstdlib>
#include <sstream>

Food::~Food()
{
}

std::string Food::getName()
{
	return name;
}

double Food::getPrice()
{
	return price;
}

int Food::getCount()
{
	return count;
}



Pasta::Pasta(std::string nm, int c)
{
	std::stringstream fullName;
	if (c > 1)
	{
		fullName << c << "x  Pasta " + nm;
	}
	else
	{
		fullName << "Pasta " + nm;
	}
	name = fullName.str();
	count = c;

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

Pasta::~Pasta()
{
}

Pizza::Pizza(std::string nm, int c)
{
	std::stringstream fullName;
	if (c > 1)
	{
		fullName << c << "x  Pizza " + nm;
	}
	else
	{
		fullName << "Pizza " + nm;
	}
	name = fullName.str();
	count = c;

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

Pizza::~Pizza()
{
}

Meal::Meal() : p_Food(NULL)
{
	name = "";
	price = 0;
	count = 0;
}

Meal::Meal(Food* pFood, int c) : p_Food(pFood)
{
	name = p_Food->getName();
	price = p_Food->getPrice();
	count = c;
}

AddKetchup::AddKetchup()
{
	name = "ketchup";

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

AddKetchup::AddKetchup(Food* baseFood,int c) : Meal(baseFood, c)
{
	std::stringstream fullName;
	if (this->getCount() > 1) 
	{
		fullName << p_Food->getName() << " " << this->getCount() << "x ketchup";
	}
	else {
		fullName << p_Food->getName() << " ketchup";
	}

	name = fullName.str();
	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = p_Food->getPrice() + float(fr);
}

AddOrigano::AddOrigano()
{
	name = "origano";

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

AddOrigano::AddOrigano(Food* baseFood, int c) : Meal(baseFood, c)
{
	std::stringstream fullName;
	if (this->getCount() > 1)
	{
		fullName << p_Food->getName() << " " << this->getCount() << "x origano";
	}
	else {
		fullName << p_Food->getName() << " origano";
	}
	name = fullName.str();

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = p_Food->getPrice() + float(fr);
}

AddExtraCheese::AddExtraCheese()
{
	name = "extra cheese";

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = float(fr);
}

AddExtraCheese::AddExtraCheese(Food* baseFood, int c) : Meal(baseFood, c)
{
	std::stringstream fullName;
	if (this->getCount() > 1)
	{
		fullName << p_Food->getName() << " " << this->getCount() << "x extra cheese";
	}
	else {
		fullName << p_Food->getName() << " extra cheese";
	}
	name = fullName.str();

	srand(static_cast <unsigned> (time(0)));
	//int ir = (rand() % 300) + 300;
	float fr = float(300) + (rand() / (RAND_MAX / (600 - 300)));
	price = p_Food->getPrice() + float(fr);
}
