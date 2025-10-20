#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ACTIVITIES = 10;

struct Interval {
    int start;
    int finish;
    int id;
};

// Sắp xếp tăng dần theo finish time
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.finish < b.finish;
}

void interval_scheduling(Interval intervals[], int n) {
    if (n <= 0) {
        cout << "Không có hoạt động nào để lập lịch." << endl;
        return;
    }

    // Greedy Step: Sắp xếp các khoảng thời gian theo finish time tăng dần
    sort(intervals, intervals + n, compareIntervals);

    // Mảng lưu ID của các hoạt động được chọn
    int selected_ids[MAX_ACTIVITIES];
    int selected_count = 0;

    // Chọn hoạt động đầu tiên (hoạt động kết thúc sớm nhất)
    selected_ids[selected_count++] = intervals[0].id;
    int last_finish_time = intervals[0].finish;

    cout << "Các hoạt động/khoảng thời gian (sắp xếp theo finish):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "  - ID " << intervals[i].id << ": [" << intervals[i].start << ", " << intervals[i].finish << "]" << endl;
    }

    // Duyệt qua các hoạt động còn lại
    for (int i = 1; i < n; ++i) {
        // Nếu start time của hoạt động hiện tại >= finish time của hoạt động cuối cùng đã chọn
        if (intervals[i].start >= last_finish_time) {
            if (selected_count < MAX_ACTIVITIES) {
                selected_ids[selected_count++] = intervals[i].id;
                last_finish_time = intervals[i].finish;
            }
        }
    }

    cout << "\n--- Kết quả Lập lịch khoảng (Greedy) ---" << endl;
    cout << "Số lượng hoạt động được chọn tối đa: " << selected_count << endl;
    cout << "Các hoạt động được chọn (ID): ";
    for (int i = 0; i < selected_count; ++i) {
        cout << selected_ids[i] << (i == selected_count - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    // (start, finish, id)
    Interval activities[6] = {
        {1, 4, 1}, {3, 5, 2}, {0, 6, 3}, {5, 7, 4}, {8, 9, 5}, {5, 9, 6}
    };
    interval_scheduling(activities, 6);
    return 0;
}