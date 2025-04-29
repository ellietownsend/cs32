//
//  mazequeue.cpp
//  project_two
//
//  Created by Ellie Townsend on 4/26/25.
//
/*
#include <queue>
#include <iostream>
using namespace std;
class Coord
        {
          public:
            Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
            int r() const { return m_r; }
            int c() const { return m_c; }
          private:
            int m_r;
            int m_c;
        };
bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    sr -= 1;
    sc -=1;
    er -= 1;
    ec -= 1;
    queue<Coord> queueCoords;
    queueCoords.push(Coord(sr, sc));
    while(!queueCoords.empty()){
        Coord visitNext = queueCoords.front();
        //Specify what row and column we will intent to visit next
        int r = visitNext.r();
        int c = visitNext.c();
        cout << "Index dequeued: " << r << "," << c << endl;
        if(r == er && c == ec){
            return true;
        }
        //Go to that index (pop it off because we already visited it)
        queueCoords.pop();
        
        if(maze[r+1][c] == '.'){
            queueCoords.push(Coord(r+1,c));
            maze[r+1][c] = 'V';
        }
        if(maze[r][c-1] == '.'){
            queueCoords.push(Coord(r,c-1));
            maze[r][c-1] = 'V';
        }
        if(maze[r-1][c] == '.'){
            queueCoords.push(Coord(r-1,c));
            maze[r-1][c] = 'V';
        }
        if(maze[r][c+1] == '.'){
            queueCoords.push(Coord(r,c+1));
            maze[r][c+1] = 'V';
        }
    }
    return false;
}

int main()
        {
            char maze[10][10] = {
                { 'X','X','X','X','X','X','X','X','X','X' },
                { 'X','.','.','.','.','X','.','.','X','X' },
                { 'X','.','X','X','.','X','X','.','.','X' },
                { 'X','X','X','.','.','.','.','X','.','X' },
                { 'X','.','X','X','X','.','X','X','X','X' },
                { 'X','.','X','.','.','.','X','.','.','X' },
                { 'X','.','.','.','X','.','X','.','.','X' },
                { 'X','X','X','X','X','.','X','.','X','X' },
                { 'X','.','.','.','.','.','.','.','.','X' },
                { 'X','X','X','X','X','X','X','X','X','X' }
            };

            if (pathExists(maze, 3,5, 8,8))
                cout << "Solvable!" << endl;
            else
                cout << "Out of luck!" << endl;
        }
*/
