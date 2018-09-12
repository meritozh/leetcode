#include <vector>

struct Node {
private:
  int Value;

public:
  Node* Next = nullptr;

  Node() = default;
  Node(int Value) : Value(Value) {}
  
  int GetValue() { return this->Value; }
};

class LinkedList {
public:
  static std::vector<int> AllValues(Node* Root) {
    std::vector<int> R;

    Node *Current = Root;
    R.push_back(Current->GetValue());
    while (Current->Next != nullptr) {
      Current = Current->Next;
      R.push_back(Current->GetValue());
    }

    return std::move(R);
  }

  static Node* GenerateLinkedList(int Length, int From) {
    Node* Root = new Node(From);
    Node* Current = Root;

    for (int Count = 1; Count < Length; ++Count) {
      Node* N = new Node(++From);
      Current->Next = N;
      Current = N;
    }

    return Root;
  }

  static Node* GenerateLinkedList(int Length, std::vector<int> Inits) {
    assert(Length <= Inits.size());
    auto Iter = Inits.begin();
    Node* Root = new Node(*Iter++);
    Node* Current = Root;

    for (int Count = 1; Count < Length; ++Count) {
      Node* N = new Node(*Iter++);
      Current->Next = N;
      Current = N;
    }

    return Root;
  }

  static Node* LastNode(Node* Root) {
    Node *Current = Root;
    while (Current->Next != nullptr) {
      Current = Current->Next;
    }
    return Current;
  }
};