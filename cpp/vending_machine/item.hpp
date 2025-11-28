
#ifndef ITEM_HPP
#define ITEM_HPP
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Item
{
private:
    string itemId;
    string name;
    int price;

public:
    Item(string itemId, string name, int price);
    string getItemId() const;
    string getName() const;
    int getPrice() const;

    void displayInfo() const;
};

#endif