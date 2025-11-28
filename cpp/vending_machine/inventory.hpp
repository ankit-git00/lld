#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "item.hpp"

#include <iostream>
using namespace std;

class Inventory
{
private:
    map<string, Item *> itemMap;
    map<string, int> quantityMap;

public:
    Inventory();
    bool addItem(string code, Item *item, int quantity);
    void updateStock(string code, int newQuantity);
    Item *getItem(string code) const;
    void displayInfo() const;
};

#endif