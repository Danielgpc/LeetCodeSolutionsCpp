#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.rbegin(), nums.rend());
    int ns = nums.size();
    int p1 = 0, p2 = 1, p3 = 2;
    while (true) {
      if (nums[p1] < nums[p2] + nums[p3]) {
        return nums[p1] + nums[p2] + nums[p3];
      } else if (p3 + 1 < ns) {
        p1++;
        p2++;
        p3++;
      } else {
        return 0;
      }
    }
  }
};
