#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> rowMin(m, 1e9), colMax(n, 0), out;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rowMin[i] = min(rowMin[i], matrix[i][j]);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        colMax[j] = max(colMax[j], matrix[i][j]);
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == colMax[j] and rowMin[i] == matrix[i][j]) {
          out.push_back(matrix[i][j]);
        }
      }
    }
    return out;
  }
};
