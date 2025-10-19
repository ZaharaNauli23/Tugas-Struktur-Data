#include <iostream>
#include <string>

struct Mahasiswa {
    int no_urut;
    std::string nama;
    int umur;
    std::string alamat;
    float nilai;
};

int main() {
    const int jumlahMahasiswa = 15;
    Mahasiswa dataMahasiswa[jumlahMahasiswa];

    // Input data mahasiswa
    for(int i = 0; i < jumlahMahasiswa; i++) {
        dataMahasiswa[i].no_urut = i + 1;  // No urut mulai dari 1
        std::cout << "Masukkan data mahasiswa " << (i+1) << ":\n";
        std::cout << "Nama: ";
        std::cin >> dataMahasiswa[i].nama;
        std::cout << "Umur: ";
        std::cin >> dataMahasiswa[i].umur;
        std::cout << "Alamat: ";
        std::cin >> dataMahasiswa[i].alamat;  // Asumsikan alamat singkat
        std::cout << "Nilai: ";
        std::cin >> dataMahasiswa[i].nilai;
    }

    // Cetak data mahasiswa
    std::cout << "\nData Semua Mahasiswa:\n";
    for(int i = 0; i < jumlahMahasiswa; i++) {
        std::cout << "No Urut: " << dataMahasiswa[i].no_urut << std::endl;
        std::cout << "Nama: " << dataMahasiswa[i].nama << std::endl;
        std::cout << "Umur: " << dataMahasiswa[i].umur << std::endl;
        std::cout << "Alamat: " << dataMahasiswa[i].alamat << std::endl;
        std::cout << "Nilai: " << dataMahasiswa[i].nilai << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}


