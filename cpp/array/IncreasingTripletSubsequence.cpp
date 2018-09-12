/**
 * Description:
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 * More specifically, if there exists `i`, `j`, `k` such that
 * `arr[i] < arr[j] < arr[k]`, given `0 <= i < j < k <= n - 1` return `true`
 * else return `false`.
 *
 * Your function should run in `O(n)` time complexitu and `O(1)` space
 * complexity.
 *
 * Example:
 * - Given `[1, 2, 3, 4, 5]`, return `true`.
 * - Given `[5, 4, 3, 2, 1]`, return `false`.
 */

#include <vector>
#include <limits>

class Solution {
public:
  bool IncreasingTripletSubsequence(std::vector<int>& Nums) {
    int Count = 0;
    int CurrentNum = INT_MIN;

    for (int I = 0, Max = Nums.size(); I < Max; ++I) {
      if (CurrentNum < Nums[I]) {
        CurrentNum = Nums[I];
        ++Count;
      } else {
        CurrentNum = INT_MIN;
        Count = 0;
      }
      if (Count == 3) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  std::vector<int> In = {5, 4, 3, 2, 1};
  assert(Solution().IncreasingTripletSubsequence(In) == false);
  
  return 0;
}