#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0, si = g.size(), sj = s.size();
    while (i < si and j < sj) {
      if (s[j] >= g[i]) {
        i++;
        j++;
      } else {
        j++;
      }
    }
    return i;
  }
};
