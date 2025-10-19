#include <iostream>
using namespace std;
int main() {
    const int SIZE = 10;
    int stack[SIZE];
    int top = -1;  // Stack kosong

    // Proses Push
    std::cout << "Masukkan data (999 untuk selesai):\n";
    while (top < SIZE - 1) {  // Sampai stack penuh
        int data;
        std::cin >> data;
        if (data == 999) break;  // Hentikan input
        stack[++top] = data;  // Push
    }

    // Proses Pop
    std::cout << "Mengeluarkan isi stack:\n";
    while (top >= 0) {
        std::cout << stack[top] << " ";  // Pop dan cetak
        top--;
    }
    std::cout << "\nStack sekarang kosong.\n";

    return 0;
}

