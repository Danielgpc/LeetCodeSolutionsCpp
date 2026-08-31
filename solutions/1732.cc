#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    vector<int> prefix(gain.size());
    prefix[0] = gain[0];
    for (int i = 1; i < gain.size(); i++) {
      prefix[i] = prefix[i - 1] + gain[i];
    }
    int val = max(*max_element(prefix.begin(), prefix.end()), 0);
    return val;
  }
};
