#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key;

    // TODO : Proses pencarian sequential/linear
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i; // simpan posisi ketika ketemu
            break;
        }
    }
    // Output hasil
    if (posisi != -1) {
        cout << "\nData ditemukan di indeks ke- " << posisi << endl;
    } else {
        cout << "\nData tidak ditemukan " << endl;
    }
}

// Data : 12 9 52 26 30 36 21
// Target : 30

// 1. Descending : 52 36 30 26 21 12 9
// 2. left = 0, right = N - 1 (7 - 1 = 6)
// 3. middle = (0 + 6) / 2 = 3 [26]
// 4. [26] == 30 NOOOO
// a. 30 < 26 NOOOO
// b. 30 > 26 YESSSS , cari dibagian middle

// 1. Descending : 52 36 30
// 2. left = 0, right = 2
// 3. middle = (0 + 2) / 2 = 1 [36]
// 4. Bandingkan:
// a. [36] == 30 NOOOO
// b. 30 < 36 YESSSS , cari dibagian < middle

// 1. Descending : 30
// 2. left = 0, right = 0
// 3. middle = (0 + 0) / 2 = 0 [30]
// 4. Bandingkan:
// a. [30] == 30 YESSSS

// iterative dan rekursive
