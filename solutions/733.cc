#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int r = image.size(), c = image[0].size();
    int sco = image[sr][sc];
    vector<vector<int>> goTo(1, {sr, sc});
    if (sco == color)
      return image;

    while (!goTo.empty()) {
      vector<int> x = goTo.back();
      int xr = x[0], xc = x[1];
      goTo.pop_back();
      if (xr + 1 < r and image[xr + 1][xc] == sco) {
        goTo.push_back({xr + 1, xc});
      }
      if (xr - 1 >= 0 and image[xr - 1][xc] == sco) {
        goTo.push_back({xr - 1, xc});
      }
      if (xc + 1 < c and image[xr][xc + 1] == sco) {
        goTo.push_back({xr, xc + 1});
      }
      if (xc - 1 >= 0 and image[xr][xc - 1] == sco) {
        goTo.push_back({xr, xc - 1});
      }
      image[xr][xc] = color;
    }
    return image;
  }
};
