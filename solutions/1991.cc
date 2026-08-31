#include <vector>

using namespace std;

class Solution {
public:
  int findMiddleIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    // Single loop checking 0 through n-1 in order
    for (int i = 0; i < n; i++) {
      int left = (i == 0) ? 0 : prefix[i - 1];
      int right = prefix.back() - prefix[i];
      if (left == right)
        return i;
    }

    return -1;
  }
};
