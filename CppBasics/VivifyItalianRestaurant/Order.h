#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <memory>

class Drink;
class Food;
class Table;

class Order {
	static int unOrderId;
	int id;
	std::vector<std::shared_ptr<Drink>> drinks;
	std::vector<std::shared_ptr<Food>> pizzas;
	std::vector<std::shared_ptr<Food>> pastas;
	int tableId;
public:
	Order(std::vector<std::shared_ptr<Drink>>, std::vector<std::shared_ptr<Food>>, std::vector<std::shared_ptr<Food>>, int tableId);
	~Order();
	void setId();
	int getId();
	int getTableId();
	void setTableId(int);
	void setDrinks(std::shared_ptr<Drink>);
	std::vector<std::shared_ptr<Drink>> getDrinks();
	std::vector<std::shared_ptr<Food>> getPizzas();
	std::vector<std::shared_ptr<Food>> getPastas();
};

#endif
