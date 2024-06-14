// Library Standar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Library GTK+

//File-file fungsi
#include "utils\parsing.h"

// FIle program
// #include "algoritma\fungsi1.h"
// #include "algoritma\fungsi3.h"
// #include "algoritma\fungsi4.h"
// #include "algoritma\fungsi5.h"
// #include "algoritma\fungsi6.h"
// #include "algoritma\fungsi7.h"
#include "algoritma\fungsi2.h"

// Struktur data yang digunakan
typedef struct Pasien {
    int indekspasien;
    char nama_pasien[100];
    char alamat[150];
    char kota[50];
    char tempat_lahir[50];
    char tanggal_lahir[30];
    int umur;
    char nomor_bpjs[20];
    char id_pasien[20];
    struct Pasien *next;
} Pasien;

typedef struct RiwayatPasien {
    int indeksriwayat;
    char tanggal_kunjungan[20];
    char id_pasien[20];
    char diagnosis[100];

    char tindakan[100];
    char kontrol[20];
    double biaya;
    struct RiwayatPasien *next;
} RiwayatPasien;

typedef struct BiayaTindakan {
    int indekstindakan;
    char aktivitas[20];
    double biayatindakan;
    struct BiayaTindakan *next;
} BiayaTindakan;

// Fungsi main
int main() {
    Pasien *head_pasien = NULL;
    RiwayatPasien *head_riwayat = NULL;
    BiayaTindakan *head_biaya = NULL;
    
    baca_csv_pasien("DataPasien.csv", &head_pasien);
    baca_csv_riwayat("RiwayatPasien.csv", &head_riwayat);
    baca_csv_biaya("BiayaTindakan.csv", &head_biaya);

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
                tambah_riwayat(&head_riwayat, &head_biaya, &head_pasien, count_riwayat(&head_riwayat));
                break;
            case 6:
                edit_riwayat(&head_riwayat);
                break;
            case 7:
                hapus_riwayat(&head_riwayat);
                break;
            case 8:
                cari_riwayat(&head_riwayat);
                break;
            case 9:
                //informasi_data_dan_riwayat(head_riwayat);
                break;
            case 10:
                //informasi_pendapatan(head_riwayat);
                break;
            case 11:
                printf("Jumlah pasien beserta penyakit tiap bulannya:\n");
                jumlah_pasien_dan_penyakit_per_tahun(head_riwayat);
                break;
            case 12:
                //informasi_kontrol (head_riwayat);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);
    return 0;
}
