#include <iostream>
using namespace std;

int main() {
    unsigned int base = 0x1000;
    unsigned int alamat = base + ((2 * 8) + 4) * sizeof(float);

    cout << "Alamat x[2][4] = " << hex << uppercase << alamat << "H" << endl;
    return 0;
}

