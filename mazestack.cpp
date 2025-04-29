//
//  mazestack.cpp
//  project_two
//
//  Created by Ellie Townsend on 4/25/25.
//
/*
#include <stack>
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
    //If the destination is equal to the starting point:
    //Make a stack of cords
    stack<Coord> coordStack;
    //Push a the starting coordinate on the stack
    sr -= 1;
    sc -=1;
    er -= 1;
    ec -= 1;
    Coord a(sr, sc);
    coordStack.push(a);
    maze[sr][sc] = 'V';
    
    //Keep going until we have visited the destination OR there is no where left to go
    while(!coordStack.empty()){
        Coord startingPoint = coordStack.top();
        coordStack.pop();
        int r = startingPoint.r();
        int c = startingPoint.c();
        cout << "Currently popped off stack: " << r << "," << c << endl;
        if (r == er && c == ec){
            return true;
        }
        //Check if we can move south
        if(maze[r+1][c] == '.'){
            //Create a coord object for our visted index
            Coord s(r+1, c);
            //Push that coord object onto the stack
            coordStack.push(s);
            //Mark visited as index
            maze[r+1][c] = 'V';
        }
        //Check if we can move west
        if(maze[r][c-1] == '.'){
            //Create a coord object for out revisted index
            Coord w(r, c-1);
            //Push that coord object onto the stack
            coordStack.push(w);
            //Mark visited as index
            maze[r][c-1] = 'V';
        }
        //Check if we can move north
        if(maze[r-1][c] == '.'){
            //Create a coord object for out revisted index
            Coord n(r-1, c);
            //Push that coord object onto the stack
            coordStack.push(n);
            //Mark visited as index
            maze[r-1][c] = 'V';
        }
        //Check if we can move east
        if(maze[r][c+1] == '.'){
            Coord e(r, c+1);
            coordStack.push(e);
            maze[r][c+1] = 'V';
        }
    }
    return false;
}*/
