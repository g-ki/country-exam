#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct Tree {
  int data;
  vector<Tree*> children;

  Tree(int _data) : data(_data) {}

  ~Tree() {
    for(Tree* t : children)
      delete t;
  }
};

Tree build_tree(int k, int* A, int n) {
  set<int> included;
  queue<Tree*> Q;
  Tree result(A[0]);
  Q.push(&result);

  int i = 1;
  while(i < n && !Q.empty()) {
    Tree* curr = Q.front(); Q.pop();

    for(int j = 0; j < k && i < n;) {
      if (included.insert(A[i++]).second) {  // == true is inserted
        curr->children.push_back(new Tree(A[i - 1]));
        Q.push(curr->children.back());
        ++j;
      }
    }
  }
  return result;
}

// bonus
void print_tree(const Tree& t) {
  queue<const Tree*> Q;
  Q.push(&t);
  cout << "# -> " << t.data << endl;
  while(!Q.empty()) {
    const Tree* curr = Q.front(); Q.pop();
    if (curr->children.size() == 0) continue;

    cout << curr->data << " -> ";
    for(const Tree* c : curr->children) {
      cout << c->data << " ";
      Q.push(c);
    }
    cout << endl;
  }
}

int main() {
  int numbers[] = {1,2,3,4,5,6,6,6,6,7,8,9,10};
  Tree t = build_tree(3, numbers, 13);

  print_tree(t);
  return 0;
}
