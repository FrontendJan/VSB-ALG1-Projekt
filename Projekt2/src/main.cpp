#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Grid.h"

using namespace std;

/**
 * @brief Main function to read input files, simulate the rot, and print the result.
 * @return 0 on successful execution
 */


int main() {
    vector<string> inputFiles = {"store1.txt", "store2.txt", "store3.txt", "store4.txt", "store5.txt", "store6.txt", "store10x20a.txt", "store10x20b.txt", "store100x200a.txt", "store100x200b.txt"};

    for (const string& filename : inputFiles) {
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            int m, n;
            inputFile >> m >> n;

            vector<vector<int>> initialState(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                string row;
                inputFile >> row;
                for (int j = 0; j < n; j++) {
                    initialState[i][j] = row[j] - '0'; // Convert char to int
                }
            }

            inputFile.close();

            Grid orangeGrid(m, n);
            orangeGrid.initializeGrid(initialState);

            int minTime = orangeGrid.simulateRot();
            cout << "Minimum time required for all oranges to rot (or -1) in " << filename << ": " << minTime << endl;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    return 0;
}