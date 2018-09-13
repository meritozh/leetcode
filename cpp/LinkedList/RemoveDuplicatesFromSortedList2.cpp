/**
 * Description:
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example:
 *
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* RemoveDuplicatesFromSortedList(Node* List) {
    Node* Root = new Node();
    Node* RootStart = Root;

    Node* Curr = List;
    // No node
    if (Curr == nullptr) {
      return RootStart->Next;
    }
    if (Curr->Next == nullptr) { // One node
      Root->Next = Curr;
      Root = Curr;
    } else { // Multiple node
      int CurrValue = Curr->GetValue();
      int ValueCount = 1;
      while (Curr != nullptr) {
        if (Curr->Next == nullptr) { // Curr is the last node
          if (ValueCount == 1) {
            Root->Next = Curr;
            Root = Curr;
          }
          break;
        } else if (CurrValue == Curr->Next->GetValue()) {
          Curr = Curr->Next;
          ValueCount++;
        } else {
          if (ValueCount == 1) {
            Root->Next = Curr;
            Root = Curr;
          }
          CurrValue = Curr->Next->GetValue();
          ValueCount = 1;
          Curr = Curr->Next;
        }
      }
    }

    Root->Next = nullptr;

    return RootStart->Next;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 1, 1, 2, 3});
  auto R = Solution().RemoveDuplicatesFromSortedList(List);
  assert(LinkedList::AllValues(R) == std::vector<int>({2, 3}));

  return 0;
}