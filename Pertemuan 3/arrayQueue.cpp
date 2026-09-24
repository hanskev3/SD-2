#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];                 // sama dengan int queue[6];
int front = -1, rear = -1;      // awalnya kosong untuk front dan rear

// TODO : Enqueue
void enqueue( int value ) {
    if (rear == MAX - 1) {      // karna max 6 tapi dimulai dari -1 jadi dari 0 ke 5
        cout << "Queue sudah Penuh !\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;    // bukan front ditambah karena rear yang bertambah
        cout << value << " masuk ke dalam queue\n";
        }
}


// TODO : Dequeue
void dequeue() {
    if (front == -1 || front > rear) {    // front > rear karena front bertambah terus saat dequeue, jadi bisa lebih besar dari rear
        cout << "Queue Kosong !\n";
    } else {
        cout << queue[front] << " keluar dari queue\n";
        front++;    // front bertambah karena data dihapus dari depan
    }
}

// TODO : Nampilin isi queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue Kosong !\n";
    } else {
        cout << "\nIsi Queue : ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl; 
    }
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}