//
//  Account.h
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <fstream>
#include "Transaction.h"
#include "Fund.h"

using namespace std;

// This constant is the size of the fundArray in the Account class.
const int FUND_SIZE = 10;

class Account
{
    // The private section of the class contains its data members.
private:
    int accountNumber;
    string firstName, lastName;

public:
    // Public member that is an array of Fund objects.
    Fund fundArray[FUND_SIZE];
    // Class constructor with no parameters.
    Account();
    // Class constructor that taken in first name, last name, and account number.
    Account(string firstName, string lastName, int accountNumber);
    // Class destructor.
    ~Account();

    // Public member to get first name.
    string getFirstName();
    // Public member to get last name.
    string getLastName();
    // Public member to get account number.
    int getAccountNumber();
    // Public member to get balance.
    int getBalance(int fundNumber);

    // Public member function to print a transaction for a specified fund to an output file.
    void printTransaction(int fundNumber, ofstream &output);
    // Public member fuction to print transaction on terminal as well.
    void printTransactionTerminal(int fundNumber);
};
#endif