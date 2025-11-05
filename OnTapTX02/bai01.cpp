/*
p: so tien
danh sach d gom n chiec quat ban
quat ban: brand, color, price
KL: voi so tien p co the mua duoc nhieu nhat bao nhieu chiec quat trong danh sach d va gom nhung chiec quat nao(brand, price)
*/

#include <iostream>
#include <time.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Fan {
  string brand;
  string color;
  int price;
};

// kho du lieu hang va mau sac
string brands[5] = {"Brand A", "Brand B", "Brand C", "Brand D", "Brand D"};
string colors[5] = {"Red", "Blue", "Green", "Black", "White"};
int prices[5] = {100000, 350000, 200000, 600000, 400000};

// khai bao p, d, n;
int p;
int n = 7;
Fan d[100];

void ktaop() {
  srand(time(NULL));
  p = rand() % 1200000 + 1;
}

void ktaod() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    string brand = brands[rand() % 5];
    string color = colors[rand() % 5];
    int price = prices[rand() % 5];
    d[i] = {brand, color, price};
  }
}

void hienthi() {
  cout << left 
      << setw(7) << "STT"
      << setw(15) << "Brand"
      << setw(15) << "Color"
      <<setw(15) << "Price" << endl;
  for(int i = 0; i < n ; i ++) {
    cout << left 
      << setw(7) << (i + 1)
      << setw(15) << d[i].brand 
      << setw(15) << d[i].color
      <<setw(15) << d[i].price << endl;
  }
}

void sapxep() {
  // sap xep theo chieu tang dan cua price
  for(int i = 0; i < n - 1;  i++) {
    for(int j = n - 1; j > i; j --) {
      if(d[j].price < d[j - 1].price) {
        swap(d[j], d[j - 1]);
      }
    }
  }
}


int main() {
  ktaop();
  cout << "Số tiền bạn có là: " << p << endl;
  ktaod();
  cout << "Danh sách quạt bàn mà cửa hàng có: " << endl;
  hienthi();
  sapxep();

  cout << "Danh sách quạt có thể mua là: " << endl;
  int tongSoQuat = 0;
  int soTienDaMua = 0;
  for(int i = 0; i < n; i ++) {
    if(soTienDaMua + d[i].price <= p) {
      tongSoQuat ++;
      soTienDaMua += d[i].price;
      cout << " - " << d[i].brand << ", " << d[i].price << "VND" << endl;
    }
  }
  if(tongSoQuat > 0) {
    cout << "Tổng số quạt bạn có thể mua la: " << tongSoQuat << " chiếc" << endl; 
  } else {
    cout << "404 !!!" << endl;
  }
  return 0;
}