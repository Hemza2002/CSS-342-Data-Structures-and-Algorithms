//
//  BSTree.h
//  Banking Assignment
// Created by Hemza Al-Shamari
//

#ifndef BSTREE_H
#define BSTREE_H

#include "Account.h"

using namespace std;

class BSTree
{
private:
    struct Node
    {
        // pointer to the account object
        Account *pAcct;
        // pointer to the right subtree
        Node *right;
        // pointer to the left subtree
        Node *left;
    };

public:
    // This function recursively deletes a binary tree starting from the given node.
    void recursiveDelete(Node *node);
    // constructor
    BSTree();
    // destructor
    ~BSTree();
    // array of fund type names
    string fundTypes[10] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"};
    // pointer to the root node
    Node *root;
    // inserts an account into the BSTree
    bool Insert(Account *);
    // helper function for inserting account recursively
    bool RecursiveInsert(Account *, Node *);
    // retrieves an account from the BSTree given the account number
    bool Retrieve(const int &, Account *&) const;
    // displays the accounts in the BSTree
    void Display(Node *node) const;
};
#endif