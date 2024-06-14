#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi struct sebagai linked list penyimpanan data pasien
typedef struct Pasien {
    int indekspasien;
    char nama_pasien[100];
    char alamat[150];
    char kota[50];
    char tempat_lahir[50];
    char tanggal_lahir[30];
    int umur;
    char nomor_bpjs[20];
    char id_pasien[20];
    struct Pasien *next;
} Pasien;

// Deklarasi struct sebagai linked list penyimpanan data riwayat pasien
typedef struct RiwayatPasien {
    int indeksriwayat;
    char tanggal_kunjungan[20];
    char id_pasien[20];
    char diagnosis[100];
    char tindakan[100];
    char kontrol[20];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

// Deklarasi struct sebagai linked list penyimpanan data biaya tindakan
typedef struct BiayaTindakan {
    int indekstindakan;
    char aktivitas[20];
    double biayatindakan;
    struct BiayaTindakan *next;
} BiayaTindakan;

// Fungsi untuk membaca csv data pasien
int baca_csv_pasien(const char *nama_file, Pasien **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[500];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        Pasien *listpasien = (Pasien*)malloc(sizeof(Pasien));
        sscanf(baris, "%d,%99[^,],%149[^,],%49[^,],%49[^,],%29[^,],%d,%19[^,],%19[^\n]",
               &listpasien->indekspasien, listpasien->nama_pasien, listpasien->alamat,
               listpasien->kota, listpasien->tempat_lahir, listpasien->tanggal_lahir,
               &listpasien->umur, listpasien->nomor_bpjs, listpasien->id_pasien);
        listpasien->next = NULL;

        if (*head == NULL) {
            *head = listpasien;
        } else {
            Pasien *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = listpasien;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk membaca csv data riwayat pasien
int baca_csv_riwayat(const char *nama_file, RiwayatPasien **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[500];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        RiwayatPasien *riwayat = (RiwayatPasien*)malloc(sizeof(RiwayatPasien));
        sscanf(baris, "%d,%19[^,],%19[^,],%99[^,],%99[^,],%19[^,],%lf",
               &riwayat->indeksriwayat, riwayat->tanggal_kunjungan, riwayat->id_pasien,
               riwayat->diagnosis, riwayat->tindakan, riwayat->kontrol, &riwayat->biaya);
        riwayat->next = NULL;

        if (*head == NULL) {
            *head = riwayat;
        } else {
            RiwayatPasien *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = riwayat;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk membaca csv data biaya tindakan
int baca_csv_biaya(const char *nama_file, BiayaTindakan **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[200];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        BiayaTindakan *biaya = (BiayaTindakan*)malloc(sizeof(BiayaTindakan));
        sscanf(baris, "%d,%19[^,],%lf", &biaya->indekstindakan, biaya->aktivitas, &biaya->biayatindakan);
        biaya->next = NULL;

        if (*head == NULL) {
            *head = biaya;
        } else {
            BiayaTindakan *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = biaya;
        }
    }
    fclose(file);
    return 1;
}

// Fungsi untuk mencetak data pasien
void cetak_pasien(Pasien *head) {
    Pasien *temp = head;
    while (temp != NULL) {
        printf("Indeks Pasien: %d, Nama: %s, Alamat: %s, Kota: %s, Tempat Lahir: %s, Tanggal Lahir: %s, Umur: %d, No BPJS: %s, ID Pasien: %s\n",
               temp->indekspasien, temp->nama_pasien, temp->alamat, temp->kota, temp->tempat_lahir,
               temp->tanggal_lahir, temp->umur, temp->nomor_bpjs, temp->id_pasien);
        temp = temp->next;
    }
}

// Fungsi untuk mencetak riwayat pasien
void cetak_riwayat(RiwayatPasien *head) {
    RiwayatPasien *temp = head;
    while (temp != NULL) {
        printf("Indeks Riwayat: %d, Tanggal Kunjungan: %s, ID Pasien: %s, Diagnosis: %s, Tindakan: %s, Follow Up Date: %s, Biaya: %.2f\n",
               temp->indeksriwayat, temp->tanggal_kunjungan, temp->id_pasien, temp->diagnosis,
               temp->tindakan, temp->kontrol, temp->biaya);
        temp = temp->next;
    }
}

// Fungsi untuk mencetak biaya tindakan
void cetak_biaya(BiayaTindakan *head) {
    BiayaTindakan *temp = head;
    while (temp != NULL) {
        printf("Indeks Tindakan: %d, Aktivitas: %s, Biaya: %.2f\n",
               temp->indekstindakan, temp->aktivitas, temp->biayatindakan);
        temp = temp->next;
    }
}