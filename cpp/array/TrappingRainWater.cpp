/**
 * Description:
 *
 * Given `n` non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, Given `[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`, return `6`.
 *
 *  ^
 *  |
 *  |
 *  |                                      3
 *  |                                    +----+
 *  |                   2                |    |  2        2
 *  |                +----+ ************ +    +----+ ** +----+
 *  |        1       |    |  1         1 |    |    |  1 |    |  1
 *  |     +----+ *** +    +----+    +----+    +    +----+    +----+
 *  |  0  |    |  0  |    |    |  0 |    |    |    |    |    |    |
 *  +-----+----+-----+----+----+----+----+----+----+----+----+----+---->
 *               (1)     +       (4)         +       (1) = (6)
 */

/**
 * Analyze:
 *
 * each_trap = min(max_left, max_right) - height
 * size = sum(each_trap)
 */

#include <vector>
#include <cassert>

class Solution {
public:
  int TrappingRainWater(std::vector<int> C) {
    auto Sum = 0;
    auto MaxLeft = 0;
    auto MaxRight = 0;
    auto Bulk = std::min(C[MaxLeft], C[MaxRight]);
    for (int I = 1, Max = C.size(); I < Max; ++I) {
      if (C[I] >= C[MaxLeft]) {
        MaxLeft = I;
        continue;
      }
      if (I > MaxRight) {
        auto CurrentMax = I;
        // Find max right
        auto Right = I + 1;
        while (Right < Max) {
          if (C[Right] > C[CurrentMax]) {
            CurrentMax = Right;
          }
          ++Right;
        }
        MaxRight = CurrentMax;

        Bulk = std::min(C[MaxRight], C[MaxLeft]);
      }
      
      if (MaxRight <= I || C[MaxLeft] < C[I] || C[MaxRight] < C[I]) {
        continue;
      }

      Sum += (Bulk - C[I]);
    }
    return Sum;
  }
};

int main() {
  std::vector<int> In = {2, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  assert(Solution().TrappingRainWater(In) == 8);
  return 0;
}