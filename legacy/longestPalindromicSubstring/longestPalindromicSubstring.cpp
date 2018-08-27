/*
 * Source : longestPalindromicSubstring.cpp
 * Author : meritozh
 * Date   : 2017-12-21
 */

/*
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 *
 * Example:
 *
 * Input: "cbbd"
 * Output: "bb"
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

static const auto __faster_hack = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();

    if (n <= 1)
      return s;

    int start = 0;
    int length = 0;

    for (int i = 0; i < n - 1; i++) {
      int left = i;
      int right = i;
      while (right < n - 1 && s[right] == s[right + 1])
        right++;
      i = right;
      while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
        left--;
        right++;
      }
      int newLength = right - left + 1;
      if (length < newLength) {
        length = newLength;
        start = left;
      }
    }

    return s.substr(start, length);
  }
};