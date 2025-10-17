#include <iostream>

using namespace std;

// khởi tạo danh sách ghế và người
char ghes[4] = {'A', 'B', 'C', 'D'};
string nguois[4] = {"Tung", "Cuc", "Truc", "Mai"};
int a[100];

bool flag[100]; // dùng để đánh dấu ghế đã có người ngồi hay chưa

// cách in kết quả
void display() {
  for(int i = 0; i < 4; i ++) {
    cout << nguois[i] << " ngồi ở ghế " << ghes[a[i]] << endl;
  }
  cout << endl;
}

// thiết kế thuật toán quay lui để giải bài toán 
// thuật toán sẽ giống thuật toán hoán vị
int dem = 0;
void Try(int i) {
  for(int j = 0; j < 4; j ++) {
    if(!flag[j]) {
      flag[j] = true;
      a[i] = j;
      if(i == 3) {
        dem ++;
        display();
      } else {
        Try(i + 1);
      }
      flag[j] = false;
    }
  }
}

int main() {

  Try(0); 
  cout << "Có " << dem << " cách sắp xếp chỗ ngồi !" << endl;

  return 0;
}