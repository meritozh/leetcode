/**
 * Description:
 *
 * Given a number represented as an array of digits, plus one to the number.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  std::vector<int> PlusOne(std::vector<int> Num) {
    int A = 1;
    for (auto Iter = Num.rbegin(), End = Num.rend(); Iter != End; ++Iter) {
      *Iter = *Iter + A;
      A = *Iter / 10;
      *Iter = *Iter % 10;
    }

    if (A > 0) {
      Num.insert(Num.begin(), 1);
    }

    return Num;
  }
};

int main() {
  std::vector<int> In = {1, 3, 2, 6};
  assert(Solution().PlusOne(In) == std::vector<int>({1, 3, 2, 7}));

  return 0;
}