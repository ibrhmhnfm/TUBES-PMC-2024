#include "fungsi2.h"
#include "const.h"
/*==================================== ALGORITMA FUNGSI 2 ========================================*/
/**Algoritma dibuat untuk menyelesaikan tugas besar PMC Semester Genap tahun ajar 2023/2024 
 * 
 *  Nama    : Ibrahim Hanif Mulyana
 *  NIM     : 13222111
 *  Kelas   : K-03
 * 
 *  nama file: fungsi2.c
 *  Referensi: -
 * 
==================================================================================================*/


// Fungsi untuk melakukan save pada file
void simpan_csv_riwayat(const char *nama_file, RiwayatPasien *head){
    FILE *file = fopen(nama_file, "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    fprintf(file, "Indeks Riwayat, Tanggal, ID Pasien, Diagnosis, Tindakan, Kontrol, Biaya\n");

    RiwayatPasien *temp = head;
    while (temp != NULL) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%lf\n",
                temp->indeksriwayat, temp->tanggal_kunjungan, temp->id_pasien,
                temp->diagnosis, temp->tindakan, temp->kontrol,
                temp->biaya);
        temp = temp->next;
    }

    fclose(file);
    printf("Riwayat Pasien berhasil disimpan ke dalam file %s.\n", nama_file);
}

// Fungsi mencari data riwayat pasien berdasarkan id pasien
void cari_riwayat(RiwayatPasien *head){
    char id_pasien[SHORT];
    printf("Masukkan ID Pasien yang ingin dicari: ");
    scanf(" %[^\n]", id_pasien);
    int found = 0;

    RiwayatPasien *temp = head->next;

    RiwayatPasien *current_riwayat = head;
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

// Fungsi untuk mencari last_index dari struct Riwayat Pasien
int last_index_riwayat(RiwayatPasien *head){
    int last_index = 0;
    RiwayatPasien *temp = head;
    while (temp != NULL) {
        if (temp->indeksriwayat > last_index) {
            last_index = temp->indeksriwayat;
        }
        temp = temp->next;
    }
    return last_index;
}

// Fungsi mengecek apakah ID sudah terdaftar
int cek_id(char *tes, Pasien *head){
    Pasien *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->id_pasien, tes) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0; 
}

// Fungsi mengecek apakah tindakan ada di list tindakan yang dapat diberikan klinik
int cek_tindakan(char *tes, BiayaTindakan *head){
    BiayaTindakan *temp = head;
    while (temp != NULL) {
        if(strcmp(temp->aktivitas, tes) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Fungsi menghitung biaya yang harus dibayar dari tindakan yang dilakukan
double hitung_tindakan(char *tes, BiayaTindakan *head){
    BiayaTindakan *temp = head;
    while (temp != NULL) {
        if(strcmp(temp->aktivitas, tes) == 0) {
            return temp->biayatindakan;
        }
        temp = temp->next;
    }
    return 0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi untuk menambah riwayat baru
void tambah_riwayat(RiwayatPasien **head, Pasien *head3, BiayaTindakan *head2){
    int total = last_index_riwayat(*head) + 1;
    double biaya;
    char tanggal[SHORT], id_pasien[SHORT], Diagnosis[MAX], Tindakan[MAX], Kontrol[SHORT];
    
    RiwayatPasien *newRiwayat = (RiwayatPasien*)malloc(sizeof(RiwayatPasien));
    if (newRiwayat == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    // ENTRY
    printf("Masukkan tanggal kunjungan pasien: ");
    scanf(" %[^\n]", tanggal);
    clear_input_buffer();
    printf("Masukkan ID Pasien: ");
    scanf(" %[^\n]", id_pasien);
    clear_input_buffer();
    
    while(1) {
        if (cek_id(id_pasien, head3)) {
            printf("Pasien berhasil ditemukan!\n");
            break;
        } else {
            printf("\nID Pasien tidak terdaftar di database pasien. Mohon masukkan ID pasien terdaftar atau mendaftarkan pasien terlebih dahulu.\n");
            printf("Masukkan ID Pasien: ");
            scanf(" %[^\n]", id_pasien);
            clear_input_buffer();
        }
    }

    printf("Masukkan diagnosis: ");
    scanf(" %[^\n]", Diagnosis);
    clear_input_buffer();
    printf("Masukkan tindakan yang dilakukan: ");
    scanf(" %[^\n]", Tindakan);
    clear_input_buffer();

    while(1) {
        if (!cek_tindakan(Tindakan, head2)) {
            printf("Tindakan tidak masuk ke dalam aktivitas klinik, mohon ulangi input.\n");
            printf("Masukkan tindakan yang dilakukan: ");
            scanf(" %[^\n]", Tindakan);
            clear_input_buffer();
        } else {
            biaya = hitung_tindakan(Tindakan, head2);
            break;
        }
    }

    printf("Masukkan tanggal kontrol: ");
    scanf(" %[^\n]", Kontrol);
    clear_input_buffer();

    // Masukkan ke struct
    newRiwayat->indeksriwayat = total;
    strcpy(newRiwayat->tanggal_kunjungan, tanggal);
    strcpy(newRiwayat->id_pasien, id_pasien);
    strcpy(newRiwayat->diagnosis, Diagnosis);
    strcpy(newRiwayat->tindakan, Tindakan);
    newRiwayat->biaya = biaya;
    strcpy(newRiwayat->kontrol, Kontrol);
    newRiwayat->next = NULL;
    
    if (*head == NULL) {
        *head = newRiwayat;
    } else {
        RiwayatPasien *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRiwayat;
    }

    printf("Riwayat Pasien Berhasil Dimasukkan!\n");
}

void edit_riwayat(RiwayatPasien *head, Pasien *pasien, BiayaTindakan *harga){
    char id_pasien[SHORT], id_pasien_baru[SHORT], tindakan[MAX];
    int indeksriwayat;
    printf("Masukkan ID Pasien yang riwayatnya ingin diubah: ");
    scanf(" %[^\n]", id_pasien);
    clear_input_buffer();

    RiwayatPasien *temp = head;
    RiwayatPasien *temp_print = head;
    Pasien *temp2 = pasien;
    BiayaTindakan *bayar = harga;
    int temu = 0;

    if (cek_id(id_pasien, pasien)){
        RiwayatPasien *current_riwayat = head;
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
    
        printf("\n\nIndeks data riwayat yang ingin diubah :");
        scanf("%d", &indeksriwayat);
        while (temp != NULL) {
            if (strcmp(temp->id_pasien, id_pasien) == 0 && temp->indeksriwayat == indeksriwayat) {
                printf("Masukkan tanggal kunjungan baru: (sebelumnya %s): ", temp->tanggal_kunjungan);
                scanf(" %[^\n]", temp->tanggal_kunjungan);
                clear_input_buffer();
                while(1){
                    printf("Masukkan ID pasien baru (sebelumnya %s): ", temp->id_pasien);
                    scanf(" %[^\n]", id_pasien_baru);
                    clear_input_buffer();
                    if (cek_id(temp->id_pasien, pasien)) {
                        strcpy(temp->id_pasien, id_pasien);
                        break;
                    } else {
                        printf("ID Pasien tidak terdaftar di database pasien. Mohon masukkan ID pasien terdaftar atau mendaftarkan pasien terlebih dahulu.\n");
                    }
                }
                printf("Masukkan diagnosis baru: (sebelumnya %s): ", temp->diagnosis);
                scanf(" %[^\n]", temp->diagnosis);
                clear_input_buffer();
                while(1){
                    printf("Masukkan tindakan baru (sebelumnya %s): ", temp->tindakan);
                    scanf(" %[^\n]", tindakan);
                    clear_input_buffer();
                    if (!cek_tindakan(temp->tindakan, harga)) {
                        printf("Tindakan tidak masuk ke dalam aktivitas klinik, mohon ulangi input.\n");
                    } else {
                        strcpy(temp->tindakan, tindakan);
                        temp->biaya = hitung_tindakan(temp->tindakan, bayar);
                        break;
                    }
                }
                printf("Masukkan tanggal kontrol baru: (sebelumnya %s): ", temp->kontrol);
                scanf(" %[^\n]", temp->kontrol);
                clear_input_buffer();
                
                printf("Riwayat Pasien Berhasil Diubah\n");
                return;
            }
            temp = temp->next;
        }
    }
    printf("Riwayat Pasien tidak ditemukan.\n");
}
void hapus_riwayat(RiwayatPasien *head, Pasien *pasien){
    char id_pasien[SHORT], id_pasien_baru[SHORT], tindakan[MAX];
    int indeksriwayat;
    printf("Masukkan ID Pasien yang riwayatnya ingin dihapus: ");
    scanf(" %[^\n]", id_pasien);
    clear_input_buffer();

    RiwayatPasien *temp = head;
    Pasien *temp2 = pasien;
    int temu = 0;

    if (cek_id(id_pasien, pasien)){
        RiwayatPasien *current_riwayat = head;
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
        printf("\n\nIndeks data riwayat yang ingin dihapus :");
        scanf("%d", &indeksriwayat);

        RiwayatPasien *temp = head;
        RiwayatPasien *previous = NULL;

        while (temp != NULL) {
            if ((strcmp(temp->id_pasien, id_pasien) == 0)&& temp->indeksriwayat == indeksriwayat){
                if (previous == NULL) {
                    head = temp->next;
                } else {
                    previous->next = temp->next;
                }
                free(temp);
                printf("Riwayat Pasien Berhasil Dihapus\n");
                return;
            }
            previous = temp;
            temp = temp->next;
        }
    }
    printf("Riwayat Pasien tidak ditemukan.\n");
}
