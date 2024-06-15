#ifndef fungsi6_h
#define fungsi6_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk riwayat pasien
typedef struct RiwayatPasien {
    int indeksriwayat;
    char id_pasien[50];
    char tanggal_kunjungan[15];
    char diagnosis[100];
    char tindakan[100];
    char kontrol[50];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

// Fungsi untuk menampilkan pasien yang perlu kontrol pada tanggal tertentu
void informasi_kontrol_pasien(RiwayatPasien *head_riwayat);

#endif // fungsi6_h
