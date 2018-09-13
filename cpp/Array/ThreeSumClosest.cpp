/**
 * Description:
 *
 * Given an array `S` of `n` integers, find three integers in `S` such that the
 * sum is closest to a given number, target. Return the sum of three integers.
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array `S = {-1, 2, 1, -4}`, and `target = 1`.
 *
 * The sum that is closest to the target is 2 (-1 + 2 + 1 = 2).
 */

#include <vector>
#include <numeric>
#include <cassert>

class Solution {
public:
  int ThreeSumClosest(std::vector<int>& Nums, int Target) {
    if (Nums.size() == 3) {
      return std::accumulate(Nums.begin(), Nums.end(), 0);
    }

    std::sort(Nums.begin(), Nums.end());
    int R = INT_MAX;
    int MinS = 0;

    for (auto I = Nums.begin(), Max = Nums.end(); I < Max - 2; ++I) {
      auto J = I + 1;
      auto K = Max - 1;
      while (J < K) {
        auto S = *I + *J + *K;
        if (std::abs(S - Target) < R) {
          MinS = S;
          R = std::abs(S - Target);
        }
        if (R == 0) {
          return MinS;
        } else if (S < Target) {
          ++J;
        } else {
          --K;
        }
      }
    }

    return MinS;
  }
};

int main() {
  std::vector<int> In = {-1, 2, 5, -4};
  assert(Solution().ThreeSumClosest(In, 1) == 0);

  return 0;
}