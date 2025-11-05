#include <iostream>
using namespace std;

int main() {
    const int n = 7; 
    float a[n] = {1, 4, 3, 5, 2, 7, 9};

    int L[n];        // L[i] = độ dài LIS kết thúc tại i
    int prev[n];     // prev[i] = phần tử đứng trước trong LIS tại i

    // Khởi tạo
    for(int i = 0; i < n; i++){
        L[i] = 1;
        prev[i] = -1;
    }

    // Quy hoạch động
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && L[j] + 1 > L[i]){
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Tìm vị trí có LIS dài nhất
    int max_len = L[0], pos = 0;
    for(int i = 1; i < n; i++){
        if(L[i] > max_len){
            max_len = L[i];
            pos = i;
        }
    }

    // Truy vết lại dãy LIS
    float lis[max_len];
    int index = max_len - 1;
    while(pos != -1){
        lis[index] = a[pos];
        index--;
        pos = prev[pos];
    }

    // In kết quả
    cout << "Do dai day con don dieu tang dai nhat: " << max_len << endl;
    for(int i = 0; i < n; i ++) {
      cout << prev[i];
    }
    cout << "Day con: ";
    for(int i = 0; i < max_len; i++)
        cout << lis[i] << " ";
    cout << endl;

    return 0;
}
