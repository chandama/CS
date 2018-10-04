	#include "Pathfinder.h"
	string Pathfinder::toString() const
	{
		stringstream ss;
		//Nested for loop that will print out 2d maze layer 5 times for each depth layer
	    for (int depth = 0; depth < Z_SIZE; depth++) {
		    for(int row = 0; row < ROW_SIZE; row++) {
				for(int col = 0; col < COL_SIZE; col++) {
					ss << current_maze[row][col][depth] << " ";
				}
				ss << endl;
		    }
		    if (depth < Z_SIZE - 1) {
		    	ss << endl;
		    }
	    }
	    return ss.str();
	}


	void Pathfinder::createRandomMaze()
	{
		for (int x = 0; x < ROW_SIZE; x++) {
			for (int y = 0; y < COL_SIZE; y++) {
				for (int z = 0; z < Z_SIZE; z++) {
					if ((z==0 && y==0 && x==0) || 
						(z== Z_SIZE - 1 && y== COL_SIZE - 1 && x== ROW_SIZE - 1)) {
						current_maze[x][y][z] = 1;	
					}
					else {
						int rnum = rand()%2;
						current_maze[x][y][z] = rnum;
					}
				}
			}
		}
	}

	bool Pathfinder::importMaze(string file_name)
	{
		cout << "importMaze from "<<file_name<<endl;
		ifstream file (file_name.c_str());
		if (file.is_open()) {
	
			string line;
			int row_count = 0;
			for (int depth = 0; depth < Z_SIZE; depth++) {
				for(int row = 0; row < ROW_SIZE; row++) {
					getline(file, line);
					stringstream ss(line);
					for(int col = 0; col < COL_SIZE; col++) {
						int value;
						ss >> value;
						// cout << "["<<row<<"]["<<col<<"]="<<value<<endl;
						maze_grid[row][col][depth] = value;
					}
				}
				getline(file,line);
			}
			if (maze_grid[4][4][4] == 0 || maze_grid[0][0][0] == 0) {
				return false;
			}
	
			file.close();
		}
		else return false;
		file.open(file_name.c_str());
		if (file.is_open()) {
			int count = 0;
			char inputs;
			while (file>>inputs) {
				if (inputs == '0') {
					count++;
				}
				else if (inputs == '1') {
					count++;
				}
				//If not 0 or 1, maze is invalid
				else return false;
			}
			if (count != 125) {
		    	return false;
			}
		}
		
		for (int x = 0; x < ROW_SIZE; x++) {
			for (int y = 0; y < COL_SIZE; y++) {
				for (int z = 0; z < Z_SIZE; z++) {
					current_maze[x][y][z] = maze_grid[x][y][z];
				}
			}
		}
		return true;
	}

	
	bool Pathfinder::find_maze_path(int grid[ROW_SIZE][COL_SIZE][Z_SIZE], int r, int c, int z) {
	  
		  //cout << "find_maze_path ["<<r<<"]["<<c<<"]["<<z<<"]"<<endl;
		  //cout << this->toString();
		  if (r < 0 || c < 0 || z < 0 || r >= ROW_SIZE || c >= COL_SIZE || z >= Z_SIZE)
		    return false;      // Cell is out of bounds.
		  else if (grid[r][c][z] != BACKGROUND)
		    return false;      // Cell is on barrier or dead end.
		  else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1 && z == Z_SIZE - 1) {
		    grid[r][c][z] = PATH;         // Cell is on path
		    solution.insert(solution.begin(),"("+to_string(c)+", "+to_string(r)+", "+to_string(z)+")");
		    return true;               // and is maze exit.
		  }
		  else { 
		    // Recursive case.
		    // Attempt to find a path from each neighbor.
		    // Tentatively mark cell as on path.
		    
		    //just fix this part for the or statements to figure out z stuff
		    grid[r][c][z] = PATH;
		    if (find_maze_path(grid, r - 1, c, z)
		        || find_maze_path(grid, r + 1, c, z)
		        || find_maze_path(grid, r, c - 1, z)
		        || find_maze_path(grid, r, c + 1, z)
		        || find_maze_path(grid, r, c, z - 1)
		        || find_maze_path(grid, r, c, z + 1) ) {
		      solution.insert(solution.begin(), "("+to_string(c)+", "+to_string(r)+", "+to_string(z)+")");
		      return true;
		    }
		    else {
		      grid[r][c][z] = TEMPORARY;  // Dead end.
		      return false;
		    }
		  }
		}

	
	vector<string> Pathfinder::solveMaze()
	{
	int tempgrid[ROW_SIZE][COL_SIZE][Z_SIZE];
		for (int x = 0; x < ROW_SIZE; x++) {
			for (int y = 0; y < COL_SIZE; y++) {
				for (int z = 0; z < Z_SIZE; z++) {
					tempgrid[x][y][z] = current_maze[x][y][z];
				}
			}
		}
		solution.clear();
		find_maze_path(tempgrid, 0, 0, 0);
		for(auto s:solution) {
			//cout <<s<<endl;
		}
		
	    return solution;
	}
