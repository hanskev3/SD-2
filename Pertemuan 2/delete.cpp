#include <iostream>
using namespace std;

// Deklarasi Struktur Node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Fungsi Cetak List
void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Fungsi tambah node di akhir (biar ada data untuk dihapus)
void insertLast(int n) {
    Node *newNode = new Node{n, NULL};
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// TODO : Hapus node pertama
void deleteFirst() {
    if(head == NULL) {
        cout << "List nya kosong\n";
        return;
    }
    Node *temp = head;                  // Simpan node pertama
    head = head -> next;               
    if (head == NULL) tail = NULL;      // Jika list menjadi kosong, update tail
    delete temp;                        // Hapus node pertama
    }


// TODO : Hapus node terakhir
void deleteLast() {
    if(head == NULL) {
        cout << "List nya kosong\n";
        return;
    }

    if(head == tail) {                  // Jika hanya ada satu node, hapus salah satu node
        delete head;
        head = tail = NULL;
        return;
    }

    Node *p = head;                     // mulai p dari head
    while(p->next != tail) {
        p = p->next;
    }
    delete tail;                      
    tail = p;                     
    tail->next = NULL;                  // Update tail dan next terakhir
}

// TODO : Hapus node dengan nilai tertentu
void deleteMiddle(int value) {
    if(head == NULL) {
        cout << "List nya kosong\n";
        return;
    }

    if(head->value == value) {          // Jika node pertama yang akan dihapus
        deleteFirst();
        return;
    }

    Node *p = head;                     
    while(p->next != NULL && p->next->value != value) {     // Cari node sebelum node yang akan dihapus
        p = p->next;
    }

        if(p->next == NULL) {            
            cout << "Node dengan nilai " << value << " tidak ada\n"; 
        } else {                              
            Node *temp = p->next;       // Simpan node yang akan dihapus
            p->next = temp->next;       
            if(temp == tail) tail = p;          // Jika node terakhir yang dihapus, update tail
            delete temp;               
        }
}

int main() {
    // Contoh list awal
    insertLast(10);
    insertLast(20);
    insertLast(30);

    cout << "List awal:\n";
    printList();

    cout << "\nHapus node pertama:\n";
    deleteFirst();
    printList();

    cout << "\nHapus node terakhir:\n";
    deleteLast();
    printList();

    cout << "\nHapus node dengan nilai 20:\n";
    deleteMiddle(20);
    printList();

    return 0;
}