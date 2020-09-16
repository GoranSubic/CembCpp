// VivifyOrders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "ItalianRestoran.h"
#include "Order.h"
#include "Table.h"
#include "Item.h"
#include <iostream>

int main()
{
    std::cout << "Italian Restoran Project!\n";

    ItalianRestoran* ir = ItalianRestoran::getRestoran();

    //1) Kreirati 4 stola numerisana brojevima od 1 do 4.
    std::vector<Table*> tables;
    for (int i = 0; i < 4; i++)
        tables.push_back(new Table());

    //2) Kreirati 4 razlicite pizze, 5 pasti, 3 razlicita pica i 5 priloga. (imena generisati).
    BaseFood* pizza1 = new BaseFood("Pizza Capricciosa");
    //std::cout << pizza1->getName() << " - " << pizza1->getPrice() << std::endl;
    BaseFood* pizza2 = new BaseFood("Pizza Siciliana");
    BaseFood* pizza3 = new BaseFood("Pizza Adriana");
    BaseFood* pizza4 = new BaseFood("Pizza Mediterana");

    //2) Kreirati 5 pasti
    BaseFood* pasta1 = new BaseFood("Pasta Italiana");
    BaseFood* pasta2 = new BaseFood("Pasta Carbonara");
    BaseFood* pasta3 = new BaseFood("Pasta 3");
    BaseFood* pasta4 = new BaseFood("Pasta 4");
    BaseFood* pasta5 = new BaseFood("Pasta 5");

    //5 priloga
    FoodDecorator* addition1 = new FoodDecorator("ketchup");
    //std::cout << "Decorator 1: " << addition1->getName() << " - " << addition1->getPrice() << std::endl;
    FoodDecorator* addition2 = new FoodDecorator("origano");
    FoodDecorator* addition3 = new FoodDecorator("biber");
    FoodDecorator* addition4 = new FoodDecorator("masline");
    FoodDecorator* addition5 = new FoodDecorator("extra cheese");

    FoodConcreteDecorator* pizzaWithAdd1 = new FoodConcreteDecorator(pizza1, addition5);
    //std::cout << "Decorator 1: " << pizzaWithAdd1->getName() << " - " << pizzaWithAdd1->getPrice() << std::endl;
    FoodConcreteDecorator* pizzaWithAdd2 = new FoodConcreteDecorator(pizzaWithAdd1, addition2);
    FoodConcreteDecorator* pizzaWithAdd3 = new FoodConcreteDecorator(pizza1, addition1);
    FoodConcreteDecorator* pizzaWithAdd32 = new FoodConcreteDecorator(pizzaWithAdd3, addition1);

    FoodConcreteDecorator* pastaWithAdd1 = new FoodConcreteDecorator(pasta1, addition1);

    //3 razlicita pica
    Drink* drink1 = new Drink("Water", 0.25);
    Drink* drink2 = new Drink("Mineral Water", 0.3);
    Drink* drink3 = new Drink("Coca Cola", 0.5);
    
    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 1
    std::vector<Food*> vPizza1;
    vPizza1.push_back(pizzaWithAdd2);
    std::vector<Food*> vPasta1;
    vPasta1.push_back(pastaWithAdd1);
    std::vector<Drink*> vDrinks1;
    vDrinks1.push_back(drink3);
    vDrinks1.push_back(drink3);
    Order* order1 = new Order(vDrinks1, vPizza1, vPasta1, 1);
    //a) Sto broj 1
    tables[0]->setOrder(order1);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 2
    std::vector<Food*> vPizza2;
    vPizza2.push_back(pizzaWithAdd2);
    std::vector<Food*> vPasta2;
    //vPasta2.push_back(pasta2);
    std::vector<Drink*> vDrinks2;
    vDrinks2.push_back(drink3);
    vDrinks2.push_back(drink3);
    Order* order2 = new Order(vDrinks2, vPizza2, vPasta2, 2);
    //b) Sto broj 2
    tables[1]->setOrder(order2);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 3
    std::vector<Food*> vPizza3;
    vPizza3.push_back(pizzaWithAdd3);
    vPizza3.push_back(pizzaWithAdd32);
    vPizza3.push_back(pizzaWithAdd32);
    std::vector<Food*> vPasta3;
    //vPasta3.push_back(pasta3);
    std::vector<Drink*> vDrinks3;
    vDrinks3.push_back(drink3);
    vDrinks3.push_back(drink1);
    vDrinks3.push_back(drink2);
    Order* order3 = new Order(vDrinks3, vPizza3, vPasta3, 3);
    //c) Sto broj 3
    tables[2]->setOrder(order3);


    //4) Naplatiti prvu i trecu porudzbinu.
    ir->printBill(order1);
    tables[0]->deleteOrder();
    ir->printBill(order3);
    tables[2]->deleteOrder();

    //5) Pokusati porucivanje Pizza Capricciosa za sto broj 2 (ocekuje se da se baci izuzetak).
    //b) Sto broj 2
    std::vector<Food*> vPizza4;
    vPizza4.push_back(pizza1);
    std::vector<Food*> vPasta4;
    //vPasta4.push_back(pasta4);
    std::vector<Drink*> vDrinks4;
    Order* order4 = new Order(vDrinks4, vPizza4, vPasta4, 2);
    tables[1]->setOrder(order4);

    //6) Naplatiti drugu porudzbinu
    ir->printBill(order2);
    tables[1]->deleteOrder();

    //7) Pokusati porucivanje Pizza Capricciosa za sto broj 2 (ocekuje se uspešno kreiranje
    //    porudzbine bez izuzetka).
    tables[1]->setOrder(order4);

    
    delete ir;
}
