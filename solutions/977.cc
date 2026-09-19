#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int ns = nums.size();
    vector<int> out(ns);
    int i = 0, j = ns - 1;
    int ind = ns - 1;

    while (i < j) {
      int pi = nums[i] * nums[i], pj = nums[j] * nums[j];
      if (pi > pj) {
        out[ind] = pi;
        ind--;
        i++;
      } else {
        out[ind] = pj;
        ind--;
        j--;
      }
    }
    int pi = nums[i] * nums[i], pj = nums[j] * nums[j];
    if (i == j) {
      out[ind] = max(pi, pj);
    }

    return out;
  }
};
