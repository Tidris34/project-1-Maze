#include "maze.h"

using namespace std;

int main() {
    unsigned int rows = 5;  // Corrected number of rows
    unsigned int cols = 5;

    const bool* maze[rows] = {
        new bool[cols]{false, false, true, false,true},
        new bool[cols]{false, true, true, false, false},
        new bool[cols]{false, false, false, true, false},
        new bool[cols]{false, false, true, false, false},
        new bool[cols]{false, false, false, false, false},
    };

    Maze maze1((const bool**)maze, rows, cols);  // Explicit cast
    Location start(3, 2);

    maze1.print_maze();

    //cout << maze1.can_escape(start) ? "yes it can": "no it can't";
    // Free dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }

    return 0;
}