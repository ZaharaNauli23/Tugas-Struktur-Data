#include <iostream>
#include <limits>  // Untuk membersihkan input

int main() {
    const int SIZE = 10;  // Ukuran stack
    int stack[SIZE];  // Array untuk stack
    int top = -1;  // Inisialisasi stack kosong

    while (true) {
        int data;
        std::cout << "Masukkan data (999 untuk selesai): ";
        std::cin >> data;

        if (std::cin.fail()) {  // Jika input salah (bukan angka)
            std::cin.clear();  // Bersihkan error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Abaikan input salah
            std::cout << "Input tidak valid. Coba lagi.\n";
            continue;
        }

        if (data == 999) {
            std::cout << "Proses selesai.\n";
            break;  // Selesai
        }

        if (data >= 60) {
            if (top < SIZE - 1) {  // Stack tidak penuh
                stack[++top] = data;  // Push: Tambahkan elemen
                std::cout << "Data " << data << " ditambahkan ke stack.\n";
            } else {
                std::cout << "Stack Penuh\n";  // Stack penuh
                break;  // Hentikan
            }
        } else {  // data < 60
            if (top >= 0) {  // Stack tidak kosong
                int popped = stack[top];  // Ambil elemen
                top--;  // Pop: Kurangi top
                std::cout << "Data yang diambil: " << popped << "\n";
            } else {
                std::cout << "Stack Kosong\n";  // Stack kosong
                break;  // Hentikan
            }
        }
    }

    return 0;
}

