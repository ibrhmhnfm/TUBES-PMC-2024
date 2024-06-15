#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fungsi3.h"
#include "const.h"

// Fungsi untuk menampilkan informasi pasien berdasarkan ID pasien //tambahan
void informasi_riwayat_pasien(Pasien *head_pasien, RiwayatPasien *head_riwayat) {
    char id_pasien[50];
    printf("Masukkan ID Pasien: ");
    scanf(" %[^\n]", id_pasien);

    Pasien *current_pasien = head_pasien;
    int found_pasien = 0;

    printf("\n\n\n");
    printf("Informasi Pasien dengan ID: %s\n", id_pasien);
    printf("================================================================================================================================\n");
    printf("| %-5s | %-25s | %-50s | %-20s | %-15s |\n", "Indeks", "Nama", "Alamat", "Kota", "Nomor BPJS");
    printf("================================================================================================================================\n");

    while (current_pasien != NULL) {
        if (strcmp(current_pasien->id_pasien, id_pasien) == 0) {
            found_pasien = 1;
            printf("| %-5d | %-25s | %-50s | %-20s | %-15s |\n",
                   current_pasien->indekspasien, current_pasien->nama_pasien, current_pasien->alamat, current_pasien->kota, current_pasien->nomor_bpjs);
        }
        current_pasien = current_pasien->next;
    }

    if (!found_pasien) {
        printf("Tidak ada informasi pasien ditemukan untuk ID pasien: %s\n", id_pasien);
    }

    printf("================================================================================================================================\n");
    printf("\n\n\n");

    RiwayatPasien *current_riwayat = head_riwayat;
    int found_riwayat = 0;

    printf("Riwayat Medis Pasien dengan ID: %s\n", id_pasien);
    printf("================================================================================================================================\n");
    printf("| %-5s | %-15s | %-30s | %-30s | %-10s | %-10s |\n", "Indeks", "Tanggal Kunjungan", "Diagnosis", "Tindakan", "Kontrol", "Biaya");
    printf("================================================================================================================================\n");

    while (current_riwayat != NULL) {
        if (strcmp(current_riwayat->id_pasien, id_pasien) == 0) {
            found_riwayat = 1;
            printf("| %-5d | %-15s | %-30s | %-30s | %-10s | %-10.2lf |\n",
                   current_riwayat->indeksriwayat, current_riwayat->tanggal_kunjungan, current_riwayat->diagnosis, current_riwayat->tindakan, current_riwayat->kontrol, current_riwayat->biaya);
        }
        current_riwayat = current_riwayat->next;
    }
    if (!found_riwayat) {
        printf("Tidak ada riwayat medis ditemukan untuk ID pasien: %s\n", id_pasien);
    }
    printf("================================================================================================================================\n");
}