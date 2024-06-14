#ifndef fungsi6_h
#define fungsi6_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data yang digunakan
typedef struct RiwayatPasien {
    int indeksriwayat;
    char tanggal_kunjungan[20];
    char id_pasien[50];
    char diagnosis[100];
    char tindakan[100];
    char kontrol[20];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

// Fungsi untuk menampilkan pasien yang perlu kontrol pada tanggal tertentu
void informasi_kontrol_pasien(RiwayatPasien *head_riwayat, const char *tanggal_kontrol);

#endif // fungsi6_h
