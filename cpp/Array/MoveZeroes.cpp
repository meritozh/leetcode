/**
 * Description:
 *
 * Given an array `nums`, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * For example, given `nums = [0, 1, 0, 3, 12]`, after calling your function,
 * nums should be `[1, 3, 12, 0, 0]`.
 *
 * Note:
 * 1. You must do this in-place without making a copy of the array.
 * 2. Minimize the total number of operations.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  void MoveZeroes(std::vector<int>& Nums) {
    auto Idx = 0;
    for (auto I = 0; I < Nums.size(); ++I) {
      if (Nums[I] != 0) {
        Nums[Idx++] = Nums[I];
      }
    }

    for (auto I = Idx; I < Nums.size(); ++I) {
      Nums[I] = 0;
    }
  }
};

int main() {
  std::vector<int> In = {0, 1, 0, 3, 12};
  Solution().MoveZeroes(In);
  assert(In == std::vector<int>({1, 3, 12, 0, 0}));

  return 0;
}