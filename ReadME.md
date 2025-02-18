# Maze Escape Project - CS 124

## Overview
This project involves implementing recursive solutions in C++ to solve and navigate a maze. The provided `maze.h` defines a `Maze` class with constructors and member functions that need to be implemented in `maze.cpp`.

## Project Details
- **Course:** CS 124 Section 03 – Spring 2025
- **Instructor:** Michael McThrow, Ohlone College
- **Due Date:** Tuesday, February 18 at 11:59 PM PST
- **Purpose:** Gain experience with recursive functions in C++.

## Maze Description
A maze is described by a text file containing spaces and `*` characters. Spaces represent open paths (`true`), while `*` represents walls (`false`).

### What You Need to Do:
1. **Implement `can_escape(Location start)`:**
   - This function takes a starting location and checks recursively if there is a path to an exit.
   - Return `true` if an escape path exists, otherwise `false`.

2. **Implement `escape_path(Location start)`:**
   - This function also takes a starting location but returns the full path as a `std::vector<Location>`.
   - The path should start from the given location and end at the exit, including all intermediate points.

3. **Write Helper Functions:**
   - You can add helper functions in `maze.cpp` to break down complex operations.
   - All helper functions must be recursive.

4. **Ensure No Forbidden Constructs:**
   - No loops, `goto`, `setjmp`, `longjmp`, or any form of iteration.

### Examples and Diagrams:
- **Maze Layout Example:**
```
* *******
*     * *
* ***** *
* * *   *
*S* *** *
*   *   *
*** * * *
*     * *
******* *
```
- **Shortest Path from (4,1):**
```
[(4,1), (3,1), (2,1), (1,1), (0,1)]
```

### Submission Guidelines:
- Submit only `maze.cpp`.
- Do not modify `maze.h`.
- No `main` function in `maze.cpp`.

### Grading and Requirements:
- Individual project; no collaboration.
- Code must compile with Clang C++ on Debian Linux.
- Automated grading will be used.
- Non-recursive solutions will receive zero credit.

---

This README details the exact requirements, tasks, and constraints for the Maze Escape project, ensuring you know precisely what needs to be done and how to succeed.

