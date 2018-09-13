/**
 * Description:
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than $\lfloor (n / 2) \rfloor$ times.
 *
 * You may assume that the array in non-empty and the majority element always
 * exist in the array.
 */

#include <vector>

class Solution {
public:
  int MajorityElement(std::vector<int>& Nums) {
    auto Count = 0;
    auto M = Nums.begin();
    for (auto I = Nums.begin(), Max = Nums.end(); I != Max; ++I) {
      if (*M == *I) {
        Count++;
      } else {
        Count--;
      }
      if (Count == 0) {
        M = I;
        Count = 1;
      }
    }

    // In this case, need not validate *M.

    return *M;
  }
};

int main() {
  std::vector<int> In = {2, 2, 3, 5, 2, 2, 6};
  assert(Solution().MajorityElement(In) == 2);

  return 0;
}