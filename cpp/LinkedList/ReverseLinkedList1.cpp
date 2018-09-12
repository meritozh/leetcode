/**
 * Description:
 *
 * Reverse a singly linked list.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* ReverseLinkedList(Node* Root) {
    Node* Prev = Root;
    Node* Current = Prev->Next;
    // Only one node
    if (Current == nullptr) {
      return Root;
    }
    Prev->Next = nullptr;
    Node* After = Current->Next;
    
    Current->Next = Prev;

    while (After != nullptr) {
      auto NextAfter = After->Next;

      After->Next = Current;

      Prev = Current;
      Current = After;
      After = NextAfter;
    }

    return Current;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList(5, 0);

  auto Start = Solution().ReverseLinkedList(List);
  auto R = LinkedList::AllValues(Start);

  assert(R == std::vector<int>({4, 3, 2, 1, 0}));

  return 0;
}