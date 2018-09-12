/**
 * Description:
 *
 * Reverse a linked list from position `m` to `n`. Do it in-place and in
 * one-pass.
 *
 * For example: Given `1->2->3->4->5->nullptr`, `m = 2` and `n = 4`,
 * return `1->4->3->2->5->nullptr`.
 *
 * Note: Given `m`, `n` satisfy the following condition: 1 <= m <= n <= length
 * of list.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* ReverseLinkedList(Node* List, int M, int N) {
    if (M == N) {
      return List;
    }
    Node* Root = new Node();
    Node* Curr = Root;
    Root->Next = List;

    Node* LNode = nullptr;
    Node* RNode = nullptr;
    Node* LastBeforeLNode = nullptr;
    for (int I = 1; I <= N; ++I) {
      Node* Temp = Curr->Next;
      if (I == M) {
        LastBeforeLNode = Curr;
        Curr = Temp;
        LNode = Curr;
      }
      Curr = Temp;
      if (I == N) {
        RNode = Curr;
      }
    }

    // 2->5
    Curr = LNode;
    Node* CurrNext = Curr->Next;
    Curr->Next = RNode->Next;

    // 3->2->5
    // 4->3->2->5
    while (Curr != RNode) {
      Node* TempNext = CurrNext->Next;
      
      CurrNext->Next = Curr;
      Curr = CurrNext;
      
      CurrNext = TempNext;
    }
    LastBeforeLNode->Next = Curr;

    return Root->Next;
  }
};

int main() {
  Node* List = LinkedList::GenerateLinkedList(5, 1);
  Node* Start = Solution().ReverseLinkedList(List, 2, 4);

  assert(LinkedList::AllValues(Start) == std::vector<int>({1, 4, 3, 2, 5}));

  return 0;
};