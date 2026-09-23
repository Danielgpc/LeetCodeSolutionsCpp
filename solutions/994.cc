#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int gr = grid.size(), gc = grid[0].size(), all = gc * gr, temp = 0;
    vector<vector<int>> goTo;
    for (int i = 0; i < gr; i++) {
      for (int j = 0; j < gc; j++) {
        if (grid[i][j] == 2) {
          goTo.push_back({i, j});
        } else if (grid[i][j] == 0) {
          temp++;
        }
      }
    }
    if (all == temp) {
      return 0;
    }
    if (goTo.empty()) {
      return -1;
    }
    vector<vector<int>> toGo;
    int em = 0;
    while (true) {
      if (goTo.empty() and !toGo.empty()) {
        em++;
        goTo = toGo;
        toGo.clear();
        continue;
      } else if (goTo.empty() and toGo.empty()) {
        break;
      }
      vector<int> x = goTo.back();
      goTo.pop_back();
      int xr = x[0], xc = x[1];
      if (xr + 1 < gr && grid[xr + 1][xc] == 1) {
        toGo.push_back({xr + 1, xc});
        grid[xr + 1][xc] = 2;
      }
      if (xr - 1 >= 0 && grid[xr - 1][xc] == 1) {
        toGo.push_back({xr - 1, xc});
        grid[xr - 1][xc] = 2;
      }
      if (xc + 1 < gc && grid[xr][xc + 1] == 1) {
        toGo.push_back({xr, xc + 1});
        grid[xr][xc + 1] = 2;
      }
      if (xc - 1 >= 0 && grid[xr][xc - 1] == 1) {
        toGo.push_back({xr, xc - 1});
        grid[xr][xc - 1] = 2;
      }
    }
    for (int i = 0; i < gr; i++) {
      for (int j = 0; j < gc; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return em;
  }
};
