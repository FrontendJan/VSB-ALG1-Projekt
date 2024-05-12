#ifndef GRID_H
#define GRID_H

#include <vector>

using namespace std;

/**
 * @brief Class representing a grid of oranges.
 */

class Grid {
private:
    int rows;   
    int cols;
    vector<vector<int>> grid;

public:

    /**
     * @brief Constructor to initialize the grid dimensions.
     * @param m Number of rows
     * @param n Number of columns
     */

    Grid(int m, int n);

        /**
     * @brief Check if a given position is within the grid boundaries.
     * @param row Row index
     * @param col Column index
     * @return True if the position is valid, false otherwise
     */

    bool isValidPosition(int row, int col);

        /**
     * @brief Initialize the grid with the given initial state.
     * @param initialState Initial state of the grid
     */

    void initializeGrid(const vector<vector<int>>& initialState);

        /**
     * @brief Simulate the rot and return the minimum time required for all oranges to rot (or -1 if some remain fresh).
     * @return Minimum time required for all oranges to rot (or -1 if some remain fresh)
     */

    int simulateRot();
};

#endif