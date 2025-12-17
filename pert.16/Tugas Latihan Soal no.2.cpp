#include <iostream>
using namespace std;

// Fungsi Binary Search sesuai algoritma standar
int binarySearch(int arr[], int n, int key, bool tampilkanProses = true) {
    int left = 0;
    int right = n - 1;
    int iterasi = 0;
    
    if (tampilkanProses) {
        cout << "\n--- Pencarian nilai " << key << " ---" << endl;
    }
    
    while (left <= right) {
        iterasi++;
        int mid = (left + right) / 2;
        
        if (tampilkanProses) {
            cout << "Iterasi " << iterasi << ": ";
            cout << "left=" << left << ", mid=" << mid << ", right=" << right;
            cout << " | arr[" << mid << "]=" << arr[mid];
        }
        
        // Jika data ditemukan
        if (arr[mid] == key) {
            if (tampilkanProses) {
                cout << " --> DITEMUKAN!" << endl;
            }
            return mid;
        }
        // Jika key lebih kecil, cari di bagian kiri
        else if (key < arr[mid]) {
            if (tampilkanProses) {
                cout << " --> Cari kiri" << endl;
            }
            right = mid - 1;
        }
        // Jika key lebih besar, cari di bagian kanan
        else {
            if (tampilkanProses) {
                cout << " --> Cari kanan" << endl;
            }
            left = mid + 1;
        }
    }
    
    // Data tidak ditemukan
    if (tampilkanProses) {
        cout << "Data tidak ditemukan" << endl;
    }
    return -1;
}

// Fungsi untuk menampilkan array
void tampilkanArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Fungsi untuk menampilkan algoritma Binary Search
void tampilkanAlgoritma() {
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║           ALGORITMA BINARY SEARCH                         ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    cout << "\nINPUT:" << endl;
    cout << "  - Array data yang sudah terurut (sorted)" << endl;
    cout << "  - n = jumlah elemen dalam array" << endl;
    cout << "  - key = nilai yang dicari" << endl;
    
    cout << "\nPROSES:" << endl;
    cout << "  1. Set left = 0, right = n - 1" << endl;
    cout << "  2. Selama left <= right, lakukan:" << endl;
    cout << "     a. Hitung mid = (left + right) / 2" << endl;
    cout << "     b. Jika arr[mid] == key:" << endl;
    cout << "        - Return mid (data ditemukan)" << endl;
    cout << "     c. Jika key < arr[mid]:" << endl;
    cout << "        - right = mid - 1 (cari di bagian kiri)" << endl;
    cout << "     d. Jika key > arr[mid]:" << endl;
    cout << "        - left = mid + 1 (cari di bagian kanan)" << endl;
    cout << "  3. Jika loop selesai tanpa return:" << endl;
    cout << "     - Return -1 (data tidak ditemukan)" << endl;
    
    cout << "\nOUTPUT:" << endl;
    cout << "  - Indeks posisi data jika ditemukan" << endl;
    cout << "  - -1 jika tidak ditemukan" << endl;
    
    cout << "\nKOMPLEKSITAS:" << endl;
    cout << "  - Time Complexity: O(log n)" << endl;
    cout << "  - Space Complexity: O(1)" << endl;
    cout << "\n───────────────────────────────────────────────────────────\n" << endl;
}

int main() {
    cout << "=============================================" << endl;
    cout << "   SOAL NO. 2 - ALGORITMA BINARY SEARCH" << endl;
    cout << "=============================================" << endl;
    
    // Tampilkan algoritma
    tampilkanAlgoritma();
    
    // Contoh data dari soal no. 1
    int data[] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};
    int n = sizeof(data) / sizeof(data[0]);
    
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║           CONTOH IMPLEMENTASI                             ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    cout << "\nData yang digunakan (dari soal no. 1):" << endl;
    cout << "Data: ";
    tampilkanArray(data, n);
    cout << "Jumlah elemen: " << n << endl;
    
    // Contoh 1: Mencari nilai 17
    cout << "\n" << string(60, '=') << endl;
    cout << "CONTOH 1: Mencari nilai 17" << endl;
    cout << string(60, '=') << endl;
    int hasil1 = binarySearch(data, n, 17);
    cout << "Hasil: Nilai 17 ditemukan pada indeks " << hasil1 << endl;
    
    // Contoh 2: Mencari nilai 22
    cout << "\n" << string(60, '=') << endl;
    cout << "CONTOH 2: Mencari nilai 22" << endl;
    cout << string(60, '=') << endl;
    int hasil2 = binarySearch(data, n, 22);
    cout << "Hasil: Nilai 22 ditemukan pada indeks " << hasil2 << endl;
    
    // Contoh 3: Mencari nilai yang tidak ada
    cout << "\n" << string(60, '=') << endl;
    cout << "CONTOH 3: Mencari nilai 20 (tidak ada dalam array)" << endl;
    cout << string(60, '=') << endl;
    int hasil3 = binarySearch(data, n, 20);
    if (hasil3 == -1) {
        cout << "Hasil: Nilai 20 tidak ditemukan dalam array" << endl;
    }
    
    // Menu interaktif
    cout << "\n\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║           COBA SENDIRI                                    ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    char lanjut;
    do {
        int cari;
        cout << "\nMasukkan nilai yang ingin dicari: ";
        cin >> cari;
        
        int hasil = binarySearch(data, n, cari);
        
        if (hasil != -1) {
            cout << "\n==> Nilai " << cari << " DITEMUKAN pada indeks " << hasil << endl;
        } else {
            cout << "\n==> Nilai " << cari << " TIDAK DITEMUKAN dalam array" << endl;
        }
        
        cout << "\nCoba nilai lain? (y/n): ";
        cin >> lanjut;
        
    } while (lanjut == 'y' || lanjut == 'Y');
    
    cout << "\n=============================================" << endl;
    cout << "   Program Selesai. Terima kasih!" << endl;
    cout << "=============================================" << endl;
    
    return 0;
}
