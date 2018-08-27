/**
 * Description:
 *
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 *
 * For example, given input array `A = [1, 1, 2]`,
 *
 * Your function should return `length = 2`, and `A` is now `[1, 2]`.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  int RemoveDuplicates(std::vector<int>& Nums) {
    if (Nums.empty()) {
      return 0;
    }

    int Idx = 1;
    for (int I = 1, Max = Nums.size(); I < Max; ++I) {
      if (Nums[I] != Nums[Idx - 1]) {
        Nums[Idx++] = Nums[I];
      }
    }

    Nums.erase(Nums.begin() + Idx, Nums.end());
    return Idx;
  }
};

int main() {
  std::vector<int> In = {1, 2, 3, 6, 6, 6, 8};
  assert(Solution().RemoveDuplicates(In) == 5);
  assert(In == std::vector<int>({1, 2, 3, 6, 8}));
  
  return 0;
}