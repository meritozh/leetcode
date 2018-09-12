/**
 * Description:
 *
 * You are given two linked lists representing two non-negative numbers. The
 * digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 *
 * Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: (7 -> 0 -> 8)
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node *AddTwoNumbers(Node *List1, Node *List2) {
    Node *Root = new Node();
    Node *Curr = Root;
    Node *Node1 = List1;
    Node *Node2 = List2;

    bool NeedCarry = false;
    while (Node1 != nullptr || Node2 != nullptr) {
      auto E1 = Node1 == nullptr ? 0 : Node1->GetValue();
      auto E2 = Node2 == nullptr ? 0 : Node2->GetValue();
      auto Sum = E1 + E2 + (NeedCarry ? 1 : 0);
      NeedCarry = Sum / 10;

      auto N = new Node(Sum % 10);
      Curr->Next = N;
      Curr = N;

      Node1 = Node1 == nullptr ? nullptr : Node1->Next;
      Node2 = Node2 == nullptr ? nullptr : Node2->Next;
    }

    return Root->Next;
  };
};

int main() {
  Node* List1 = LinkedList::GenerateLinkedList(3, {2, 4, 3});
  Node* List2 = LinkedList::GenerateLinkedList(3, {5, 6, 4});

  auto L = Solution().AddTwoNumbers(List1, List2);
  auto R = LinkedList::AllValues(L);

  assert(R == std::vector<int>({7, 0, 8}));

  return 0;
}