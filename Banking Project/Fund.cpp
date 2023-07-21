//
//  Fund.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include <iostream>
#include "Fund.h"

using namespace std;

// Constructor that sets the balance to zero when a new Fund object is created
Fund::Fund()
{
    this->balance = 0;
}

// Destructor that is called when the Fund object is destroyed
Fund::~Fund()
{
}

// Method to retrieve the current balance of the Fund
int Fund::getBalance()
{
    return balance;
}

// Method to set the balance of the Fund
void Fund::setBalance(int amount)
{
    balance = amount;
}

// Method to add funds to the Fund
void Fund::addFunds(int amount)
{
    int newBalance = getBalance() + amount;
    setBalance(newBalance);
}

// Method to subtract funds from the Fund
void Fund::minusFunds(int amount)
{
    int newBalance = getBalance() - amount;
    setBalance(newBalance);
}

// Method to record a transaction in the Fund's history
void Fund::recordTransaction(Transaction history)
{
    // Add the transaction object to the end of the vector
    transactionHistory.push_back(history);
}