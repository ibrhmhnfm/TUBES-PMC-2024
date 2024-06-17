#ifndef FUNGSI5_H
#define FUNGSI5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

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
