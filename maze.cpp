#include "maze.h"
#include <vector>
using std::vector;

bool canEscapeHelper(bool **maze, unsigned int numRows, unsigned int numCols,
                     int row, int col, vector<vector<bool>> &visited)
{
    if (row == 0 || col == 0 || row == static_cast<int>(numRows) - 1 ||
        col == static_cast<int>(numCols) - 1)
        return true;
    visited[row][col] = true;
    if (row > 0 && maze[row - 1][col] && !visited[row - 1][col] &&
        canEscapeHelper(maze, numRows, numCols, row - 1, col, visited))
        return true;
    if (row < static_cast<int>(numRows) - 1 && maze[row + 1][col] && !visited[row + 1][col] &&
        canEscapeHelper(maze, numRows, numCols, row + 1, col, visited))
        return true;
    if (col > 0 && maze[row][col - 1] && !visited[row][col - 1] &&
        canEscapeHelper(maze, numRows, numCols, row, col - 1, visited))
        return true;
    if (col < static_cast<int>(numCols) - 1 && maze[row][col + 1] && !visited[row][col + 1] &&
        canEscapeHelper(maze, numRows, numCols, row, col + 1, visited))
        return true;
    return false;
}

bool escapePathHelper(bool **maze, unsigned int numRows, unsigned int numCols,
                      int row, int col, vector<vector<bool>> &visited,
                      vector<Location> &path)
{
    visited[row][col] = true;
    path.push_back({static_cast<unsigned int>(row), static_cast<unsigned int>(col)});
    if (row == 0 || col == 0 || row == static_cast<int>(numRows) - 1 ||
        col == static_cast<int>(numCols) - 1)
        return true;
    if (row > 0 && maze[row - 1][col] && !visited[row - 1][col] &&
        escapePathHelper(maze, numRows, numCols, row - 1, col, visited, path))
        return true;
    if (row < static_cast<int>(numRows) - 1 && maze[row + 1][col] && !visited[row + 1][col] &&
        escapePathHelper(maze, numRows, numCols, row + 1, col, visited, path))
        return true;
    if (col > 0 && maze[row][col - 1] && !visited[row][col - 1] &&
        escapePathHelper(maze, numRows, numCols, row, col - 1, visited, path))
        return true;
    if (col < static_cast<int>(numCols) - 1 && maze[row][col + 1] && !visited[row][col + 1] &&
        escapePathHelper(maze, numRows, numCols, row, col + 1, visited, path))
        return true;
    path.pop_back();
    return false;
}

bool Maze::can_escape(Location startingPoint)
{
    unsigned int startRow = startingPoint.first, startCol = startingPoint.second;
    if (startRow >= num_rows || startCol >= num_cols || !maze[startRow][startCol])
        return false;
    if (startRow == 0 || startCol == 0 || startRow == num_rows - 1 || startCol == num_cols - 1)
        return true;
    vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
    return canEscapeHelper(maze, num_rows, num_cols, static_cast<int>(startRow),
                           static_cast<int>(startCol), visited);
}

vector<Location> Maze::escape_path(Location startingPoint)
{
    vector<Location> path;
    unsigned int startRow = startingPoint.first, startCol = startingPoint.second;
    if (startRow >= num_rows || startCol >= num_cols || !maze[startRow][startCol])
        return path;
    if (startRow == 0 || startCol == 0 || startRow == num_rows - 1 || startCol == num_cols - 1)
    {
        path.push_back(startingPoint);
        return path;
    }
    vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
    if (escapePathHelper(maze, num_rows, num_cols, static_cast<int>(startRow),
                         static_cast<int>(startCol), visited, path))
        return path;
    return vector<Location>();
}
