#include <iostream>
using namespace std;

#define MAX 5  // ukuran maksimum stack

int main() {
    int stack[MAX];
    int top = -1; // menandakan stack masih kosong

    // --- Isi awal stack (misalnya sudah terisi 5 elemen) ---
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;
    stack[++top] = 40;
    stack[++top] = 50;

    cout << "Isi stack akan dikeluarkan satu per satu (POP):" << endl;

    // --- Proses POP ---
    while (top >= 0) { 
        cout << "Data yang dikeluarkan (POP): " << stack[top] << endl;
        top--; // hapus elemen paling atas
    }

    cout << "Stack sekarang kosong." << endl;

    return 0;
}

