#include<iostream>
const int MAX_QUEUE = 4;

template<typename T>
class StaticQueue {
  T data_[MAX_QUEUE];
  int front_, back_;

  bool full() const { return (back_ + 1) % MAX_QUEUE == front_; }

  public:
  StaticQueue() : front_(0), back_(0) {}

  bool empty() const { return front_ == back_; }

  void push_back(const T& x) {
    if (!full()) {
      data_[back_] = x;
      back_ = (back_ + 1) % MAX_QUEUE;
    } else {
      std::cerr << "push_back: StaticQueue is full.\n";
    }
  }

  void pop_front() {
    if (!empty()) front_ = (front_ + 1) % MAX_QUEUE;
    else std::cerr << "pop_front: StaticQueue is empty.\n";
  }

  T front() const {
    if (!empty()) {
      return data_[front_];
    } else {
      std::cerr << "head: StaticQueue is empty.\n";
      return T();
    }
  }
};

void test_static_queue() {
  StaticQueue<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  q.pop_front();
  q.push_back(5);
  q.push_back(6);

  while(!q.empty()) {
    std::cout << q.front() << std::endl;
    q.pop_front();
  }
  q.pop_front(); // get error msg
}

template<typename T>
struct Node {
  T data;
  Node<T>* next;

  Node(T data_, Node<T>* next_ = nullptr)
    : data(data_), next(next_) {}
};

template<typename T>
class Queue {
  Node<T>* front_;
  Node<T>* back_;

  void copy(const Queue& other) {
    Node<T>* head = other.front_;
    while(head != nullptr) {
      push_back(head->data);
      head = head->next;
    }
  }

  void drop() {
    while(!empty()) pop_front();
  }

  public:
  Queue() : front_(nullptr), back_(nullptr) {}
  Queue(const Queue& other) : Queue() { copy(other); }
  Queue& operator=(const Queue& other) {
    if (this != &other) {
      drop();
      copy(other);
    }
    return *this;
  }

  ~Queue() { drop(); }

  bool empty() const { return front_ == nullptr; }

  void push_back(const T& x) {
    if (empty()) {
      front_ = back_ = new Node<T>(x);
    } else {
      back_->next = new Node<T>(x);
      back_ = back_->next;
    }
  }

  void pop_front() {
    if (!empty()) front_ = front_->next;
    else std::cerr << "pop_front: Queue is empty.\n";
  }

  T& front() const {
    if (!empty()) {
      return front_->data;
    } else {
      std::cerr << "front: Queue is empty.\n";
    }
  }
};

void test_queue() {
  Queue<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.push_back(4);
  q.pop_front();
  q.push_back(5);
  q.push_back(6);

  Queue<int> qc = q;

  while(!qc.empty()) {
    std::cout << qc.front() << std::endl;
    qc.pop_front();
  }
  qc.pop_front(); // get error msg
  std::cout << q.empty() << std::endl;
}

int main() {
  test_static_queue();
  test_queue();
  return 0;
}
