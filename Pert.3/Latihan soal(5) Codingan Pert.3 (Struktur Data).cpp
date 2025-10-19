#include <iostream>
#include <string>
#include <vector>

struct Buku {
    int nomor_akses;
    std::string nama_penulis;
    std::string judul_buku;
    bool bendera_terbitkan;  // true = tersedia
    int jumlah_stok;
};

std::vector<Buku> daftarBuku;

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
    baru.bendera_terbitkan = true;
    daftarBuku.push_back(baru);
    std::cout << "Buku berhasil ditambahkan!\n";
}

void tampilkanInformasiBuku() {
    if(daftarBuku.empty()) {
        std::cout << "Tidak ada buku.\n";
        return;
    }
    for(const auto& buku : daftarBuku) {
        std::cout << "Nomor Akses: " << buku.nomor_akses << ", Penulis: " << buku.nama_penulis 
                  << ", Judul: " << buku.judul_buku << ", Stok: " << buku.jumlah_stok << std::endl;
    }
}

void tampilkanBukuPenulis() {
    std::string penulis;
    std::cout << "Masukkan nama penulis: ";
    std::cin >> penulis;
    int count = 0;
    for(const auto& buku : daftarBuku) {
        if(buku.nama_penulis == penulis) {
            std::cout << "Judul: " << buku.judul_buku << ", Stok: " << buku.jumlah_stok << std::endl;
            count++;
        }
    }
    if(count == 0) std::cout << "Tidak ada buku dari penulis ini.\n";
}

void jumlahBukuJudul() {
    std::string judul;
    std::cout << "Masukkan judul buku: ";
    std::cin >> judul;
    int count = 0;
    for(const auto& buku : daftarBuku) {
        if(buku.judul_buku == judul) count += buku.jumlah_stok;
    }
    std::cout << "Jumlah buku dengan judul ini: " << count << std::endl;
}

void jumlahTotalBuku() {
    int total = 0;
    for(const auto& buku : daftarBuku) total += buku.jumlah_stok;
    std::cout << "Jumlah total buku: " << total << std::endl;
}

void terbitkanBuku() {
    int nomor;
    std::cout << "Masukkan nomor akses buku: ";
    std::cin >> nomor;
    for(auto& buku : daftarBuku) {
        if(buku.nomor_akses == nomor && buku.jumlah_stok > 0) {
            buku.jumlah_stok--;  // Kurangi stok
            buku.bendera_terbitkan = (buku.jumlah_stok > 0);  // Update flag
            std::cout << "Buku berhasil diterbitkan. Stok sekarang: " << buku.jumlah_stok << std::endl;
            return;
        }
    }
    std::cout << "Buku tidak ditemukan atau stok habis.\n";
}

int main() {
    int pilihan;
    while(true) {
        std::cout << "\nMenu Perpustakaan:\n";
        std::cout << "1 - Menampilkan informasi buku\n";
        std::cout << "2 - Tambahkan buku baru\n";
        std::cout << "3 - Tampilkan semua buku di perpustakaan penulis tertentu\n";
        std::cout << "4 - Menampilkan jumlah buku dengan judul tertentu\n";
        std::cout << "5 - Menampilkan jumlah total buku di perpustakaan\n";
        std::cout << "6 - Terbitkan buku\n";
        std::cout << "0 - Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        if(pilihan == 0) break;
        switch(pilihan) {
            case 1: tampilkanInformasiBuku(); break;
            case 2: tambahBuku(); break;
            case 3: tampilkanBukuPenulis(); break;
            case 4: jumlahBukuJudul(); break;
            case 5: jumlahTotalBuku(); break;
            case 6: terbitkanBuku(); break;
            default: std::cout << "Pilihan salah!\n";
        }
    }
    return 0;
}

