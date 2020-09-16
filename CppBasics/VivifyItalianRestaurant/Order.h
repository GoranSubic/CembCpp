#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

class Drink;
class Food;
class Table;

class Order {
	static int unOrderId;
	int id;
	std::vector<Drink*> drinks;
	std::vector<Food*> pizzas;
	std::vector<Food*> pastas;
	int tableId;
public:
	Order(std::vector<Drink*>, std::vector<Food*>, std::vector<Food*>, int tableId);
	~Order();
	void setId();
	int getId();
	int getTableId();
	void setTableId(int);
	void setDrinks(Drink*);
	std::vector<Drink*> getDrinks();
	std::vector<Food*> getPizzas();
	std::vector<Food*> getPastas();
};

#endif
