#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int out = 0, r = grid.size(), c = grid[0].size();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == '2' or grid[i][j] == '0')
          continue;
        vector<vector<int>> goTo;
        goTo.push_back({i, j});
        grid[i][j] = '2';
        while (!goTo.empty()) {
          vector<int> x = goTo.back();
          int xr = x[0], xc = x[1];
          goTo.pop_back();
          if (xr + 1 < r and grid[xr + 1][xc] == '1') {
            goTo.push_back({xr + 1, xc});
            grid[xr + 1][xc] = '2';
          }
          if (xr - 1 >= 0 and grid[xr - 1][xc] == '1') {
            goTo.push_back({xr - 1, xc});
            grid[xr - 1][xc] = '2';
          }
          if (xc + 1 < c and grid[xr][xc + 1] == '1') {
            goTo.push_back({xr, xc + 1});
            grid[xr][xc + 1] = '2';
          }
          if (xc - 1 >= 0 and grid[xr][xc - 1] == '1') {
            goTo.push_back({xr, xc - 1});
            grid[xr][xc - 1] = '2';
          }
        }
        out++;
      }
    }
    return out;
  }
};
