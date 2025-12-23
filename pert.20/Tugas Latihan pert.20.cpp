#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ==================== SOAL 1: BUBBLE SORT ====================
void soal1() {
    cout << "\n========== SOAL 1: BUBBLE SORT ==========" << endl;
    int data[10];
    
    srand(time(0));
    cout << "Data random sebelum sorting: ";
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100 + 1;
        cout << data[i] << " ";
    }
    cout << endl;
    
    // Bubble Sort
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    
    cout << "Data setelah Bubble Sort: ";
    for (int i = 0; i < 10; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// ==================== SOAL 2: CIRCULAR LINKED LIST ====================
struct Node {
    int data;
    Node* next;
};

Node* tail = NULL;

void insert(int value) {
    Node* baru = new Node();
    baru->data = value;
    
    if (tail == NULL) {
        baru->next = baru;
        tail = baru;
    } else {
        baru->next = tail->next;
        tail->next = baru;
        tail = baru;
    }
    cout << "Data " << value << " berhasil diinsert" << endl;
}

void hapus(int value) {
    if (tail == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    Node* current = tail->next;
    Node* prev = tail;
    
    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) {
                delete current;
                tail = NULL;
            } else {
                prev->next = current->next;
                if (current == tail) tail = prev;
                delete current;
            }
            cout << "Data " << value << " berhasil dihapus" << endl;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);
    
    cout << "Data tidak ditemukan" << endl;
}

void tampil() {
    if (tail == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    Node* current = tail->next;
    cout << "Isi Circular Linked List: ";
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != tail->next);
    cout << "(kembali ke awal)" << endl;
}

void soal2() {
    cout << "\n========== SOAL 2: CIRCULAR SINGLE LINKED LIST ==========" << endl;
    
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    tampil();
    
    hapus(20);
    tampil();
    
    insert(50);
    tampil();
}

// ==================== SOAL 3: BINARY SEARCH ====================
void soal3() {
    cout << "\n========== SOAL 3: BINARY SEARCH ==========" << endl;
    int data[15] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78, 84, 90, 95, 99};
    
    cout << "Data (sudah terurut): ";
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    int cari;
    cout << "Masukkan angka yang dicari: ";
    cin >> cari;
    
    int kiri = 0, kanan = 14, langkah = 0;
    bool ketemu = false;
    
    while (kiri <= kanan) {
        langkah++;
        int tengah = (kiri + kanan) / 2;
        
        if (data[tengah] == cari) {
            cout << "Data " << cari << " ditemukan pada indeks " << tengah << endl;
            ketemu = true;
            break;
        }
        
        if (data[tengah] < cari)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    
    if (!ketemu) {
        cout << "Data " << cari << " tidak ditemukan" << endl;
    }
    cout << "Jumlah langkah pencarian: " << langkah << endl;
}

// ==================== SOAL 4: BINARY TREE ====================
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void inorder(TreeNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(TreeNode* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(TreeNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void soal4() {
    cout << "\n========== SOAL 4: BINARY TREE TRAVERSAL ==========" << endl;
    
    TreeNode* root = new TreeNode();
    root->data = 50;
    
    root->left = new TreeNode();
    root->left->data = 30;
    
    root->right = new TreeNode();
    root->right->data = 70;
    
    root->left->left = new TreeNode();
    root->left->left->data = 20;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    
    root->left->right = new TreeNode();
    root->left->right->data = 40;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    
    root->right->left = new TreeNode();
    root->right->left->data = 60;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    
    root->right->right = new TreeNode();
    root->right->right->data = 80;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    cout << "Struktur Tree:\n";
    cout << "       50\n";
    cout << "      /  \\\n";
    cout << "    30    70\n";
    cout << "   / \\   / \\\n";
    cout << "  20 40 60 80\n\n";
    
    cout << "Inorder Traversal (Left-Root-Right): ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder Traversal (Root-Left-Right): ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder Traversal (Left-Right-Root): ";
    postorder(root);
    cout << endl;
}

// ==================== SOAL 5: QUEUE ====================
struct QueueNode {
    int data;
    QueueNode* next;
};

QueueNode* front = NULL;
QueueNode* rear = NULL;

void enqueue(int value) {
    QueueNode* baru = new QueueNode();
    baru->data = value;
    baru->next = NULL;
    
    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Pelanggan " << value << " masuk antrian" << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    
    QueueNode* temp = front;
    int value = front->data;
    front = front->next;
    
    if (front == NULL) rear = NULL;
    
    delete temp;
    cout << "Pelanggan " << value << " dilayani dan keluar dari antrian" << endl;
}

void tampilQueue() {
    if (front == NULL) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    
    cout << "Isi antrian (depan ke belakang): ";
    QueueNode* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void soal5() {
    cout << "\n========== SOAL 5: QUEUE SIMULASI ANTRIAN ==========" << endl;
    cout << "=== Simulasi Antrian Bank ===" << endl;
    
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);
    tampilQueue();
    
    cout << "\n--- Melayani pelanggan ---" << endl;
    dequeue();
    tampilQueue();
    
    cout << "\n--- Pelanggan baru datang ---" << endl;
    enqueue(105);
    tampilQueue();
    
    cout << "\n--- Melayani pelanggan ---" << endl;
    dequeue();
    dequeue();
    tampilQueue();
}

// ==================== MAIN ====================
int main() {
    int pilihan;
    
    do {
        cout << "\n============================================" << endl;
        cout << "   PROGRAM LATIHAN DATA STRUKTUR C++" << endl;
        cout << "============================================" << endl;
        cout << "1. Bubble Sort (10 data random)" << endl;
        cout << "2. Circular Single Linked List" << endl;
        cout << "3. Binary Search" << endl;
        cout << "4. Binary Tree Traversal" << endl;
        cout << "5. Queue Berbasis Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilih menu (0-5): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: soal1(); break;
            case 2: soal2(); break;
            case 3: soal3(); break;
            case 4: soal4(); break;
            case 5: soal5(); break;
            case 0: cout << "\nTerima kasih! Program selesai." << endl; break;
            default: cout << "\nPilihan tidak valid!" << endl;
        }
        
        if (pilihan != 0) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }
        
    } while(pilihan != 0);
    
    return 0;
}
