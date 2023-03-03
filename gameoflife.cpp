#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

const int WIDTH = 60; // Grid width
const int HEIGHT = 56; // Grid height

vector<vector<int>> grid(WIDTH, vector<int>(HEIGHT));

void printGrid() {
    clrscr();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if(grid[x][y]==0){cout<<" "; continue;}
            cout << "O";
        }
        cout << endl;
    }
    cout << endl;
    //sleep(1);
    this_thread::sleep_for(chrono::milliseconds(80));
}

void updateGrid() {
    vector<vector<int>> newGrid(WIDTH, vector<int>(HEIGHT));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int newX = x + i;
                    int newY = y + j;
                    if (newX < 0) newX = WIDTH - 1;
                    if (newX >= WIDTH) newX = 0;
                    if (newY < 0) newY = HEIGHT - 1;
                    if (newY >= HEIGHT) newY = 0;
                    if (grid[newX][newY] == 1) neighbors++;
                }
            }
            if (grid[x][y] == 1 && (neighbors == 2 || neighbors == 3)) newGrid[x][y] = 1;
            else if (grid[x][y] == 0 && neighbors == 3) newGrid[x][y] = 1;
        }
    }
    grid = newGrid;
}

int main() {

//Ship go brrrrrr
    grid[1][0] = 1;
    grid[2][1] = 1;
    grid[0][2] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
	
     while(1) {
        printGrid();
        updateGrid();
    }

    return 0;
}
