#ifndef ITEM_H
#define ITEM_H

#include <string>

//Item
class Item {
public:
	//Item();
	virtual ~Item() = 0;
	virtual std::string getName() = 0;
	virtual void setName(std::string n) = 0;
	virtual double getPrice() = 0;
	virtual void setPrice(double p) = 0;
};

class Drink :public Item {
	std::string name;
	double price;
	double volume;
public:
	Drink(std::string, double);
	~Drink();
	std::string getName();
	void setName(std::string);
	double getPrice();
	void setPrice(double);
	double getVolume();
	void setVolume(double);
};

// Decorator pattern
// Component Food(Pizza and Pasta)
class Food : public Item {
public:
	virtual ~Food() = 0;
};

// Concrete Component
class BaseFood : public Food {
	std::string name;
	double price;
public:
	BaseFood(std::string nm);
	~BaseFood();
	std::string getName();
	void setName(std::string);
	double getPrice();
	void setPrice(double);
};

// Decorator
class FoodDecorator : public Food {
	std::string nameDec;
	double priceDec;
//protected:
//	Food* p_Food;
public:
	FoodDecorator(std::string);
	std::string getName()
	{
		//return p_Food->getName();
		return nameDec;
	};
	void setName(std::string nm)
	{
		//p_Food->setName(nm);
		nameDec = nm;
	};
	double getPrice()
	{
		//return p_Food->getPrice();
		return priceDec;
	};
	void setPrice(double pr)
	{
		//p_Food->setPrice(pr);
		priceDec = pr;
	};
};

// Concrete Decorator
class FoodConcreteDecorator : public FoodDecorator
{
	Food* p_Food;
	Food* p_Decorator;
public:
	FoodConcreteDecorator(Food* baseFood, FoodDecorator* decoratorFood);
	std::string getName()
	{
		return p_Food->getName() + " " + p_Decorator->getName();
	};
	void setName(std::string nm)
	{
		p_Food->setName(nm);
	};
	double getPrice()
	{
		return p_Food->getPrice() + p_Decorator->getPrice();
	};
	void setPrice(double pr)
	{
		p_Food->setPrice(pr);
	};
};


#endif
