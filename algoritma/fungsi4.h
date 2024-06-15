#ifndef LAPORAN_PENDAPATAN_H
#define LAPORAN_PENDAPATAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// Fungsi untuk mengubah bulan dalam format teks ke nomor bulan
int bulan_ke_nomor(const char *bulan);

// Fungsi untuk membuat laporan pendapatan
void laporan_pendapatan(RiwayatPasien *head_riwayat);

#endif // LAPORAN_PENDAPATAN_H
