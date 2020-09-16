#ifndef TABLE_H
#define TABLE_H

class Order;

class Table {
	Order* order;
	int id;
	static int unId;
public:
	Table();
	Table(Order*);
	int getId();
	Order* getOrder();
	void setOrder(Order*);
	void deleteOrder();
};

#endif
