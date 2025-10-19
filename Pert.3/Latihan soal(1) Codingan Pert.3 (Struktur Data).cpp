#include <iostream>
#include <string>

struct Mahasiswa {
    int no_urut;
    std::string nama;
    int usia;
    float nilai;
};

int main() {
    const int jumlahMahasiswa = 5;  // Jumlah mahasiswa sebagai contoh
    Mahasiswa dataMahasiswa[jumlahMahasiswa];

    // Input data mahasiswa
    for(int i = 0; i < jumlahMahasiswa; i++) {
        dataMahasiswa[i].no_urut = i + 1;  // No urut mulai dari 1
        std::cout << "Masukkan nama mahasiswa " << (i+1) << ": ";
        std::cin >> dataMahasiswa[i].nama;
        std::cout << "Masukkan usia mahasiswa " << (i+1) << ": ";
        std::cin >> dataMahasiswa[i].usia;
        std::cout << "Masukkan nilai mahasiswa " << (i+1) << ": ";
        std::cin >> dataMahasiswa[i].nilai;
    }

    // Cetak data mahasiswa
    std::cout << "\nData Mahasiswa:\n";
    for(int i = 0; i < jumlahMahasiswa; i++) {
        std::cout << "No Urut: " << dataMahasiswa[i].no_urut << std::endl;
        std::cout << "Nama: " << dataMahasiswa[i].nama << std::endl;
        std::cout << "Usia: " << dataMahasiswa[i].usia << std::endl;
        std::cout << "Nilai: " << dataMahasiswa[i].nilai << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}


