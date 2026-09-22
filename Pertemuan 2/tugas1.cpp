#include <iostream>
#include <limits>
using namespace std;

// Deklarasi struktur node
struct Node {
    string nama;
    float nilai;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert di depan
void insertFirst(string nama, float nilai) {
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert di belakang
void insertLast(string nama, float nilai) {
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {                 // Jika linked list kosong
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert setelah node dengan nilai tertentu
void insertAfter(string nama, float nilai, float check) {
    if (head == NULL) {                 // Jika linked list kosong
        cout << "List kosong, insert di depan dulu\n";
        return;
    }

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = NULL;

    Node *p = head;                     // Pointer untuk menelusuri linked list
    while (p != NULL && p->nilai != check) {
        p = p->next;
    }

    if (p == NULL) {                    // Jika nilai check tidak ditemukan
        cout << "Node dengan nilai " << check << " tidak ada\n";
        delete newNode;
    } else {                            // Jika nilai check ditemukan
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

// Hapus node pertama
void deleteFirst() {
    if (head == NULL) {
        cout << "List nya kosong\n";
        return;
    }
    Node *temp = head;                  // Simpan node pertama
    head = head->next;
    if (head == NULL) tail = NULL;      // Jika list menjadi kosong, update tail
    delete temp;                        // Hapus node pertama
}

// Hapus node terakhir
void deleteLast() {
    if (head == NULL) {
        cout << "List nya kosong\n";
        return;
    }

    if (head == tail) {                 // Jika hanya ada satu node
        delete head;
        head = tail = NULL;
        return;
    }

    Node *p = head;                     // Mulai p dari head
    while (p->next != tail) {
        p = p->next;
    }
    delete tail;
    tail = p;
    tail->next = NULL;                  // Update tail dan next terakhir
}

// Hapus node dengan nilai tertentu
void deleteByValue(float value) {
    if (head == NULL) {
        cout << "List nya kosong\n";
        return;
    }

    if (head->nilai == value) {         // Jika node pertama yang akan dihapus
        deleteFirst();
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->nilai != value) {   // Cari node sebelum node yang akan dihapus
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ada\n";
    } else {
        Node *temp = p->next;           // Simpan node yang akan dihapus
        p->next = temp->next;
        if (temp == tail) tail = p;     // Jika node terakhir yang dihapus, update tail
        delete temp;
    }
}

// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi Linked List (head -> tail): ";
    while (temp != NULL) {
        cout << "[" << temp->nama << ", " << temp->nilai << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Bersihkan buffer input supaya cin tidak rusak kalau ada input yang salah/format tak terduga
void bersihkanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int pilihan;
    string nama;
    float nilai, check;

    do {
        cout << "\n===== MENU DATA NILAI MAHASISWA =====\n";
        cout << "1. Insert di depan\n";
        cout << "2. Insert di belakang\n";
        cout << "3. Insert setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan list\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";

        cin >> pilihan;
        if (cin.fail()) {                // Jaga-jaga kalau input menu bukan angka
            cout << "Input harus berupa angka.\n";
            bersihkanBuffer();
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "Nama: ";
                cin >> nama;
                cout << "Nilai: ";
                cin >> nilai;
                if (cin.fail()) {
                    cout << "Nilai harus berupa angka (contoh: 80 atau 80.5).\n";
                    bersihkanBuffer();
                    break;
                }
                insertFirst(nama, nilai);
                printList();
                break;

            case 2:
                cout << "Nama: ";
                cin >> nama;
                cout << "Nilai: ";
                cin >> nilai;
                if (cin.fail()) {
                    cout << "Nilai harus berupa angka (contoh: 80 atau 80.5).\n";
                    bersihkanBuffer();
                    break;
                }
                insertLast(nama, nilai);
                printList();
                break;

            case 3:
                cout << "Nilai acuan (setelah node mana): ";
                cin >> check;
                cout << "Nama baru: ";
                cin >> nama;
                cout << "Nilai baru: ";
                cin >> nilai;
                if (cin.fail()) {
                    cout << "Nilai harus berupa angka (contoh: 80 atau 80.5).\n";
                    bersihkanBuffer();
                    break;
                }
                insertAfter(nama, nilai, check);
                printList();
                break;

            case 4:
                cout << "Nilai yang ingin dihapus: ";
                cin >> nilai;
                if (cin.fail()) {
                    cout << "Nilai harus berupa angka.\n";
                    bersihkanBuffer();
                    break;
                }
                deleteByValue(nilai);
                printList();
                break;

            case 5:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}