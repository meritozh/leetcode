/**
 * Description:
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 *
 * You should try to do it in place. The program should run in `O(1)` space
 * complexity and `O(n)` time complexity.
 *
 * Example:
 * 
 * Given `1->2->3->4->5->NULL`
 * Return `1->3->5->2->4->NULL`.
 *
 * Note:
 *
 * 1. The relative order inside both the even and odd groups should remain as it
 *    was in the input.
 * 2. The first node is considered odd, the second node even and so on ...
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  void OddEvenLinkedList(Node* Root) {
    Node* PrevOdd = Root;
    Node* PrevEven = PrevOdd->Next;
    // Only one node
    if (PrevEven == nullptr) {
      return;
    }

    Node* CurrOdd = PrevEven->Next;
    // Only two node
    if (CurrOdd == nullptr) {
      return;
    }

    Node* CurrEven = CurrOdd->Next;
    // Only three node
    if (CurrEven == nullptr) {
      PrevOdd->Next = CurrOdd;
      CurrOdd->Next = PrevEven;
      PrevEven->Next = nullptr;
      return;
    }

    Node* AfterOdd = CurrEven->Next;
    Node* AfterEven = AfterOdd ? AfterOdd->Next : nullptr;

    auto FirstEven = PrevEven;

    PrevOdd->Next = CurrOdd;
    CurrOdd->Next = AfterOdd;

    PrevEven->Next = CurrEven;
    CurrEven->Next = AfterEven;

    while (AfterOdd != nullptr) {
      PrevOdd = CurrOdd;
      CurrOdd = AfterOdd;
      auto Even = AfterOdd->Next;
      if (Even == nullptr) {
        break;
      } else {
        AfterOdd = Even->Next;
      }
    }
    while (AfterEven != nullptr) {
      PrevEven = CurrEven;
      CurrEven = AfterEven;
      auto Odd = AfterEven->Next;
      if (Odd == nullptr) {
        break;
      } else {
        AfterEven = Odd->Next;
      }
    }

    CurrOdd->Next = FirstEven;
  }

  void ImprovedOddEvenLinkedList(Node* Root) {
    Node* OddNode = Root;
    Node* EvenNode = Root->Next;
    Node* FirstEvenNode = EvenNode;
    if (EvenNode == nullptr) {
      return;
    }

    auto N = EvenNode->Next;
    for (int I = 3; N != nullptr; ++I) {
      if (I % 2 == 1) { // Odd
        OddNode->Next = N;
        OddNode = N;
        N = N->Next;
      } else { // Even
        EvenNode->Next = N;
        EvenNode = N;
        N = N->Next;
      }
    }

    OddNode->Next = FirstEvenNode;
    EvenNode->Next = nullptr;
  }
};

int main() {
  Node* List = LinkedList::GenerateLinkedList(5, 1);
  Solution().ImprovedOddEvenLinkedList(List);

  assert(LinkedList::AllValues(List) == std::vector<int>({1, 3, 5, 2, 4}));

  return 0;
}