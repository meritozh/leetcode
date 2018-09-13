/**
 * Description:
 *
 * Rotate an array of `n` elements to the right by `k` steps.
 *
 * For example, with `n = 7` and `k = 3`, the array `[1, 2, 3, 4, 5, 6, 7]` is
 * rotated to `[5, 6, 7, 1, 2, 3, 4]`.
 *
 * Note: Try to come up as many solutions as you can, there are at least 3
 * different ways to solve this problem.
 */

#include <algorithm>
#include <vector>

class Solution {
public:
  void RotateArray(std::vector<int> &Nums, int K) {
    auto RP = Nums.begin() + K + 1;
    std::reverse(Nums.begin(), RP);
    std::reverse(RP, Nums.end());
    std::reverse(Nums.begin(), Nums.end());
  }
};

int main() {
  std::vector<int> In = {1, 2, 3, 4, 5, 6, 7};
  Solution().RotateArray(In, 3);
  assert(In == std::vector<int>({5, 6, 7, 1, 2, 3, 4}));

  return 0;
}