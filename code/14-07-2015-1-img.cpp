#include<iostream>
using namespace std;
#define MAX_M 10
#define MAX_N 10

void subsample(float img[MAX_M][MAX_N], int m, int n) {
  int s_m = (m + 1) / 2;
  int s_n = (n + 1) / 2;
  for(int i=0; i < s_m; i++) {
    for(int j=0; j < s_n; j++) {
      float avg = (img[i*2][j*2] + img[i*2][j*2 + 1] +:
          img[i*2 + 1][j*2] + img[i*2 + 1][j*2 + 1]) / 4.0;

      cout << avg << " ";
    }
    cout << endl;
  }
}

int main() {
  float img[10][10] = {{1.0, 2.0, 3.0}, {4.5, 6.5, 7.5}};

  subsample(img, 2, 3);
  return 0;
}
