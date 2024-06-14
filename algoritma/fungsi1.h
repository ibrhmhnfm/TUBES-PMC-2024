#ifndef PASIEN_H
#define PASIEN_H

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

// Deklarasi fungsi-fungsi
int baca_csv_pasien(const char *nama_file, Pasien **head);
void simpan_csv_pasien(const char *nama_file, Pasien *head);
void cari_pasien(Pasien *head);
int get_last_index(Pasien *head);
int cek_duplikasi(Pasien *head, char *xyz, Pasien *ignore);
void tambah_pasien(Pasien **head);
void ubah_pasien(Pasien *head);
void hapus_pasien(Pasien **head);

#endif // PASIEN_H
