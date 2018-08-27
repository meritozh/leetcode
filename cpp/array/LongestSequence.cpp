/*
 * Description:
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example, given `[100, 4, 200, 1, 3, 2]`, the longest consecutive
 * elements sequence is `[1, 2, 3, 4]`, return its length: `4`.
 *
 * Your algorithm should run in `O(n)` complexity.
 */

#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
public:
  int LongestConsecutive(const std::vector<int>& Nums) {
    std::unordered_set<int> S;
    for (auto I : Nums) {
      S.insert(I);
    }

    int Longest = 0;
    for (auto I : Nums) {
      int Length = 1;
      for (int J = I - 1; S.find(J) != S.end(); --J) {
        S.erase(J);
        ++Length;
      }
      for (int J = I + 1; S.find(J) != S.end(); ++J) {
        S.erase(J);
        ++Length;
      }
      Longest = std::max(Longest, Length);
    }

    return Longest;
  }
};

int main() {
  std::vector<int> In({100, 4, 200, 1, 3, 2});
  assert(Solution().LongestConsecutive(In) == 4);

  return 0;
}