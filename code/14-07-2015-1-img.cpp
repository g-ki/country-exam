#include<iostream>
using namespace std;
#define MAX_M 10
#define MAX_N 10

inline bool is_inside(int x, int y, int M, int N) {
  return x >= 0 && x < M && y >= 0 && y < N;
}

float avg_pixel(int x, int y, float img[MAX_M][MAX_N], int M, int N) {
  float sum = 0;
  int size = 0;
  for (int i = x*2; i <= x*2 + 1; i++)
    for (int j=y*2; j <= y*2 + 1; j++)
      if (is_inside(i, j, M, N)) {
        sum += img[i][j];
        size += 1;
      }
  return sum / size;
}

void subsample(float img[MAX_M][MAX_N], int m, int n) {
  int s_m = (m + 1) / 2;
  int s_n = (n + 1) / 2;
  for(int i=0; i < s_m; i++) {
    for(int j=0; j < s_n; j++) {
      cout << avg_pixel(i, j, img, m, n) << " ";
    }
    cout << endl;
  }
}

int main() {
  float img[10][10] = {{1.0, 2.0, 3.0}, {4.5, 6.5, 7.5}};

  subsample(img, 2, 3);
  return 0;
}
