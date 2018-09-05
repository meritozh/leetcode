/**
 * Description:
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1, 2, 3 -> 1, 3, 2
 * 3, 2, 1 -> 1, 2, 3
 * 1, 1, 5 -> 1, 5, 1
 */

/**
 * Analyze:
 *
 * A0 A1 A2 A3 ... An
 *
 * 1. From right to left, find one who violate the increase trend, is Partition.
 * 2. From right to left, find first number who bigger than Partition.
 * 3. Swap two number.
 * 4. Reverse numbers from right to (Partition + 1).
 */

#include <vector>
#include <cassert>

class Solution {
public:
  void NextPermutation(std::vector<int>& Nums, int Idx = 0) {
    auto I = Nums.end() - 2;
    for (auto Min = Nums.begin(); I >= Min; --I) {
      if (*I < *(I + 1)) {
        break;
      }
    }
    // The last permutation, just reverse all elements.
    if (I < Nums.begin()) {
      std::reverse(Nums.begin(), Nums.end());
      return;
    }
    // The iterator which violate the increase trend.
    auto Partition = I;

    for (auto I = Nums.end() - 1, Min = Partition; I > Min; --I) {
      if (*I > *Partition) {
        std::swap(*I, *Partition);
        break;
      }
    }

    std::reverse(Partition + 1, Nums.end());
  }
};

int main() {
  std::vector<int> In = {3, 2, 1};
  Solution().NextPermutation(In);
  assert(In == std::vector<int>({1, 2, 3}));

  return 0;
}