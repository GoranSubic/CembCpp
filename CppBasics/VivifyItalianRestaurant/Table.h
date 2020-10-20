#ifndef TABLE_H
#define TABLE_H

#include <memory>

class Order;

class Table {
	std::shared_ptr<Order> order;
	int id;
	static int unId;
public:
	Table();
	Table(std::shared_ptr<Order> const&);
	int getId();
	std::shared_ptr<Order> getOrder();
	void setOrder(std::shared_ptr<Order> const&);
	void deleteOrder();
};

#endif
