#include<iostream>
const int MAX_STACK = 100;

template<typename T>
class StaticStack {
  T data_[MAX_STACK];
  int top_;

  bool full() const { return top_ == MAX_STACK - 1; }

  public:
  StaticStack() : top_(-1) { }

  bool empty() const { return top_ == -1; }

  void push(const T& x) {
    if (!full())
      data_[++top_] = x;
    else
      std::cerr << "Stack is full.\n";
  }

  void pop() {
    if(!empty())
      --top_;
    else
      std::cerr << "Stack is empty.\n";
  }

  T& top() { if(!empty()) return data_[top_]; }
};

template<typename T>
struct Node {
  T data;
  Node<T>* next;

  Node(T _data, Node<T>* _next = nullptr)
    : data(_data), next(_next) {}
};

template<typename T>
class Stack {
  Node<T>* top_;

  void copy(const Stack<T>& other) {
    if (other.empty()) return;

    Node<T>* head = other.top_;
    Node<T>* current = new Node<T>(head->data);
    top_ = current;
    head = head->next;
    while(head != nullptr) {
      current->next = new Node<T>(head->data);
      current = current->next;
      head = head->next;
    }
  }

  void drop() {
    while(!empty()) pop();
  }

  public:
  Stack() : top_(nullptr) {}

  Stack(const Stack& other) : top_(nullptr) {
    copy(other);
  }

  Stack<T>& operator=(const Stack<T>& other) {
    if (this != &other) {
      drop();
      copy(other);
    }
    return *this;
  }

  bool empty() const { return top_ == nullptr; }

  void push(const T& x) {
    if (empty()) {
      top_ = new Node<T>(x);
    } else {
      top_ = new Node<T>(x, top_);
    }
  }

  void pop() {
    if (!empty()) {
      Node<T>* head = top_;
      top_ = top_->next;
      delete head;
    } else {
      std::cerr << "Stack is empty.\n";
    }
  }

  T& top() const {
    if(!empty())
      return top_->data;
    else {
      std::cerr << "Stack is empty.\n";
    }
  }
};


int main() {
  // test StaticStack
  StaticStack<int> ss;
  std::cout << ss.empty() << std::endl;
  ss.push(1);
  std::cout << "ss.top " << ss.top() << std::endl;
  std::cout << ss.empty() << std::endl;
  ss.pop();
  std::cout << ss.empty() << std::endl;
  ss.pop();

  std::cout << "---- STACK ----\n";
  // test Stack
  Stack<int> s1;
  std::cout << s1.empty() << std::endl;
  s1.pop();
  s1.push(1);
  s1.push(2);
  Stack<int> s = s1;
  std::cout << "s.top " << s.top() << std::endl;
  std::cout << s.empty() << std::endl;
  s.pop();
  std::cout << "s.top " << s.top() << std::endl;
  std::cout << s.empty() << std::endl;
  s.pop();
  std::cout << s.empty() << std::endl;
  std::cout << s1.empty() << std::endl;

  return 0;
}
