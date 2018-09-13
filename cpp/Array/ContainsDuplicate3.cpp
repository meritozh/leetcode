/**
 * Description:
 *
 * Given an array of integers, find out whether there are two distinct indices
 * `i` and `j` in the array such that the difference between `nums[i]` and
 * `nums[j]` is at most `t` and the difference between `i` and `j` is at most
 * `k`.
 */

#include <set>
#include <vector>
#include <algorithm>

class Solution {
public:
  bool ContainsDuplicate(std::vector<int>& Nums, int T, int K) {
    std::multiset<int> S(Nums.begin(), Nums.end());

    for (auto I = S.begin(), Max = S.end(); I != Max; ++I) {
      auto LIter = S.lower_bound(*I - T);
      auto RIter = S.upper_bound(*I + T);

      auto E1 = *I;
      auto E2 = *LIter;
      auto E3 = *RIter;

      if (LIter == S.end() || RIter == S.end()) {
        continue;
      }
      auto N = std::find(Nums.begin(), Nums.end(), *I);
      for (auto L = LIter, R = RIter; L != R; ++L) {
        auto M = std::find(Nums.begin(), Nums.end(), *L);
        if (M == N) {
          continue;
        }
        if (std::abs(M - N) <= K) {
          return true;
        }
      }
    }

    return false;
  }
};

int main() {
  std::vector<int> In = {2, 8, 1, 6, 3, 8, 9, 12};
  assert(Solution().ContainsDuplicate(In, 2, 2) == true);

  return 0;
}