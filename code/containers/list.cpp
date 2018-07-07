#include<iostream>

template<typename T>
class StaticList {
  // TODO
};

template<typename T>
struct Node {
  T data;
  Node* next;
  Node* prev;

  Node(T data_, Node* prev_ = nullptr, Node* next_ = nullptr)
    : data(data_), next(next_), prev(prev_) {}
};

template<typename T>
class List {
  Node<T>* front_;
  Node<T>* back_;

  void copy(const List& other) {
    for (auto i = other.begin(); i != other.end(); i = i->next)
      push_back(i->data);
  }

  public:
  List() : front_(nullptr), back_(nullptr) {}
  List(const List& other) { copy(other); }
  List& operator=(const List& other) {
    if (this != &other) {
      erase();
      copy(other);
    }
    return *this;
  }

  ~List() { erase(); }

  void erase() {
    while(!empty()) pop_back();
  }

  Node<T>* begin() const { return front_; }
  Node<T>* end() const { return back_; }

  bool empty() const { return front_ == nullptr; }

  void insert_before(Node<T>* node, const T& x) {
    if (node->prev == nullptr) {
      node->prev = new Node<T>(x, nullptr, node);
    } else {
      Node<T>* prev_node = node->prev;
      prev_node->next = new Node<T>(x, prev_node, node);
      node->prev = prev_node->next;
    }
    if (node == front_) front_ = node->prev;
  }

  void insert_after(Node<T>* node, const T& x) {
    if (node->next == nullptr) {
      node->next = new Node<T>(x, node);
    } else {
      Node<T>* next_node = node->next;
      next_node->prev = new Node<T>(x, node, next_node);
      node->next = next_node->prev;
    }
    if (node == back_) back_ = node->next;
  }

  void push_back(const T& x) {
    if (empty())
      front_ = back_ = new Node<T>(x);
    else
      insert_after(back_, x);
  }

  void push_front(const T& x) {
    if (empty())
      front_ =  back_ = new Node<T>(x);
    else
      insert_before(front_, x);
  }

  void delete_at(Node<T>* node) {
    if (node == front_) front_ = front_->next;
    if (node == back_) back_ = back_->prev;

    if (node->prev != nullptr) node->prev->next = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    delete node;
  }

  void pop_back() {
    if (!empty()) delete_at(back_);
  }

  void pop_front() {
    if (!empty()) delete_at(front_);
  }
};

void test_list() {
  List<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_front(3);

  std::cout << l.empty() << std::endl;
  l.pop_back();
  l.pop_front();
  l.delete_at(l.begin());
  std::cout << l.empty() << std::endl;
}

int main() {
  test_list();
  return 0;
}


