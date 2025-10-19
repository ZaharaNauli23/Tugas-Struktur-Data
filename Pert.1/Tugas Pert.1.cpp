#include <iostream>
using namespace std;

int main() {
    int angka;
    char huruf;
    float desimal;

    cout << "Masukkan nilai integer, karakter, dan float (pisahkan dengan spasi): ";
    cin >> angka >> huruf >> desimal;

    cout << "Nilai integer: " << angka << endl;
    cout << "Nilai karakter: " << huruf << endl;
    cout << "Nilai float: " << desimal << endl;

    return 0;
}

