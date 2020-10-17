#ifndef ITEM_H
#define ITEM_H

#include <string>

//Item
class Item {
public:
	//Item();
	virtual ~Item() = 0;
	virtual std::string getName();
	virtual double getPrice();
	virtual int getCount();
protected:
	std::string name;
	double price;
	int count;
};

class Drink :public Item {
	double volume;
public:
	Drink(std::string, double, int c = 0);
	~Drink();

	std::string getName();
	double getPrice();
	int getCount();

	double getVolume();
	void setVolume(double);
};

// Decorator pattern
// Component Food(Pizza and Pasta)
class Food : public Item {
public:
	virtual ~Food() = 0;

	std::string getName();
	double getPrice();
	int getCount();
};

// Concrete Component - Pasta
class Pasta : public Food {
public:
	Pasta(std::string nm, int c = 0);
	~Pasta();
};

// Concrete Component - Pizza
class Pizza : public Food {
public:
	Pizza(std::string nm, int c = 0);
	~Pizza();
};

// Decorator
class Meal : public Food 
{
protected:
	Food* p_Food;
public:
	Meal();
	Meal(Food* pFood, int c = 0);
};

// Concrete Decorator
class AddKetchup : public Meal
{
public:
	AddKetchup();
	AddKetchup(Food* baseFood, int c = 0);
};

class AddOrigano : public Meal
{
public:
	AddOrigano();
	AddOrigano(Food* baseFood, int c = 0);
};

class AddExtraCheese : public Meal
{
public:
	AddExtraCheese();
	AddExtraCheese(Food* baseFood, int c = 0);
};

#endif
