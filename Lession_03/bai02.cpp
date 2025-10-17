#include <iostream>

using namespace std;

int a[100];
int n = 7;
int k = 6;

// khởi tạo mảng ký tự
char s[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void display1() {
  for(int i = 1; i <= k; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void display() {
  for(int i = 1; i <= k; i ++) {
    cout << s[a[i] - 1] << " ";
  }
  cout << endl;
}

// thiết kế thuật toán lấy 6 kí tự từ tập 7 kí tự bằng phương pháp quay lui
// thiết kế giống giải thuật sinh tổ hợp bằng quay lui
void Try(int i) {
  for(int j = a[i - 1] + 1; j <= n - k + i; j ++) {
    a[i] = j;
    if(i == k) {
      display();
    } else {
      Try(i + 1);
    }
  }
}

int main() {

  Try(1);
  return 0;
}