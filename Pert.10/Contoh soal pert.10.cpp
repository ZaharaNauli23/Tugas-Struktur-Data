// Program C++ untuk mengimplementasikan tumpukan
// Menggunakan singly linked list

#include <bits/stdc++.h>
using namespace std;

// Deklarasikan node linked list
struct Node {
    int data;
    struct Node* link;
};

struct Node* top;

// Fungsi utilitas untuk menambahkan elemen (push)
// Data dimasukkan di awal (top)
void push(int data) {
    // Buat node baru dan alokasikan memori
    struct Node* temp;
    temp = new Node();

    // Periksa apakah tumpukan (heap) sudah penuh
    // Memasukkan elemen yang akan menyebabkan stack overflow
    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Inisialisasi data ke field data
    temp->data = data;

    // Letakkan top pointer referensi ke dalam temp link
    temp->link = top;

    // Jadikan temp sebagai top stack
    top = temp;
}

// Fungsi utilitas untuk memeriksa apakah tumpukan kosong atau tidak
int isEmpty() {
    return top == NULL;
}

// Fungsi utilitas untuk mengembalikan elemen teratas dalam stack
int peek() {
    // Periksa tumpukan kosong
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Fungsi utilitas untuk pop (hapus) elemen teratas dari tumpukan
void pop() {
    struct Node* temp;

    // Cek untuk stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {
        // Simpan top ke temp
        temp = top;

        // Top menunjuk ke node berikutnya
        top = top->link;

        // Putuskan link node yang lama
        temp->link = NULL;

        // Hapus memori node teratas
        free(temp);
    }
}

// Fungsi untuk mencetak semua elemen stack
void display() {
    struct Node* temp;

    // Cek untuk stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    } else {
        temp = top;
        while (temp != NULL) {
            // Cetak data node
            cout << temp->data << " -> ";

            // Pindah ke node berikutnya
            temp = temp->link;
        }
    }
}

// Driver Code
int main() {
    // Push elemen ke dalam stack
    push(11);
    push(22);
    push(33);
    push(44);

    // Menampilkan elemen stack
    display();

    // Mencetak elemen stack paling atas
    cout << "\nElemen Top adalah " << peek() << endl;

    // Hapus elemen teratas stack
    pop();
    pop();

    // Menampilkan elemen stack
    display();

    // Cetak elemen stack paling atas
    cout << "\nElemen Top adalah " << peek() << endl;

    return 0;
}


