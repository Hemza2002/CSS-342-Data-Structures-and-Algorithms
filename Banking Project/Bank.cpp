//
//  Bank.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include "Bank.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// A public member function of the Bank class that reads transaction data from a file.
void Bank::readTransactions(string filename)
{
    // Declare an input file stream object
    ifstream myfile;
    // Open the file specified by the filename parameter
    myfile.open(filename);
    // Check if the file was opened successfully
    if (!myfile)
    { // Display an error message if the file couldn't be opened
        cerr << "The file is not open." << endl;
    }
    // Loop until the end of the file is reached
    while (myfile)
    { // Declare a string to hold a line from the file
        string line;
        // Read in a line from the file
        getline(myfile, line);
        // Create a stringstream from the line
        istringstream iss(line);
        // Declare a char variable to hold the transaction type
        char actionType;
        // Read in the transaction type from the stringstream
        iss >> actionType;
        // If the line is empty, break out of the loop
        if (line.empty())
        {
            break;
        }
        // If the transaction is an account opening
        if (actionType == 'O')
        { // Declare variables to hold the first and last names
            string firstName, lastName;
            // Declare a variable to hold the account number
            int accountNum;
            // Read in the data from the stringstream
            iss >> firstName >> lastName >> accountNum;
            // Create a Transaction object with the data
            Transaction Q(actionType, firstName, lastName, accountNum);
            // Add the Transaction object to the TransactionQueue
            TransactionQueue.push(Q);
        }
        // If the transaction is a deposit or withdrawal
        if (actionType == 'D' || actionType == 'W')
        { // Declare variables to hold the transaction ID, fund number, account number, and amount
            int ID, fundNum, accountNum, amount;
            // Read in the data from the stringstream
            iss >> ID >> amount;
            // Calculate the account number from the transaction ID
            accountNum = ID / 10;
            // Calculate the fund number from the transaction ID
            fundNum = ID % 10;
            // Create a Transaction object with the data
            Transaction Q(actionType, accountNum, fundNum, amount);
            // Add the Transaction object to the TransactionQueue
            TransactionQueue.push(Q);
        }
        // If the transaction is a transfer
        if (actionType == 'T')
        { // Declare variables to hold the transaction IDs, account numbers, fund numbers, and amounts
            int ID, accountNum, fundNum, amount, toID, toAccountNum, toFundNum;
            // Read in the data from the stringstream
            iss >> ID >> amount >> toID;
            // Calculate the account number from the transaction ID
            accountNum = ID / 10;
            // Calculate the fund number from the transaction ID
            fundNum = ID % 10;
            // Calculate the account number of the recipient from the transaction ID
            toAccountNum = toID / 10;
            // Calculate the fund number of the recipient from the transaction ID
            toFundNum = toID % 10;
            // Create a Transaction object with the data
            Transaction Q(actionType, accountNum, fundNum, amount, toAccountNum, toFundNum);
            // Add the Transaction object to the TransactionQueue
            TransactionQueue.push(Q);
        }
        // If the transaction is a history request
        if (actionType == 'H')
        { // Declare variables to hold the transaction ID, account number, and fund number
            int ID, accountNum, fundNum;
            iss >> ID;
            // If the ID is less than 5 digits long, it's an account summary request
            if (log10(ID) + 1 < 5)
            {
                accountNum = ID;
                // Set fund number to -1 to indicate a summary request
                fundNum = -1;
                // Create new Transaction object
                Transaction Q(actionType, accountNum, fundNum);
                // Add transaction to queue
                TransactionQueue.push(Q);
            }
            // Otherwise, it's a fund transaction history request
            else
            {
                // Get the account number by dividing the ID by 10
                accountNum = ID / 10;
                // Get the fund number by taking the ID modulo 10
                fundNum = ID % 10;
                // Create new Transaction object
                Transaction Q(actionType, accountNum, fundNum);
                // Add transaction to queue
                TransactionQueue.push(Q);
            }
        }
    }
    // Close file
    myfile.close();
}

// A publiv member function that processes transactions for the Bank class
void Bank::processTransactions()
{
    // Flag for the while loop to keep executing transactions
    bool flag = true;
    // Output file to write transaction results to
    ofstream outputFile("BankTransOut.txt");
    while (flag)
    {
        Account *A = NULL;
        // Get the next transaction in the queue
        Transaction currentTrans = TransactionQueue.front();
        char actionType;
        // Get the type of the current transaction
        actionType = currentTrans.getActionType();
        // Open account transaction
        if (actionType == 'O')
        {
            // Create a new account with the provided information
            Account *A = new Account(currentTrans.getFirstName(), currentTrans.getLastName(), currentTrans.getAccountNum());
            // Add the new account to the list of accounts

            if (!accountList.Insert(A))
            {

                delete A;
            }
        }
        // Deposit transaction
        else if (actionType == 'D')
        {
            // Get the account number from the transaction
            int accountNum = currentTrans.getAccountNum();
            // Get the fund number from the transaction
            int fundNum = currentTrans.getFundNum();
            // Get the amount to deposit from the transaction
            int amount = currentTrans.getAmount();
            // Retrieve the account object from the account list
            accountList.Retrieve(accountNum, A);
            // Add the deposit amount to the specified fund
            A->fundArray[fundNum].addFunds(amount);
            // Record the transaction in the specified fund's transaction history
            A->fundArray[fundNum].recordTransaction(currentTrans);
        }
        // Withdrawal transaction
        else if (actionType == 'W')
        {
            // Get the account number from the transaction
            int accountNum = currentTrans.getAccountNum();
            // Get the fund number from the transaction
            int fundNum = currentTrans.getFundNum();
            // Get the amount to withdraw from the transaction
            int amount = currentTrans.getAmount();
            // Retrieve the account object from the account list
            accountList.Retrieve(accountNum, A);
            // If the account has enough money to withdraw
            if (amount <= A->fundArray[fundNum].getBalance())
            {
                // Subtract the withdrawal amount from the specified fund
                A->fundArray[fundNum].minusFunds(amount);
                // Record the transaction in the specified fund's transaction history
                A->fundArray[fundNum].recordTransaction(currentTrans);
            }
            // If the account does not have enough money to withdraw
            if (amount > A->fundArray[fundNum].getBalance())
            {
                // If the fund is a money market or prime money market fund
                if (fundNum == 0 || fundNum == 2)
                {
                    // If the account does not have enough money in the specified fund and its linked fund to withdraw
                    if (amount > (A->fundArray[fundNum].getBalance() + A->fundArray[fundNum + 1].getBalance()))
                    {
                        // Set the transaction to failed
                        currentTrans.setFailed(true);
                        // Record the failed transaction in the specified fund's transaction history
                        A->fundArray[fundNum].recordTransaction(currentTrans);
                    }
                    // If the account has enough money in the specified fund and its linked fund to withdraw
                    else
                    {
                        // Get the balance of the specified fund before the withdrawal
                        int newBalance = A->fundArray[fundNum].getBalance();
                        // Set the balance of the specified fund to 0
                        A->fundArray[fundNum].setBalance(0);
                        // Calculate the remaining amount to withdraw from the
                        amount = amount - newBalance;
                        // Subtract the remaining amount from the next fund
                        A->fundArray[fundNum + 1].minusFunds(amount);
                        // Set the balance in the current transaction to the previous balance
                        currentTrans.setBalance(newBalance);
                        // Create a new transaction for the next fund with the remaining amount
                        Transaction newTrans(actionType, accountNum, fundNum + 1, amount);
                        // Record the current transaction in the current fund's transaction history
                        A->fundArray[fundNum].recordTransaction(currentTrans);
                        // Record the new transaction in the next fund's transaction history
                        A->fundArray[fundNum + 1].recordTransaction(newTrans);
                    }
                }
                // Check if fund number is 1 or 3, since these funds can be linked for withdrawals
                else if (fundNum == 1 || fundNum == 3)
                {
                    // Check if there are sufficient funds in the specified fund and its linked fund to cover the withdrawal amount
                    if (amount > (A->fundArray[fundNum].getBalance() + A->fundArray[fundNum - 1].getBalance()))
                    {
                        // Set transaction to failed if there are not enough funds
                        currentTrans.setFailed(true);
                        A->fundArray[fundNum].recordTransaction(currentTrans);
                    }
                    else
                    {
                        // Get the balance of the specified fund before the withdrawal
                        int newBalance = A->fundArray[fundNum].getBalance();
                        // Set the balance of the specified fund to 0
                        A->fundArray[fundNum].setBalance(0);
                        // Calculate the remaining amount to withdraw from the linked fund
                        amount = amount - newBalance;
                        // Subtract the remaining amount from the linked fund
                        A->fundArray[fundNum - 1].minusFunds(amount);
                        currentTrans.setBalance(newBalance);
                        // Record the transaction for both the specified fund and its linked fund
                        Transaction newTrans(actionType, accountNum, fundNum - 1, amount);
                        A->fundArray[fundNum].recordTransaction(currentTrans);
                        A->fundArray[fundNum - 1].recordTransaction(newTrans);
                    }
                }
                else
                {
                    // Set transaction to failed and output error message if the specified fund is not 1 or 3 and there are not enough funds
                    currentTrans.setFailed(true);
                    cout << "ERROR: Not enough funds to withdraw " << amount << " from " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[fundNum] << endl;
                    outputFile << "ERROR: Not enough funds to withdraw " << amount << " from " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[fundNum] << endl;
                    A->fundArray[fundNum].recordTransaction(currentTrans);
                }
            }
        }

        // Transfer transaction
        else if (actionType == 'T')
        {
            // Retrieve transaction details
            int accountNum = currentTrans.getAccountNum();
            int fundNum = currentTrans.getFundNum();
            int amount = currentTrans.getAmount();
            int toAccountNum = currentTrans.getToAccountNum();
            int toFundNum = currentTrans.getToFundNum();
            // Declare pointers to Account objects
            Account *A, *B;
            // Retrieve accounts from the accountList
            bool accountA = accountList.Retrieve(accountNum, A);
            bool accountB = accountList.Retrieve(toAccountNum, B);
            // If both accounts are valid
            if (accountA && accountB)
            {
                // Withdraw the specified amount from fund in account A
                A->fundArray[fundNum].minusFunds(amount);
                // Deposit the specified amount to fund in account B
                B->fundArray[toFundNum].addFunds(amount);
                // Record transaction in the fund's transaction history in account A
                A->fundArray[fundNum].recordTransaction(currentTrans);
                // Record transaction in the fund's transaction history in account B
                B->fundArray[toFundNum].recordTransaction(currentTrans);
            }
        }
        // Display history
        else if (actionType == 'H')
        {
            // Get account number from the transaction
            int accountNum = currentTrans.getAccountNum();
            // Retrieve account with accountNum from accountList
            accountList.Retrieve(accountNum, A);
            // Check if fundNum in the transaction is negative
            if (currentTrans.getFundNum() < 0)
            {
                // Print transaction history for all funds of the account
                cout << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " by fund." << endl;
                outputFile << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " by fund." << endl;
                // Loop through all 10 funds of the account
                for (int i = 0; i < 10; i++)
                {
                    // Check if the current fund has transaction history
                    if (A->fundArray[i].transactionHistory.size() > 0)
                    {
                        // Print the name of the fund and its current balance
                        cout << fundTypes[i] << ": $" << A->fundArray[i].getBalance() << endl;
                        outputFile << fundTypes[i] << ": $" << A->fundArray[i].getBalance() << endl;
                        // Print the transaction history of the fund
                        A->printTransaction(i, outputFile);
                        A->printTransactionTerminal(i);
                    }
                }
            }
            else
            {
                // Print transaction history for a specific fund of the account
                cout << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[currentTrans.getFundNum()] << ": $" << A->fundArray[currentTrans.getFundNum()].getBalance() << endl;
                outputFile << "Transaction History for " << A->getLastName() << " " << A->getFirstName() << " " << fundTypes[currentTrans.getFundNum()] << ": $" << A->fundArray[currentTrans.getFundNum()].getBalance() << endl;
                // Print the transaction history of the specified fund
                A->printTransaction(currentTrans.getFundNum(), outputFile);
                A->printTransactionTerminal(currentTrans.getFundNum());
            }
        }
        // Pop the next transaction from the transaction queue
        TransactionQueue.pop();
        // Check if there are any more transactions in the queue
        if (TransactionQueue.empty())
        {
            // set flag to false to indicate end of transaction processing
            flag = false;
        }
    }
    // Close the output file
    outputFile.close();
}

// Print the final balances of all accounts in the bank
void Bank::printTransactions()
{
    // open output file in append mode
    ofstream outputFile("BankTransOut.txt", std::ios_base::app);
    outputFile << "Processing Done. Final Balances" << endl;
    cout << "Processing Done. Final Balances" << endl;
    // print the final balances of all accounts in the bank
    accountList.Display(accountList.root);
}