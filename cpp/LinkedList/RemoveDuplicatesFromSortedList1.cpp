/**
 * Description:
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 *
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* RemoveDuplicatesFromSortedList(Node* List) {
    Node* Root = new Node();
    Node* RootStart = Root;
    
    Node* Curr = List;
    Root->Next = Curr;
    Root = Curr;
    int Dup = Curr->GetValue();
    Curr = Curr->Next;

    while (Curr != nullptr) {
      if (Dup != Curr->GetValue()) {
        Root->Next = Curr;
        Root = Curr;
        Dup = Curr->GetValue();
      }
      Curr = Curr->Next;
    }
    Root->Next = nullptr;

    return RootStart->Next;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 1, 2, 3, 3});
  auto R = Solution().RemoveDuplicatesFromSortedList(List);
  assert(LinkedList::AllValues(R) == std::vector<int>({1, 2, 3}));

  return 0;
}