#ifndef FUNGSI2_H
#define FUNGSI2_H

#define MAX 100
#define SHORT 20

#include "const.h"

// Function prototypes
void tambah_riwayat(RiwayatPasien *head, BiayaTindakan *head2, Pasien *head3, int total);
void edit_riwayat(RiwayatPasien *head);
void hapus_riwayat(RiwayatPasien *head);
void cari_riwayat(RiwayatPasien *head);

int count_riwayat(RiwayatPasien *head);
int count_pasien(Pasien *head);
int count_tindakan(BiayaTindakan *head);

#endif // FUNGSI2_H
