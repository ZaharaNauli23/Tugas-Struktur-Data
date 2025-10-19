#include <iostream>

const int SIZE = 10;  // Ukuran stack
int stack[SIZE];  // Array untuk stack
int top = -1;  // Inisialisasi stack kosong

void push(int data) {
    if (top < SIZE - 1) {  // Periksa jika stack tidak penuh
        stack[++top] = data;  // Push data
        std::cout << "Data " << data << " ditambahkan ke stack.\n";
    } else {
        std::cout << "Stack penuh, tidak bisa menambahkan.\n";
    }
}

int main() {
    int data;
    while (top < SIZE - 1) {  // Loop hingga stack penuh
        std::cout << "Masukkan data: ";
        std::cin >> data;  // Input data
        push(data);  // Panggil fungsi push
    }
    return 0;
}

