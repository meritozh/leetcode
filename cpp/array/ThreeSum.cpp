/**
 * Description:
 *
 * Given an array `S` of `n` integers, are there elements `a, b, c` in `S` such
 * that `a + b + c = 0`? Find all unique triplets in the array which given the
 * sum of zero.
 *
 * Note:
 * - Elements in a triplet `(a, b, c)` must be in non-descending order.
 *   (ie, a <= b <= c)
 * - The solution set must not contain duplicate triplets.
 *
 * For example, given array `S = {-1, 0, 1, 2, -1, -4}`.
 *
 * A solution set is:
 * (-1, 0, 1) (-1, -1, 2)
 */

#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> ThreeSum(std::vector<int> &Nums) {
    std::vector<std::vector<int>> R;
    if (Nums.size() < 3) {
      return R;
    }

    std::sort(Nums.begin(), Nums.end());
    const int Target = 0;
    for (auto I = Nums.begin(), Last = Nums.end(); I < Last - 2; ++I) {
      // (I, J, K) is the result. We cannot seek twice when I doesn't
      // changed.
      if (I > Nums.begin() && *I == *(I - 1)) {
        continue;
      }
      auto J = I + 1;
      auto K = Last - 1;
      while (J < K) {
        if (*I + *J + *K < Target) {
          ++J;
          // Same reason with J.
          while (*J == *(J - 1) && J < K) {
            ++J;
          }
        } else if (*I + *J + *K > Target) {
          --K;
          // Same reason with K.
          while (*K == *(K + 1) && J < K) {
            --K;
          }
        } else {
          R.push_back({*I, *J, *K});
          ++J;
          --K;
          while (*J == *(J - 1) && J < K) {
            ++J;
          }
          while (*K == *(K + 1) && J < K) {
            --K;
          }
        }
      }
    }

    return R;
  }
};

int main() {
  std::vector<int> In = {-1, 0, 1, 2, -1, -4};
  auto R = Solution().ThreeSum(In);
  auto E = R == std::vector<std::vector<int>>({{-1, 0, 1}, {-1, -1, 2}}) ||
           R == std::vector<std::vector<int>>({{-1, -1, 2}, {-1, 0, 1}});
  assert(E);

  return 0;
}