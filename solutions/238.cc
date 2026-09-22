// WARN: NOT SOLVED

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int ns = nums.size();
    vector<int> prefix(ns);
    prefix[0] = nums[0];
    for (int i = 1; i < ns; i++) {
      prefix[i] = prefix[i - 1] * nums[i];
    }
    vector<int> out(ns);
    for (int i = 1; i < ns; i++) {
      if (nums[i] != 0)
        out[i] = prefix[i] * prefix[i - 1] / nums[i];
      else
        out[i] = prefix[i] * prefix[i - 1];
    }
    return out;
  }
};
