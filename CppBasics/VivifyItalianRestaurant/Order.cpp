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

Order::Order(std::vector<std::shared_ptr<Drink>> v, std::vector<std::shared_ptr<Food>> p, std::vector<std::shared_ptr<Food>> t, int tblId)
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
	std::shared_ptr<ItalianRestoran> cs = ItalianRestoran::getRestoran();
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

void Order::setDrinks(std::shared_ptr<Drink> d)
{
	drinks.push_back(d);
}

std::vector<std::shared_ptr<Drink>> Order::getDrinks()
{
	return drinks;
}

std::vector<std::shared_ptr<Food>> Order::getPizzas()
{
	return pizzas;
}

std::vector<std::shared_ptr<Food>> Order::getPastas()
{
	return pastas;
}
