#include "Grid.h"
#include <queue>

/**
 * @brief Constructor to initialize the grid dimensions.
 * @param m Number of rows
 * @param n Number of columns
 */

Grid::Grid(int m, int n) {
    rows = m;
    cols = n;
    grid = vector<vector<int>>(rows, vector<int>(cols, 0));
}


/**
 * @brief Check if a given position is within the grid boundaries.
 * @param row Row index
 * @param col Column index
 * @return True if the position is valid, false otherwise
 */

bool Grid::isValidPosition(int row, int col) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}


/**
 * @brief Initialize the grid with the given initial state.
 * @param initialState Initial state of the grid
 */

void Grid::initializeGrid(const vector<vector<int>>& initialState) {
    grid = initialState;
}

/**
 * @brief Simulate the rot and return the minimum time required for all oranges to rot (or -1 if some remain fresh).
 * @return Minimum time required for all oranges to rot (or -1 if some remain fresh)
 */

int Grid::simulateRot() {
    int fresh = 0;
    queue<pair<int, int>> rottenQueue;

    // Count initial fresh oranges and enqueue initial rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            } else if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            }
        }
    }

    // If there are no fresh oranges initially, return 0
    if (fresh == 0) {
        return 0;
    }

    // If there are no rotten oranges initially, return -1
    if (rottenQueue.empty()) {
        return -1;
    }

    int time = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!rottenQueue.empty() && fresh > 0) {
        int size = rottenQueue.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> pos = rottenQueue.front();
            rottenQueue.pop();
            int x = pos.first;
            int y = pos.second;

            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (isValidPosition(newX, newY) && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    rottenQueue.push({newX, newY});
                    fresh--;
                }
            }
        }
        time++;
    }

    return (fresh == 0) ? time : -1;
}