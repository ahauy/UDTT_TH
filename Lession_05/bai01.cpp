#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
  int n;
  cout << "Nhập số gói hàng (tối thiểu 6): ";
  cin >> n;

  // while (n < 6)
  // {
  //   cout << "Vui lòng nhập lại số gói hàng (tối thiểu 6): ";
  //   cin >> n;
  // }

  int w[n + 1], v[n + 1];
  cout << "Nhập trọng lượng và giá trị của tường gói hàng: " << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << "Gói: ";
    cin >> w[i] >> v[i];
  }

  int m;
  cout << "Nhập sức chứa tối đa của túi (m): ";
  cin >> m;

  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));

  // dùng quy hoạch động để tạo bảng
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= w[i])
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }

  cout << endl << endl;
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  cout << "Giá trị lớn nhất có thể đạt được là: " << dp[n][m] << endl;

  cout << "Các gói hàng được chọn: " << endl;
  int tongSoGoi = 0;
  int j = m;
  cout << left
       << setw(6) << "STT"
       << setw(15) << "Khối lượng"
       << setw(10) << "Giá trị" << endl;
  for (int i = n; i > 0; i--)
  {
    if (dp[i][j] != dp[i - 1][j])
    {
      cout << left
           << setw(6) << i
           << setw(15) << w[i]
           << setw(10) << v[i] << endl;
      tongSoGoi++;
      j = j - w[i];
    }
  }

  cout << "Số gói hàng được lấy là: " << tongSoGoi << " (gói)" << endl;

  return 0;
}