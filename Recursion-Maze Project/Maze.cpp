//
//  Maze.cpp
//  Recursion Assignment
//
//  Hemza Al-Shamari
//  HW3 - Recursion
//

#include <iostream>
#include <fstream>
#include <string>

#include "Maze.h"

using namespace std;

Maze::Maze(string mazeFile)
{
    // Creating an input file stream object
    ifstream fileIn;
    // Opening the file specified in the parameter
    fileIn.open(mazeFile);

    // Checking if the file failed to open
    if (!fileIn)
    {
        // Throwing a runtime error with a message indicating the file failed to open and the file name
        throw runtime_error("Failed to open the file " + mazeFile);
    }

    // Declaring a string variable to store a line from the file
    string line;

    // Reading the xAxis and yAxis values from the file and store them in their respective variables
    fileIn >> xAxis >> yAxis;
    // Reading the exitRow and exitCol values from the file and store them in their respective variables
    fileIn >> exitRow >> exitCol;

    // Reading a line from the file and store it in the line variable
    getline(fileIn, line);

    // Using a nested loop to read each character from the file and store it in the 2D array
    for (int i = 0; i < yAxis; i++)
    {
        for (int j = 0; j < xAxis; j++)
        {
            // Reading a character from the file and store it in the array
            fileIn.get(field[i][j]);
        }

        // Reading a line from the file and store it in the line variable
        getline(fileIn, line);
    }

    // Closing the file
    fileIn.close();
}

// Checking if the current location of the creature is within the bounds of the maze
bool Maze::creatureCheck(int row, int column) const
{ // Returning true if the row or column is outside the bounds of the maze
    if (row > yAxis || column > xAxis || row < 0 || column < 0)
    {
        return true;
    }
    // Otherwise, returning false
    return false;
}
// Checking if the current location of the creature is a clear space
bool Maze::IsClear(int row, int column) const
{ // Returning true if the current location is a clear space (' ')
    return field[row][column] == ' ';
}
// Checking if the current location of the creature is a wall
bool Maze::IsWall(int row, int column) const
{ // Returning true if the current location is a wall ('x')
    return (field[row][column] == 'x');
}
// Checking if the current location of the creature is a path
bool Maze::IsPath(int row, int column) const
{ // Returning true if the current location is a path ('*')
    return field[row][column] == '*';
}
// Checking if the current location of the creature has been visited
bool Maze::IsVisited(int row, int column) const
{ // Return true if the current location has been visited ('+')
    return field[row][column] == '+';
}
// Checking if the current location of the creature is the exit
bool Maze::IsExit(int row, int column) const
{ // Returning true if the current location is the exit (row == exitRow and column == exitCol)
    return (row == exitRow && column == exitCol);
}
// Marking the current location of the creature as a path
void Maze::MarkAsPath(int row, int column)
{ // Setting the current location to '*'
    field[row][column] = '*';
}
// Marking the current location of the creature as visited
void Maze::MarkAsVisited(int row, int column)
{ // Setting the current location to '+'
    field[row][column] = '+';
}
// Overloading the output stream operator to display the maze
ostream &operator<<(ostream &os, const Maze &item)
{ // Looping through each row of the maze
    for (int i = 0; i < item.yAxis; i++)
    { // Looping through each column of the current row
        for (int j = 0; j < item.xAxis; j++)
        { // Outputting the character at the current location
            os << item.field[i][j];
        }
        // Adding a line break after each row
        os << endl;
    }
    // Returning the output stream
    return os;
}
