#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA 100

typedef struct {
    char nama[50];
    int semester, opsi_tidur, jam_kuliah_kepanitiaan, rhr, jam_hobi, jam_kultural, total_aktivitas;
    char punya_hobi, tingkat_stres[10];
} Mahasiswa;

Mahasiswa data_mhs[MAX_DATA];
int jumlah_data = 0;

void flush_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);



int main() {
    int pilihan;
    do {
        printf("\n=================================================\n PROGRAM ANALISIS TINGKAT STRESS MAHASISWA TEKNIK \n SDG 3 - Good Health and Well-Being\n=================================================\n");
        printf("1. Analisa Tingkat Stress\n");
        printf("2. Lihat Semua Data\n");
        printf("3. Statistik\n");
        printf("4. Referensi Jurnal\n");
        printf("5. Keluar\n");
        printf("-------------------------------------------------");
        printf("\nPilih menu : ");
        if (scanf("%d", &pilihan) != 1) { printf("\n[Sistem] Input salah! Masukkan angka 1 sampai 5.\n"); flush_buffer(); continue; }
        flush_buffer();
        if (pilihan == 1) analisa_tingkat_stres();
        else if (pilihan == 2) lihat_semua_data();
        else if (pilihan == 3) statistik();
        else if (pilihan == 4) referensi_jurnal();
        else if (pilihan == 5) printf("\n=================================================\n  Terima kasih! Tetap jaga kesehatan mental Anda.  \n=================================================\n");
        else printf("\n[Sistem] Pilihan menu tidak valid. Coba lagi.\n");
    } while (pilihan != 5);
    return 0;
}
