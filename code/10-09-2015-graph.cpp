#include<iostream>
using namespace std;
#define N_SIZE 1000

struct Node {
  int value;
  Node* children[N_SIZE];
  int size;

  Node(int val = -1) : value(val), size(0) {}

  bool add_child(Node* n) {
    if (n == nullptr) return false;

    if (size < N_SIZE) {
      children[size++] = n;
      return true;
    }
    return false;
  }
};

struct Graph {
  Node nodes[N_SIZE];
  int size;

  Graph() : size(0) {}

  Node* add_node(int name) {
    if (size < N_SIZE) {
      nodes[size++] = Node(name);
      return &nodes[size - 1];
    }
    return nullptr;
  }
};


// for big graphs recursion could become too deep and return an error
bool has_path(const Node* a, const Node* b) {
  if (a == b) return true;

  for (int i = 0; i < a->size; ++i)
    if (has_path(a->children[i], b))
      return true;

  return false;
}

inline bool has_some_path(const Node* a, const Node* b) {
  return has_path(a, b) || has_path(b, a);
}

bool is_connected(const Graph& g) {
  for (int i=0; i < g.size - 1; ++i)
    for (int j=i+1; j < g.size; j++)
      if (!has_some_path(&g.nodes[i], &g.nodes[j]))
        return false;

  return true;
}

int main () {
  Graph g;

  Node* n1 = g.add_node(1);
  Node* n2 = g.add_node(2);
  Node* n3 = g.add_node(3);

  n1->add_child(n2);
  n2->add_child(n3);

  cout << "Result: " << is_connected(g) << endl;
  return 0;
}
