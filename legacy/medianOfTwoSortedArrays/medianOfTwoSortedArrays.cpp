/*
 * Source : medianOfTwoSortedArrays.cpp
 * Author : meritozh
 * Date   : 2017-12-18
 */

/*
 * Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log(m+n)).
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

static const auto __faster_hack = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();

    // Must n <= m.
    if (n > m) {
      swap(n, m);
      swap(nums1, nums2);
    }

    // search in [0, n].
    int mid, pos, id = (n + m + 1) / 2;
    int l = 0, r = n;

    while (l <= r) {
      mid = (l + r) >> 1;
      pos = id - mid;
      if (mid < n && nums2[pos - 1] > nums1[mid])
        l = mid + 1;
      else if (mid >= 1 && nums2[pos] < nums1[mid - 1])
        r = mid - 1;
      else
        break;
    }

    double ans;
    if (mid == 0)
      ans = nums2[pos - 1];
    else if (pos == 0)
      ans = nums1[mid - 1];
    else
      ans = max(nums1[mid - 1], nums2[pos - 1]);

    if ((n + m) & 1)
      return ans;
    else {
      if (mid == n)
        ans = (ans + nums2[pos]) / 2.0;
      else if (pos == m)
        ans = (ans + nums1[mid]) / 2.0;
      else
        ans = (ans + min(nums1[mid], nums2[pos])) / 2.0;
    }
    return ans;
  }
};

int main() {
  vector<int> vec1{7, 8};
  vector<int> vec2{1, 2, 3, 4, 5, 6};

  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1, 5};
  vec2 = {2, 4};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {};
  vec2 = {3, 5};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1, 3, 5};
  vec2 = {2, 4};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1, 2};
  vec2 = {3, 4};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {};
  vec2 = {1};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {2};
  vec2 = {};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  /*
  vec1 = {};
  vec2 = {};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";
  */

  vec1 = {};
  vec2 = {1, 2, 3, 4};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1, 2, 3, 4};
  vec2 = {};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1, 2, 3, 4, 5};
  vec2 = {};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {};
  vec2 = {1, 2, 3, 4, 5};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << "\n";

  vec1 = {1};
  vec2 = {2, 3, 4, 5, 6};
  cout << Solution().findMedianSortedArrays(vec1, vec2) << endl;

  return 0;
}
