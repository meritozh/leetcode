/**
 * Description:
 *
 * Given an array of integers, find two numbers such that they add up to a
 * specific target number.
 *
 * The function `TwoSum` should return indices of the two numbers such they add
 * up to the target, where `index1` must be less than `index2`. Please note that
 * your returned answers (both `index1` and `index2`) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: Number = {2, 7, 11, 15}, target = 9
 * Output: index1 = 1, index2 = 2
 */

#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
  std::vector<int> TwoSum(std::vector<int>& Nums, int Target) {
    std::unordered_multimap<int, int> M;
    for (int I = 0, Max = Nums.size(); I < Max; ++I) {
      M.insert({Nums[I], I});
    }

    for (int I = 0; I < Nums.size(); ++I) {
      auto It = M.find(Target - Nums[I]);
      // If target is 4, the M have two 2, we cannot return same pos.
      if (It != M.end() && It->second != I) {
        if (It->second > I) {
          return {I + 1, It->second + 1};
        }
        return {It->second + 1, I + 1};
      }
    }

    throw std::logic_error("No answer");
  }
};

int main() {
  std::vector<int> In = {2, 2, 7, 11, 15};
  assert(Solution().TwoSum(In, 4) == std::vector<int>({1, 2}));

  return 0;
}