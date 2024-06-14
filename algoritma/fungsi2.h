#ifndef FUNGSI2_H
#define FUNGSI2_H

#define MAX 100
#define SHORT 20

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

// Function prototypes
void tambah_riwayat(RiwayatPasien *head, BiayaTindakan *head2, Pasien *head3, int total);
void edit_riwayat(RiwayatPasien *head);
void hapus_riwayat(RiwayatPasien *head);
void cari_riwayat(RiwayatPasien *head);

int count_riwayat(RiwayatPasien *head);
int count_pasien(Pasien *head);
int count_tindakan(BiayaTindakan *head);

#endif // FUNGSI2_H
