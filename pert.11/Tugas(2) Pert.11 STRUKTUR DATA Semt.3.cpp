#include <iostream>
#include <string>

using namespace std;

// Struktur Mahasiswa
struct Mahasiswa 
{
    string nama;
    string nim;
    string gender;
    float nilai;
};

// Node untuk Linked List
struct Node 
{
    Mahasiswa data;
    Node* next;
};

// Kelas Stack (tanpa dummy head; top langsung ke node pertama)
class Stack 
{
private:
    Node* top;  // Pointer ke top (tidak ada head dummy)
public:
    Stack() { top = nullptr; }
    
    // Push (Insert Data) - Sama seperti standar, tapi tanpa head dummy
    void push(Mahasiswa mhs) 
	{
        Node* newNode = new Node();
        newNode->data = mhs;
        newNode->next = top;
        top = newNode;
        cout << "Data berhasil ditambahkan ke Stack!" << endl;
    }
    
    // Pop (Hapus Data) - Sama seperti standar
    void pop() 
	{
        if (top == nullptr) 
		{
            cout << "Stack kosong, tidak ada data untuk dihapus!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Data yang dihapus: " << temp->data.nama << " (" << temp->data.nim << ")" << endl;
        delete temp;
    }
    
    // Display (Cetak Data) - Sama seperti standar
    void display() 
	{
        if (top == nullptr) 
		{
            cout << "Stack kosong!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Isi Stack (dari top ke bottom):" << endl;
        while (temp != nullptr) 
		{
            cout << "Nama: " << temp->data.nama 
                 << ", NIM: " << temp->data.nim 
                 << ", Gender: " << temp->data.gender 
                 << ", Nilai: " << temp->data.nilai << endl;
            temp = temp->next;
        }
    }
    
    // Destructor untuk membersihkan memori
    ~Stack() 
	{
        while (top != nullptr) 
		{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() 
{
    Stack s;
    int choice;
    Mahasiswa mhs;
    
    do 
	{
        cout << "\nMenu Stack Mahasiswa (Tanpa Head):" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilih: ";
        cin >> choice;
        
        switch (choice) 
		{
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore(); // Untuk handle newline
                getline(cin, mhs.nama);
                cout << "Masukkan NIM: ";
                getline(cin, mhs.nim);
                cout << "Masukkan Gender: ";
                getline(cin, mhs.gender);
                cout << "Masukkan Nilai Struktur Data: ";
                cin >> mhs.nilai;
                s.push(mhs);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 4);
    
    return 0;
}
