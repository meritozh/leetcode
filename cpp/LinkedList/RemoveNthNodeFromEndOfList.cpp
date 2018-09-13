/**
 * Description:
 *
 * Given a linked list, remove the `n`-th node from the end of list and return
 * its head.
 *
 * For example, given linked list: `1->2->3->4->5`, and `n = 2`.
 *
 * After removing the second node from the end, the linked list becomes
 * `1->2->3->5`,
 *
 * Note:
 * - Given `n` will always be valid.
 * - Try to do this in one pass.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* RemoveNthNodeFromEndOfList(Node* List, int N) {
    Node* Root = new Node();
    Root->Next = List;

    if (N == 0) {
      return Root->Next;
    }

    Node* Prev = Root;
    Node* Curr = Prev->Next;

    int Len = 0;
    while (Curr != nullptr) {
      ++Len;
      Curr = Curr->Next;
    }

    Curr = Prev->Next;
    int I = Len - N;
    while (I > 0) {
      Prev = Curr;
      Curr = Curr->Next;
      --I;
    }

    Prev->Next = Curr->Next;

    return Root->Next;
  }

  Node* ImprovedRemoveNthNodeFromEndOfList(Node* List, int N) {
    Node* Root = new Node();
    Root->Next = List;
    Node* Prev = Root;
    Node* Curr = Root;

    for (int I = 0; I < N; ++I) {
      Curr = Curr->Next;
    }

    while (Curr->Next != nullptr) {
      Prev = Prev->Next;
      Curr = Curr->Next;
    }

    Node* Temp = Prev->Next;
    Prev->Next = Temp->Next;

    return Root->Next;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 2, 3, 4, 5});
  auto R = Solution().ImprovedRemoveNthNodeFromEndOfList(List, 2);
  assert(LinkedList::AllValues(R) == std::vector<int>({1, 2, 3, 5}));

  return 0;
}