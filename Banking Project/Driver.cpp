//
//  Driver.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
    // create a new Bank object
    Bank b;
    // read transactions from input file
    b.readTransactions("BankTransIn.txt");
    // process the transactions
    b.processTransactions();
    // print the transactions to the console
    b.printTransactions();
    // return 0 to indicate successful program execution
    return 0;
}