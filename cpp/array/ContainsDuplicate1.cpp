/**
 * Description:
 *
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 */

#include <set>
#include <vector>

class Solution {
public:
  bool ContainsDuplicate(std::vector<int>& Nums) {
    // <value, times>
    std::set<int> S;
    for (int I = 0, Max = Nums.size(); I < Max; ++I) {
      auto E = Nums[I];
      if (S.find(E) != S.end()) {
        return true;
      } else {
        S.insert(E);
      }
    }

    return false;
  }
};

int main() {
  std::vector<int> In = {1, 2, 24, 3, 6, 54, 2};
  assert(Solution().ContainsDuplicate(In) == true);

  return 0;
}