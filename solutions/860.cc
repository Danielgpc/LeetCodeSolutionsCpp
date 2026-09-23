#include <vector>

using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int fives = 0, tens = 0;
    int bs = bills.size();
    for (int i = 0; i < bs; i++) {
      if (bills[i] == 5) {
        fives++;
      } else if (bills[i] == 10 and fives > 0) {
        tens++;
        fives--;
      } else if (bills[i] == 20 and fives > 0 and tens > 0) {
        tens--;
        fives--;
      } else if (bills[i] == 20 and fives >= 3) {
        fives -= 3;
      } else {
        return false;
      }
    }
    return true;
  }
};
