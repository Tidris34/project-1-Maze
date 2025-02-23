/*
 * maze.h -- Defines maze class for Project #1 in CS 124
 * Based on Programming Project 11.47.7 in Horstmann
 *
 * Michael McThrow
 * CS 124
 * Ohlone College
 */
#ifndef _MAZE_H_
#define _MAZE_H_

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using Location = std::pair<unsigned int, unsigned int>;

class Maze
{
private:
    bool **maze;
    unsigned int num_rows;
    unsigned int num_cols;

public:
    Maze(const bool **maze, unsigned int num_rows, unsigned int num_cols)
    {
        this->maze = new bool *[num_rows];
        for (int i = 0; i < num_rows; i++)
            this->maze[i] = new bool[num_cols];

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                this->maze[i][j] = maze[i][j];
            }
        }

        this->num_rows = num_rows;
        this->num_cols = num_cols;
    }

    Maze(const std::string &maze_filename)
    {
        std::ifstream input(maze_filename);
        std::vector<std::string> lines;

        while (!input.eof())
        {
            std::string current_line;
            std::getline(input, current_line);
            lines.push_back(current_line);
        }

        num_rows = lines.size();
        num_cols = lines[0].length();

        maze = new bool *[num_rows];
        for (int i = 0; i < num_rows; i++)
            maze[i] = new bool[num_cols];

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                char c = lines[i][j];
                maze[i][j] = (c == ' ');
            }
        }
    }

    ~Maze()
    {
        for (int i = 0; i < num_rows; i++)
            delete[] this->maze[i];

        delete[] this->maze;
    }

    void print_maze()
    {
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                std::cout << (maze[i][j] ? ' ' : '*');
            }
            std::cout << std::endl;
        }
    }

    unsigned int get_num_rows()
    {
        return num_rows;
    }

    unsigned int get_num_cols()
    {
        return num_cols;
    }

    // Implement this function in maze.cpp
    bool can_escape(Location starting_point);

    // Implement this function in maze.cpp
    std::vector<Location> escape_path(Location starting_point);
};

#endif // _MAZE_H_
