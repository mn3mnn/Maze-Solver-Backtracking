//
// Created by DELL on 12/14/2022.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;



// Maze size
#define N 9

void solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], vector<vector<vector<int>>>& res);


/* A utility function to print all solutions in res */
void printAllSolutions(const vector<vector<vector<int>>> & res)
{
    if (res.empty()){
        cout << "NO Solution for the Maze.\n";
        return;
    }
    for(auto & sol : res){
        for(auto & r : sol){
            for(auto & c : r){
                cout << ' ' <<  c << ' ';
            }
            cout << '\n';
        }
        cout << "\n--------------------------------------------------\n";
    }
}

// A utility function to check if x,y is valid index for N*N maze
/// check if x, y position hasn't been visited before
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    // if (x,y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1){
        /////////////////////
        if (!sol[x][y]) {
            return true;
        }
    }
    return false;
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the paths in the
   form of 1s. */
bool solveMaze(int maze[N][N])
{
    // store the solutions for the maze
    vector<vector<vector<int>>> res;

    int sol[N][N] = {{0}};

    solveMazeUtil(maze, 0, 0, sol, res);

    // print all solutions
    printAllSolutions(res);

    return ! res.empty();
}

/* A recursive utility function to solve Maze problem */
void solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], vector<vector<vector<int>>>& res)
{
    /// if (x,y is goal)
    /// store this solution and backtrack
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        /// copy sol into tmp vector and push it to res
        vector<vector<int>> tmp(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                tmp[i][j] = sol[i][j];
            }
        }
        res.push_back(tmp);

        return;
    }
    // Check if maze[x][y] is valid
    /// and hasn't been visited before
    if(isSafe(maze, x, y, sol))
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /// try ALL directions
        // Move down
        solveMazeUtil(maze, x+1, y, sol, res);
        // move right
        solveMazeUtil(maze, x, y+1, sol,  res);
        // move up
        solveMazeUtil(maze, x - 1, y, sol, res);
        // move left
        solveMazeUtil(maze, x, y - 1, sol, res);

        /// then unmark x,y and backtrack
        sol[x][y] = 0;
    }

}


int main() {

//    NimGame_1 nim(23);
//    NimGame_2 nim(9);

//    nim.run();

    int maze[N][N]  =  {
            {1, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 0, 1},
            {0, 1, 1, 1, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 1, 0, 0, 1}
    };

    solveMaze(maze);


    system("pause");
    return 0;
}



