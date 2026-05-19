#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA 100

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
