//
//  Fund.h
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#ifndef FUND_H
#define FUND_H
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Fund
{
private:
    // A private attribute to store the fund balance
    int balance;

public:
    // A public vector to store the transaction history of the fund
    vector<Transaction> transactionHistory;
    // Constructor for the Fund class
    Fund();
    // Destructor for the Fund class
    ~Fund();
    // A method to retrieve the current balance of the fund
    int getBalance();
    // A method to set the balance of the fund
    void setBalance(int amount);
    // A method to add funds to the fund
    void addFunds(int amount);
    // A method to subtract funds from the fund
    void minusFunds(int amount);
    // A method to record a transaction in the fund's transaction history
    void recordTransaction(Transaction history);
};
#endif