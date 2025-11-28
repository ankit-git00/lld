#include "inventory.hpp"

Inventory::Inventory() {}

bool Inventory::addItem(string code, Item *item, int quantity)
{
    itemMap[code] = item;
    quantityMap[code] = quantity;

    return true;
}

void Inventory::updateStock(string code, int quantity)
{
    quantityMap[code] = quantity;
}

void Inventory::displayInfo() const
{
    for (auto item : itemMap)
    {
        cout << "Code : " << item.first << '\n';
        item.second->displayInfo();
    }
}

int main()
{

    Inventory curr;
}