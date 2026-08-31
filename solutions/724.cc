#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    vector<int> prefixSum(nums.size());
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    int totalSum = prefixSum[nums.size() - 1];

    for (int i = 0; i < nums.size(); i++) {
      int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
      int rightSum = totalSum - prefixSum[i];

      if (leftSum == rightSum) {
        return i;
      }
    }
    return -1;
  }
};
