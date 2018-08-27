/*
 * Source : longestSubStringWithoutRepeatingCharacters.cpp
 * Author : meritozh
 * Date   : 2017-12-18
 */

/*
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", with the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must ba a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

static const auto __faster_hack = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // map: character => index
    map<char, int> map;
    decltype(map)::iterator it;
    int lastRepeatIndex = -1;
    auto length = 0ul;
    for (auto i = 0ul; i < s.size(); i++) {
      it = map.find(s[i]);
      if (it != map.end() && it->second > lastRepeatIndex) {
        lastRepeatIndex = it->second;
      }
      auto size = i - lastRepeatIndex;
      if (length < size)
        length = size;
      map[s[i]] = i;
    }
    return length;
  }
};

class AnotherSolution {
public:
  int longestSubStringWithoutRepeatingCharacters(string s) {
    int m[256];
    memset(m, -1, sizeof(m));
    int lastRepeatIndex = -1;
    size_t length = 0;

    for (size_t i = 0; i < s.size(); i++) {
      if(m[static_cast<int>(s[i])] != -1 && lastRepeatIndex < m[static_cast<int>(s[i])])
        lastRepeatIndex = m[static_cast<int>(s[i])];
      auto size = i - lastRepeatIndex;
      if (length < size)
        length = size;
      m[static_cast<int>(s[i])] = i;
    }

    return length;
  }
};
