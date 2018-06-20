#include<cmath>
#include<iostream>

template<typename T>
struct Node {
  T data;
  Node<T>* next;

  Node(T data_, Node<T>* next_ = nullptr)
    : data(data_), next(next_) {}

  ~Node() { delete next; }
};

template<typename T>
struct List {
  Node<T>* front;
  Node<T>* back;

  List() : front(nullptr), back(nullptr) {}

  void clone(const List& l) {
    for(Node<T>* curr = l.front; curr != nullptr; curr = curr->next)
      append(curr->data);
  }

  List(const List& l) : front(nullptr), back(nullptr) {
    clone(l);
  }

  List& operator=(const List& l) {
    if (this != &l) {
      delete front;
      clone(l);
    }
    return *this;
  }

  List& append(T value) {
    if (front == nullptr) {
      front = back = new Node<T>(value);
    } else {
      back->next = new Node<T>(value);
      back = back->next;
    }

    return *this;
  }

  ~List() { delete front; }
};

bool is_sorted(const List<int>* l) {
  Node<int>* current = l->front;
  if (current == nullptr) return true;
  while(current->next != nullptr) {
    if (current->data > current->next->data)
      return false;
    current = current->next;
  }
  return true;
}

List<int> merge(const List<int>& la, const List<int>& lb) {
  List<int> result;
  const Node<int>* na = la.front;
  const Node<int>* nb = lb.front;

  while(na != nullptr && nb != nullptr) {
    if (na->data < nb->data) {
      result.append(na->data);
      na = na->next;
    } else {
      result.append(nb->data);
      nb = nb->next;
    }
  }

  for (;na != nullptr; na = na->next) result.append(na->data);
  for (;nb != nullptr; nb = nb->next) result.append(nb->data);

  return result;
}

List<int> kind_of_magic(const List<List<int>>& ll) {
  List<int> result;
  const Node<List<int>>* current = ll.front;
  for(;current != nullptr; current = current->next)
    if (is_sorted(&current->data))
      result = merge(result, current->data);

  return result;
}


void print(const List<int>& l) {
  const Node<int>* current = l.front;
  for(;current != nullptr; current = current->next)
    std::cout << current->data << " ";

  std::cout << std::endl;
}

int main() {
  List<List<int>> ll;
  List<int> la, lb, lc;

  la.append(1).append(5).append(10);
  lb.append(2).append(1).append(3);
  lc.append(1).append(2).append(6);

  ll.append(la).append(lb).append(lc);

  List<int> result = kind_of_magic(ll);
  print(result);

  return 0;
}
