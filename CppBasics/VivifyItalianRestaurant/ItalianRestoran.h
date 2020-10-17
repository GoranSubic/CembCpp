#ifndef ITALIANRESTORAN_H
#define ITALIANRESTORAN_H

#include <string>
#include <fstream>
#include <vector>

class Order;
class Table;

class ItalianRestoran {
    static ItalianRestoran* restoran;

    // Private constructor so that no objects can be created.
    ItalianRestoran();
    std::ofstream LogFile;
public:
    ~ItalianRestoran();
    static ItalianRestoran* getRestoran();
    void setDateTimeLog(const std::string, const std::string);
    void printBill(Order*);
};

#endif
