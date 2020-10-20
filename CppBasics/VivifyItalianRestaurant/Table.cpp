#include "Table.h"
#include "ItalianRestoran.h"
#include <iostream>
#include <sstream>

int Table::unId = 0;

Table::Table()
{
	id = ++unId;
	//order = nullptr;
}

Table::Table(std::shared_ptr<Order> const& o)
{
	if (!this->order)
	{
		id = ++unId;
		order = o;
	}
	else
		std::cout << "Table " << this->id << " already has unpaid order!" << std::endl;
}

int Table::getId()
{
	return id;
}

std::shared_ptr<Order> Table::getOrder()
{
	return order;
}

void Table::setOrder(std::shared_ptr<Order> const& o)
{
	try {
		if (!this->order)
			order = o;
		else
			throw 5;
	} catch (int param) {
		std::stringstream ss;
		ss << "Failed Order:";
		std::stringstream tt;
		tt << "\nCan't make an order, table " << this->id << " already has unpaid order!" << std::endl;

		std::shared_ptr<ItalianRestoran> cs = ItalianRestoran::getRestoran();
		cs->setDateTimeLog(ss.str(), tt.str());

		std::cout << tt.str();
	}
}

void Table::deleteOrder()
{
	//delete order;
	//order = nullptr;
	order.reset();
}
