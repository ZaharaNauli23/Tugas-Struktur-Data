#include <iostream>
using namespace std;

int main() {
    unsigned int base = 0x1000;
    unsigned int alamat = base + ((2 * 14) + 4) * sizeof(long);

    cout << "Alamat x[2][4] = " << hex << uppercase << alamat << "H" << endl;
    return 0;
}

