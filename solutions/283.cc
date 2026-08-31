#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int r = 0, w = 0;
    while (r < nums.size()) {
      if (nums[r] != 0) {
        swap(r, w);
        w++;
        r++;
      } else
        r++;
    }
  }
};
