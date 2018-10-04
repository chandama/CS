#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PathfinderInterface.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

/*
WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int Z_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2;
const int PATH = 3;

class Pathfinder: public PathfinderInterface
{
public:
	Pathfinder() {
		srand(13);
		for (int x = 0; x < ROW_SIZE; x++) {
			for (int y = 0; y < COL_SIZE; y++) {
				for (int z = 0; z < Z_SIZE; z++) {
					maze_grid[x][y][z] = 1;
					current_maze[x][y][z] = 1;
				}
			}
		}
	}
	~Pathfinder() {}
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
protected:
	bool find_maze_path(int grid[ROW_SIZE][COL_SIZE][Z_SIZE], int r, int c, int z);
	vector<string> solution;
	int maze_grid[ROW_SIZE][COL_SIZE][Z_SIZE];
	int current_maze[ROW_SIZE][COL_SIZE][Z_SIZE];
	
};
