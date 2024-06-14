#ifndef FUNGSI5_H
#define FUNGSI5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data yang digunakan
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

typedef struct BiayaTindakan {
    int indekstindakan;
    char aktivitas[20];
    double biayatindakan;
    struct BiayaTindakan *next;
} BiayaTindakan;

typedef struct DiseaseCount {
    char disease[100];
    int count;
    struct DiseaseCount *next;
} DiseaseCount;

typedef struct MonthYearCount {
    char month_year[20];
    int patient_count;
    DiseaseCount *disease_head;
    struct MonthYearCount *next;
} MonthYearCount;

typedef struct YearCount {
    char year[5];
    MonthYearCount *month_head;
    struct YearCount *next;
} YearCount;

// Fungsi untuk mendapatkan nomor bulan
const char *get_month_number(const char *month_name);

// Fungsi untuk mendapatkan nama bulan dari nomor bulan
const char *get_month_name(const char *month_number);

// Fungsi untuk menambahkan pasien berdasarkan bulan dan tahun
void tambah_pasien_bulan_tahun(YearCount **head, const char *year, const char *month_year, const char *diagnosis);

// Fungsi untuk mengurutkan penyakit berdasarkan jumlah dalam urutan menurun
DiseaseCount *sort_disease_count(DiseaseCount *head);

// Fungsi untuk mengurutkan bulan berdasarkan tahun dalam urutan naik
MonthYearCount *sort_month_year_count(MonthYearCount *head);

// Fungsi untuk menampilkan jumlah pasien dan penyakit per tahun
void jumlah_pasien_dan_penyakit_per_tahun(RiwayatPasien *head);

#endif // FUNGSI5_H
