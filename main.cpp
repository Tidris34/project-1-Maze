#include "maze.h"

using namespace std;

int main() {
    unsigned int rows = 3;  // Corrected number of rows
    unsigned int cols = 3;

    const bool* maze[3] = {
        new bool[3]{false, false, true},
        new bool[3]{false, true, true},
        new bool[3]{false, true, false}
    };

    Maze maze1((const bool**)maze, rows, cols);  // Explicit cast

    maze1.print_maze();

    // Free dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
//nigger
    return 0;
}