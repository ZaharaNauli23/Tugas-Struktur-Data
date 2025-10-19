#include <iostream>
using namespace std;

int main() {
    int A, B, temp;

    cout << "Masukkan dua bilangan (A dan B): ";
    cin >> A >> B;

    cout << "Sebelum ditukar: A = " << A << ", B = " << B << endl;

    temp = A;
    A = B;
    B = temp;

    cout << "Setelah ditukar: A = " << A << ", B = " << B << endl;

    return 0;
}

