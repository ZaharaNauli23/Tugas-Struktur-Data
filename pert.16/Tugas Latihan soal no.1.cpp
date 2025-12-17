#include <iostream>
using namespace std;

// Fungsi Binary Search dengan menampilkan proses iterasi
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int iterasi = 0;
    
    cout << "\n=== Proses Binary Search untuk mencari nilai " << key << " ===" << endl;
    
    while (left <= right) {
        iterasi++;
        int mid = (left + right) / 2;
        
        cout << "\nIterasi " << iterasi << ":" << endl;
        cout << "Left = " << left << ", Right = " << right << ", Mid = " << mid << endl;
        cout << "Data[" << mid << "] = " << arr[mid] << endl;
        
        if (arr[mid] == key) {
            cout << ">>> " << key << " == " << arr[mid] << " --> DITEMUKAN di indeks " << mid << endl;
            cout << ">>> Jumlah iterasi: " << iterasi << endl;
            return mid;
        }
        else if (key < arr[mid]) {
            cout << ">>> " << key << " < " << arr[mid] << " --> Cari di bagian KIRI" << endl;
            right = mid - 1;
        }
        else {
            cout << ">>> " << key << " > " << arr[mid] << " --> Cari di bagian KANAN" << endl;
            left = mid + 1;
        }
    }
    
    cout << "\n>>> Data TIDAK DITEMUKAN setelah " << iterasi << " iterasi" << endl;
    return -1;
}

// Fungsi untuk menampilkan array dengan indeks
void tampilkanArray(int arr[], int n) {
    cout << "\nIndeks: ";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
    }
    cout << "\nData  : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n" << endl;
}

int main() {
    // Data dari soal
    int data[] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};
    int n = sizeof(data) / sizeof(data[0]);
    
    cout << "=============================================" << endl;
    cout << "   SOAL NO. 1 - BINARY SEARCH TRACKING" << endl;
    cout << "=============================================" << endl;
    
    tampilkanArray(data, n);
    cout << "Jumlah data (n): " << n << endl;
    
    // Soal 1a: Mencari N = 17
    cout << "\n\n╔════════════════════════════════════════╗" << endl;
    cout << "║  SOAL 1a: Mencari N = 17              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    int hasil1 = binarySearch(data, n, 17);
    if (hasil1 != -1) {
        cout << "\n==> KESIMPULAN: Nilai 17 DITEMUKAN pada indeks " << hasil1 << endl;
        cout << "    Status: Data ditemukan pada iterasi pertama" << endl;
    }
    
    // Soal 1b: Mencari N = 22
    cout << "\n\n╔════════════════════════════════════════╗" << endl;
    cout << "║  SOAL 1b: Mencari N = 22              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    int hasil2 = binarySearch(data, n, 22);
    if (hasil2 != -1) {
        cout << "\n==> KESIMPULAN: Nilai 22 DITEMUKAN pada indeks " << hasil2 << endl;
        cout << "    Status: Data ditemukan setelah beberapa iterasi" << endl;
    }
    
    cout << "\n=============================================" << endl;
    cout << "   Program Selesai" << endl;
    cout << "=============================================" << endl;
    
    return 0;
}
