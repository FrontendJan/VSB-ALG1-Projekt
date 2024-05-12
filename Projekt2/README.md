# Orange Rot Simulation

This project simulates the spread of rot among oranges in a rectangular grid. The goal is to determine the minimum time required for all the oranges to become rotten, or -1 if some oranges remain fresh.

## Problem Description

You are given a rectangular grid representing a storage area for oranges. Each cell in the grid can be in one of three states:

- Empty (0)
- Fresh orange (1)
- Rotten orange (2)

Initially, some oranges may already be rotten. A rotten orange spreads the rot to its four adjacent neighbors (up, down, left, and right) in the next time step. The rot spreads continuously until there are no more fresh oranges left.

The task is to implement a function that takes the initial state of the grid as input and returns the minimum time required for all oranges to become rotten, or -1 if some oranges remain fresh.

## Implementation

The project is implemented in C++ and consists of the following files:

- `main.cpp`: Contains the `main` function that reads input files, creates instances of the `Grid` class, and prints the results.
- `Grid.h`: Header file that declares the `Grid` class, which represents the grid of oranges.
- `Grid.cpp`: Implementation file for the `Grid` class, containing the member function definitions, including the core algorithm to simulate the rot.

The `Grid` class provides the following functionalities:

- Initialize the grid with the given initial state.
- Check if a position is within the grid boundaries.
- Simulate the rot and return the minimum time required for all oranges to rot (or -1 if some remain fresh).

## Usage

1. Compile the source files (`main.cpp` and `Grid.cpp`) using a C++ compiler.
2. Provide input files containing the initial state of the grid in the following format:
   - The first line should contain the number of rows (`m`).
   - The second line should contain the number of columns (`n`).
   - The following `m` lines should represent the initial state of the grid, with each line containing `n` integers (0 for empty, 1 for fresh orange, 2 for rotten orange).
3. Run the compiled program and specify the input file names or paths.
4. The program will process each input file, simulate the rot, and print the minimum time required for all oranges to rot (or -1 if some oranges remain fresh).

## Documentation

The code is documented using Doxygen-style comments. To generate the documentation, follow these steps:

1. Install Doxygen on your system.
2. Navigate to the project directory.
3. Run the `doxygen` command with the provided `Doxyfile` configuration file.
4. The generated documentation will be available in the `doc/html` directory, and you can open the `index.html` file in a web browser to browse the documentation.

## Contributing

If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.