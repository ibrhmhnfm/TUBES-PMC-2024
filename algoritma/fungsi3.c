#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fungsi3.h"

// Fungsi untuk menampilkan informasi pasien berdasarkan ID pasien //tambahan
void informasi_pasien(Pasien *head_pasien, const char *id_pasien) {
    Pasien *current = head_pasien;
    int found = 0;

    printf("Informasi Pasien dengan ID: %s\n", id_pasien);
    printf("================================================================================================================================\n");
    printf("| %-5s | %-25s | %-50s | %-20s | %-15s |\n", "Indeks", "Nama", "Alamat", "Kota", "Nomor BPJS");
    printf("================================================================================================================================\n");

    while (current != NULL) {
        if (strcmp(current->id_pasien, id_pasien) == 0) {
            found = 1;
            printf("| %-5d | %-25s | %-50s | %-20s | %-15s |\n",
                   current->indekspasien, current->nama_pasien, current->alamat, current->kota, current->nomor_bpjs);
        }
        current = current->next;
    }

    if (!found) {
        printf("Tidak ada informasi pasien ditemukan untuk ID pasien: %s\n", id_pasien);
    }
}

// Fungsi untuk menampilkan riwayat medis seorang pasien berdasarkan ID pasien //tambahan
void informasi_riwayat_pasien(RiwayatPasien *head_riwayat, const char *id_pasien) {
    RiwayatPasien *current = head_riwayat;
    int found = 0;

    printf("Riwayat Medis Pasien dengan ID: %s\n", id_pasien);
    printf("================================================================================================================================\n");
    printf("| %-5s | %-15s | %-30s | %-30s | %-10s | %-10s |\n", "Indeks", "Tanggal Kunjungan", "Diagnosis", "Tindakan", "Kontrol", "Biaya");
    printf("================================================================================================================================\n");

    while (current != NULL) {
        if (strcmp(current->id_pasien, id_pasien) == 0) {
            found = 1;
            printf("| %-5d | %-15s | %-30s | %-30s | %-10s | %-10.2lf |\n",
                   current->indeksriwayat, current->tanggal_kunjungan, current->diagnosis, current->tindakan, current->kontrol, current->biaya);
        }
        current = current->next;
    }
    if (!found) {
        printf("Tidak ada riwayat medis ditemukan untuk ID pasien: %s\n", id_pasien);
    }
}