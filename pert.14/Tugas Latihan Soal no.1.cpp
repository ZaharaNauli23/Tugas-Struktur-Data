#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    string nama, nim, gender;
    float nilai;
    Node *next;
};

class CircularLinkedList {
private:
    Node *head;
    
public:
    CircularLinkedList() { head = NULL; }
    
    void insert(string nama, string nim, string gender, float nilai) {
        Node *baru = new Node{nama, nim, gender, nilai, NULL};
        
        if (!head) {
            head = baru;
            baru->next = baru; // Point ke diri sendiri
        } else if (nim < head->nim) {
            // Insert di awal, cari tail dulu
            Node *tail = head;
            while (tail->next != head)
                tail = tail->next;
            
            baru->next = head;
            tail->next = baru;
            head = baru;
        } else {
            // Cari posisi yang tepat
            Node *curr = head;
            while (curr->next != head && curr->next->nim < nim)
                curr = curr->next;
            
            baru->next = curr->next;
            curr->next = baru;
        }
        cout << "\n>> Data berhasil ditambahkan!\n";
    }
    
    void hapus(string nim) {
        if (!head) {
            cout << "\n>> Data masih kosong!\n";
            return;
        }
        
        // Jika hanya ada satu node
        if (head->next == head) {
            if (head->nim == nim) {
                delete head;
                head = NULL;
                cout << "\n>> Data berhasil dihapus!\n";
            } else {
                cout << "\n>> NIM tidak ditemukan!\n";
            }
            return;
        }
        
        // Jika yang dihapus adalah head
        if (head->nim == nim) {
            Node *tail = head;
            while (tail->next != head)
                tail = tail->next;
            
            Node *temp = head;
            tail->next = head->next;
            head = head->next;
            delete temp;
            cout << "\n>> Data berhasil dihapus!\n";
            return;
        }
        
        // Cari node yang akan dihapus
        Node *curr = head;
        do {
            if (curr->next->nim == nim) {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                cout << "\n>> Data berhasil dihapus!\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);
        
        cout << "\n>> NIM tidak ditemukan!\n";
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
        do {
            cout << "| " << left << setw(8) << curr->nim 
                 << " | " << setw(19) << curr->nama 
                 << " | " << setw(8) << curr->gender 
                 << " | " << setw(6) << fixed << setprecision(2) << curr->nilai << " |\n";
            curr = curr->next;
        } while (curr != head);
        cout << "+==========+=====================+==========+========+\n";
        cout << ">> HEAD menunjuk ke NIM: " << head->nim << " (Circular)\n";
    }
    
    ~CircularLinkedList() {
        if (!head) return;
        
        Node *curr = head;
        Node *temp;
        do {
            temp = curr;
            curr = curr->next;
            delete temp;
        } while (curr != head);
    }
};

void tampilMenu() {
    cout << "\n";
    cout << "CIRCULAR LINKED LIST\n";
    cout << "==========================\n";
    cout << "1. INSERT DATA\n";
    cout << "2. HAPUS DATA\n";
    cout << "3. CETAK DATA\n";
    cout << "4. EXIT\n";
    cout << "Pilihan (1 - 4) : ";
}

int main() {
    CircularLinkedList list;
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
