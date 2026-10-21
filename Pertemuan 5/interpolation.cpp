#include <iostream>
#include <algorithm>
#include <math.h>       // untuk fungsi floor()
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data ascending agar bisa digunakan untuk Interpolation Search
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;         // untuk menyimpan indeks data yang dicari
    float posisi1;      // untuk menyimpan posisi interpolasi sebelum dibulatkan

    // TODO : Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = (float)(cari - data[low]) / (data[high] - data[low]) * (high - low) + low;
        posisi  = floor(posisi1);

        cout << "\nPosisi perkiraan: " << posisi1 << " -> dibulatkan ke " << posisi;

        if(data[posisi] == cari) {
            flag = 1;
            break;
        }

        if(data[posisi] > cari) {
            high = posisi - 1;
        } else {
            low = posisi + 1;
        }
    }
    
    
    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}


// 1. ascending : 9 12 21 26 30 36 52
// 2. posisi = 30 - 9
//            --------- x (6 - 0) + 0
//             52 - 9

// posisi = 21 / 43 * 6 = 2,93 --> 2 (dibulatkan ke bawah) --> [21]

// 3. Perbandingan 
// a. [21] == 30 NOOOO
// b. 21 > 30 NOOOO
// c. 21 < 30 YESSSS, low = posisi + 1, low = 2 + 1 = 3

// 1. posisi = 30 - 26
//            --------- x (6 - 3) + 3
//             52 - 26

// posisi = 4 / 26 * 3 + 3 = 3,46 --> 3 --> [26]
// 2. Perbandingan
// a. [26] == 30 NOOOO
// b. 26 > 30 NOOOO
// c. 26 < 30 YESSSS, low = posisi + 1, low = 3 + 1 = 4

// 1. posisi = 30 - 30
//            --------- x (6 - 4) + 4
//             52 - 30

// posisi = 0 / 22 * 2 + 4 = 4 --> [30]
// 2. Perbandingan
// a. [30] == 30 YESSSS, data ditemukan di indeks ke-4