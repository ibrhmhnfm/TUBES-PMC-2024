// Library Standar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "algoritma\const.h"

//Library GTK+

//File-file fungsi
#include "utils\parsing.c"

// FIle program
#include "algoritma\fungsi1.c"
#include "algoritma\fungsi2.c"
#include "algoritma\fungsi3.c"
#include "algoritma\fungsi4.c"
#include "algoritma\fungsi5.c"
#include "algoritma\fungsi6.c"

// Fungsi main
int main() {
    Pasien *head_pasien = NULL;
    RiwayatPasien *head_riwayat = NULL;
    BiayaTindakan *head_biaya = NULL;
    
    baca_csv_pasien("C:\\Users\\Nasywa\\Downloads\\TUBES-PMC-2024-main\\TUBES-PMC-2024-main\\data\\DataPasien.csv", &head_pasien);
    baca_csv_riwayat("C:\\Users\\Nasywa\\Downloads\\TUBES-PMC-2024-main\\TUBES-PMC-2024-main\\data\\RiwayatPasien.csv", &head_riwayat);
    baca_csv_biaya("C:\\Users\\Nasywa\\Downloads\\TUBES-PMC-2024-main\\TUBES-PMC-2024-main\\data\\/BiayaTindakan.csv", &head_biaya);

    int pilihan;
    do {
        printf("\nMenu Utama:\n");
        printf("1. Tambah Data Pasien\n");
        printf("2. Ubah Data Pasien\n");
        printf("3. Hapus Data Pasien\n");
        printf("4. Cari Data Pasien\n");
        printf("5. Tambah Riwayat Pasien\n");
        printf("6. Ubah Riwayat Pasien\n");
        printf("7. Hapus Riwayat Pasien\n");
        printf("8. Cari Riwayat Pasien\n");
        printf("9. Cari Data dan Riwayat Pasien\n");
        printf("10. Informasi Pendapatan\n");
        printf("11. Informasi Jumlah Pasien dan Penyakit\n");
        printf("12. Informasi Kontrol Pasien\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_pasien(&head_pasien);
                break;
            case 2:
                ubah_pasien(head_pasien);
                break;
            case 3:
                hapus_pasien(&head_pasien);
                break;
            case 4:
                cari_pasien(head_pasien);
                break;
            case 5:
                tambah_riwayat(&head_riwayat,head_pasien, head_biaya);
                break;
            case 6:
                edit_riwayat(head_riwayat, head_pasien, head_biaya);
                break;
            case 7:
                hapus_riwayat(head_riwayat, head_pasien);
                break;
            case 8:
                cari_riwayat(head_riwayat);
                break;
            case 9:
                informasi_riwayat_pasien(head_pasien, head_riwayat);
                break;
            case 10:
                laporan_pendapatan(head_riwayat);
                break;
            case 11:
                printf("Jumlah pasien beserta penyakit tiap bulannya:\n");
                jumlah_pasien_dan_penyakit_per_tahun(head_riwayat);
                break;
            case 12:
                informasi_kontrol_pasien(head_riwayat);
                break;
            case 0: 
                /*char nama_file[100];
                printf("Masukkan nama file untuk menyimpan data (misal: DataPasien2024.csv): ");
                scanf(" %[^\n]", nama_file);
                simpan_csv_pasien(nama_file, head_pasien);
                simpan_csv_riwayat(nama_file, head_riwayat);
                printf("Keluar dari program.\n");*/
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);
    return 0;
}
