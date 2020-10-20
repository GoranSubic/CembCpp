#define _CRT_SECURE_NO_WARNINGS
#include "ItalianRestoran.h"
#include "Item.h"
#include "Order.h"
#include "Table.h"
#include "Utilities.h"

#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

ItalianRestoran::ItalianRestoran() {
    LogFile.open("LogFile.txt");
}

ItalianRestoran::~ItalianRestoran()
{
}

std::shared_ptr<ItalianRestoran> ItalianRestoran::getRestoran   () {
    std::shared_ptr<ItalianRestoran> instance = restoran.lock();
    if (!instance) {
        instance.reset(new ItalianRestoran);
        restoran = instance;
    }
    return instance;
}

void ItalianRestoran::setDateTimeLog(const std::string txt1, const std::string txt2)
{
    LogFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        LogFile << txt1 << Util::CurrentDateTime() << ":\t" << txt2;
    }
    catch (std::ofstream::failure e) {
        std::cout << "setDateTimeLog - Exception opening/reading/closing file\n";
    }
}

void ItalianRestoran::printBill(std::shared_ptr<Order> const& order)
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
        if ((*itDrinks)->getCount() > 1)
        {
            std::cout << (*itDrinks)->getCount() << "x ";
        }
        std::cout << (*itDrinks)->getName() << " " << (*itDrinks)->getVolume() << " " << (*itDrinks)->getPrice() << "   ";
        sum += (*itDrinks)->getPrice();
    }
    std::cout << std::endl;
    std::cout << "Sum is: " << sum << std::endl;

    std::stringstream ss;
    ss << "Receipt: ";
    std::stringstream tt;
    tt << " table " << order->getTableId() << ", payment " << sum << "RSD" << std::endl;
    std::shared_ptr<ItalianRestoran> cs = ItalianRestoran::getRestoran();
    cs->setDateTimeLog(ss.str(), tt.str());

}

//Initialize pointer to zero so that it can be initialized in first call to getInstance
std::weak_ptr<ItalianRestoran> ItalianRestoran::restoran;
