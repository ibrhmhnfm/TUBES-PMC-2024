#ifndef fungsi3_h
#define fungsi3_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur data untuk pasien
typedef struct Pasien {
    int indekspasien;
    char id_pasien[50];
    char nama_pasien[100];
    char alamat[100];
    char kota[50];
    char nomor_bpjs[20];
    struct Pasien *next;
} Pasien;

// Struktur data untuk riwayat pasien
typedef struct RiwayatPasien {
    int indeksriwayat;
    char id_pasien[50];
    char tanggal_kunjungan[15];
    char diagnosis[100];
    char tindakan[100];
    char kontrol[10];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

// Fungsi untuk menampilkan informasi pasien berdasarkan ID pasien
void informasi_riwayat_pasien(Pasien *head_pasien, RiwayatPasien *head_riwayat);

#endif // fungsi3_h
