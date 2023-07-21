//
//  Maze.h
//  Recursion Assignment
//
//  Hemza Al-Shamari
//  HW3 - Recursion
//

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Maze
{
    // Friend operator to print out the maze
    friend ostream &operator<<(ostream &os, const Maze &item);

public:
    // Boolean function to check the position of creature and if its withing bounds of the maze
    bool creatureCheck(int row, int column) const;
    // Boolean function to check if the given position in the maze is clear
    bool IsClear(int row, int column) const;
    // Boolean function to check if the given position in the maze is a wall
    bool IsWall(int row, int column) const;
    // Boolean function to check if the given position in the maze is a path
    bool IsPath(int row, int column) const;
    // Boolean function to check if the given position in the maze is visited
    bool IsVisited(int row, int column) const;
    // Boolean function to check if the given position in the maze is an exit
    bool IsExit(int row, int column) const;

    // mark the maze with *
    void MarkAsPath(int row, int column);

    // mark the maze with +
    void MarkAsVisited(int row, int column);

    // Maze constructor requiring a file name
    explicit Maze(string mazeFile);

private:
    // Intiailzing private variables
    //  Setting a maximum number of elements in the array
    static const int MAX_NUMBER_IN_ARRAY = 100;

    // 2D character array to represent the maze field.
    char field[MAX_NUMBER_IN_ARRAY][MAX_NUMBER_IN_ARRAY];

    // Width of the maze
    int xAxis;

    // Height of the maze
    int yAxis;

    // Exit y position
    int exitRow;

    // Exit x position
    int exitCol;
};
#endif /* MAZE_H */