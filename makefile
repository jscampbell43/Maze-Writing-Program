# Assign 6 makefile                                                                  

# define target, its dependencies and files                                        
p6: main.o UnionFind.o Maze.o
		g++ -std=c++11 -o p6 main.o UnionFind.o Maze.o

# define how each object file is to be built                                       
main.o: main.cpp UnionFind.h Maze.h
		g++ -std=c++11 -c main.cpp

UnionFind.o: UnionFind.cpp UnionFind.h 
		g++ -std=c++11 -c UnionFind.cpp

Maze.o: Maze.cpp Maze.h 
		g++ -std=c++11 -c Maze.cpp

# clean up                                                                         
clean:
		rm -f p6 *.o *~
