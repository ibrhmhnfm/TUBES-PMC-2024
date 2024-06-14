#ifndef fungsi3_h
#define fungsi3_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char id_pasien[50];
    struct Pasien *next;
} Pasien;

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

// Fungsi untuk menampilkan informasi pasien berdasarkan ID pasien
void informasi_pasien(Pasien *head_pasien, const char *id_pasien);

// Fungsi untuk menampilkan riwayat medis seorang pasien berdasarkan ID pasien
void informasi_riwayat_pasien(RiwayatPasien *head_riwayat, const char *id_pasien);

#endif // fungsi3_h
