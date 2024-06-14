#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi2.h"
#include "..\utils\parsing.h"

void tambah_riwayat(RiwayatPasien *head, BiayaTindakan *head2, Pasien *head3, int total){
    int biaya;
    char tanggal[SHORT], id_pasien[SHORT], Diagnosis[MAX], Tindakan[MAX], Kontrol[SHORT];
    
    int found = 0, found2 = 0;

    // ENTRY
    printf("Masukkan tanggal kunjungan pasien : ");
    scanf("%s", tanggal);
    while(1){
        printf("\nMasukkan ID Pasien : ");
        scanf("%s", id_pasien);
        Pasien *tempPasien = head3;
        while(tempPasien != NULL) {
            if (strcmp(tempPasien->id_pasien, id_pasien) == 0){
                found = 1;
                break;
            } else {
                tempPasien = tempPasien->next;
            }
        }
        if (!found){
            printf("\nID Pasien tidak ada di Data Pasien. Mohon masukkan ID Pasien terdaftar\n");
        } else {
            break;
        }
    }
    printf("\nMasukkan diagnosis : ");
    scanf("%s", Diagnosis);
    while(1){
        printf("\nMasukkan tindakan yang dilakukan : ");
        scanf("%s", Tindakan);
        BiayaTindakan *tempTindakan = head2;
        while(tempTindakan != NULL) {
            if (strcmp(tempTindakan->aktivitas, Tindakan) == 0){
                found2 = 1;
                biaya = tempTindakan->biayatindakan;
                break;
            } else {
                tempTindakan = tempTindakan->next;
            }
        }
        if (!found2){
            printf("\nTindakan tidak masuk ke dalam aktivitas klinik, mohon ulangi input : ");
        } else {
            break;
        }
    }
    printf("\nMasukkan tanggal kontrol : ");
    scanf("%s", Kontrol);

    // Masukkan ke struct
    RiwayatPasien *newRiwayat = (RiwayatPasien*) malloc(sizeof(RiwayatPasien));
    newRiwayat->indeksriwayat = head->indeksriwayat + 1;
    strcpy(newRiwayat->tanggal_kunjungan, tanggal);
    strcpy(newRiwayat->id_pasien, id_pasien);
    strcpy(newRiwayat->diagnosis, Diagnosis);
    strcpy(newRiwayat->tindakan, Tindakan);
    newRiwayat->biaya = biaya;
    strcpy(newRiwayat->kontrol, Kontrol);
    newRiwayat->next = head->next;
    head->next = newRiwayat;

    printf("Riwayat Pasien Berhasil Dimasukkan\n");
}

void edit_riwayat(RiwayatPasien *head){
    char id_pasien[SHORT];
    int indeksriwayat;
    printf("Masukkan ID Pasien yang riwayatnya ingin diubah: ");
    scanf("%s", id_pasien);
    printf("Masukkan Indeks Riwayat yang ingin diubah: ");
    scanf("%d", &indeksriwayat);

    RiwayatPasien *current = head->next;
    while (current != NULL) {
        if (strcmp(current->id_pasien, id_pasien) == 0 && current->indeksriwayat == indeksriwayat) {
            printf("Masukkan tanggal kunjungan baru: ");
            scanf("%s", current->tanggal_kunjungan);
            printf("Masukkan diagnosis baru: ");
            scanf("%s", current->diagnosis);
            printf("Masukkan tindakan baru: ");
            scanf("%s", current->tindakan);
            printf("Masukkan biaya baru: ");
            scanf("%lf", &current->biaya);
            printf("Masukkan tanggal kontrol baru: ");
            scanf("%s", current->kontrol);
            printf("Riwayat Pasien Berhasil Diubah\n");
            return;
        }
        current = current->next;
    }
    printf("Riwayat Pasien tidak ditemukan.\n");
}

void hapus_riwayat(RiwayatPasien *head){
    char id_pasien[SHORT];
    int indeksriwayat;
    printf("Masukkan ID Pasien yang riwayatnya ingin dihapus: ");
    scanf("%s", id_pasien);
    printf("Masukkan Indeks Riwayat yang ingin dihapus: ");
    scanf("%d", &indeksriwayat);

    RiwayatPasien *current = head;
    RiwayatPasien *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->id_pasien, id_pasien) == 0 && current->indeksriwayat == indeksriwayat) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Riwayat Pasien Berhasil Dihapus\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Riwayat Pasien tidak ditemukan.\n");
}

void cari_riwayat(RiwayatPasien *head){
    char id_pasien[SHORT];
    printf("Masukkan ID Pasien yang ingin dicari: ");
    scanf("%s", id_pasien);

    RiwayatPasien *current = head->next;
    while (current != NULL) {
        if (strcmp(current->id_pasien, id_pasien) == 0) {
            printf("Indeks Riwayat: %d\n", current->indeksriwayat);
            printf("Tanggal Kunjungan: %s\n", current->tanggal_kunjungan);
            printf("Diagnosis: %s\n", current->diagnosis);
            printf("Tindakan: %s\n", current->tindakan);
            printf("Biaya: %.2f\n", current->biaya);
            printf("Kontrol: %s\n", current->kontrol);
            printf("-------------------------------\n");
        }
        current = current->next;
    }
}

int count_riwayat(RiwayatPasien *head) {
    int count = 0;
    RiwayatPasien *current = head->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int count_pasien(Pasien *head) {
    int count = 0;
    Pasien *current = head->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int count_tindakan(BiayaTindakan *head) {
    int count = 0;
    BiayaTindakan *current = head->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
