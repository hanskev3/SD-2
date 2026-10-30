#include <iostream>
#include <vector>
using namespace std;

// TODO : Fungsi Bergabung Kembali
void merge(vector<int>& arr, int left, int mid, int right) {
    // salin dua bagian ke array sementara
    vector<int> kiri(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> kanan(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;          // indeks bagian kiri
    int j = 0;          // indeks bagian kanan
    int k = left;       // indeks posisi di array asal

    // gabungkan sambil membandingkan elemen terkecil dari kedua bagian
    while (i < kiri.size() && j < kanan.size()) {
        if (kiri[i] <= kanan[j]) {
            arr[k] = kiri[i];
            i++;
        } else {
            arr[k] = kanan[j];
            j++;
        }
        k++;
    }

    // sisa elemen bagian kiri (jika ada)
    while (i < kiri.size()) {
        arr[k] = kiri[i];
        i++;
        k++;
    }

    // sisa elemen bagian kanan (jika ada)
    while (j < kanan.size()) {
        arr[k] = kanan[j];
        j++;
        k++;
    }
}


// TODO : Memecah Barisan
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // pecah menjadi dua bagian, urutkan masing-masing
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // gabungkan kembali kedua bagian yang sudah terurut
        merge(arr, left, mid, right);
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data);

    mergeSort(data, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
}