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
    
    // INPUT FILE
    /* Meminta Input Nama File*/
    char input_file1[100], input_file2[100];
    char path1[100], path2[100];
    char save_path1[100], save_path2[100];

    /* while Loop untuk meminta input nama file sampai benar */
    printf("Masukkan nama file data pasien (contoh: DataPasien.csv): ");
    scanf(" %[^\n]", input_file1);

    /* Gabung path data dengan nama file */
    strcpy(path1, "data/");
    strcat(path1, input_file1);
    

    while(baca_csv_pasien(path1, &head_pasien) == 0){   
        /* while Loop untuk meminta input nama file sampai benar */
        printf("Masukkan nama file data pasien (contoh: DataPasien.csv): ");
        scanf(" %[^\n]", input_file1);

        /* Gabung path data dengan nama file */
        strcpy(path1, "data/");
        strcat(path1, input_file1);
    }
    
    /* while Loop untuk meminta input nama file sampai benar */
    printf("Masukkan nama file data riwayat pasien (contoh: RiwayatPasien.csv): ");
    scanf(" %[^\n]", input_file2);

    /* Gabung path data dengan nama file */
    strcpy(path2, "data/");
    strcat(path2, input_file2);

    while(baca_csv_riwayat(path2, &head_riwayat) == 0){   
        /* while Loop untuk meminta input nama file sampai benar */
        printf("Masukkan nama file data riwayat pasien (contoh: RiwayatPasien.csv): ");
        scanf(" %[^\n]", input_file2);

        /* Gabung path data dengan nama file */
        strcpy(path2, "data/");
        strcat(path2, input_file2);
    }
    
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
                char nama_file1[100], nama_file2[100];
                printf("Masukkan nama file untuk menyimpan data pasien (misal: DataPasien2024.csv): ");
                scanf(" %[^\n]", nama_file1);

                // PATH
                strcpy(save_path1, "data/");
                strcat(save_path1, nama_file1);
                simpan_csv_pasien(save_path1, head_pasien);

                printf("Masukkan nama file untuk menyimpan data riwayat (misal: RiwayatPasien2024.csv): ");
                scanf(" %[^\n]", nama_file2);

                strcpy(save_path2, "data/");
                strcat(save_path2, nama_file2);
                simpan_csv_riwayat(save_path2, head_riwayat);
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);
    return 0;
}
