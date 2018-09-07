/**
 * Description:
 *
 * You are climbing a stair case. It takes `n` steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 */

#include <cassert>
#include <cmath>

class Solution {
public:
  int ClimbingStair(int N) {
    const auto S = std::sqrt(5);
    auto R = std::floor(
        (std::pow((1 + S) / 2, N + 1) + std::pow((1 - S) / 2, N + 1)) / S +
        0.5);
    return R;
  }
};

int main() {
  int In = 4;
  assert(Solution().ClimbingStair(In) == 5);
  return 0;
}