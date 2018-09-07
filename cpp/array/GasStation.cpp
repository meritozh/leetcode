/**
 * Description:
 *
 * There are `N` gas stations along a circular route, where the amount of gas
 * at station `i` is `gas[i]`.
 *
 * You have a car with an unlimited gas tank and it costs `cost[i]` of gas to
 * travel from station `i` to its next station (`i + 1`). You begin the journey
 * with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 *
 * Note: The solution is guaranteed to be unique.
 */

#include <vector>
#include <cassert>

class Solution {
public:
  int CanCompleteCircuit(std::vector<int>& Gas, std::vector<int>& Cost) {
    auto Total = 0;
    auto R = -1;
    for (auto I = 0, Sum = 0; I < Gas.size(); ++I) {
      // Each traveling will leave `sum` gas.
      Sum += Gas[I] - Cost[I];
      // Leave `total` gas after circuit traveling.
      Total += Gas[I] - Cost[I];
      if (Sum > 0) {
        R = I;
        Sum = 0;
      }
    }

    return Total >= 0 ? R + 1 : -1;
  }
};

int main() {
  std::vector<int> Gas = {3, 2, 5, 7, 6};
  std::vector<int> Cost = {2, 4, 3, 6, 5};
  assert(Solution().CanCompleteCircuit(Gas, Cost) == 5);

  return 0;
}
