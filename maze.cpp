#include "maze.h"
#include <functional>

using namespace std;

bool Maze::can_escape(Location start){
    if(!maze[start.first][start.second]){
        return false;
    }
    if (
        start.first == 0 || 
        start.first == num_rows - 1 || 
        start.second == 0 || 
        start.second == num_cols - 1
    ) {
        return true;
    }
    else if(
        can_escape(Location(start.first + 1, start.second)) ||
        can_escape(Location(start.first - 1, start.second)) ||
        can_escape(Location(start.first, start.second + 1)) ||
        can_escape(Location(start.first, start.second - 1))
    ){
        return true;
    }
    else{
        return false;
    }
    
    return false;
}

vector<Location> Maze::escape_path(Location start) {
 
     
}