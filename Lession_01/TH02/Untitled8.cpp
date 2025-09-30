#include <iostream>

using namespace std;

int n, x[100];
bool flag[100]; // cờ đánh giấu các phần tử đã xét - nếu đã xét sẽ được đánh giấu là true

void display()
{
  for (int i = 1; i <= n; i++)
  {
    cout << x[i];
  }
  cout << endl;
}

void Try(int i) {
  for(int j = 1; j <= n; j ++) {
    if(flag[j] == false) {
      flag[j] = true;
      x[i] = j; 
      if(i == n) {
        display();
      } else {
        Try(i + 1);
      }
      flag[j] = false;
    }
  }
}

int main() {

  n = 3;
  Try(1);

  return 0;
}