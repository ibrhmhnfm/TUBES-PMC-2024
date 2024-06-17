#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi1.h"
#include "const.h"

// Fungsi untuk menyimpan CSV pasien
void simpan_csv_pasien(const char *nama_file, Pasien *head) {
    FILE *file = fopen(nama_file, "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }

    fprintf(file, "Indeks Pasien,Nama Pasien,Alamat,Kota,Tempat Lahir,Tanggal Lahir,Umur,Nomor BPJS,ID Pasien\n");

    Pasien *temp = head;
    while (temp != NULL) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d,%s,%s\n",
                temp->indekspasien, temp->nama_pasien, temp->alamat,
                temp->kota, temp->tempat_lahir, temp->tanggal_lahir,
                temp->umur, temp->nomor_bpjs, temp->id_pasien);
        temp = temp->next;
    }

    fclose(file);
    printf("Data pasien berhasil disimpan ke dalam file %s.\n", nama_file);
}

// Fungsi untuk mencari pasien berdasarkan nama
void cari_pasien(Pasien *head) {
    char nama[100];
    printf("Masukkan nama pasien yang dicari: ");
    scanf(" %[^\n]", nama);

    Pasien *temp = head;
    int ditemukan = 0;
    int rusa = 0;

    while (temp != NULL) {
        if (strstr(temp->nama_pasien, nama) != NULL) {
            rusa++;
            if (rusa == 1) printf("\nData Pasien Ditemukan: \n");
            printf("\n");
            printf("Indeks Pasien: %d\n", temp->indekspasien);
            printf("Nama Pasien: %s\n", temp->nama_pasien);
            printf("Alamat: %s\n", temp->alamat);
            printf("Kota: %s\n", temp->kota);
            printf("Tempat Lahir: %s\n", temp->tempat_lahir);
            printf("Tanggal Lahir: %s\n", temp->tanggal_lahir);
            printf("Umur: %d\n", temp->umur);
            printf("Nomor BPJS: %s\n", temp->nomor_bpjs);
            printf("ID Pasien: %s\n", temp->id_pasien);
            ditemukan = 1;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        printf("Pasien dengan nama \"%s\" tidak ditemukan.\n", nama);
    }
}

// Fungsi untuk mendapatkan indeks terakhir dari linked list
int get_last_index(Pasien *head) {
    int last_index = 0;
    Pasien *temp = head;
    while (temp != NULL) {
        if (temp->indekspasien > last_index) {
            last_index = temp->indekspasien;
        }
        temp = temp->next;
    }
    return last_index;
}

// Fungsi untuk memeriksa apakah nomor BPJS atau ID Pasien sudah ada
int cek_duplikasi(Pasien *head, char *xyz, Pasien *ignore) {
    Pasien *temp = head;
    while (temp != NULL) {
        if (temp != ignore && (strcmp(temp->nomor_bpjs, xyz) == 0 || strcmp(temp->id_pasien, xyz) == 0)) {
            return 1;
        }
        temp = temp->next;
    }
    return 0; 
}

// Fungsi untuk menambah pasien baru
void tambah_pasien(Pasien **head) {
    Pasien *new_pasien = (Pasien*)malloc(sizeof(Pasien));
    new_pasien->indekspasien = get_last_index(*head) + 1;

    printf("Masukkan Nama Pasien: ");
    scanf(" %[^\n]", new_pasien->nama_pasien);
    printf("Masukkan Alamat: ");
    scanf(" %[^\n]", new_pasien->alamat);
    printf("Masukkan Kota: ");
    scanf(" %[^\n]", new_pasien->kota);
    printf("Masukkan Tempat Lahir: ");
    scanf(" %[^\n]", new_pasien->tempat_lahir);
    printf("Masukkan Tanggal Lahir: ");
    scanf(" %[^\n]", new_pasien->tanggal_lahir);
    printf("Masukkan Umur: ");
    scanf("%d", &new_pasien->umur);
    
    do {
        printf("Masukkan Nomor BPJS: ");
        scanf(" %[^\n]", new_pasien->nomor_bpjs);

        if (cek_duplikasi(*head, new_pasien->nomor_bpjs, NULL)) {
            printf("Nomor BPJS sudah ada, silahkan masukkan lagi.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Masukkan ID Pasien: ");
        scanf(" %[^\n]", new_pasien->id_pasien);

        if (cek_duplikasi(*head,  new_pasien->id_pasien, NULL)) {
            printf("ID Pasien sudah ada, silahkan masukkan lagi.\n");
        } else {
            break;
        }
    } while (1);

    new_pasien->next = NULL;

    if (*head == NULL) {
        *head = new_pasien;
    } else {
        Pasien *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_pasien;
    }

    printf("Data pasien berhasil ditambahkan.\n");
}

// Fungsi untuk mengubah data pasien
void ubah_pasien(Pasien *head) {
    char id[20];
    printf("Masukkan ID Pasien yang ingin diubah: ");
    scanf(" %[^\n]", id);

    Pasien *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->id_pasien, id) == 0) {
            printf("Masukkan Nama Pasien baru (sebelumnya: %s): ", temp->nama_pasien);
            scanf(" %[^\n]", temp->nama_pasien);
            printf("Masukkan Alamat baru (sebelumnya: %s): ", temp->alamat);
            scanf(" %[^\n]", temp->alamat);
            printf("Masukkan Kota baru (sebelumnya: %s): ", temp->kota);
            scanf(" %[^\n]", temp->kota);
            printf("Masukkan Tempat Lahir baru (sebelumnya: %s): ", temp->tempat_lahir);
            scanf(" %[^\n]", temp->tempat_lahir);
            printf("Masukkan Tanggal Lahir baru (sebelumnya: %s): ", temp->tanggal_lahir);
            scanf(" %[^\n]", temp->tanggal_lahir);
            printf("Masukkan Umur baru (sebelumnya: %d): ", temp->umur);
            scanf("%d", &temp->umur);

            do {
                printf("Masukkan Nomor BPJS baru (sebelumnya: %s): ", temp->nomor_bpjs);
                scanf(" %[^\n]", temp->nomor_bpjs);

                if (cek_duplikasi(head, temp->nomor_bpjs, temp)) {
                    printf("Nomor BPJS sudah ada, silahkan masukkan lagi.\n");
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Masukkan ID Pasien baru (sebelumnya: %s): ", temp->id_pasien);
                scanf(" %[^\n]", temp->id_pasien);

                if (cek_duplikasi(head, temp->id_pasien, temp)) {
                    printf("ID Pasien sudah ada, silahkan masukkan lagi.\n");
                } else {
                    break;
                }
            } while (1);

            printf("Data pasien berhasil diubah.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Pasien dengan ID \"%s\" tidak ditemukan.\n");
}

// Fungsi untuk menghapus pasien
void hapus_pasien(Pasien **head) {
    int indeks;
    printf("Masukkan indeks pasien yang ingin dihapus: ");
    scanf("%d", &indeks);

    Pasien *temp = *head, *prev = NULL;

    // Mencari pasien yang ingin dihapus
    while (temp != NULL && temp->indekspasien != indeks) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Pasien dengan indeks \"%d\" tidak ditemukan.\n", indeks);
        return;
    }

    // Menghapus pasien
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);

    // Mengupdate indeks pasien setelah pasien yang dihapus
    temp = (prev == NULL) ? *head : prev->next;
    while (temp != NULL) {
        temp->indekspasien--;
        temp = temp->next;
    }

    printf("Data pasien berhasil dihapus.\n");
}

