#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include "UnionFind.h"
#include "Maze.h"

int main(int argc, char** argv){
	if(argc == 1){
		cout << "no cli input. input a number n to make an nxn maze." << endl;
		return 0;
	}
	else if(argc == 2){
		int n = atoi (argv[1]);
		if(n < 3){
			cout << "invalid input. enter a number greater than 3" << endl;
		}
		else{
		Maze M(n);
		M.generateMaze();
		M.printHexMaze();
		}
	}
	else{
		cout << "invalid input. input a number n to make an nxn maze." << endl;
		return 0;
	}   
    return 0; 
