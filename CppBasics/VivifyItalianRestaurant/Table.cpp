#include "Table.h"
#include <iostream>

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
	if (!this->order)
		order = o;
	else
		std::cout << "\nCan't make an order, table " << this->id << " already has unpaid order!" << std::endl;
}

void Table::deleteOrder()
{
	//delete order;
	order = nullptr;
}
