#include <iostream>
using namespace std;

struct Node {
    string nama, gender;
    int nim;
    float nilai;
    Node *next, *prev;
};

Node *head = NULL;

// ================= INSERT DATA (SORTED) =================
void insertData() {
    Node *baru = new Node;
    cout << "Nama   : "; cin >> baru->nama;
    cout << "NIM    : "; cin >> baru->nim;
    cout << "Gender : "; cin >> baru->gender;
    cout << "Nilai  : "; cin >> baru->nilai;

    if (!head) {
        head = baru;
        head->next = head;
        head->prev = head;
        return;
    }

    Node *curr = head;
    do {
        if (baru->nim < curr->nim) break;
        curr = curr->next;
    } while (curr != head);

    Node *prevNode = curr->prev;
    prevNode->next = baru;
    baru->prev = prevNode;
    baru->next = curr;
    curr->prev = baru;

    if (baru->nim < head->nim)
        head = baru;
}

// ================= HAPUS DATA =================
void hapusData() {
    if (!head) {
        cout << "Data kosong!\n";
        return;
    }

    int cari;
    cout << "Masukkan NIM yang dihapus: ";
    cin >> cari;

    Node *curr = head;
    do {
        if (curr->nim == cari) {
            if (curr->next == curr) {
                head = NULL;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head)
                    head = curr->next;
            }
            delete curr;
            cout << "Data berhasil dihapus\n";
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "NIM tidak ditemukan\n";
}

// ================= CETAK DATA =================
void cetakData() {
    if (!head) {
        cout << "Data kosong!\n";
        return;
    }

    Node *curr = head;
    cout << "\nNIM\tNama\tGender\tNilai\n";
    cout << "---------------------------------\n";
    do {
        cout << curr->nim << "\t"
             << curr->nama << "\t"
             << curr->gender << "\t"
             << curr->nilai << endl;
        curr = curr->next;
    } while (curr != head);
}

// ================= PROGRAM UTAMA =================
int main() {
    int pilih;
    do {
        cout << "\nCIRCULAR DOUBLY LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilih;

        switch (pilih) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Program selesai\n"; break;
            default: cout << "Pilihan salah!\n";
        }
    } while (pilih != 4);

    return 0;
}
