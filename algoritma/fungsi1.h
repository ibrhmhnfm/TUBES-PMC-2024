#ifndef PASIEN_H
#define PASIEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// Deklarasi fungsi-fungsi
void simpan_csv_pasien(const char *nama_file, Pasien *head);
void cari_pasien(Pasien *head);
int get_last_index(Pasien *head);
int cek_duplikasi(Pasien *head, char *xyz, Pasien *ignore);
void tambah_pasien(Pasien **head);
void ubah_pasien(Pasien *head);
void hapus_pasien(Pasien **head);

#endif // PASIEN_H