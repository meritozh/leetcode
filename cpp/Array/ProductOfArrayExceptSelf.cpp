/**
 * Description:
 *
 * Given an array of `n` integers where `n > 1`, `nums`, return an array output
 * such that `output[i]` is equal to the product of all the elements of `nums`
 * except `nums[i]`.
 *
 * Solve it **without division** and in `O(n)`.
 *
 * For example, given `[1, 2, 3, 4]`, return `[24, 12, 8, 6]`.
 *
 * Follow up:
 *
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for purpose of space complexity analysis.)
 */

#include <vector>

class Solution {
public:
  std::vector<int> ProductOfArrayExceptSelf(std::vector<int> &Nums) {
    std::vector<int> R = {1};

    for (int I = 0, Max = Nums.size() - 1; I < Max; ++I) {
      auto E = R.back() * Nums[I];
      R.push_back(E);
    }

    auto P = 1;
    for (int I = Nums.size() - 1, Min = 0; I >= Min; --I) {
      if (I != Nums.size() - 1) {
        P = P * Nums[I + 1];
      }
      R[I] = R[I] * P;
    }

    return R;
  }
};

int main() {
  std::vector<int> In = {1, 2, 3, 4};
  assert(Solution().ProductOfArrayExceptSelf(In) ==
         std::vector<int>({24, 12, 8, 6}));

  return 0;
}