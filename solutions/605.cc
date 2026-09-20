#include <vector>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int p = 0, fs = flowerbed.size();
    if (n == 0)
      return true;
    for (int i = 0; i < fs; i++) {
      bool emptyL = (i == 0 || flowerbed[i - 1] == 0),
           emptyR = (i == fs - 1 || flowerbed[i + 1] == 0);
      if (emptyL && emptyR && flowerbed[i] == 0) {
        n--;
        flowerbed[i] = 1;
      }
      if (n == 0) {
        return true;
      }
    }
    return false;
  }
};
