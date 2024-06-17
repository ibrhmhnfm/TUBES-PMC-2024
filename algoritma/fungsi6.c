#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi6.h"
#include "const.h"

// Fungsi untuk menampilkan pasien yang perlu kontrol pada tanggal tertentu
void informasi_kontrol_pasien(RiwayatPasien *head_riwayat) {
    char tanggal_kontrol[50];
    printf("Masukkan Tanggal Kontrol (dd month yyyy seperti: 12 Januari 2023): \n");
    scanf(" %[^\n]", tanggal_kontrol);
    
    RiwayatPasien *current = head_riwayat;
    int found = 0;

    printf("Pasien yang perlu kontrol pada tanggal: %s\n", tanggal_kontrol);
    printf("======================================================================================================================================\n");
    printf("| %-5s | %-15s | %-30s | %-30s | %-10s           | %-10s   |\n", "Indeks", "Tanggal Kunjungan", "ID Pasien", "Diagnosis", "Tindakan", "Biaya");
    printf("======================================================================================================================================\n");

    while (current != NULL) {
        if (strcmp(current->kontrol, tanggal_kontrol) == 0) {
            found = 1;
            printf("| %-5d  | %-15s  | %-30s | %-30s | %-10s      | %-10.2lf  |\n",
                   current->indeksriwayat, current->tanggal_kunjungan, current->id_pasien, current->diagnosis, current->tindakan, current->biaya);
            printf("======================================================================================================================================\n");
        }
        current = current->next;
    }

    if (!found) {
        printf("Tidak ada pasien yang perlu kontrol pada tanggal: %s\n", tanggal_kontrol);
    }
}