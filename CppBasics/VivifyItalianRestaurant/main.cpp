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

    std::unique_ptr<ItalianRestoran> ir(ItalianRestoran::getRestoran());
    //ItalianRestoran* ir = ItalianRestoran::getRestoran();

    //1) Kreirati 4 stola numerisana brojevima od 1 do 4.
    std::vector<Table*> tables;
    for (int i = 0; i < 4; i++)
        tables.push_back(new Table());

    //2) Kreirati 4 razlicite pizze, 5 pasti, 3 razlicita pica i 5 priloga. (imena generisati).
    Pizza* pizzaCapricciosa = new Pizza("Capricciosa");
    Pizza* pizzaSiciliana = new Pizza("Siciliana");
    Pizza* pizzaAdriana = new Pizza("Adriana");
    Pizza* pizzaMediterana = new Pizza("Mediterana");
    Pizza* pizzaCapricciosaX3 = new Pizza("Capricciosa", 3);

    //2) Kreirati 5 pasti
    Pasta* pastaItaliana = new Pasta("Italiana");
    Pasta* pastaCarbonara = new Pasta("Carbonara");
    Pasta* pasta3 = new Pasta("3");
    Pasta* pasta4 = new Pasta("4");
    Pasta* pasta5 = new Pasta("5");

    //5 priloga
    Food* ketchup = new AddKetchup();
    Food* origano = new AddOrigano();

    Food* pizzaCapricciosaKetchup = new AddKetchup(pizzaCapricciosa);
    Food* pizzaCapricciosaKetchupOrigano = new AddOrigano(pizzaCapricciosaKetchup);
    Food* pizzaCapricciosa2xKetchup = new AddKetchup(pizzaCapricciosa, 2);
    Food* pizzaCapricciosaX32xKetchup = new AddKetchup(pizzaCapricciosaX3, 2);

    Food* pastaItaliExtraCheese = new AddExtraCheese(pastaItaliana);


    //3 razlicita pica
    Drink* drink1 = new Drink("Water", 0.25, 1);
    Drink* drink2 = new Drink("Mineral Water", 0.3);
    Drink* drink3 = new Drink("Coca Cola", 0.5, 2);
    Drink* drink4 = new Drink("Juice", 0.25);
    Drink* drink5 = new Drink("Coca Cola", 0.5);
    
    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 1
    std::vector<Food*> vPizza1;
    vPizza1.push_back(pizzaCapricciosaKetchupOrigano);
    std::vector<Food*> vPasta1;
    vPasta1.push_back(pastaItaliExtraCheese);
    std::vector<Drink*> vDrinks1;
    vDrinks1.push_back(drink4);
    Order* order1 = new Order(vDrinks1, vPizza1, vPasta1, 1);
    //a) Sto broj 1
    tables[0]->setOrder(order1);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 2
    std::vector<Food*> vPizza2;
    vPizza2.push_back(pizzaSiciliana);
    std::vector<Food*> vPasta2;
    vPasta2.push_back(pastaCarbonara);
    std::vector<Drink*> vDrinks2;
    vDrinks2.push_back(drink3);
    Order* order2 = new Order(vDrinks2, vPizza2, vPasta2, 2);
    //b) Sto broj 2
    tables[1]->setOrder(order2);

    //3) Kreirati tri porudzbine za prethodno kreirane stavke - 3
    std::vector<Food*> vPizza3;
    vPizza3.push_back(pizzaCapricciosaX32xKetchup);
    std::vector<Food*> vPasta3;
    //vPasta3.push_back(pasta3);
    std::vector<Drink*> vDrinks3;
    vDrinks3.push_back(drink5);
    vDrinks3.push_back(drink2);
    vDrinks3.push_back(drink1);
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
    vPizza4.push_back(pizzaCapricciosa);
    std::vector<Food*> vPasta4;
    std::vector<Drink*> vDrinks4;
    Order* order4 = new Order(vDrinks4, vPizza4, vPasta4, 2);
    tables[1]->setOrder(order4);

    //6) Naplatiti drugu porudzbinu
    ir->printBill(order2);
    tables[1]->deleteOrder();

    //7) Pokusati porucivanje Pizza Capricciosa za sto broj 2 (ocekuje se uspešno kreiranje
    //    porudzbine bez izuzetka).
    tables[1]->setOrder(order4);

    
    //Don't have to delete ir becouse of unique_ptr
    //delete ir;
}
