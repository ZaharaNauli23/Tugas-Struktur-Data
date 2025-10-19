#include <iostream>
#include <cstdlib>
using namespace std;

struct SIMPUL {
    int INFO;
    struct SIMPUL *LINK;
};

SIMPUL *P, *FIRST, *LAST;

void BUAT_SIMPUL(int);

int main() {
    int x;
    cout << "Masukkan Data : ";
    cin >> x;

    BUAT_SIMPUL(x);
    cout << "Data : " << P->INFO << endl;

    return 0;
}

void BUAT_SIMPUL(int x) {
    P = (SIMPUL *)malloc(sizeof(SIMPUL));
    if (P != NULL)
        P->INFO = x;
    else
        cout << "Pembuatan Simpul Gagal" << endl;
}


