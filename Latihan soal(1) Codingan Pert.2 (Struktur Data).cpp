#include <iostream>
using namespace std;

int main() {
    unsigned int base = 0x1000;   // alamat &x[0] = 1000H
    unsigned int alamat_x8 = base + (8 * sizeof(char));

    cout << "Alamat x[8] = " << hex << uppercase << alamat_x8 << "H" << endl;
    return 0;
}


