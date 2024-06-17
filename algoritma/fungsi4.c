#include "fungsi4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"

// Fungsi untuk mengubah bulan dalam format teks ke nomor bulan
int bulan_ke_nomor(const char *bulan) {
    if (strcmp(bulan, "Januari") == 0) return 1;
    if (strcmp(bulan, "Februari") == 0) return 2;
    if (strcmp(bulan, "Maret") == 0) return 3;
    if (strcmp(bulan, "April") == 0) return 4;
    if (strcmp(bulan, "Mei") == 0) return 5;
    if (strcmp(bulan, "Juni") == 0) return 6;
    if (strcmp(bulan, "Juli") == 0) return 7;
    if (strcmp(bulan, "Agustus") == 0) return 8;
    if (strcmp(bulan, "September") == 0) return 9;
    if (strcmp(bulan, "Oktober") == 0) return 10;
    if (strcmp(bulan, "November") == 0) return 11;
    if (strcmp(bulan, "Desember") == 0) return 12;
    return -1; // Jika tidak ada yang cocok
}

void laporan_pendapatan(RiwayatPasien *head_riwayat) {
    double pendapatan_perbulan[12] = {0};
    double pendapatan_pertahun[6] = {0};  // Menggunakan array untuk 2018-2023
    int jumlahBulan[12] = {0};
    int jumlahTahun[6] = {0};  // Menghitung jumlah entri per tahun

    RiwayatPasien* temp = head_riwayat;
    while (temp != NULL) {
        int hari, tahun;
        char bulan[20];
        sscanf(temp->tanggal_kunjungan, "%d %s %d", &hari, bulan, &tahun);
        int bulan_num = bulan_ke_nomor(bulan);

        if (bulan_num < 1 || bulan_num > 12 || tahun < 2018 || tahun > 2023) {
            temp = temp->next;
            continue;  // Lewati entri di luar rentang tahun 2018-2023
        }
        pendapatan_perbulan[bulan_num - 1] += temp->biaya;
        pendapatan_pertahun[tahun - 2018] += temp->biaya;
        
        jumlahBulan[bulan_num - 1]++;
        jumlahTahun[tahun - 2018]++;

        temp = temp->next;
    }

    printf("Laporan Pendapatan Bulanan:\n");
    printf("=========================================================\n");
    printf("| Bulan |    Total Pendapatan  | Rata-rata Pendapatan |\n");
    printf("=========================================================\n");
    for (int i = 0; i < 12; i++) {
        if (jumlahBulan[i] > 0) {
            printf("| %5d | %16.2f     | %20.2f   |\n", i + 1, pendapatan_perbulan[i], pendapatan_perbulan[i] / jumlahBulan[i]);
        } else {
            printf("| %5d | %16s | %20s   |\n", i + 1, "Tidak ada pendapatan", "");
        }
    }
    printf("========================================================\n");

    printf("\nLaporan Pendapatan Tahunan (2018-2023):\n");
    printf("========================================================\n");
    printf("| Tahun |    Total Pendapatan  | Rata-rata Pendapatan |\n");
    printf("========================================================\n");
    for (int i = 0; i < 6; i++) {
        int tahun_sekarang = 2018 + i;
        if (jumlahTahun[i] > 0) {
            printf("| %5d | %16.2f     | %20.2f |\n", tahun_sekarang, pendapatan_pertahun[i], pendapatan_pertahun[i] / jumlahTahun[i]);
        } else {
            printf("| %5d | %16s | %20s |\n", tahun_sekarang, "Tidak ada pendapatan", "");
        }
    }
    printf("========================================================\n");
    return 0;
}
