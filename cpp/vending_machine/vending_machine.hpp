#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include "inventory.hpp"

class VendingMachine
{

private:
    int balance;
    string selectedItemCode;

public:
    VendingMachine();
    int getBalance() const;
    string getSelectItemCode() const;
    void setState(VendingMachine *);
    void dispenseItem();
    void refundBalance();
    void selectItem(string code);
    void insertCoins(int amount);

    void disolayInfo() const;
};