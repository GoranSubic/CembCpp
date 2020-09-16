#define _CRT_SECURE_NO_WARNINGS
#include "ItalianRestoran.h"
#include "Item.h"
#include "Order.h"
#include "Table.h"

#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

ItalianRestoran::ItalianRestoran() {
    LogFile.open("LogFile.txt");
}

ItalianRestoran* ItalianRestoran::getRestoran() {
    if (!restoran)
        restoran = new ItalianRestoran;
    return restoran;
}

void ItalianRestoran::setDateTimeLog(std::string txt1, std::string txt2)
{
    // current date/time based on current system
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::string Y = std::to_string(1900 + ltm->tm_year);
    std::string M = std::to_string(1 + ltm->tm_mon);
    std::string D = std::to_string(ltm->tm_mday);
    std::string T = std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);

    LogFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        LogFile << txt1 << " date " << D << "/" << M << "/" << Y << "  " << T << " " << txt2;
    }
    catch (std::ofstream::failure e) {
        std::cout << "setDateTimeLog - Exception opening/reading/closing file\n";
    }
}

void ItalianRestoran::printBill(Order* order)
{
    double sum = 0;
    std::vector<Food*> p = order->getPizzas();
    std::vector<Food*> t = order->getPastas();
    std::vector<Drink*> d = order->getDrinks();

    std::vector<Food*>::iterator itPizzas = p.begin();
    std::vector<Food*>::iterator itPastas = t.begin();
    std::vector<Drink*>::iterator itDrinks = d.begin();

    int i = 0;
    std::cout << "\n\nTable " << order->getTableId() << " payment" << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for (itPizzas; itPizzas != p.end(); itPizzas++)
    {
        std::cout << ++i << ". " << (*itPizzas)->getName() << " " << (*itPizzas)->getPrice() << std::endl;
        sum += (*itPizzas)->getPrice();
    }

    for (itPastas; itPastas != t.end(); itPastas++)
    {
        std::cout << ++i << ". " << (*itPastas)->getName() << " " << (*itPastas)->getPrice() << std::endl;
        sum += (*itPastas)->getPrice();
    }

    std::cout << ++i << ". ";
    for (itDrinks; itDrinks != d.end(); itDrinks++)
    {
        std::cout << (*itDrinks)->getName() << " " << (*itDrinks)->getVolume() << " " << (*itDrinks)->getPrice() << "   ";
        sum += (*itDrinks)->getPrice();
    }
    std::cout << std::endl;

    std::cout << "Sum is: " << sum << std::endl;


    std::stringstream ss;
    ss << "Receipt: ";
    std::stringstream tt;
    tt << " table " << order->getTableId() << ", payment " << sum << "RSD" << std::endl;
    ItalianRestoran* cs = ItalianRestoran::getRestoran();
    cs->setDateTimeLog(ss.str(), tt.str());


    delete order;

}

//Initialize pointer to zero so that it can be initialized in first call to getInstance
ItalianRestoran* ItalianRestoran::restoran = 0;
