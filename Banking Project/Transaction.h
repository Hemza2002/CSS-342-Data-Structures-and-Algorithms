//
//  Transaction.h
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
private:
    // First and last name of the account owner.
    string firstName, lastName;
    // Account number, toAccountNum for transfer transactions.
    int accountNum, toAccountNum;
    // Fund number, toFundNum and amount for transfer transactions.
    int fundNum, toFundNum, amount;
    // Type of transaction.
    char actionType;
    // Boolean flag to indicate if the transaction failed.
    bool failed = false;

public:
    // A public constructor that takes an action type and account number as parameters.
    Transaction(char actionType, int accountNum);
    // A public constructor that takes an action type, account number, and fund number as parameters.
    Transaction(char actionType, int accountNum, int fundNum);
    // A public constructor that takes an action type, account number, fund number, and amount as parameters.
    Transaction(char actionType, int accountNum, int fundNum, int amount);
    // A public constructor that takes an action type, first name, last name, and account number as parameters.
    Transaction(char actionType, string firstName, string lastName, int accountNum);
    // A public constructor that takes an action type, account number, fund number, amount, to-account number, and to-fund number as parameters.
    Transaction(char actionType, int accountNum, int fundNum, int amount, int toAccountNum, int toFundNum);

    // Overloaded operator to print transaction information to an output stream
    friend ostream &operator<<(ostream &os, Transaction &transaction);

    // A public member function that returns the action type of the transaction.
    char getActionType();
    // A public member function that returns the account number associated with the transaction.
    int getAccountNum();
    // A public member function that returns the fund number associated with the transaction.
    int getFundNum();
    // A public member function that returns the amount of the transaction.
    int getAmount();
    // A public member function that returns the account number of the recipient of the transaction.
    int getToAccountNum();
    // A public member function that returns the fund number of the recipient of the transaction.
    int getToFundNum();
    // A public member function that returns a boolean indicating whether the transaction failed or not.
    bool getFailed();
    // A public member function that returns the first name associated with the transaction.
    string getFirstName();
    // A public member function that returns the last name associated with the transaction.
    string getLastName();

    // A public member function that sets a boolean flag indicating whether the transaction failed or not.
    void setFailed(bool x);
    // A public member function that sets the balance associated with the transaction.
    void setBalance(int x);
};
#endif