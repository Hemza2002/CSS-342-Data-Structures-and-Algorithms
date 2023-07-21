//
//  assignment3.cpp
//  Recursion Assignment
//
//  Hemza Al-Shamari
//  HW3 - Recursion
//

#include <iostream>
#include <fstream>

#include "Maze.h"
#include "Creature.h"

using namespace std;

void testingFiles()
{    // maze with no solution path: X
     Maze maze0("maze0.txt");
     Creature creaure0(8, 3);
     cout << "Path: " << creaure0.Solve(maze0) << endl;
     cout << maze0 << endl;
     // maze with solution
     Maze maze1("maze1.txt");
     Creature creaure1(5, 18);
     cout << "Path: " << creaure1.Solve(maze1) << endl;
     cout << maze1 << endl;
     // maze with solution
     Maze maze2("maze1.txt");
     Creature creaure2(5, 15);
     cout << "Path: " << creaure2.Solve(maze2) << endl;
     cout << maze2 << endl;
     // maze with solution
     Maze maze3("maze4.txt");
     Creature creaure3(4, 1);
     cout << "Path: " << creaure3.Solve(maze3) << endl;
     cout << maze3 << endl;
     // maze with creature at exit already
     Maze maze4("mazeSimple.txt");
     Creature creaure4(6, 2);
     cout << "Path: " << creaure4.Solve(maze4) << endl;
     cout << maze4 << endl;
     // maze with no solution
     Maze maze5("mazeNoExit1.txt");
     Creature creaure5(6, 3);
     cout << "Path: " << creaure5.Solve(maze5) << endl;
     cout << maze5 << endl;
}
int main()
{
     testingFiles();
     cout << "Completed" << endl;
     return 0;
}
