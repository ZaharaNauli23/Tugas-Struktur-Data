#include <iostream>
using namespace std;

int main() {
    int skor;
    cout << "Masukkan nilai skor (0 - 100): ";
    cin >> skor;

    if (skor == 100)
        cout << "Skor sempurna!" << endl;
    else if (skor >= 90)
        cout << "Nilai: A" << endl;
    else if (skor >= 80)
        cout << "Nilai: B" << endl;
    else if (skor >= 70)
        cout << "Nilai: C" << endl;
    else if (skor >= 60)
        cout << "Nilai: D" << endl;
    else
        cout << "Nilai: F" << endl;

    return 0;
}

