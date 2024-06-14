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

// Fungsi untuk mengubah bulan dalam format teks ke nomor bulan
int bulan_ke_nomor(const char *bulan) {
    if (strcmp(bulan, "Januari") == 0) return 1;
    if (strcmp(bulan, "Februari") == 0) return 2;
    if (strcmp(bulan, "Maret") == 0) return 3;
    if (strcmp(bulan, "April") == 0) return 4;
    if (strcmp(bulan, "Mei") == 0) return 5;
    if (strcmp(bulan, "Juni") == 0) return 6;
    if (strcmp(bulan, "Juli") == 0) return 7;
    if (strcmp(bulan, "Agustus") == 0) return 8;
    if (strcmp(bulan, "September") == 0) return 9;
    if (strcmp(bulan, "Oktober") == 0) return 10;
    if (strcmp(bulan, "November") == 0) return 11;
    if (strcmp(bulan, "Desember") == 0) return 12;
    return -1; // Jika tidak ada yang cocok
}

void laporan_pendapatan(RiwayatPasien *head_riwayat) {
    double pendapatan_perbulan[12] = {0};
    double pendapatan_pertahun[6] = {0};  // Menggunakan array untuk 2018-2023
    int jumlahBulan[12] = {0};
    int jumlahTahun[6] = {0};  // Menghitung jumlah entri per tahun

    RiwayatPasien* temp = head_riwayat;
    while (temp != NULL) {
        int hari, tahun;
        char bulan[20];
        sscanf(temp->tanggal_kunjungan, "%d %s %d", &hari, bulan, &tahun);
        int bulan_num = bulan_ke_nomor(bulan);

        if (bulan_num < 1 || bulan_num > 12 || tahun < 2018 || tahun > 2023) {
            temp = temp->next;
            continue;  // Lewati entri di luar rentang tahun 2018-2023
        }
        pendapatan_perbulan[bulan_num - 1] += temp->biaya;
        pendapatan_pertahun[tahun - 2018] += temp->biaya;
        
        jumlahBulan[bulan_num - 1]++;
        jumlahTahun[tahun - 2018]++;

        temp = temp->next;
    }

    printf("Laporan Pendapatan Bulanan:\n");
    for (int i = 0; i < 12; i++) {
        if (jumlahBulan[i] > 0) {
            printf("Bulan %d: Total Pendapatan = %.2f, Rata-rata Pendapatan = %.2f\n", i + 1, pendapatan_perbulan[i], pendapatan_perbulan[i] / jumlahBulan[i]);
        } else {
            printf("Bulan %d: Tidak ada pendapatan\n", i + 1);
        }
    }

    printf("\nLaporan Pendapatan Tahunan (2018-2023):\n");
    for (int i = 0; i < 6; i++) {
        int currentYear = 2018 + i;
        if (jumlahTahun[i] > 0) {
            printf("Tahun %d: Total Pendapatan = %.2f, Rata-rata Pendapatan = %.2f\n", currentYear, pendapatan_pertahun[i], pendapatan_pertahun[i] / jumlahTahun[i]);
        } else {
            printf("Tahun %d: Tidak ada pendapatan\n", currentYear);
        }
    }
}


int main() {
    RiwayatPasien *head_riwayat = NULL;

    if (baca_csv_riwayat("RiwayatPasien.csv", &head_riwayat)) {
        laporan_pendapatan(head_riwayat);
    } else {
        printf("Gagal membaca file CSV.\n");
    }
}