/**
 * Description:
 *
 * Follow up for "Remove Duplicates": what if duplicates are allowed at more
 * twice?
 *
 * For example, given sorted array `A = [1, 1, 1, 2, 2, 3]`, your function
 * should return `length = 5`, and `A` is now `[1, 1, 2, 2, 3]`.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  int RemoveDuplicates(std::vector<int>& Nums) {
    if (Nums.size() <= 2) {
      return Nums.size();
    }

    int Idx = 2;
    for (int I = 2, Max = Nums.size(); I < Max; ++I) {
      if (Nums[I] != Nums[Idx - 2]) {
        Nums[Idx++] = Nums[I];
      }
    }

    Nums.erase(Nums.begin() + Idx, Nums.end());
    return Idx;
  }
};

int main() {
  std::vector<int> In = {1, 1, 2, 2, 3, 3, 3, 6};
  assert(Solution().RemoveDuplicates(In) == 7);
  assert(In == std::vector<int>({1, 1, 2, 2, 3, 3, 6}));

  return 0;
}