#include <vector>

using namespace std;

class Solution {
public:
  int finalPositionOfSnake(int n, vector<string> &commands) {
    vector<int> snakePos = {0, 0};
    for (string command : commands) {
      if (command == "UP") {
        snakePos[0]++;
      } else if (command == "DOWN") {
        snakePos[0]--;
      } else if (command == "RIGHT") {
        snakePos[1]++;
      } else if (command == "LEFT") {
        snakePos[1]--;
      }
    }
    return abs(snakePos[0] * n) + abs(snakePos[1]);
  }
};
