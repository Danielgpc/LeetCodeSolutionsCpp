#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int truckCap = 0, bts = boxTypes.size(), totalUnits = 0;
    sort(
        boxTypes.begin(), boxTypes.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });
    int ct = 0, cb = 0;

    while (truckCap < truckSize and ct < bts) {
      int boxes = min(boxTypes[ct][0], truckSize - truckCap);
      truckCap += boxes;
      totalUnits += boxes * boxTypes[ct][1];
      ct++;
    }
    return totalUnits;
  }
};
