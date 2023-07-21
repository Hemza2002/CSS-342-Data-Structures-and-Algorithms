//
//  Creature.cpp
//  Recursion Assignment
//
//  Hemza Al-Shamari
//  HW3 - Recursion
//

#include <iostream>
#include <string>

#include "Creature.h"
#include "Maze.h"

using namespace std;

// Constructor for class Creature
// Initializes the path and sets the starting position of the creature to (r, c)
Creature::Creature(int r, int c)
{ // Initializing the path to empty string
    path = "";
    // Setting starting row to r
    row = r;
    // Setting starting column to c
    col = c;
}

// Overloading the <<operator to print the position of the creature object
ostream &operator<<(ostream &os, const Creature &creature)
{ // Printing the message and position of creature
    os << "The creature's position is:\n"
       << "row: " << creature.row
       << "\ncol: " << creature.col << endl;
    // Returning the output stream object
    return os;
}
// goNorth function to move creature one step towards North in the maze
void Creature::goNorth(Maze &maze)
{ // If the current position is an exit, return
    if (maze.IsExit(row, col))
    {
        return;
    }
    // If the next position is a wall, return
    if (maze.IsWall(row - 1, col))
    {
        return;
    }
    // If the next posiiton is clear, mark it as path
    if (maze.IsClear(row - 1, col))
    {
        maze.MarkAsPath(row, col);
    }
    // If the next position is not clear, mark is at visited
    else
    {
        maze.MarkAsVisited(row, col);
    }
    // Moving one step towards North
    row--;
    // Adding the string N to the path of the creature
    path += "N";
    // Recursively calling the goNorth, goSouth, goWest, and goEast functions
    goNorth(maze);
    goSouth(maze);
    goWest(maze);
    goEast(maze);
    // If the current position is not an exit, mark it as visited and move one step back towards South
    if (!maze.IsExit(row, col))
    {
        maze.MarkAsVisited(row, col);
        row++;
        path.pop_back();
    }
}
// goWest function to move creature one step towards West in the maze
void Creature::goWest(Maze &maze)
{ // If the current position is an exit, return
    if (maze.IsExit(row, col))
    {
        return;
    }
    // If the next position is a wall, return
    if (maze.IsWall(row, col - 1))
    {
        return;
    }
    // If the next posiiton is clear, mark it as path
    if (maze.IsClear(row, col - 1))
    {
        maze.MarkAsPath(row, col);
    }
    // If the next position is not clear, return
    else
    {
        return;
    }
    // Moving one step towards West
    col--;
    // Adding the string W to the path of the creature
    path += "W";
    // Recursively calling the goWest, goEast, goNorth, and goSouth functions
    goWest(maze);
    goEast(maze);
    goNorth(maze);
    goSouth(maze);
    // If the current position of the creature is not the exit, mark it as visited and backtrack
    if (!maze.IsExit(row, col))
    {
        maze.MarkAsVisited(row, col);
        col++;
        path.pop_back();
    }
}
// goSouth function to move creature one step towards South in the maze
void Creature::goSouth(Maze &maze)
{ // If current poisiton is an exit, return
    if (maze.IsExit(row, col))
    {
        return;
    }
    // If next posiiton is a wall, return
    if (maze.IsWall(row + 1, col))
    {
        return;
    }
    // If next position is clear, mark it as path
    if (maze.IsClear(row + 1, col))
    {
        maze.MarkAsPath(row, col);
    }
    // If next positon is not clear, return
    else
    {
        return;
    }
    // Moving one step towards South
    row++;
    // Adding the string S to the path of the creature
    path += "S";
    // Recursively calling all direction functions
    goSouth(maze);
    goWest(maze);
    goEast(maze);
    goNorth(maze);
    // If the current position of the creature is not the exit, mark it as visited and backtrack
    if (!maze.IsExit(row, col))
    {
        maze.MarkAsVisited(row, col);
        row--;
        path.pop_back();
    }
}
// goEast function to move creature one step towards Easy in the maze
void Creature::goEast(Maze &maze)
{ // If current position is an exit, return
    if (maze.IsExit(row, col))
    {
        return;
    }
    // If next position is a wall, return
    if (maze.IsWall(row, col + 1))
    {
        return;
    }
    // If next position is clear, mark it as a path
    if (maze.IsClear(row, col + 1))
    {
        maze.MarkAsPath(row, col);
    }
    // If next posiiton is not clear, return
    else
    {
        return;
    }
    // Moving one step towards East
    col++;
    // Adding the string E to the path of the creature
    path += "E";
    // Recursively calling all direction functions
    goEast(maze);
    goNorth(maze);
    goSouth(maze);
    goWest(maze);
    // If the current position of the creature is not the exit, mark it as visited and backtrack
    if (!maze.IsExit(row, col))
    {
        maze.MarkAsVisited(row, col);
        col--;
        path.pop_back();
    }
}
// Solve function for the Creature class
std::string Creature::Solve(Maze &maze)
{ // Checking if the creature is at an "X" in the maze
    if (maze.creatureCheck(row, col))
    {
        return "X";
    }
    // Checking if the creature is at a wall
    if (maze.IsWall(row, col))
    {
        return "X";
    }
    // Recursively attempting to move the creature in all four directions
    goNorth(maze);
    goEast(maze);
    goSouth(maze);
    goWest(maze);
    // If the creature is at the exit, return the path it took to get there
    if (maze.IsExit(row, col))
    { // If the path is empty, the creature was already at the exit
        if (path == "")
        {
            cout << "Creature at exit already" << endl;
        }
        // Marking the exit as part of the path and return the path
        maze.MarkAsPath(row, col);
        return path;
    }
    // If the creature isn't at the exit, mark its current position as visited
    maze.MarkAsVisited(row, col);
    return "X";
}