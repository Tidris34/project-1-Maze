#include "maze.h"
#include <iostream>
#include "maze.cpp"

using namespace std;

int main()
{
    unsigned int rows = 5;
    unsigned int cols = 5;

    const bool *maze[rows] = {
        new bool[cols]{false, true, false, false, false},
        new bool[cols]{false, true, true, true, false},
        new bool[cols]{false, false, false, true, false},
        new bool[cols]{false, true, true, true, false},
        new bool[cols]{false, false, false, true, true},
    };

    Maze maze1((const bool **)maze, rows, cols);
    Location start(2, 3);

    maze1.print_maze();
    maze1.can_escape(start) ? cout << "yes it can" : cout << "no it can't";

    vector path = maze1.escape_path(start);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << " " << path[i].second << endl;
    }

    // cout << maze1.can_escape(start) ? "yes it can": "no it can't";
    //  Free dynamically allocated memory
    for (int i = 0; i < rows; ++i)
    {
        delete[] maze[i];
    }

    return 0;
}