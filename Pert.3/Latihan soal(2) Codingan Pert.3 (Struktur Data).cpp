#include <iostream>
#include <string>

struct Mahasiswa {
    int no_urut;
    std::string nama;
    int umur;
};

int main() {
    const int jumlahMahasiswa = 5;
    Mahasiswa dataMahasiswa[jumlahMahasiswa];

    // Input data mahasiswa
    for(int i = 0; i < jumlahMahasiswa; i++) {
        dataMahasiswa[i].no_urut = i + 1;  // No urut mulai dari 1
        std::cout << "Masukkan nama mahasiswa " << (i+1) << ": ";
        std::cin >> dataMahasiswa[i].nama;
        std::cout << "Masukkan umur mahasiswa " << (i+1) << ": ";
        std::cin >> dataMahasiswa[i].umur;
    }

    // Cetak detail mahasiswa dengan No urut 2
    std::cout << "\nDetail Mahasiswa dengan No Urut 2:\n";
    for(int i = 0; i < jumlahMahasiswa; i++) {
        if(dataMahasiswa[i].no_urut == 2) {
            std::cout << "No Urut: " << dataMahasiswa[i].no_urut << std::endl;
            std::cout << "Nama: " << dataMahasiswa[i].nama << std::endl;
            std::cout << "Umur: " << dataMahasiswa[i].umur << std::endl;
            break;  // Hanya cetak satu yang sesuai
        }
    }

    return 0;
}

