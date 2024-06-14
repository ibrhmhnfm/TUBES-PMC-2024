#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct DiseaseCount {
    char disease[100];
    int count;
    struct DiseaseCount *next;
} DiseaseCount;

typedef struct MonthYearCount {
    char month_year[20];
    int patient_count;
    DiseaseCount *disease_head;
    struct MonthYearCount *next;
} MonthYearCount;

typedef struct YearCount {
    char year[5];
    MonthYearCount *month_head;
    struct YearCount *next;
} YearCount;

// Fungsi untuk mendapatkan nomor bulan
const char *get_month_number(const char *month_name) {
    if (strcmp(month_name, "Januari") == 0) return "01";
    if (strcmp(month_name, "Februari") == 0) return "02";
    if (strcmp(month_name, "Maret") == 0) return "03";
    if (strcmp(month_name, "April") == 0) return "04";
    if (strcmp(month_name, "Mei") == 0) return "05";
    if (strcmp(month_name, "Juni") == 0) return "06";
    if (strcmp(month_name, "Juli") == 0) return "07";
    if (strcmp(month_name, "Agustus") == 0) return "08";
    if (strcmp(month_name, "September") == 0) return "09";
    if (strcmp(month_name, "Oktober") == 0) return "10";
    if (strcmp(month_name, "November") == 0) return "11";
    if (strcmp(month_name, "Desember") == 0) return "12";
    return "00";
}

// Fungsi untuk mendapatkan nama bulan dari nomor bulan
const char *get_month_name(const char *month_number) {
    if (strcmp(month_number, "01") == 0) return "Januari";
    if (strcmp(month_number, "02") == 0) return "Februari";
    if (strcmp(month_number, "03") == 0) return "Maret";
    if (strcmp(month_number, "04") == 0) return "April";
    if (strcmp(month_number, "05") == 0) return "Mei";
    if (strcmp(month_number, "06") == 0) return "Juni";
    if (strcmp(month_number, "07") == 0) return "Juli";
    if (strcmp(month_number, "08") == 0) return "Agustus";
    if (strcmp(month_number, "09") == 0) return "September";
    if (strcmp(month_number, "10") == 0) return "Oktober";
    if (strcmp(month_number, "11") == 0) return "November";
    if (strcmp(month_number, "12") == 0) return "Desember";
    return "Tidak Diketahui";
}

// Fungsi untuk menambahkan pasien berdasarkan bulan dan tahun
void tambah_pasien_bulan_tahun(YearCount **head, const char *year, const char *month_year, const char *diagnosis) {
    YearCount *current_year = *head;

    while (current_year != NULL && strcmp(current_year->year, year) != 0) {
        current_year = current_year->next;
    }

    if (current_year == NULL) {
        current_year = (YearCount*)malloc(sizeof(YearCount));
        strcpy(current_year->year, year);
        current_year->month_head = NULL;
        current_year->next = *head;
        *head = current_year;
    }

    MonthYearCount *current_month = current_year->month_head;
    while (current_month != NULL && strcmp(current_month->month_year, month_year) != 0) {
        current_month = current_month->next;
    }

    if (current_month == NULL) {
        current_month = (MonthYearCount*)malloc(sizeof(MonthYearCount));
        strcpy(current_month->month_year, month_year);
        current_month->patient_count = 0;
        current_month->disease_head = NULL;
        current_month->next = current_year->month_head;
        current_year->month_head = current_month;
    }

    current_month->patient_count++;

    DiseaseCount *current_disease = current_month->disease_head;
    while (current_disease != NULL && strcmp(current_disease->disease, diagnosis) != 0) {
        current_disease = current_disease->next;
    }

    if (current_disease == NULL) {
        current_disease = (DiseaseCount*)malloc(sizeof(DiseaseCount));
        strcpy(current_disease->disease, diagnosis);
        current_disease->count = 0;
        current_disease->next = current_month->disease_head;
        current_month->disease_head = current_disease;
    }

    current_disease->count++;
}

// Fungsi untuk mengurutkan penyakit berdasarkan jumlah dalam urutan menurun
DiseaseCount *sort_disease_count(DiseaseCount *head) {
    DiseaseCount *sorted = NULL;
    DiseaseCount *current = head;
    while (current != NULL) {
        DiseaseCount *next = current->next;
        if (!sorted || sorted->count < current->count) {
            current->next = sorted;
            sorted = current;
        } else {
            DiseaseCount *temp = sorted;
            while (temp->next && temp->next->count >= current->count) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

MonthYearCount *sort_month_year_count(MonthYearCount *head) {
    MonthYearCount *sorted = NULL;
    MonthYearCount *current = head;

    while (current != NULL) {
        MonthYearCount *next = current->next;
        if (!sorted || strcmp(current->month_year, sorted->month_year) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            MonthYearCount *temp = sorted;
            while (temp->next && strcmp(temp->next->month_year, current->month_year) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void jumlah_pasien_dan_penyakit_per_tahun(RiwayatPasien *head) {
    YearCount *head_count = NULL;
    RiwayatPasien *temp = head;

    while (temp != NULL) {
        char day[3], month[10], year[5], month_year[20];
        sscanf(temp->tanggal_kunjungan, "%2s %9s %4s", day, month, year);
        sprintf(month_year, "%s-%s", get_month_number(month), year);

        tambah_pasien_bulan_tahun(&head_count, year, month_year, temp->diagnosis);

        temp = temp->next;
    }

    // Sort the YearCount linked list by year in descending order
    YearCount *sorted_head_year = NULL;
    while (head_count != NULL) {
        YearCount *max_year = head_count;
        YearCount *prev_max_year = NULL;
        YearCount *prev = head_count;
        YearCount *current = head_count->next;

        while (current != NULL) {
            if (strcmp(current->year, max_year->year) > 0) {
                max_year = current;
                prev_max_year = prev;
            }
            prev = current;
            current = current->next;
        }

        if (prev_max_year != NULL) {
            prev_max_year->next = max_year->next;
        } else {
            head_count = max_year->next;
        }

        max_year->next = sorted_head_year;
        sorted_head_year = max_year;
    }

    // Display sorted YearCount list in table format
    YearCount *year_temp = sorted_head_year;
    while (year_temp != NULL) {
        printf("=======================================================\n");
        printf("|                      Tahun %s                     |\n", year_temp->year);
        printf("=======================================================\n");
        printf("| Bulan Tahun | Jumlah Pasien |   Penyakit   | Jumlah |\n");
        printf("=======================================================\n");

        // Sort the MonthYearCount linked list by month in ascending order
        year_temp->month_head = sort_month_year_count(year_temp->month_head);

        MonthYearCount *count_temp = year_temp->month_head;
        while (count_temp != NULL) {
            char month[3], year[5];
            sscanf(count_temp->month_year, "%2s-%4s", month, year);
            printf("| %-11s | %-13d |", get_month_name(month), count_temp->patient_count);

            // Sort and display DiseaseCount list for the current month
            count_temp->disease_head = sort_disease_count(count_temp->disease_head);
            DiseaseCount *disease_temp = count_temp->disease_head;
            int first_disease = 1;
            while (disease_temp != NULL) {
                if (!first_disease) {
                    printf("|             |               |");
                }
                printf(" %-12s | %-6d |\n", disease_temp->disease, disease_temp->count);
                first_disease = 0;
                disease_temp = disease_temp->next;
            }

            if (count_temp->disease_head == NULL) {
                printf("\n");
            }

            count_temp = count_temp->next;
            printf("-------------------------------------------------------\n"); // Pemisah tiap bulan
        }

        year_temp = year_temp->next;
    }
    printf("=======================================================\n");
}
