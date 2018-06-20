#include<iostream>
#include<cmath>

int dfs_count(int x, int y, char el, char map[][100], int m, int n) {
  if (x < 0 || x >= m || y < 0 || y >= n || map[x][y] != el)
    return 0;

  map[x][y] = 0;

  return 1 + dfs_count(x - 1,y, el, map, m, n)
    + dfs_count(x - 1, y, el, map, m, n)
    + dfs_count(x, y + 1, el, map, m, n)
    + dfs_count(x, y - 1, el, map, m, n);
}


int max_area(char el, char map[][100], int m, int n) {
  int max = 0;
  for (int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
      max = std::max(max, dfs_count(i, j, el, map, m, n));

  return max;
}

int main() {
  char map[100][100] = {
    {'R', 'R', '1', '1', '2', '2'},
    {'1', 'R', 'R', 'R', '1', '2'},
    {'S', '1', 'R', 'R', '2', '3'},
    {'4', '4', 'S', 'S', 'R', 'R'}
  };

  std::cout << max_area('4', map, 4, 6) << std::endl;

  return 0;
}
