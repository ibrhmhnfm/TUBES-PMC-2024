#ifndef LAPORAN_PENDAPATAN_H
#define LAPORAN_PENDAPATAN_H

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
int baca_csv_pasien(const char *nama_file, Pasien **head);

// Fungsi untuk membaca csv data riwayat pasien
int baca_csv_riwayat(const char *nama_file, RiwayatPasien **head);

// Fungsi untuk membaca csv data biaya tindakan
int baca_csv_biaya(const char *nama_file, BiayaTindakan **head);

// Fungsi untuk mengubah bulan dalam format teks ke nomor bulan
int bulan_ke_nomor(const char *bulan);

// Fungsi untuk membuat laporan pendapatan
void laporan_pendapatan(RiwayatPasien *head_riwayat);

#endif // LAPORAN_PENDAPATAN_H
