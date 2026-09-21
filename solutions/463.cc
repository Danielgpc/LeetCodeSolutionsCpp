#include <vector>

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int res = 0, rs = grid.size(), cs = grid[0].size();
    vector<vector<int>> goTo;
    bool flag = true;
    for (int i = 0; i < rs and flag; i++) {
      for (int j = 0; j < cs and flag; j++) {
        if (grid[i][j] == 1) {
          flag = false;
          goTo.push_back({i, j});
          grid[i][j] = -1;
        }
      }
    }

    while (!goTo.empty()) {
      vector<int> x = goTo.back();
      goTo.pop_back();
      int xr = x[0], xc = x[1];
      if (xr + 1 < rs and grid[xr + 1][xc] == 1) {
        goTo.push_back({xr + 1, xc});
        grid[xr + 1][xc] = -1;
      } else if (!(xr + 1 < rs and grid[xr + 1][xc] == -1)) {
        res++;
      }
      if (xr - 1 >= 0 and grid[xr - 1][xc] == 1) {
        goTo.push_back({xr - 1, xc});
        grid[xr - 1][xc] = -1;
      } else if (!(xr - 1 >= 0 and grid[xr - 1][xc] == -1)) {
        res++;
      }
      if (xc + 1 < cs and grid[xr][xc + 1] == 1) {
        goTo.push_back({xr, xc + 1});
        grid[xr][xc + 1] = -1;
      } else if (!(xc + 1 < cs and grid[xr][xc + 1] == -1)) {
        res++;
      }
      if (xc - 1 >= 0 and grid[xr][xc - 1] == 1) {
        goTo.push_back({xr, xc - 1});
        grid[xr][xc - 1] = -1;
      } else if (!(xc - 1 >= 0 and grid[xr][xc - 1] == -1)) {
        res++;
      }
    }
    return res;
  }
};
