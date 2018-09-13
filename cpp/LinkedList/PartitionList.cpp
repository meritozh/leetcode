/**
 * Description:
 *
 * Given a linked list and a value `x`, partition it such that all nodes less
 * than `x` come before nodes greater than or equal to `x`.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example, Given `1->4->3->2->5->2` and `x = 3`, return `1->2->2->4->3->5`.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* PartitionList(Node* List, int X) {
    Node* LeftList = new Node();
    Node* RightList = new Node();

    Node* LeftStart = LeftList;
    Node* RightStart = RightList;

    Node* Curr = List;
    while (Curr != nullptr) {
      if (Curr->GetValue() < X) {
        LeftList->Next = Curr;
        LeftList = Curr;
      } else {
        RightList->Next = Curr;
        RightList = Curr;
      }
      Curr = Curr->Next;
    }
    RightList->Next = nullptr;
    LeftList->Next = RightStart->Next;

    return LeftStart->Next;
  }
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 4, 3, 2, 5, 2});
  auto R = Solution().PartitionList(List, 3);
  assert(LinkedList::AllValues(R) == std::vector<int>({1, 2, 2, 4, 3, 5}));

  return 0;
}