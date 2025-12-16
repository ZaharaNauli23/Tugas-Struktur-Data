#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data node mahasiswa
typedef struct Mahasiswa {
    char NIM[20];
    char NAMA[50];
    int NILAI;
    struct Mahasiswa *next;
} Mahasiswa;

// Fungsi untuk membuat node baru
Mahasiswa* buatNode(char NIM[], char NAMA[], int NILAI) {
    Mahasiswa *baru = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    strcpy(baru->NIM, NIM);
    strcpy(baru->NAMA, NAMA);
    baru->NILAI = NILAI;
    baru->next = NULL;
    return baru;
}

// a. Fungsi untuk menambahkan data baru (urut naik berdasarkan NILAI)
void tambahData(Mahasiswa **head, char NIM[], char NAMA[], int NILAI) {
    Mahasiswa *baru = buatNode(NIM, NAMA, NILAI);
    if (*head == NULL || NILAI < (*head)->NILAI) {
        baru->next = *head;
        *head = baru;
        return;
    }
    Mahasiswa *bantu = *head;
    while (bantu->next != NULL && bantu->next->NILAI <= NILAI) {
        bantu = bantu->next;
    }
    baru->next = bantu->next;
    bantu->next = baru;
}

// b. Fungsi untuk menampilkan data dengan NILAI = 90
void tampilkanNilai90(Mahasiswa *head) {
    int ketemu = 0;
    Mahasiswa *bantu = head;
    printf("\nData mahasiswa dengan NILAI = 90:\n");
    printf("-------------------------------------------\n");
    while (bantu != NULL) {
        if (bantu->NILAI == 90) {
            printf("NIM   : %s\n", bantu->NIM);
            printf("NAMA  : %s\n", bantu->NAMA);
            printf("NILAI : %d\n", bantu->NILAI);
            printf("-------------------------------------------\n");
            ketemu = 1;
        }
        bantu = bantu->next;
    }
    if (!ketemu) {
        printf("Tidak ada data dengan nilai 90.\n");
    }
}

// c. Fungsi untuk menampilkan seluruh data
void tampilkanSemua(Mahasiswa *head) {
    if (head == NULL) {
        printf("\nData masih kosong.\n");
        return;
    }
    Mahasiswa *bantu = head;
    printf("\nSeluruh Data Mahasiswa:\n");
    printf("-------------------------------------------\n");
    while (bantu != NULL) {
        printf("NIM   : %s\n", bantu->NIM);
        printf("NAMA  : %s\n", bantu->NAMA);
        printf("NILAI : %d\n", bantu->NILAI);
        printf("-------------------------------------------\n");
        bantu = bantu->next;
    }
}

// d. Fungsi untuk menghapus data dengan NIM tertentu
void hapusData(Mahasiswa **head, const char NIM[]) {
    if (*head == NULL) {
        printf("\nList kosong!\n");
        return;
    }

    Mahasiswa *hapus, *bantu = *head;

    // Jika data pertama yang dihapus
    if (strcmp(bantu->NIM, NIM) == 0) {
        hapus = bantu;
        *head = bantu->next;
        free(hapus);
        printf("\nData dengan NIM %s berhasil dihapus.\n", NIM);
        return;
    }

    // Cari data yang cocok
    while (bantu->next != NULL && strcmp(bantu->next->NIM, NIM) != 0) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        printf("\nData dengan NIM %s tidak ditemukan.\n", NIM);
        return;
    }

    hapus = bantu->next;
    bantu->next = hapus->next;
    free(hapus);
    printf("\nData dengan NIM %s berhasil dihapus.\n", NIM);
}

// e. Fungsi untuk menghitung nilai rata-rata kelas
void hitungRata(Mahasiswa *head) {
    if (head == NULL) {
        printf("\nList kosong, tidak bisa menghitung rata-rata.\n");
        return;
    }

    int total = 0, jumlah = 0;
    Mahasiswa *bantu = head;

    while (bantu != NULL) {
        total += bantu->NILAI;
        jumlah++;
        bantu = bantu->next;
    }

    float rata = (float)total / jumlah;
    printf("\nNilai rata-rata kelas = %.2f\n", rata);
}

// Program utama
int main() {
    Mahasiswa *head = NULL;
    int pilihan, nilai;
    char NIM[20], NAMA[50];

    do {
        printf("\n=== PROGRAM LINKED LIST MAHASISWA ===\n");
        printf("1. Tambah data baru\n");
        printf("2. Tampilkan data dengan NILAI = 90\n");
        printf("3. Tampilkan seluruh data\n");
        printf("4. Hapus data dengan NIM 2007140022\n");
        printf("5. Hitung nilai rata-rata kelas\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // membersihkan buffer enter

        switch (pilihan) {
            case 1:
                printf("Masukkan NIM   : ");
                gets(NIM);
                printf("Masukkan NAMA  : ");
                gets(NAMA);
                printf("Masukkan NILAI : ");
                scanf("%d", &nilai);
                tambahData(&head, NIM, NAMA, nilai);
                printf("\nData berhasil ditambahkan!\n");
                break;

            case 2:
                tampilkanNilai90(head);
                break;

            case 3:
                tampilkanSemua(head);
                break;

            case 4:
                hapusData(&head, "2007140022");
                break;

            case 5:
                hitungRata(head);
                break;

            case 0:
                printf("\nTerima kasih, program selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}
