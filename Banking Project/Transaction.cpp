//
//  Transaction.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include <ostream>
#include "Transaction.h"

using namespace std;

// Returns the action type (e.g. 'D' for deposit, 'W' for withdrawal, etc.)
char Transaction::getActionType()
{
    return actionType;
}

// Returns the account number associated with the transaction
int Transaction::getAccountNum()
{
    return accountNum;
}

// Returns the fund number associated with the transaction
int Transaction::getFundNum()
{
    return fundNum;
}

// Returns the destination fund number associated with a transfer transaction
int Transaction::getToFundNum()
{
    return toFundNum;
}

// Returns the amount of money associated with the transaction
int Transaction::getAmount()
{
    return amount;
}

// Returns the destination account number associated with a transfer transaction
int Transaction::getToAccountNum()
{
    return toAccountNum;
}

// Returns a boolean indicating if the transaction failed or not
bool Transaction::getFailed()
{
    return failed;
}

// Returns the first name associated with the transaction
string Transaction::getFirstName()
{
    return firstName;
}

// Returns the last name associated with the transaction
string Transaction::getLastName()
{
    return lastName;
}

// Sets a boolean indicating if the transaction failed or not
void Transaction::setFailed(bool x)
{
    this->failed = x;
}

// Sets the balance (i.e. amount) associated with the transaction
void Transaction::setBalance(int x)
{
    this->amount = x;
}

// Constructor that initializes a transaction for a non-transfer action
Transaction::Transaction(char actionType, int accountNum, int fundNum, int amount)
{
    this->actionType = actionType;
    this->accountNum = accountNum;
    this->fundNum = fundNum;
    this->amount = amount;
    this->failed = false;
};

// Constructor that initializes a transaction for a transfer action
Transaction::Transaction(char actionType, int accountNum, int fundNum, int amount, int toAccountNum, int toFundNum)
{
    this->actionType = actionType;
    this->accountNum = accountNum;
    this->fundNum = fundNum;
    this->amount = amount;
    this->toAccountNum = toAccountNum;
    this->toFundNum = toFundNum;
    this->failed = false;
}

// Constructor that initializes a transaction for an open account action
Transaction::Transaction(char actionType, string firstName, string lastName, int accountNum)
{
    this->actionType = actionType;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountNum = accountNum;
    this->failed = false;
}

// Constructor that initializes a transaction for an open fund action
Transaction::Transaction(char actionType, int accountNum, int fundNum)
{
    this->actionType = actionType;
    this->accountNum = accountNum;
    this->fundNum = fundNum;
    this->failed = false;
}

// Constructor that initializes a transaction for a history action
Transaction::Transaction(char actionType, int accountNum)
{
    this->actionType = actionType;
    this->accountNum = accountNum;
    this->failed = false;
}

// Overloaded operator to print transaction information to an output stream
ostream &operator<<(ostream &os, Transaction &transaction)
{
    // Check the type of transaction to determine the format of the output
    if (transaction.getActionType() == 'T')
    {
        // If it's a transfer, include the destination account and fund numbers
        os << transaction.getActionType() << " " << transaction.getAccountNum() << transaction.getFundNum() << " " << transaction.getAmount() << " " << transaction.getToAccountNum() << transaction.getToFundNum();
    }
    else
    {
        // If it's not a transfer, only include the account and fund numbers and the amount
        os << transaction.getActionType() << " " << transaction.getAccountNum() << transaction.getFundNum() << " " << transaction.getAmount();
    }
    // Return the output stream
    return os;
}
