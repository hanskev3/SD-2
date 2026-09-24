#include <iostream>
using namespace std;

#define MAX 5 
int stack[MAX];     // sama dengan int stack[5];
int top = -1;       // awalnya kosong, jadi top = -1

// TODO : Operasi Push (menambahkan data ke stack)
void push (int value) {
    if (top == MAX - 1) {   // karna max 5 tapi dimulai dari -1 jadi maxnya 4
        cout << "Stack Penuh !\n";
    } else {
        top++;              // top = top + 1 (inkrement top)
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}

// TODO : Operasi Pop (menghapus data dari stack)
void pop (){
    if (top == -1) {
        cout << "Stack Kosong !\n";
    } else {
        cout << "\n" << stack[top] << "dihapus dari stack\n";
        top--;              // top = top - 1 (dekrement top)
    }
}

// TODO : Nampilin Stack
void display() {
    if (top == -1) {
        cout << "Stack Kosong !\n";
    } else {
        cout << "\nIsi Stack : ";
        for (int i = top; i >= 0; i --) {
            cout << stack[i] << " ";
        } 
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display();

    return 0;
}