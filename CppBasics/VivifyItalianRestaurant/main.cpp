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

    std::shared_ptr<ItalianRestoran> ir(ItalianRestoran::getRestoran());
    //ItalianRestoran* ir = ItalianRestoran::getRestoran();

    //1) Kreirati 4 stola numerisana brojevima od 1 do 4.
    std::vector<std::unique_ptr<Table>> tables;
    for (int i = 0; i < 4; i++)
        tables.push_back(std::make_unique<Table>(Table()));

    //2) Kreirati 4 razlicite pizze, 5 pasti, 3 razlicita pica i 5 priloga. (imena generisati).
    std::shared_ptr<Pizza> pizzaCapricciosa = std::make_shared<Pizza>(Pizza("Capricciosa"));
    std::shared_ptr<Pizza> pizzaSiciliana = std::make_shared<Pizza>(Pizza("Siciliana"));
    std::shared_ptr<Pizza> pizzaAdriana = std::make_shared<Pizza>(Pizza("Adriana"));
    std::shared_ptr<Pizza> pizzaMediterana = std::make_shared<Pizza>(Pizza("Mediterana"));
    std::shared_ptr<Pizza> pizzaCapricciosaX3 = std::make_shared<Pizza>(Pizza("Capricciosa", 3));

    //2) Kreirati 5 pasti
    std::shared_ptr<Pasta> pastaItaliana = std::make_shared<Pasta>(Pasta("Italiana"));
    std::shared_ptr<Pasta> pastaCarbonara = std::make_shared<Pasta>(Pasta("Carbonara"));
    std::shared_ptr<Pasta> pasta3 = std::make_shared<Pasta>(Pasta("3"));
    std::shared_ptr<Pasta> pasta4 = std::make_shared<Pasta>(Pasta("4"));
    std::shared_ptr<Pasta> pasta5 = std::make_shared<Pasta>(Pasta("5"));

    //5 priloga
    std::unique_ptr<Food> ketchup = std::make_unique<AddKetchup>(AddKetchup());
    std::unique_ptr<Food> origano = std::make_unique<AddOrigano>(AddOrigano());

    std::shared_ptr<Food> pizzaCapricciosaKetchup = std::make_shared<AddKetchup>(pizzaCapricciosa);
    std::shared_ptr<Food> pizzaCapricciosaKetchupOrigano = std::make_shared<AddOrigano>(pizzaCapricciosaKetchup);
    std::shared_ptr<Food> pizzaCapricciosa2xKetchup = std::make_shared<AddKetchup>(pizzaCapricciosa, 2);
    std::shared_ptr<Food> pizzaCapricciosaX32xKetchup = std::make_shared<AddKetchup>(pizzaCapricciosaX3, 2);

    std::shared_ptr<Food> pastaItaliExtraCheese = std::make_shared<AddExtraCheese>(pastaItaliana);


    //3 razlicita pica
    std::shared_ptr<Drink> drink1 = std::make_shared<Drink>("Water", 0.25, 1);
    std::shared_ptr<Drink> drink2 = std::make_shared<Drink>("Mineral Water", 0.3);
    std::shared_ptr<Drink> drink3 = std::make_shared<Drink>("Coca Cola", 0.5, 2);
    std::shared_ptr<Drink> drink4 = std::make_shared<Drink>("Juice", 0.25);
    std::shared_ptr<Drink> drink5 = std::make_shared<Drink>("Coca Cola", 0.5);
    
    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 1
    std::vector<std::shared_ptr<Food>> vPizza1;
    vPizza1.push_back(pizzaCapricciosaKetchupOrigano);
    std::vector<std::shared_ptr<Food>> vPasta1;
    vPasta1.push_back(pastaItaliExtraCheese);
    std::vector<std::shared_ptr<Drink>> vDrinks1;
    vDrinks1.push_back(drink4);
    std::shared_ptr<Order> order1 = std::make_shared<Order>(vDrinks1, vPizza1, vPasta1, 1);
    //a) Sto broj 1
    tables[0]->setOrder(order1);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 2
    std::vector<std::shared_ptr<Food>> vPizza2;
    vPizza2.push_back(pizzaSiciliana);
    std::vector<std::shared_ptr<Food>> vPasta2;
    vPasta2.push_back(pastaCarbonara);
    std::vector<std::shared_ptr<Drink>> vDrinks2;
    vDrinks2.push_back(drink3);
    std::shared_ptr<Order> order2 = std::make_shared<Order>(vDrinks2, vPizza2, vPasta2, 2);
    //b) Sto broj 2
    tables[1]->setOrder(order2);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 3
    std::vector<std::shared_ptr<Food>> vPizza3;
    vPizza3.push_back(pizzaCapricciosaX32xKetchup);
    std::vector<std::shared_ptr<Food>> vPasta3;
    std::vector<std::shared_ptr<Drink>> vDrinks3;
    vDrinks3.push_back(drink5);
    vDrinks3.push_back(drink2);
    vDrinks3.push_back(drink1);
    std::shared_ptr<Order> order3 = std::make_shared<Order>(vDrinks3, vPizza3, vPasta3, 3);
    //c) Sto broj 3
    tables[2]->setOrder(order3);


    //4) Naplatiti prvu i trecu porudzbinu.
    ir->printBill(order1);
    tables[0]->deleteOrder();
    ir->printBill(order3);
    tables[2]->deleteOrder();

    //5) Pokusati porucivanje Pizza Capricciosa za sto broj 2 (ocekuje se da se baci izuzetak).
    //b) Sto broj 2
    std::vector<std::shared_ptr<Food>> vPizza4;
    vPizza4.push_back(pizzaCapricciosa);
    std::vector<std::shared_ptr<Food>> vPasta4;
    std::vector<std::shared_ptr<Drink>> vDrinks4;
    vDrinks4.push_back(drink3);
    std::shared_ptr<Order> order4 = std::make_shared<Order>(vDrinks4, vPizza4, vPasta4, 2);
    tables[1]->setOrder(order4);

    //6) Naplatiti drugu porudzbinu
    ir->printBill(order2);
    tables[1]->deleteOrder();

    //7) Pokusati porucivanje Pizza Capricciosa za sto broj 2 (ocekuje se uspešno kreiranje
    //    porudzbine bez izuzetka).
    order4 = std::make_shared<Order>(vDrinks4, vPizza4, vPasta4, 2);
    tables[1]->setOrder(order4);
    ir->printBill(order4);

    
    //Don't have to delete ir becouse of unique_ptr
    //delete ir;
}
