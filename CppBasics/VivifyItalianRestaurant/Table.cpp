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

Table::Table(Order* o)
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

Order* Table::getOrder()
{
	return order;
}

void Table::setOrder(Order* o)
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

		ItalianRestoran* cs = ItalianRestoran::getRestoran();
		cs->setDateTimeLog(ss.str(), tt.str());

		std::cout << tt.str();
	}
}

void Table::deleteOrder()
{
	//delete order;
	order = nullptr;
}
