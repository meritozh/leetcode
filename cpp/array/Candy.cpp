/**
 * Description:
 *
 * There are `N` children standing in a line. Each child is assigned a rating
 * value.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 * - Each child must have at least one candy.
 * - Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 */

#include <vector>
#include <numeric>
#include <cassert>

class Solution {
public:
  int Candy(std::vector<int>& Ratings) {
    const int N = Ratings.size();
    std::vector<int> Increment(N);

    for (int I = 1, Inc = 1; I < N; ++I) {
      if (Ratings[I] > Ratings[I - 1]) {
        Increment[I] = std::max(Inc++, Increment[I]);
      } else {
        Inc = 1;
      }
    }

    for (int I = N - 2, Inc = 1; I >= 0; --I) {
      if (Ratings[I] > Ratings[I + 1]) {
        Increment[I] = std::max(Inc++, Increment[I]);
      } else {
        Inc = 1;
      }
    }

    return std::accumulate(Increment.begin(), Increment.end(), N);
  }
};

int main() {
  std::vector<int> In = {4, 2, 1, 8, 7, 3, 5};
  assert(Solution().Candy(In) == 14);

  return 0;
}