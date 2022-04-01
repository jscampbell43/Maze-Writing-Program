/*                                                                                 
James Campbell                                                                     
Pengo Account: jcampbel@pengo                                                      
Email: jscampbell43@gmail.com                                                      
Maze.h                                                                            
Assignment 6 Maze Generation with Disjoint Sets                                     
 */ 
 
#ifndef MAZE_H
#define MAZE_H
 
#include <iostream>
#include <iomanip>
#include <vector>
#include "UnionFind.h"
using namespace std;

class Maze{
	public:
		Maze();// Default Constructor
		Maze(int n);// Variable Constructor 
		~Maze();// Destructor
		int index(int x, int y){return x + rows * y;}// Calculates index (x,y)
		void generateMaze();// Count through grid, join all squares to 1 path
		bool checkRight(int x);// Breaks RIGHT WALL if valid
		bool checkBottom(int x);// Breaks BOTTOM WALL if valid
		bool checkLeft(int x);// Breaks LEFT WALL if valid
		bool checkTop(int x);// Breaks TOP WALL if valid
		bool RightEdge(int x);// Index is at RIGHT EDGE
		bool BottomEdge(int x);// Index is at BOTTOM EDGE
		bool LeftEdge(int x);// Index is at LEFT EDGE
		bool TopEdge(int x);// Index is at TOP EDGE
		void printMaze();// Prints out entire Maze
		void printHexMaze();// Prints final maze
	private:
		UnionFind *U;// Disjoint Set that Matches maze size
		int* maze;// Array to store Maze grid values
		int* mazeTracker;// Array to store Maze grid indexes
		int* mazeTrackerShuffle;// Array to shuffle index Array tracker
		int rows; // Input n is stored here
		int size; // RowsXRows
};
 
#endif
