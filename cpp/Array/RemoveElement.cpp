/**
 * Description:
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  int RemoveElement(std::vector<int> &Nums, int Target) {
    auto Idx = 0;
    for (int I = 0; I < Nums.size(); ++I) {
      if (Nums[I] != Target) {
        Nums[Idx++] = Nums[I];
      }
    }
    Nums.erase(Nums.begin() + Idx, Nums.end());
    return Idx;
  }
};

int main() {
  std::vector<int> In = {-1, 0, 1, 1, 3, 5, 7};
  auto R = Solution().RemoveElement(In, 1);
  assert(In == std::vector<int>({-1, 0, 3, 5, 7}));
  assert(R == 5);

  return 0;
}