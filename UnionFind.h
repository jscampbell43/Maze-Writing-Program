/*                                                                                 
James Campbell                                                                     
Pengo Account: jcampbel@pengo                                                      
Email: jscampbell43@gmail.com                                                      
UnionFind.h                                                                           
Assignment 6 Maze Generation with Disjoint Sets                                     
 */ 
 
#ifndef UNIONFIND_H
#define UNIONFIND_H
 
#include <iostream>
using namespace std;

class UnionFind{
	public:
		UnionFind();// Default Constructor
		UnionFind(int n);// Constructor creates maze of size nxn
		~UnionFind();// Destructor
		void showRankandParent();// Prints Rank and Parent arrays
		void makeSet(int x);// Initialize parent and rank of x
		void unionElements(int x, int y);// Link IF elements in different sets
		void linkElements(int x, int y);// Combine elements into same set
		int findSet(int x);// Finds which set x element is in
		// Helper function to determine if element x and y are in the same set
		bool sameComponent(int x, int y){return findSet(x) == findSet(y);}
		int numberOfSets();// Helper function returns current number of sets
	private:
		int* rank;// Array pointer for Rank
		int* parent;// Array pointer for Parent
		int numOfSets;// Stores number of sets
		int size;// Stores size of all the elements
};
 
#endif
