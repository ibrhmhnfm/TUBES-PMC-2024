#ifndef FUNGSI2_H
#define FUNGSI2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#define SHORT 20
#define MAX 100

// Function prototypes
void simpan_csv_riwayat(const char *nama_file, RiwayatPasien *head);
void cari_riwayat(RiwayatPasien *head);
int last_index_riwayat(RiwayatPasien *head);
int cek_id(char *tes, Pasien *head);
int cek_tindakan(char *tes, BiayaTindakan *head);
double hitung_tindakan(char *tes, BiayaTindakan *head);
void clear_input_buffer();
void tambah_riwayat(RiwayatPasien **head, Pasien *head3, BiayaTindakan *head2);
void edit_riwayat(RiwayatPasien *head, Pasien *pasien, BiayaTindakan *harga);
void hapus_riwayat(RiwayatPasien *head, Pasien *pasien);

#endif /* FUNGSI2_H */
