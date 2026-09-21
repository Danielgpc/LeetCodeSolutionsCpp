#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix) {
    int rows = matrix.size(), columns = matrix[0].size();
    vector<vector<int>> out(columns, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        out[j][i] = matrix[i][j];
      }
    }

    return out;
  }
};
