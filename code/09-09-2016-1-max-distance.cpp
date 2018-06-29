#include<iostream>
#include<string>
#include<utility>
using namespace std;

pair<int, int> max_dist(string str) {
  int max_i = 0, max_j = 0;

  // i = front, j = back; compare while j - i > max distance (max_j - max_i)
  for (int i = 0; i < str.size() - 1; ++i) {
    int j  = str.size() - 1;
    if (j - i <= (max_j - max_i)) break;

    for (; j > i; --j) {
      if (str[i] == str[j] && j - i > (max_j - max_i)) {
        max_i = i;
        max_j = j;
      } else if (j - i <= (max_j - max_i)) break;
    }
  }
  return pair<int, int>(max_i, max_j);
}

int main() {
  pair<int, int> max = max_dist("this is just a simple example");
  cout << max.first << " " << max.second << endl;
  return 0;
}
