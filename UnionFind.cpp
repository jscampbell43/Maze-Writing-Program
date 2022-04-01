/*                                                                                 
James Campbell                                                                     
Pengo Account: jcampbel@pengo                                                      
Email: jscampbell43@gmail.com                                                      
UnionFind.cpp                                                                            
Assignment 6 Maze Generation with Disjoint Sets                                     
 */ 
 
#include <iostream>
using namespace std;
#include "UnionFind.h"

// Default Constructor
UnionFind::UnionFind(){
	numOfSets = 3;
	size = 3;
	rank = new int[size];
	// Initialize rank to all 0
	for(int i = 0; i < size; i++){
		rank[i] = 0;
	}
	parent = new int[size];
	// Initialize all parent to self 
	for(int i = 0; i < size; i++){
		parent[i] = i;
	}
}

// Constructor creates maze of size nxn
UnionFind::UnionFind(int n){
	numOfSets = n;
	size = n;
	rank = new int[size];
	// Initialize rank to all 0
	for(int i = 0; i < size; i++){
		rank[i] = 0;
	}
	parent = new int[size];
	// Initialize all parent to self 
	for(int i = 0; i < size; i++){
		parent[i] = i;
	}
}

// Destructor
UnionFind::~UnionFind(){
	delete [] rank;
	delete [] parent;
}

// Helper function: shows values stored in Rank, Parent arrays (testing only)
void UnionFind::showRankandParent(){
	cout << "Rank Array: ";
	for(int i = 0; i < size; i++){
		cout << rank[i] << " ";
	}
	cout << endl << "Parent Array: ";
	for(int i = 0; i < size; i++){
		cout << parent[i] << " ";
	}
	cout << endl;
	cout << "Number of sets: " << numOfSets << endl;
}

// Initialize parent and rank of x (never called - Constructors used)
void UnionFind::makeSet(int x){
	parent[x] = x;
	rank[x] = 0;
	return;
}

// Link IF elements in different sets, decrease numOfSets	
void UnionFind::unionElements(int x, int y){
	//bounds check
	if( x >= size || x < 0 || y >= size || y < 0 || x == y){
		return;
	}
	// If in same set already do nothing
	if(findSet(x) == findSet(y)){
		return;
	}
	// Otherwise call link on: (set of x, set of y)
	linkElements(findSet(x), findSet(y));
	// Decrease number of sets by 1
	numOfSets--;
	return;
}

// Combine elements into same set
void UnionFind::linkElements(int x, int y){
	//bounds check
	if( x >= size || x < 0 || y >= size || y < 0 || x == y){
		return;
	}
	// If x is larger y's parent becomes x
	if(rank[x] > rank[y]){
		parent[y] = x;
	}
	// If y is larger x's parent becomes y
	else{
		parent[x] = y;
		// If same rank
		if(rank[x] == rank[y]){
			// Promote y
			rank[y]++;
		}
	}
	return;
}

// Finds which set x element is in
int UnionFind::findSet(int x){
	// bounds check
	if( x >= size || x < 0 ){
		return -1;
	}
	// Self repairing, combines all to one parent. Recursive step
	if(x != parent[x]){
		parent[x] = findSet(parent[x]);
	}
	return parent[x];
}

// Helper function returns current number of sets
int UnionFind::numberOfSets(){
	return numOfSets;
}
