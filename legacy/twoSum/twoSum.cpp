/*
 * Source : twoSum.cpp
 * Author : meritozh
 * Date   : 2017-12-17
 */

/*
 * Two Sum
 *
 * Given an array of integers, return indices of the two number such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

static const auto __faster_hack = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // map: value => indice
    unordered_map<int, int> map;
    // use 0ul because a warning, size() returns unsigned long.
    for (auto i = 0ul; i < nums.size(); i++) {
      const auto it = map.find(target - nums[i]);
      if (it != map.end())
        return vector<int>{static_cast<int>(i), it->second};
      else
        map.emplace(nums[i], i);
    }
    throw runtime_error("no solution");
  }
};
