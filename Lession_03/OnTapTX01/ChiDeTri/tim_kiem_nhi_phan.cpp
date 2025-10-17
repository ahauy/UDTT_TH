#include <iostream>
#include <time.h>

using namespace std;

int a[100] = {0};
int n;

void init() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % 10;
  }
}

void display() {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// sắp xếp dãy tìm kiếm
void bubbleSort(int a[]) {
  for(int i = 0; i< n; i ++) {
    for(int j = n - 1; j > i; j --) {
      if(a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
      }
    }
  }
}

// thiết kế giải thuật tìm kiếm nhị phân
bool binary_search(int a[], int k, int l, int r) {
  int m = (l + r) / 2;
  if(a[m] == k) {
    return true;
  }
  if(l > r) {
    return false;
  }
  if(k < a[m]) {
    return binary_search(a, k, l, m - 1);
  } else {
    return binary_search(a, k, m + 1, r);
  }
}

// // thuật toán tìm kiếm vị trí để ko phá vỡ sự sắp xếp
// int search(int a[], int k, int l, int r) {
//   if(l == r) {
//     return l;
//   }
//   int m = (l + r) / 2;
//   if(k < a[m]) {
//     return search(a, k, l, m);
//   } else {
//     return search(a, k, m, r);
//   }
// }

// // chèn
// void insert(int a[], int k) {
//   if(binary_search(a, k, 0, n - 1)) {
//     cout << "Mảng đã được sắp xếp !!" << end;
//   } else {
//     cout << "Mảng sau khi được thêm " << k << " :" << endl;
//     int indexInsert = search(a, k, 0, n - 1);
//     for(int i = indexInsert; i < n; i ++) {
//       a[i + 1] = a[i];
//     }
//     a[indexInsert] = k;
//   }
// }

int main() {
  cin >> n;
  init();
  display();
  bubbleSort(a);
  display();
  int k;
  cin >> k;
  cout << "Kiểm tra xem " << k << " có thuộc mảng hay không ?" << endl;
  if(binary_search(a, k, 0, n - 1)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  // insert(a, 3);
  return 0;
}