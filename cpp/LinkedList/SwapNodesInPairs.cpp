/**
 * Description:
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example, given `1->2->3->4`, you should return the list as `2->1->4->3`.
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* SwapNodesInPairs(Node* List) {
    Node* Root = List;
    Node* Prev = List;
    // 0 node
    if (Prev == nullptr) {
      return Root;
    }
    // One node
    Node* Curr = List->Next;
    if (Curr == nullptr) {
      return Root;
    }

    Node* Temp = Curr->Next;
    // Swap    
    Curr->Next = Prev;
    Prev->Next = Temp;
    Root = Curr;
    
    Node* LastPrev = Prev;

    // Step in two by two
    while (Prev != nullptr && Curr != nullptr) {
      if (Temp == nullptr) { // Last node is even node
        break;
      } else if (Temp->Next == nullptr) { // Last node is odd node
        Prev->Next = Temp;
        break;
      }
      Prev = Temp;
      Curr = Prev->Next;
      Temp = Curr->Next;
      Curr->Next = Prev;
      Prev->Next = Temp;

      LastPrev->Next = Curr;
      LastPrev = Prev;
    }

    return Root;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 2, 3, 4});
  auto R = Solution().SwapNodesInPairs(List);
  assert(LinkedList::AllValues(R) == std::vector<int>({2, 1, 4, 3}));

  return 0;
}