/*
tui co kich thuoc la: s(inch)
danh sach d gom n chiec dien thoai
phone: brand, size(inch), price(dola)
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <math.h>

using namespace std;

// khai bao cau truc cua phone
struct Phone
{
  string brand;
  int size;
  int price;
};

// khai bao kho du lieu brand, size va price
string brands[5] = {"Brand A", "Brand B", "Brand C", "Brand D", "Brand D"};
int sizes[5] = {6, 7, 9, 8, 10};
int prices[5] = {500, 800, 600, 900, 1000};

// khai bao kich thuoc chiec tui
int s;
int n = 7;
Phone d[100];

void ktaos()
{
  srand(time(NULL));
  s = 10 + rand() % 30;
}

void ktaod()
{
  for (int i = 0; i < n; i++)
  {
    string brand = brands[rand() % 5];
    int size = sizes[rand() % 5];
    int price = prices[rand() % 5];

    d[i] = {brand, size, price};
  }
}

void hienthi()
{
  cout << left
       << setw(7) << "STT"
       << setw(15) << "Brand"
       << setw(15) << "Size"
       << setw(15) << "Price" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << left
         << setw(7) << (i + 1)
         << setw(15) << d[i].brand
         << setw(15) << d[i].size
         << setw(15) << d[i].price << endl;
  }
}

int main()
{
  ktaos();
  cout << "Chiếc túi có kích thước là: " << s << endl;
  ktaod();
  cout << "Danh sách điện thoại có trong cửa hàng là: " << endl;
  hienthi();

  // khao tao 2 mang w(size) va v(price)
  int w[n + 1];
  int v[n + 1];
  for (int i = 0; i <= n; i++)
    w[i] = d[i - 1].size;
  for (int i = 0; i <= n; i++)
    v[i] = d[i - 1].price;

  // khoi tao mang dp
  int dp[n + 1][s + 1];
  memset(dp, 0, sizeof(dp));

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= s; j ++) {
      dp[i][j] = dp[i - 1][j];
      if(j >= w[i]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }

  cout << "Giá trị lớn nhất có thể lấy được là: " << dp[n][s] << endl;
  int tongSoDienThoai = 0;
  int kichThuoc = 0;
  int j = s;
  for(int i = n; i > 0; i --) {
    if(dp[i][j] != dp[i - 1][j]) {
      cout << "- " << d[i - 1].brand << ", " << d[i - 1].price << "$" << endl;
      j = j - w[i];
      kichThuoc += w[i];
      tongSoDienThoai ++;
    }
  }

  cout << "Lấy được " << kichThuoc <<  "/" << s << " inch" << endl;
  cout << "Tổng số điện thoại có thể lấy là: " << tongSoDienThoai << endl;

  return 0;
}