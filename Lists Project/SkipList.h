//
//  SkipList.h
//  Lists Assignment
//
// Hemza Al-Shamari
//

#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;

class SkipList
{
    // friend function declaration
    friend ostream &operator<<(ostream &os, const SkipList &list);

private:
    // Declaration of the SNode class, which is the node of the Skip List.
    class SNode
    {
    public:
        // Constructor that initializes node pointers and data
        explicit SNode(int d)
        {
            data = d;
            next = nullptr;
            prev = nullptr;
            upLevel = nullptr;
            downLevel = nullptr;
        }
        // Node member variables
        int data;
        SNode *next;
        SNode *prev;
        SNode *upLevel;
        SNode *downLevel;
        // Declaring SkipList class as a friend of the SNode class
        friend class SkipList;
    };

    // Private member function declaration
    void AddBefore(SNode *newNode, SNode *nextNode);
    // Pointers to the front and rear guard nodes of the Skip List
    SNode **frontGuards;
    SNode **rearGuards;

public:
    // Class member variable declaration
    int depth;
    // Class constructor and destructor declaration
    explicit SkipList(int depth = 1);
    virtual ~SkipList();
    // Public member functions declaration
    bool Add(int data);
    bool Remove(int data);
    bool Contains(int data);
    // Member function that returns a boolean value
    bool AlsoHigher() const;
};
#endif /* SKIPLIST_H */