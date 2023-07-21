//
//  Account.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include "Account.h"
#include "Fund.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Definition of the default constructor for the Account class.
Account::Account()
{
}

// Definition of the constructor for the Account class that takes three arguments.
Account::Account(string firstName, string lastName, int accountNumber)
{
    // Assign the value of the firstName argument to the firstName member variable.
    this->firstName = firstName;
    // Assign the value of the lastName argument to the lastName member variable.
    this->lastName = lastName;
    // Assign the value of the accountNum argument to the accountNum member variable.
    this->accountNumber = accountNumber;
}

// Definition of the destructor for the Account class.
Account::~Account()
{
}

// Definition of the getFirstName member function for the Account class.
string Account::getFirstName()
{
    // Return the value of the firstName member variable.
    return firstName;
}

// Definition of the getLastName member function for the Account class.
string Account::getLastName()
{
    // Return the value of the lastName member variable.
    return lastName;
}

// Definition of the getAccountNum member function for the Account class.
int Account::getAccountNumber()
{
    // Return the value of the accountNum member variable.
    return accountNumber;
}

// Definition of the getBalance member function for the Account class that takes one argument.
int Account::getBalance(int fundNumber)
{
    // Get the balance of the fund identified by the fundNumber argument and store it in the balance variable.
    int balance = fundArray[fundNumber].getBalance();
    // Return the balance.
    return balance;
}

// Definition of the printTransaction member function for the Account class that takes two arguments.
void Account::printTransaction(int fundNumber, ofstream &output)
{
    // Loop through the transactions in the specified fund's transaction history.
    for (std::vector<Transaction>::size_type i = 0; i < fundArray[fundNumber].transactionHistory.size(); i++)

    {
        // Check if the current transaction failed.
        if (fundArray[fundNumber].transactionHistory[i].getFailed() == true)
        {
            // If it did, print the transaction with a message indicating that it failed.
            output << "    " << fundArray[fundNumber].transactionHistory[i] << " (Failed)" << endl;
        }
        // If the transaction did not fail
        else
        {
            // Print the transaction without any additional message.
            output << "    " << fundArray[fundNumber].transactionHistory[i] << endl;
        }
    }
}

void Account::printTransactionTerminal(int fundNumber)
{
    // Loop through the transactions in the spcecified fund's transaction history.
    for (std::vector<Transaction>::size_type i = 0; i < fundArray[fundNumber].transactionHistory.size(); i++)

    {
        // Check if the current transaction failed.
        if (fundArray[fundNumber].transactionHistory[i].getFailed() == true)
        {
            // If it did, print the transaction with a message indicating that it failed.

            cout << "    " << fundArray[fundNumber].transactionHistory[i] << " (Failed)" << endl;
        }
        // If the transaction did not fail
        else
        {
            // Print the transaction without any additional message.

            cout << "    " << fundArray[fundNumber].transactionHistory[i] << endl;
        }
    }
}
