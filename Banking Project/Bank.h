//
//  Bank.h
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#ifndef BANK_H
#define BANK_H
#include <string>
#include <queue>
#include <iostream>
#include "BSTree.h"
#include "Transaction.h"
using namespace std;

class Bank
{
private:
    // A string variable to hold the name of the file containing transaction data.
    string fileName;
    // A queue of Transaction objects to store the transactions read from the input file.
    queue<Transaction> TransactionQueue;
    // A BSTree object to hold the Bank's accounts in a binary search tree.
    BSTree accountList;

public:
    // Array of strings to hold the fund types
    string fundTypes[10] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"};
    // A public member function of the Bank class that reads transaction data from a file.
    void readTransactions(string fileName);
    // A public member function of the Bank class that processes the transactions stored in the Bank's transaction queue.
    void processTransactions();
    // A public member function of the Bank class that prints the transactions processed by the Bank.
    void printTransactions();
};
#endif