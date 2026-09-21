#include <vector>

using namespace std;

class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int d1 = 0, d2 = 0, ms = mat.size();
    if (ms == 1)
      return mat[0][0];
    if (ms % 2 == 1) {
      for (int i = 0; i < ms; i++) {
        d1 += mat[i][i];
        d2 += mat[i][ms - 1 - i];
      }
      d2 -= mat[ms / 2][ms / 2];
      int sum = d2 + d1;
      return sum;
    } else {
      for (int i = 0; i < ms; i++) {
        d1 += mat[i][i];
        d2 += mat[i][ms - 1 - i];
      }
      int sum = d2 + d1;
      return sum;
    }
  }
};
