#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    string nama, nim, gender;
    float nilai;
    Node *next, *prev;
};

class DoublyLinkedList {
private:
    Node *head, *tail;
    
public:
    DoublyLinkedList() { head = tail = NULL; }
    
    void insert(string nama, string nim, string gender, float nilai) {
        Node *baru = new Node{nama, nim, gender, nilai, NULL, NULL};
        
        if (!head || nim < head->nim) {
            baru->next = head;
            if (head) head->prev = baru;
            else tail = baru;
            head = baru;
        } else {
            Node *curr = head;
            while (curr->next && curr->next->nim < nim)
                curr = curr->next;
            
            baru->next = curr->next;
            baru->prev = curr;
            if (curr->next) curr->next->prev = baru;
            else tail = baru;
            curr->next = baru;
        }
        cout << "\n>> Data berhasil ditambahkan!\n";
    }
    
    void hapus(string nim) {
        Node *curr = head;
        
        while (curr && curr->nim != nim)
            curr = curr->next;
        
        if (!curr) {
            cout << "\n>> NIM tidak ditemukan!\n";
            return;
        }
        
        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;
        
        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;
        
        delete curr;
        cout << "\n>> Data berhasil dihapus!\n";
    }
    
    void cetak() {
        if (!head) {
            cout << "\n>> Data masih kosong!\n";
            return;
        }
        
        cout << "\n";
        cout << "+==========+=====================+==========+========+\n";
        cout << "|   NIM    |        NAMA         |  GENDER  | NILAI  |\n";
        cout << "+==========+=====================+==========+========+\n";
        
        Node *curr = head;
        while (curr) {
            cout << "| " << left << setw(8) << curr->nim 
                 << " | " << setw(19) << curr->nama 
                 << " | " << setw(8) << curr->gender 
                 << " | " << setw(6) << fixed << setprecision(2) << curr->nilai << " |\n";
            curr = curr->next;
        }
        cout << "+==========+=====================+==========+========+\n";
    }
    
    ~DoublyLinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void tampilMenu() {
    cout << "\n";
    cout << "LIN. DOUBLY LINKED LIST\n";
    cout << "==========================\n";
    cout << "1. INSERT DATA\n";
    cout << "2. HAPUS DATA\n";
    cout << "3. CETAK DATA\n";
    cout << "4. EXIT\n";
    cout << "Pilihan (1 - 4) : ";
}

int main() {
    DoublyLinkedList list;
    int pilih;
    string nama, nim, gender;
    float nilai;
    
    do {
        tampilMenu();
        cin >> pilih;
        cin.ignore();
        
        switch(pilih) {
            case 1:
                cout << "\n=== INSERT DATA ===\n";
                cout << "NAMA   : "; getline(cin, nama);
                cout << "NIM    : "; getline(cin, nim);
                cout << "GENDER (L/P) : "; getline(cin, gender);
                cout << "NILAI  : "; cin >> nilai;
                list.insert(nama, nim, gender, nilai);
                break;
                
            case 2:
                cout << "\n=== HAPUS DATA ===\n";
                cout << "NIM yang akan dihapus : "; getline(cin, nim);
                list.hapus(nim);
                break;
                
            case 3:
                cout << "\n=== CETAK DATA ===";
                list.cetak();
                break;
                
            case 4:
                cout << "\n>> Terima kasih! Program selesai.\n\n";
                break;
                
            default:
                cout << "\n>> Pilihan tidak valid!\n";
        }
    } while(pilih != 4);
    
    return 0;
}
