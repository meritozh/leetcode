/**
 * Description:
 *
 * Given an array `S` of `n` integers, are three element `a, b, c` and `d` in
 * `S` such that `a + b + c + d = target`? Find all unique quardruplets in the
 * array which gives the sum of target.
 *
 * Note:
 * - Elements in a quardruplet `(a, b, c, d)` must be in non-descending order.
 *   (ie, a <= b <= c <= d)
 * - The solution set must not contain duplicate quardruplets.
 *
 * For example, given array `S = {1, 0, -1, 0, -2, 2}`, and `target = 0`.
 *
 * A solution set is:
 * (-1, 0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2, 0, 0, 2)
 */

#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> FourSum(std::vector<int> &Nums, int Target) {
    std::vector<std::vector<int>> R;
    if (Nums.size() < 4) {
      return R;
    }

    std::sort(Nums.begin(), Nums.end());
    auto Last = Nums.end();
    // (I, J, K, L)
    for (auto I = Nums.begin(), Max = Last - 3; I < Max; ++I) {
      if (I > Nums.begin() && *I == *(I - 1)) {
        continue;
      }
      for (auto L = Last - 1, Min = I + 2; L > Min; --L) {
        if (L < Last - 1 && *L == *(L - 1)) {
          continue;
        }
        auto J = I + 1;
        auto K = L - 1;
        while (J < K) {
          auto S = *I + *J + *K + *L;
          if (S > Target) {
            --K;
            while (J < K && *K == *(K + 1)) {
              --K;
            }
            continue;
          } else if (S < Target) {
            ++J;
            while (J < K && *J == *(J - 1)) {
              ++J;
            }
            continue;
          } else {
            R.push_back({*I, *J, *K, *L});
            ++J;
            --K;
            while (J < K && *J == *(J - 1)) {
              ++J;
            }
            while (K > J && *K == *(K + 1)) {
              --K;
            }
          }
        }
      }
    }
    return R;
  }

  std::vector<std::vector<int>> ImprovedFourSum(std::vector<int> &Nums,
                                                int Target) {
    std::vector<std::vector<int>> R;
    if (Nums.size() <= 3) {
      return R;
    }
    std::sort(Nums.begin(), Nums.end());
    // <sum, {<idx1, idx2>, ...}>
    std::unordered_map<int, std::vector<std::pair<int, int>>> C;
    for (int I = 0, Max = Nums.size() - 1; I < Max; ++I) {
      for (int J = I + 1, Max = Nums.size(); J < Max; ++J) {
        C[Nums[I] + Nums[J]].push_back({I, J});
      }
    }

    for (auto I = C.begin(), Max = C.end(); I != Max; ++I) {
      auto Rest = Target - I->first;
      auto L = C.find(Rest);
      if (L != C.end()) {
        auto Partial1 = I->second;
        auto Partial2 = L->second;
        for (auto &E1 : Partial1) {
          for (auto &E2 : Partial2) {
            if (E1.second < E2.first) {
              R.push_back({Nums[E1.first], Nums[E1.second], Nums[E2.first],
                           Nums[E2.second]});
            }
          }
        }
      }
    }
    return R;
  }
};

int main() {
  std::vector<int> In = {1, 0, -1, 0, -2, 2};
  auto R = Solution().FourSum(In, 0);
  std::vector<std::vector<int>> E = {
      {-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2}};
  if (R.size() != E.size()) {
    assert(false);
  }
  for (auto &I : E) {
    assert(std::find(R.begin(), R.end(), I) != R.end());
  }

  return 0;
}