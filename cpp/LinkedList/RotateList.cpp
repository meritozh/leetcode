/**
 * Description:
 *
 * Given a list, rotate the list to the right by `k` places, where `k` is
 * non-negative.
 *
 * For example:
 *
 * Given `1->2->3->4->5->nullptr` and `k = 2`, return `4->5->1->2->3->nullptr`.
 */

#include "base/LinkedList.hpp"

class Solution {
public:
  Node* RotateList(Node* List, int K) {
    int N = 1;
    Node* Curr = List;
    Node* Start = Curr;

    if (K == 0 || Curr == nullptr) {
      return List;
    }

    while (Curr->Next != nullptr) {
      ++N;
      Curr = Curr->Next;
    }

    // Maybe K >= N
    K = K % N;
    int I = N - K;
    
    Curr->Next = Start;
    while (I > 0) {
      Curr = Curr->Next;
      --I;
    }
    
    Start = Curr->Next;
    Curr->Next = nullptr;

    return Start;
  };
};

int main() {
  auto List = LinkedList::GenerateLinkedList({1, 2, 3, 4, 5});
  auto R = Solution().RotateList(List, 2);
  assert(LinkedList::AllValues(R) == std::vector<int>({4, 5, 1, 2, 3}));

  return 0;
}