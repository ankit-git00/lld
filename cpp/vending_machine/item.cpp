#include "item.hpp"

Item::Item(string itemId, string name, int price) : itemId(itemId), name(name), price(price) {}

string Item::getItemId() const
{
    return itemId;
}

string Item::getName() const
{
    return name;
}

int Item::getPrice() const
{
    return price;
}

void Item::displayInfo() const
{
    cout << "Name : " << name << endl;
    cout << "Price : " << price << endl;
}

// int main()
// {
//     Item i1("1", "sampeitem", 10);
//     cout << i1.getItemId() << '\n';
// }
