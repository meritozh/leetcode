/**
 * Description:
 *
 * The set `[1, 2, 3, ... , n]` contains a total of `n!` unique permutation.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence (ie, for `n = 3`):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given `n` and `k`, return the kth permutation sequence.
 *
 * Note: Given `n` will be between 1 and 9 inclusive.
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

class Solution {
public:
  std::vector<int> PermutationSequence(int N, int K) {
    std::vector<int> R;

    std::vector<int> Factorial = {1};
    for (auto I = 1; I <= N; ++I) {
      Factorial.push_back(Factorial.back() * I);
    }

    std::vector<int> S;
    for (auto I = 1; I <= N; ++I) {
      S.push_back(I);
    }

    /// from 0
    --K;
    for (auto I = N - 1; I > 0; --I) {
      auto Reminder = K % Factorial[I];
      auto Quotient = K / Factorial[I];
      K = Reminder;
      
      auto E = std::next(S.begin(), Quotient);
      R.push_back(*E);
      S.erase(E);
    }
    R.push_back(S.front());

    return R;
  }
};

int main() {
  auto R = Solution().PermutationSequence(4, 13);
  assert(R == std::vector<int>({3, 1, 2, 4}));

  return 0;
}