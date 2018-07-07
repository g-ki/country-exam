#include<iostream>

const int MAX_TREE = 32;
template<typename T>
class StaticTree {
  T nodes_[MAX_TREE];
  unsigned left_child_[MAX_TREE];
  unsigned right_child_[MAX_TREE];
  unsigned top_;

  public:
  StaticTree() : top_(-1) {}

  bool empty() const { return top_ == -1; }

  void insert_left(int index, const T& x) {
    if (top_ >= MAX_TREE) return;
    nodes_[++top_] = x;
    if (index >= 0) left_child_[index] = top_ - 1;
  }

  void insert_right(int index, const T& x) {
    if (top_ >= MAX_TREE) return;
    nodes_[++top_] = x;
    if (index >= 0) right_child_[index] = top_ - 1;
  }

  T& value(int id) const { return nodes_[id]; }
  int left(int id) const { return left_child_[id]; }
  int right(int id) const { return right_child_ [id]; }

  // TODO
};

template<typename T>
struct Node {
  T data;
  Node<T>* left;
  Node<T>* right;

  Node(T data_, Node* left_ = nullptr, Node* right_ = nullptr)
    : data(data_), left(left_), right(right_) {}

  bool leaf() const { return left == nullptr && right == nullptr; }

  bool insert(const T& x) {
    if (x < data) {
      if (left == nullptr) {
        left = new Node(x);
        return true;
      } else left->insert(x);
    } else if (x > data) {
      if (right == nullptr) {
        right = new Node(x);
        return true;
      } else right->insert(x);
    }
    return false;
  }

  bool has(const T& x) const {
    if (x == data) return true;
    if (x < data && left != nullptr) return left->has(x);
    if (x > data && right != nullptr) return right->has(x);
    return false;
  }

  Node* min() {
    return (left == nullptr) ? this : left->min();
  }

  Node* max() {
    return (right == nullptr) ? this : right->max();
  }

  static bool remove(Node*& root, const T& val) {
    if (root == nullptr) return false;

    if (root->data > val)
      return remove(root->left, val);
    else if (root->data < val)
      return remove(root->right, val);

    // root->data == val
    if (root->leaf()) {
      delete root;
      root = nullptr;
      return true;
    }

    Node<T>* tmp = root;
    if (root->left != nullptr && root->right != nullptr) {
      tmp = root->left->max();
      root->data = tmp->data;
      tmp->data = val;
      return remove(root->left, val);
    } else {
      if (root->left == nullptr) root = root->right;
      else if (root->right == nullptr) root = root->left;
      delete tmp;
    }
    return true;
  }

  static void erase(Node* root) {
    if (root != nullptr) {
      erase(root->left);
      erase(root->right);
      delete root;
    }
  }

  static Node* copy(const Node* root) {
    if (root == nullptr) return nullptr;
    return new Node(root->data, copy(root->left), copy(root->right));
  }
};

template<typename T>
class BinTree {
  Node<T>* root_;

  void copy(const BinTree& other) {
    root_ = Node<T>::copy(other.root_);
  };

  void erase() {
    Node<T>::erase(root_); root_ = nullptr;
  }
  public:
  BinTree() : root_(nullptr) {};
  BinTree(const BinTree& other) { copy(other); }
  BinTree& operator=(const T& other) {
    if (this != &other) {
      erase();
      copy(other);
    }
    return *this;
  }

  ~BinTree() { erase(); }

  bool empty() const { return root_ == nullptr; }

  void insert(const T& x) {
    if (empty())
      root_ = new Node<T>(x);
    else
      root_->insert(x);
  }

  bool remove(const T& x) {
    if (empty()) return false;
    if (root_->leaf() && root_->data == x) {
      delete root_;
      root_ = nullptr;
      return true;
    }
    return Node<T>::remove(root_, x);
  }

  bool has(const T& x) const {
    return root_->has(x);
  }

  T min() const {
    if (!empty()) return root_->min()->data;
    std::cerr << "Error: BinTree is empty\n";
    return T();
  }

  T max() const {
    if (!empty()) return root_->max()->data;
    std::cerr << "Error: BinTree is empty\n";
    return T();
  }
};

void test_tree() {
  BinTree<int> t1;
  std::cout << t1.empty() << std::endl;
  t1.insert(5);
  t1.insert(8);
  t1.insert(3);
  BinTree<int> t = t1;
  std::cout << t.empty() << std::endl;
  std::cout << t.min() << std::endl;
  std::cout << t.max() << std::endl;
  std::cout << t.has(5) << std::endl;
  std::cout << t.has(-5) << std::endl;
  t.remove(5);
  std::cout << t.has(5) << std::endl;
  t.remove(3);
  t.remove(8);
  std::cout << t.empty() << std::endl;
}

int main() {
  test_tree();
  return 0;
}
