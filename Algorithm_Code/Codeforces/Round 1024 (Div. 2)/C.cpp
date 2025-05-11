#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<vector<int>> generateOptimalGrid(int n) {
    vector<vector<int>> grid(n, vector<int>(n, -1));
    vector<bool> used(n * n, false); 
    
    if (n == 1) {
        grid[0][0] = 0;
        return grid;
    }
    
    int zeroRow = (n - 1) / 2;
    int zeroCol = (n - 1) / 2;
    
    grid[zeroRow][zeroCol] = 0;
    used[0] = true;
    
    int dx[] = {0, 1, 0, -1}; 
    int dy[] = {1, 0, -1, 0};
    int num = 1;
    int x = zeroRow, y = zeroCol;
    
    for (int step = 1; step <= n && num < n * n; step += 2) {
        y++;
        if (y < n && !used[num]) {
            grid[x][y] = num++;
            used[num - 1] = true;
        }
        
        for (int i = 0; i < step && num < n * n; i++) {
            x++;
            if (x < n && !used[num]) {
                grid[x][y] = num++;
                used[num - 1] = true;
            }
        }
        
        for (int i = 0; i < step + 1 && num < n * n; i++) {
            y--;
            if (y >= 0 && !used[num]) {
                grid[x][y] = num++;
                used[num - 1] = true;
            }
        }
        
        for (int i = 0; i < step + 1 && num < n * n; i++) {
            x--;
            if (x >= 0 && !used[num]) {
                grid[x][y] = num++;
                used[num - 1] = true;
            }
        }
        
        for (int i = 0; i < step + 1 && num < n * n; i++) {
            y++;
            if (y < n && !used[num]) {
                grid[x][y] = num++;
                used[num - 1] = true;
            }
        }
    }
    
    for (int i = 0; i < n && num < n * n; i++) {
        for (int j = 0; j < n && num < n * n; j++) {
            if (grid[i][j] == -1) {
                grid[i][j] = num++;
            }
        }
    }
    
    return grid;
}

void printGrid(const vector<vector<int>>& grid) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() 
{
	int n;
    cin >> n;
    vector<vector<int>> grid = generateOptimalGrid(n);
    printGrid(grid);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	int T = 1;
	cin >> T;
	while(T--) solve();
    
    return 0;
}