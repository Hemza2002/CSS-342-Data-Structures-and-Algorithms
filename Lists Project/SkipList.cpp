//
//  SkipList.cpp
//  Lists Assignment
//
// Hemza Al-Shamari
//

#include "SkipList.h"
#include <climits>
#include <iostream>
#include <random>
#include <stdio.h>

using namespace std;

SkipList::SkipList(int inDepth)
{
    // Assigning the input depth to the depth of the SkipList object
    depth = inDepth;
    // Dynamically allocating an array of pointers to SNode objects, for the front guards of each level
    frontGuards = new SNode *[depth];
    // Dynamically allocating an array of pointers to SNode objects, for the rear guards of each level
    rearGuards = new SNode *[depth];
    // For each level, create a new frontGuard and rearGuard node
    for (int i = 0; i < depth; i++)
    { // Dynamically creating two new SNode objects, one with a value of INT_MIN and one with a value of INT_MAX
        SNode *pointer = new SNode(INT_MIN);
        SNode *secondPointer = new SNode(INT_MAX);
        // Assigning the front and rear guard nodes to the corresponding arrays of pointers
        frontGuards[i] = pointer;
        rearGuards[i] = secondPointer;
        // Setting the pointers for the front and rear guards
        frontGuards[i]->next = rearGuards[i];
        rearGuards[i]->prev = frontGuards[i];
        // Setting upLevel and downLevel pointers for each guard node, except for the top-most and bottom-most guards
        if (i < depth - 1)
        {
            // Setting the upLevel pointer of the front guard to point to the front guard of the level above it
            frontGuards[i]->upLevel = frontGuards[i + 1];
            // Setting the upLevel pointer of the rear guard to point to the rear guard of the level above it
            rearGuards[i]->upLevel = rearGuards[i + 1];
        }
        // If the current level is not the bottom level:
        if (i > 0)
        {
            // Setting the downLevel pointer of the front guard to point to the front guard of the level below it
            frontGuards[i]->downLevel = frontGuards[i - 1];
            // Setting the downLevel pointer of the rear guard to point to the rear guard of the level below it
            rearGuards[i]->downLevel = rearGuards[i - 1];
        }
    }
}

SkipList::~SkipList()
{
    // For each level of the SkipList,
    for (int i = 0; i < depth; i++)
    {
        // Setting the current node to the front guard of the current level
        SNode *current = frontGuards[i];
        // Traversing each node of the current level
        while (current != nullptr)
        {
            // Storing the current node in a temporary pointer
            SNode *temp = current;
            // Moving to the next node
            current = current->next;
            // Deleting the temporary node
            delete temp;
        }
        // After all nodes have been deleted, setting both front and rear guards to null
        frontGuards[i] = nullptr;
        rearGuards[i] = nullptr;
    }
    // Finally, deleting the array of pointers to front and rear guards
    delete[] frontGuards;
    delete[] rearGuards;
}

bool SkipList::Contains(int data)
{
    // Initializing the number of levels to search to the maximum level of the Skip List
    int levels = depth - 1;
    // Initializing the current node to the front guard of the maximum level
    SNode *current = frontGuards[levels];
    // While there are still nodes to traverse and the search has not reached the bottom level:
    while (current != nullptr && levels > -1)
    {
        // While the next node in the current level has a value less than the search value:
        while (current->next->data < data)
        {
            // Moving the current node to the next node in the current level
            current = current->next;
        }
        // If the value of the next node in the current level matches the search value:
        if (current->next->data == data)
        {
            // Returning true
            return true;
        }
        // Otherwise:

        // Moving the current node down to the corresponding node in the level below
        current = current->downLevel;
        // Decrementing the number of levels to search
        levels--;
    }
    // If the search has reached the bottom level and the value has not been found, return false
    if (current == nullptr)
    {
        return false;
    }
    // Returning false if the value has not been found
    return false;
}

bool SkipList::Add(int data)
{ // Keeping track of the level
    int level = 0;
    // Starting to search from the first node at the bottom level
    SNode *current = frontGuards[0]->next;
    // Searching for the right position to insert the new node
    while (current->next != nullptr && current->data < data)
    {
        current = current->next;
    }
    // Checking for duplicates
    if (current->data == data)
    {
        return false;
    }
    // Creating a new node with the given data
    SNode *newNode = new SNode(data);
    // Inserting the new node before the current node
    AddBefore(newNode, current);
    // Randomly determine whether to add the new node to higher levels
    bool addHigher = AlsoHigher();
    // While the coin toss is successful and have not reached the top level
    while (addHigher && level < depth - 1)
    {
        level++;
        // Creating a new node to be inserted at the higher level
        SNode *newUpper = new SNode(newNode->data);
        // Linking the new nodes in the vertical direction
        newNode->upLevel = newUpper;
        newUpper->downLevel = newNode;
        // Moving to the beginning of the current level
        while (newNode->prev != nullptr)
        {
            newNode = newNode->prev;
        }
        // Starting the searching from the first node at the higher level
        SNode *upperCurrent = frontGuards[level]->next;
        // Searching for the right position to insert the new upper node
        while (upperCurrent->data != INT_MAX && upperCurrent->data < newUpper->data)
        {
            upperCurrent = upperCurrent->next;
        }
        // Inserting the new upper node before the upper current node
        newNode = newUpper;
        AddBefore(newNode, upperCurrent);
        // Flipping a coin to determine whether to add another higher level
        addHigher = AlsoHigher();
    }

    return true;
}

void SkipList::AddBefore(SNode *newNode, SNode *nextNode)
{
    // Setting the pointers for the new node
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    // Setting the pointers for the nodes adjacent to the new node
    if (nextNode->prev != nullptr)
    {
        nextNode->prev->next = newNode;
    }
    nextNode->prev = newNode;
}

bool SkipList::Remove(int data)
{ // Starting at the top level
    int level = depth - 1;
    SNode *deleteN = frontGuards[level];
    // While there are more layers to explore
    while (deleteN != nullptr && level > -1)
    { // Go right until finding a node with a higher value
        while (deleteN->next->data < data)
        {
            deleteN = deleteN->next;
        }
        // If the value is found
        if (deleteN->next->data == data)
        { // For each level below the current one
            while (deleteN->next->downLevel != nullptr)
            { // Removing the node
                SNode *tempDelete = deleteN->next;
                SNode *nextTemp = tempDelete->next;

                deleteN->next = nextTemp;
                nextTemp->prev = deleteN;

                deleteN = deleteN->downLevel;

                tempDelete->downLevel = nullptr;
                tempDelete->next = nullptr;
                tempDelete->prev = nullptr;
                tempDelete->downLevel = nullptr;
                delete tempDelete;

                while (deleteN->next->data < data)
                {
                    // If not, go right.
                    deleteN = deleteN->next;
                }
            }
            // Finally, removing the node from the bottom level
            SNode *tempDelete = deleteN->next;
            SNode *nextTemp = tempDelete->next;

            deleteN->next = nextTemp;
            nextTemp->prev = deleteN;

            deleteN = deleteN->downLevel;
            delete tempDelete;

            return true;
        }
        // If the value was not found, go down a level and continue searching

        deleteN = deleteN->downLevel;
        level--;
    }
    // If the value was not found at any level, return false
    if (deleteN == nullptr)
    {
        return false;
    }
    return false;
}

bool SkipList::AlsoHigher() const
{ // Generating randon number
    return rand() % 2 == 1;
}

ostream &operator<<(ostream &os, const SkipList &list)
{
    // Printing the skiplist title
    os << "Skiplist Data Structure: \n";

    // Iterating over the skiplist levels in reverse order
    for (int i = list.depth - 1; i > -1; i--)
    {
        // Getting pointers to the front and rear guards of the current level
        SkipList::SNode *head = list.frontGuards[i];
        SkipList::SNode *rear = list.rearGuards[i];
        // Printing the current level number
        os << "Level " << i << ": ";

        // Iterating over the nodes in the current level and print their values
        while (head->data != rear->data)
        {
            os << head->data << ", ";
            head = head->next;
        }
        // Printing the value of the last node in the level, which is the same as the value of the rear guard
        os << rear->data;
        // Printing a newline character to move to the next line
        os << endl;
    }
    // Returning the output stream to allow chaining with other stream insertion operators
    return os;
}