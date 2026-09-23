#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    int ss = s.size();
    int out = 0;

    int times[256] = {0};
    bool appear[256] = {false};

    for (int i = 0; i < ss; i++) {
      appear[(unsigned char)s[i]] = true;
      times[(unsigned char)s[i]]++;
    }

    bool has_odd = false;

    for (int i = 0; i < 256; i++) {
      if (appear[i]) {
        if (times[i] % 2 == 0) {
          out += times[i];
        } else {
          out += times[i] - 1;
          has_odd = true;
        }
      }
    }

    if (has_odd) {
      out += 1;
    }

    return out;
  }
};
