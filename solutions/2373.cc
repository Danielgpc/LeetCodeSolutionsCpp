#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int gs = grid.size();
    vector<vector<int>> out(gs - 2, vector<int>(gs - 2));
    for (int i = 1; i < gs - 1; i++) {
      for (int j = 1; j < gs - 1; j++) {
        int x = max({grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                     grid[i][j - 1], grid[i][j], grid[i][j + 1],
                     grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]});
        out[i - 1][j - 1] = x;
      }
    }
    return out;
  }
};
