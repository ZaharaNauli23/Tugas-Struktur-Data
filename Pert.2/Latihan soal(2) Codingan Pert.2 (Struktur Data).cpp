#include <iostream>
using namespace std;

int main() {
    unsigned int base = 0x1000; // alamat x[3]
    unsigned int selisih = (9 - 3) * sizeof(int);
    unsigned int alamat_x9 = base + selisih;

    cout << "Alamat x[9] = " << hex << uppercase << alamat_x9 << "H" << endl;
    return 0;
}

