#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
  int start, finish;
};

void sapxep(Job jobs[], int n) {
  for(int i = 0; i < n - 1; i ++) {
    for(int j = n - 1; j > i; j --) {
      if(jobs[j].finish < jobs[j - 1].finish) {
        swap(jobs[j], jobs[j - 1]);
      }
    }
  }
}

void schedule(Job jobs[], int n) {
  sapxep(jobs, n);
  cout << "Các công việc được chọn: " << endl;
  int last = 0;
  cout << "( " << jobs[last].start << ", " << jobs[last].finish << " )" << endl;
  for(int i = 1; i < n; i ++) {
    if(jobs[i].start >= jobs[last].finish) {
      cout << "( " << jobs[i].start << ", " << jobs[i].finish << " )" << endl;
      last = i;
    }
  }
}

int main() {
  int n;
  cout << "Nhập số lượng công việc: ";
  cin >> n;

  Job jobs[n];
  cout << "Nhập thời gian bắt đầu và kết thúc của từng công việc: " << endl;
  for(int i = 0; i < n ; i ++) {
    cin >> jobs[i].start >> jobs[i].finish;
  }
  schedule(jobs, n);
  return 0;
}