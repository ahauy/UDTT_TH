#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int dp[105][105];
int a[105]; // mảng sinh cấu hình

// Tính số cách bằng Quy hoạch động
void tinh_so_cach() {
    memset(dp, 0, sizeof(dp));

    // for(int j = 0; j <= m; j++)
    //     dp[0][j] = 1;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         dp[i][j] = dp[i][j-1];
    //         if(i >= j)
    //             dp[i][j] += dp[i-j][j];
    //     }
    // }

  for(int i = 0; i <= m; i ++) {
    dp[i][0] = 1;
  }

  for(int i = 1; i <= m; i ++) {
    for(int j = 0; j <= n; j ++) {
      if(i > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - i];
      }
    }
  }

    cout << "\nSo cach phan tich " << n << " thanh tong cac so <= " << m << " la: " << dp[n][m] << endl << endl;
}

// Liệt kê bằng phương pháp sinh
void liet_ke() {
    int k = 1;
    a[k] = n; // cấu hình đầu tiên là (n)

    while(true) {
        // In cấu hình
        for(int i = 1; i <= k; i++) {
            cout << a[i] << (i == k ? "" : " + ");
        }
        cout << endl;

        // Tìm vị trí có thể giảm
        int i = k;
        int remain = 0;

        while(i > 1 && a[i] == 1) {
            remain += a[i];
            i--;
        }

        if(i == 1 && a[i] == 1)
            break; // kết thúc vì không sinh thêm được

        // Giảm a[i]
        a[i]--;
        remain++;

        // Điền lại phần remain thành các số không nhỏ hơn a[i]
        while(remain > a[i]) {
            a[i+1] = a[i];
            remain -= a[i];
            i++;
        }

        a[i+1] = remain;
        k = i+1;

        // Kiểm tra giới hạn m
        for(int u = 1; u <= k; u++) {
            if(a[u] > m) {
                a[u] = m;
            }
        }
    }
}

int main() {
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap m: ";
    cin >> m;

    tinh_so_cach();

    cout << "Danh sach cac cach phan tich (su dung phuong phap sinh):\n";
    liet_ke();

    return 0;
}
