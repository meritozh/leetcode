/*
 * Source : addTwoNumbers.cpp
 * Author : meritozh
 * Date   : 2017-12-17
 */

/*
 * Add Two Numbers
 *
 * You are given two non-empty linked lists representing two-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a
 * single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

static const auto __faster_hack = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto carry = 0;
    auto resultNode = new ListNode(0);
    auto currentNode = resultNode;

    while (l1 || l2 || carry) {
      auto val1 = l1 ? l1->val : 0;
      auto val2 = l2 ? l2->val : 0;
      auto value = val1 + val2 + carry;
      carry = value / 10;
      currentNode->next = new ListNode(value % 10);
      currentNode = currentNode->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return resultNode->next;
  }
};
