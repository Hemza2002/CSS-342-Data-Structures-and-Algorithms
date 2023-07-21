//
//  Creature.h
//  Recursion Assignment
//
//  Hemza Al-Shamari
//  HW3 - Recursion
//

#ifndef CREATURE_H
#define CREATURE_H

#include <stdio.h>
#include <iostream>
#include <string>

#include "Maze.h"

using namespace std;

class Creature
{
    // Friend operator to print out the creature
    friend ostream &operator<<(ostream &os, const Creature &creature);

public:
    // Creature constructor which takes in the rows and columns
    Creature(int r, int c);
    // Solve function, returns the solution path for the maze passed as parameter.
    string Solve(Maze &maze);

private:
    // Initailzing private instance variables needed
    // Variable representing the current row position
    int row;
    // Variable representing the current col position
    int col;
    // Variable representing the path taken by the creature in the maze
    string path;
    // Function which moves the creature in the corresponding direction and update the maze and the path
    void goNorth(Maze &maze);
    // Function which moves the creature in the corresponding direction and update the maze and the path
    void goSouth(Maze &maze);
    // Function which moves the creature in the corresponding direction and update the maze and the path
    void goEast(Maze &maze);
    // Function which moves the creature in the corresponding direction and update the maze and the path
    void goWest(Maze &maze);
};

#endif /* CREATURE_H*/