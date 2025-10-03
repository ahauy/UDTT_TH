#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 6;

struct SinhVien {
	string ten;
	string hoDem;
	int namSinh;
	string diaChi;
};

struct List{
	SinhVien e[MAX];
	int count;
};

List L;

void init(List &L) {
	L.count = -1;
}

void add(List &L, SinhVien sv) {
	if(L.count < MAX) {
		L.count ++;
		L.e[L.count] = sv;
	} else {
		return;
	}
}

void ktao(List &L) {
	SinhVien sv1 = {"Hau", "Vu Tuan", 2005, "Bac Ninh"};
	add(L, sv1);
	SinhVien sv2 = {"Thang", "Nguyen Dang", 2005, "Bac Ninh"};
	add(L, sv2);
	SinhVien sv3 = {"Hung", "Nguyen Kieu", 2005, "Hai Phong"};
	add(L, sv3);
	SinhVien sv4 = {"Hang", "Ta Thu", 2005, "Thai Nguyen"};
	add(L, sv4);
}

void displayList(List L) {
	cout << setw(7) << left << "STT";
	cout << setw(20) << left << "Ho dem";
	cout << setw(15) << left << "Ten";
	cout << setw(15) << left << "Nam sinh";
	cout << setw(20) << left << "Que quan";
	cout << endl;
	
	for(int i = 0; i <= L.count; i ++) {
		cout << setw(7) << left << i + 1;
		cout << setw(20) << left << L.e[i].hoDem;
		cout << setw(15) << left << L.e[i].ten;
		cout << setw(15) << left << L.e[i].namSinh;
		cout << setw(20) << left << L.e[i].diaChi;
		cout << endl;
	}
}

int main() {
	init(L);
	ktao(L);
	displayList(L);
	return 0;
}