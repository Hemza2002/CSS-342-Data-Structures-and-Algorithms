//
//  BSTree.cpp
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#include "BSTree.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor for the BSTree class
BSTree::BSTree()
{
    // Set the root node to null
    root = nullptr;
}
// A destructor for the BSTree class.
BSTree::~BSTree()
{
    // Recursively delete all nodes in the tree starting from the root.
    recursiveDelete(root);
}

// A private member function of the BSTree class that recursively deletes all nodes in the tree.
void BSTree::recursiveDelete(Node *node)
{
    // If the current node is not null, recursively delete its left and right subtrees.
    if (node != nullptr)
    {
        recursiveDelete(node->left);
        recursiveDelete(node->right);
        // Delete the Account object stored in the current node.
        delete node->pAcct;
        // Delete the current node.
        delete node;
        // Set the pointer to null to prevent dangling pointers.
        node = nullptr;
    }
}

// Insert a new account into the binary tree
bool BSTree::Insert(Account *nAccount)
{
    // If the root node is null
    if (root == nullptr)
    {
        // Create a new node and set it as the root node
        root = new Node;
        // Set the account pointer for the root node
        root->pAcct = nAccount;
        // Set the left node to null
        root->left = nullptr;
        // Set the right node to null
        root->right = nullptr;
        // Return true to indicate successful insertion
        return true;
    }
    // If the root node is not null
    else
    {
        // Set the current node to the root node
        Node *curNode = root;
        // Call the RecursiveInsert function to insert the new account
        return RecursiveInsert(nAccount, curNode);
    }
    // Return false to indicate unsuccessful insertion
}

// A recursive method to place all the account in a sorted order
bool BSTree::RecursiveInsert(Account *nAccount, Node *curNode)
{
    // Create a file output stream object
    ofstream output;
    // Open the output file in append mode
    output.open("BankTransOut.txt", std::ios_base::app);
    // If the new account number is less than the current node's account number
    if (nAccount->getAccountNumber() < curNode->pAcct->getAccountNumber())
    {
        // If the left node is null
        if (curNode->left == nullptr)
        {
            // Create a new node
            Node *nNode = new Node();
            // Set the account pointer for the new node
            nNode->pAcct = nAccount;
            // Set the left node to null
            nNode->left = nullptr;
            // Set the right node to null
            nNode->right = nullptr;
            // Set the left node of the current node to the new node
            curNode->left = nNode;
            // Return true to indicate successful insertion
            return true;
        }
        // If the left node is not null
        else
        {
            // Call the RecursiveInsert function recursively with the left node as the current node
            return RecursiveInsert(nAccount, curNode->left);
        }
    }
    // If the new account number is greater than the current node's account number
    else if (nAccount->getAccountNumber() > curNode->pAcct->getAccountNumber())
    {
        // If the right node is null
        if (curNode->right == nullptr)
        {
            // Create a new node
            Node *nNode = new Node();
            // Set the account pointer for the new node
            nNode->pAcct = nAccount;
            // Set the left node to null
            nNode->left = nullptr;
            // Set the right node to null
            nNode->right = nullptr;
            // Set the right node of the current node to the new node
            curNode->right = nNode;
            // Return true
            return true;
        }
        // If the left node is not null, keep going right recursively
        else
        {
            return RecursiveInsert(nAccount, curNode->right);
        }
    }
    // If the new account ID is the same as the current account ID, output an error message and return false
    else
    {
        output << "ERROR: Account " << nAccount->getAccountNumber() << " is already open. Transaction refused." << endl;
        cout << "ERROR: Account " << nAccount->getAccountNumber() << " is already open. Transaction refused." << endl;
        return false;
    }
}

// This function retrieves an account given an account number
bool BSTree::Retrieve(const int &accountNum, Account *&nAccount) const
{
    // Open the output file for appending
    ofstream output;
    output.open("BankTransOut.txt", std::ios_base::app);
    // Set the current node to the root of the tree and initialize the search flag
    Node *current = root;
    bool search = false;

    // Loop until the account is found or the end of the tree is reached
    while (!search)
    {
        // If the current node is not null and its account number matches the search account number
        if (current != nullptr && accountNum == current->pAcct->getAccountNumber())
        {
            // Set the search flag to true, and set the output parameter to the found account
            search = true;
            nAccount = current->pAcct;
            return search;
        }
        // If the current node is not null and the search account number is greater than the current account number
        else if (current != nullptr && accountNum > current->pAcct->getAccountNumber())
        {
            // Traverse to the right child node
            current = current->right;
        }
        // If the current node is not null and the search account number is less than the current account number
        else if (current != nullptr && accountNum < current->pAcct->getAccountNumber())
        {
            // Traverse to the left child node
            current = current->left;
        }
        // If the current node is null, the end of the tree has been reached, and the account was not found
        else
        {
            search = true;
        }
    }
    // Output an error message to the file, and return false
    output << "ERROR: Account " << accountNum << " not found. Transferal refused." << endl;
    cout << "ERROR: Account " << accountNum << " not found. Transferal refused." << endl;
    return false;
}

void BSTree::Display(Node *node) const
{
    // If the node is null, return
    if (node == nullptr)
    {
        return;
    }
    // Open output file
    ofstream fin;
    fin.open("BankTransOut.txt", std::ios_base::app);
    // Recursively display the left subtree
    Display(node->left);
    // Get account information from current node
    Account *A = node->pAcct;
    // Write account information to output file
    fin << A->getLastName() << " " << A->getFirstName() << " Account ID: " << A->getAccountNumber() << endl;
    cout << A->getLastName() << " " << A->getFirstName() << " Account ID: " << A->getAccountNumber() << endl;

    // Write balance for each fund to output file
    for (int i = 0; i < 10; i++)
    {
        fin << "    " << fundTypes[i] << ": $" << A->fundArray[i].getBalance() << endl;
        cout << "    " << fundTypes[i] << ": $" << A->fundArray[i].getBalance() << endl;
    }
    // Add newline character to output file
    fin << endl;
    cout << endl;
    // Close output file
    fin.close();
    // Recursively display the right subtree
    Display(node->right);
}