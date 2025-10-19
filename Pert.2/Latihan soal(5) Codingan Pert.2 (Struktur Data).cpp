#include <iostream>
using namespace std;

int main() {
    unsigned int base_diketahui = 0x12EF; // alamat [1][1][4]
    int size = sizeof(int); // 2 byte untuk latihan teori

    int posisi1 = (1 * (3 * 5)) + (1 * 5) + 4; // [1][1][4]
    int posisi2 = (0 * (3 * 5)) + (0 * 5) + 3; // [0][0][3]
    int selisih = posisi1 - posisi2;

    unsigned int alamat_target = base_diketahui - (selisih * size);

    cout << "Alamat x[0][0][3] = " << hex << uppercase << alamat_target << "H" << endl;
    return 0;
}

