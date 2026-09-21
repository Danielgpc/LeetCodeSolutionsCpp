#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int mp = 0, s = 1e9;
    for (int x : prices) {
      s = min(s, x);
      mp = max(mp, x - s);
    }
    return mp;
  }
};
