#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.empty())
      return true;
    int i = 0, j = 0;
    int is = s.size(), js = t.size();
    while (i < is and j < js) {
      if (s[i] == t[j]) {
        i++;
        if (i == is) {
          return true;
        }
      }
      j++;
    }
    return false;
  }
};
