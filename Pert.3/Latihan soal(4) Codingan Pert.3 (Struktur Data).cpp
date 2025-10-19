#include <iostream>
#include <string>
#include <vector>  // Untuk array dinamis

struct Buku {
    int nomor_akses;
    std::string nama_penulis;
    std::string judul_buku;
    bool bendera_terbitkan;  // true = tersedia, false = dipinjam
    int jumlah_stok;  // Untuk menghandle penambahan/kurangan stok
};

std::vector<Buku> daftarBuku;  // Array global untuk menyimpan buku

void tambahBuku() {
    Buku baru;
    std::cout << "Masukkan nomor akses: ";
    std::cin >> baru.nomor_akses;
    std::cout << "Masukkan nama penulis: ";
    std::cin >> baru.nama_penulis;
    std::cout << "Masukkan judul buku: ";
    std::cin >> baru.judul_buku;
    std::cout << "Masukkan jumlah stok awal: ";
    std::cin >> baru.jumlah_stok;
    baru.bendera_terbitkan = true;  // Default: tersedia
    daftarBuku.push_back(baru);
    std::cout << "Buku berhasil ditambahkan!\n";
}

void tampilkanBuku() {
    for(const auto& buku : daftarBuku) {
        std::cout << "Nomor Akses: " << buku.nomor_akses << std::endl;
        std::cout << "Penulis: " << buku.nama_penulis << std::endl;
        std::cout << "Judul: " << buku.judul_buku << std::endl;
        std::cout << "Status: " << (buku.bendera_terbitkan ? "Tersedia" : "Dipinjam") << std::endl;
        std::cout << "Stok: " << buku.jumlah_stok << std::endl;
        std::cout << "------------------------\n";
    }
}

int main() {
    // Contoh penggunaan
    tambahBuku();  // Tambah satu buku
    tampilkanBuku();
    return 0;
}

