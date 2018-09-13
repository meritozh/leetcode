/**
 * Description:
 *
 * Given an array of integers and an integer `k`, find out whether there are
 * two distinct indices `i` and `j` in the array such that `nums[i] = nums[j]`
 * and the difference between `i` and `j` is at most `k`.
 */

#include <vector>
#include <map>

class Solution {
public:
  bool ContainsDuplicate(std::vector<int>& Nums, int K) {
    // <value, index>
    std::map<int, int> M;

    auto End = Nums.end();
    for (int I = 0, Max = Nums.size(); I < Max; ++I) {
      auto E = Nums[I];
      auto Iter = M.find(E);
      if (Iter == M.end()) {
        M.insert({E, I});
      } else {
        if ((I - Iter->second) <= K) {
          return true;
        }
      }
    }

    return false;
  }
};

int main() {
  std::vector<int> In = {1, 2, 6, 7, 1, 3, 2, 4};
  assert(Solution().ContainsDuplicate(In, 4) == true);

  return 0;
}