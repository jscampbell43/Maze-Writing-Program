#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include "Maze.h" 

// Default Constructor. Makes Maze of size 3x3
Maze::Maze(){
	srand(time(0));
	rows = 3;
	size = rows*rows;
	// Connect Disjoint Set to organize valid maze
	U = new UnionFind(size);
	// Create Maze 
	maze = new int[size];
	// Create Maze index Tracker
	mazeTracker = new int[size];
	// Initialize Maze to all solid blocks (int value 15)
	// Initialize MazeTracker to hold every index in Maze
	for(int i = 0; i < size; i++){
		maze[i] = 15;
		mazeTracker[i] = i;
	}
	// Set first value in Maze to Entrance (int value 11)
	maze[0] = 11;
	// Set last value in Maze to Exit (int value 14)
	maze[size-1] = 14;
	// Create Maze Tracker Shuffle maze and randomly shuffle MazeTracker
	mazeTrackerShuffle = new int[size];
	for(int i = 0; i < size; i++){
		int index = rand()%size;
		mazeTrackerShuffle[index] = mazeTracker[i];
		std::swap(mazeTracker[index], mazeTracker[i]);
		//Now MazeTracker still holds every index but it is Randomized
	}
}

// Variable Constructor. Makes Maze of size nxn		
Maze::Maze(int n){
	srand(time(0));
	rows = n;
	size = rows*rows;
	// Connect Disjoint Set to organize valid maze
	U = new UnionFind(size);
	// Create Maze 
	maze = new int[size];
	// Create Maze index Tracker
	mazeTracker = new int[size];
	// Initialize Maze to all solid blocks (int value 15)
	// Initialize MazeTracker to hold every index in Maze
	for(int i = 0; i < size; i++){
		maze[i] = 15;
		mazeTracker[i] = i;
	}
	// Set first value in Maze to Entrance (int value 11)
	maze[0] = 11;
	// Set last value in Maze to Exit (int value 14)
	maze[size-1] = 14;
	// Create Maze Tracker Shuffle maze and randomly shuffle MazeTracker
	mazeTrackerShuffle = new int[size];
	for(int i = 0; i < size; i++){
		int index = rand()%size;
		mazeTrackerShuffle[index] = mazeTracker[i];
		std::swap(mazeTracker[index], mazeTracker[i]);
	}
	//Now MazeTracker still holds every index but it is Randomized
}

// Destructor
Maze::~Maze(){
 	delete [] maze;
 	delete [] mazeTracker; 
 	delete [] mazeTrackerShuffle;
}

void Maze::generateMaze(){
	// Keep Doing Entire process until 1 SET
	while(U->numberOfSets()!=1){
		// Bool To ensure only 1 wall knocked down at a time
		bool validAdjacentFound;
		// Count through every index in Random order
		for(int i = 0; i < size; i ++){
			//Generate random picking array with 4 values, 1 for each direction
			int fourDirections[4] = {0,1,2,3};
			int fourDirShuffle[4];
			for(int i = 0; i < 4; i++){
				int index = rand()%4;
				fourDirShuffle[index] = fourDirections[i];
				std::swap(fourDirections[index], fourDirections[i]);
			}
			// Now fourDirections holds 0,1,2,3 in random order
			// Store the current random index
			int currentIndex = mazeTracker[i];
			validAdjacentFound = false;
			// Count through every adjacent square in Random order
			for(int j = 0; j < 4 && !validAdjacentFound; j++){
				if(fourDirections[j] == 0){
					// CheckRight- IF Valid: Break Wall and RETURN TRUE.
					validAdjacentFound = checkRight(currentIndex);	
				}
				if(fourDirections[j] == 1){
					// CheckBottom- IF Valid: Break Wall and RETURN TRUE.
					validAdjacentFound = checkBottom(currentIndex);
				}
				if(fourDirections[j] == 2){
					// CheckLeft- IF Valid: Break Wall and RETURN TRUE.
					validAdjacentFound = checkLeft(currentIndex);
				}
				if(fourDirections[j] == 3){
					// CheckTop- IF Valid: Break Wall and RETURN TRUE.
					validAdjacentFound = checkTop(currentIndex);
				}
			}
		}
	}
}

// Breaks RIGHT WALL if valid and UNIONS Indexes
bool Maze::checkRight(int x){
	if(!RightEdge(x) && (U->findSet(x))!=U->findSet(x+1)){
		maze[x] -= 1;
		maze[x+1] -= 4;
		U->unionElements(x,x+1);
		return true;
	}
	return false;
}

// Breaks BOTTOM WALL if valid and UNIONS Indexes
bool Maze::checkBottom(int x){
	if(!BottomEdge(x) && (U->findSet(x))!=U->findSet(x+rows)){
		maze[x] -= 2;
		maze[x+rows] -= 8;
		U->unionElements(x,x+rows);
		return true;
	}
	return false;
}

// Breaks LEFT WALL if valid and UNIONS Indexes
bool Maze::checkLeft(int x){
	if(!LeftEdge(x) && (U->findSet(x))!=U->findSet(x-1)){
		maze[x] -= 4;
		maze[x-1] -= 1;
		U->unionElements(x,x-1);
		return true;
	}
	return false;
}

// Breaks TOP WALL if valid and UNIONS Indexes
bool Maze::checkTop(int x){
	if(!TopEdge(x) && (U->findSet(x))!=U->findSet(x-rows)){
		maze[x] -= 8;
		maze[x-rows] -= 2;
		U->unionElements(x,x-rows);
		return true;
	}
	return false;
}

// Index is at RIGHT EDGE
bool Maze::RightEdge(int x){
	if(x % rows == rows - 1){
		return true;
	}
	return false;
}

// Index is at BOTTOM EDGE
bool Maze::BottomEdge(int x){
	if(x / rows ==  rows -1){
		return true;
	}
	return false;	
}

// Index is at LEFT EDGE
bool Maze::LeftEdge(int x){
	if(x % rows == 0){
		return true;
	}
	return false;	
}

// Index is at TOP EDGE
bool Maze::TopEdge(int x){
	if(x <  rows){
		return true;
	}
	return false;
}

// Prints out entire Maze (testing only)
void Maze::printMaze(){
	U->showRankandParent();
	cout << "MazeTracker Array: ";
	for(int i = 0; i < size; i++){
		cout << mazeTracker[i] << " ";
	}
	cout << endl;
	cout << "MazeTrackerShuffle Array: ";
	for(int i = 0; i < size; i++){
		cout << mazeTrackerShuffle[i] << " ";
	}
	cout << endl;
	for(int j = 0; j < rows; j++){
		for(int i = 0; i < rows; i++){
			cout << maze[index(i,j)] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Prints out FINAL MAZE in Hex format
void Maze::printHexMaze(){
	for(int j = 0; j < rows; j++){
		for(int i = 0; i < rows; i++){
				cout << std::hex << maze[index(i,j)];
		}
		cout << endl;
	}
	cout << endl;
}

