#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"
#include "..\algoritma\const.h"

// Fungsi untuk membaca CSV riwayat
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
        sscanf(baris, "%d,%19[^,],%49[^,],%99[^,],%99[^,],%19[^,],%lf",
               &riwayat->indeksriwayat, riwayat->tanggal_kunjungan, riwayat->id_pasien,
               riwayat->diagnosis, riwayat->tindakan, riwayat->kontrol, &riwayat->biaya);
        riwayat->next = NULL;
        
        // Trim trailing whitespace
        trim_trailing_whitespace(riwayat->id_pasien);

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

// Fungsi untuk membaca CSV data pasien 
int baca_csv_pasien(const char *nama_file, Pasien **head) {
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    char baris[500];
    fgets(baris, sizeof(baris), file);  // Membaca header
    while (fgets(baris, sizeof(baris), file)) {
        Pasien *pasien = (Pasien*)malloc(sizeof(Pasien));
        sscanf(baris, "%d,%99[^,],%149[^,],%49[^,],%49[^,],%29[^,],%d,%19[^,],%49[^,]",
               &pasien->indekspasien, pasien->nama_pasien, pasien->alamat, pasien->kota,
               pasien->tempat_lahir, pasien->tanggal_lahir, &pasien->umur, pasien->nomor_bpjs, pasien->id_pasien);
        pasien->next = NULL;

        // Trim trailing whitespace
        trim_trailing_whitespace(pasien->id_pasien);

        if (*head == NULL) {
            *head = pasien;
        } else {
            Pasien *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = pasien;
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

// Function to trim trailing whitespace
void trim_trailing_whitespace(char *str) {
    char *end;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    end[1] = '\0';
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