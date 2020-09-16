#include "Order.h"
#include "Item.h"
#include "ItalianRestoran.h"

#include <sstream>

int Order::unOrderId = 0;

Order::~Order()
{
	drinks.clear();
	pizzas.clear();
}

Order::Order(std::vector<Drink*> v, std::vector<Food*> p, std::vector<Food*> t, int tblId)
{
	id = ++unOrderId;
	tableId = tblId;
	drinks = v;
	pizzas = p;
	pastas = t;

	std::stringstream ss;
	ss << "Order:   ";

	std::stringstream tt;
	tt << " table " << tableId << std::endl;
	ItalianRestoran* cs = ItalianRestoran::getRestoran();
	cs->setDateTimeLog(ss.str(), tt.str());
}

int Order::getTableId()
{
	return tableId;
}

void Order::setTableId(int tid)
{
	tableId = tid;
}

void Order::setDrinks(Drink* d)
{
	drinks.push_back(d);
}

std::vector<Drink*> Order::getDrinks()
{
	return drinks;
}

std::vector<Food*> Order::getPizzas()
{
	return pizzas;
}

std::vector<Food*> Order::getPastas()
{
	return pastas;
}
