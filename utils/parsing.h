#ifndef PARSING
#define PARSING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\algoritma\const.h"

// Fungsi untuk membaca csv data pasien
int baca_csv_pasien(const char *nama_file, Pasien **head);

// Fungsi untuk membaca csv data riwayat pasien
int baca_csv_riwayat(const char *nama_file, RiwayatPasien **head);

// Fungsi untuk membaca csv data biaya tindakan
int baca_csv_biaya(const char *nama_file, BiayaTindakan **head);

void trim_trailing_whitespace(char *str);

// Fungsi untuk mencetak data pasien
void cetak_pasien(Pasien *head);

// Fungsi untuk mencetak riwayat pasien
void cetak_riwayat(RiwayatPasien *head);

// Fungsi untuk mencetak biaya tindakan
void cetak_biaya(BiayaTindakan *head);

#endif // PARSING_H