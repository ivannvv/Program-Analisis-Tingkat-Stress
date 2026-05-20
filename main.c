
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
}

//bagian Anandita M D
void cetak_rekomendasi(Mahasiswa m, char* indent) {
    int ada_rek = 0;
    if (m.opsi_tidur <= 1) { printf("%s- Memperbaiki jam tidur untuk mengembalikan energi.\n", indent); ada_rek = 1;}
    if (m.total_aktivitas > 55) { printf("%s- Mengurangi aktivitas berlebih dan menerapkan manajemen waktu untuk mencegah burnout.\n", indent); ada_rek = 1; }
    else if (m.total_aktivitas >= 41) { printf("%s- Mengatur skala prioritas dan manajemen waktu agar tidak kelelahan.\n", indent); ada_rek = 1; }
    if (m.rhr > 90) { printf("%s- Mencoba olahraga ringan dan latihan pernapasan untuk meredakan kecemasan.\n", indent); ada_rek = 1; }
    if (tolower(m.punya_hobi) == 'n' || m.jam_hobi < 2) { printf("%s- Meluangkan waktu untuk hobi demi menjaga keseimbangan mental.\n", indent); ada_rek = 1; }
    if (m.jam_kultural > 15) { printf("%s- Komunikasikan batasan waktu kegiatan kultural agar tidak menambah tekanan mental.\n", indent); ada_rek = 1; }
    if (strcmp(m.tingkat_stres, "Tinggi") == 0) printf("%s- Sangat disarankan untuk melakukan konsultasi dengan pihak profesional.\n", indent);
    if (!ada_rek && strcmp(m.tingkat_stres, "Rendah") == 0) printf("%s- Kondisimu sangat baik! Pertahankan pola hidup sehatmu dan jaga terus kesehatannya ya!\n", indent);
}


//bagian Lanang Cakrawala
void analisa_tingkat_stres() {
    char setuju;
    printf("\n=================================================\n            DISCLAIMER & PERSETUJUAN             \n=================================================\nPENTING: Hasil tes ini bukan diagnosis medis profesional.\nJika Anda merasa sangat tertekan, segera hubungi profesional\nkesehatan mental atau layanan darurat.\n\nSetuju melanjutkan? (y/n): ");
    scanf(" %c", &setuju); 
    flush_buffer();
    if (tolower(setuju) != 'y' || jumlah_data >= MAX_DATA) {
        printf(jumlah_data >= MAX_DATA ? 
            "\n[Sistem] Memori penuh!\n" : 
            "\n[Sistem] Anda menolak persetujuan.\n");
        return;
    }

    Mahasiswa m; int skor = 0;
    printf("\n--- IDENTITAS MAHASISWA ---\nMasukkan Nama     : "); 
    fgets(m.nama, sizeof(m.nama), stdin); 
    m.nama[strcspn(m.nama, "\n")] = 0;
    printf("Masukkan Semester : "); 
    scanf("%d", &m.semester);

    printf("\n1. Durasi tidur harian /jam\n   0 = < 6 jam | 1 = 6 jam | 2 = 7-9 jam | 3 = > 10 jam\n");
    do { 
        printf("   Pilih opsi (0-3): "); 
        scanf("%d", &m.opsi_tidur); 
    } while (m.opsi_tidur < 0 || m.opsi_tidur > 3);
    skor += (m.opsi_tidur == 0) ? 3 :
            (m.opsi_tidur == 1) ? 2 : 
            (m.opsi_tidur == 3) ? 1 : 0;

    printf("\n2. Total jam kuliah & kepanitiaan perminggu (jam): "); 
    scanf("%d", &m.jam_kuliah_kepanitiaan);
    printf("\n5. Durasi kegiatan Pembinaan Kultural Kampus perminggu (jam): "); 
    scanf("%d", &m.jam_kultural);
    m.total_aktivitas = m.jam_kuliah_kepanitiaan + m.jam_kultural;
    skor += (m.total_aktivitas > 55) ? 3 : 
            (m.total_aktivitas >= 41) ? 2 : 0;

    char punya_alat;
    printf("\n3. Apakah Anda memiliki alat untuk mengukur denyut jantung? (y/n): "); 
    scanf(" %c", &punya_alat);
    if (tolower(punya_alat) != 'y') printf("\n   [Opsi Manual]: Raba nadi leher/tangan, hitung 30 detik lalu kalikan 2.\n");
    printf("   Masukkan denyut jantung saat istirahat (bpm): "); scanf("%d", &m.rhr);
    if (m.rhr > 90 || m.rhr < 60) skor += 2;

    printf("\n4. Apakah memiliki hobi? (y/n): "); 
    scanf(" %c", &m.punya_hobi);
    if (tolower(m.punya_hobi) == 'y') {
        printf("   Frekuensi waktu hobi per minggu (jam): ");
        scanf("%d", &m.jam_hobi);
        if (m.jam_hobi < 2) skor += 1;
    } else { m.jam_hobi = 0; skor += 2; }

    strcpy(m.tingkat_stres, (skor >= 7) ? "Tinggi" : (skor >= 4) ? "Sedang" : "Rendah");

    printf("\n=================================================\n            HASIL ANALISIS INDIVIDU              \n=================================================\nNama: %s | Semester: %d\n\n[-] Analisis Indikator:\n", m.nama, m.semester);
    printf("  * Tidur       : %s\n", (m.opsi_tidur == 0) ? "Kurang tidur berat (<6 jam)." : (m.opsi_tidur == 1) ? "Tidur kurang optimal (6 jam)." : "Durasi tidur cukup.");
    printf("  * Beban Kerja : %d jam/minggu (%s)\n", m.total_aktivitas, (m.total_aktivitas > 55) ? "Extreme Overwork" : (m.total_aktivitas >= 41) ? "Overtime" : "Normal");
    printf("  * Jantung     : %d bpm (%s)\n", m.rhr, (m.rhr > 90) ? "Cenderung tinggi, waspada stres/cemas" : "Normal");
    printf("  * Hobi        : %s\n", (tolower(m.punya_hobi) == 'y') ? "Aktif dilakukan" : "Tidak ada hobi (Kekurangan media refreshing!)");
    printf("  * Kultural    : Waktu kegiatan kultural sebesar %d jam/minggu.\n\n[!] KESIMPULAN TINGKAT STRES: %s\n-------------------------------------------------\n[Saran] Rekomendasi untuk kamu:\n", m.jam_kultural, m.tingkat_stres);
    
    cetak_rekomendasi(m, "  ");
    printf("=================================================\n");
    data_mhs[jumlah_data++] = m;
}

// Start Bagian Wibi
void lihat_semua_data() {
    if (jumlah_data == 0) { printf("\n[Sistem] Belum ada data mahasiswa yang dimasukkan.\n"); return; }
    printf("\n========================================================================================================================\n                                          DAFTAR DATA ANALISIS & REKOMENDASI STRES                                      \n========================================================================================================================\n");
    for (int i = 0; i < jumlah_data; i++) {
        char txt_tidur[15], txt_hobi[20];
        strcpy(txt_tidur, (data_mhs[i].opsi_tidur == 0) ? "< 6 Jam" : (data_mhs[i].opsi_tidur == 1) ? "6 Jam" : (data_mhs[i].opsi_tidur == 2) ? "7-9 Jam" : "> 10 Jam");
        if (tolower(data_mhs[i].punya_hobi) == 'y') sprintf(txt_hobi, "Ada (%d jam/wk)", data_mhs[i].jam_hobi); else strcpy(txt_hobi, "Tidak Ada");

        printf("Data ke-%d: %s (Semester %d)\n------------------------------------------------------------------------------------------------------------------------\n", i + 1, data_mhs[i].nama, data_mhs[i].semester);
        printf("[Indikator] | Tidur: %-8s | Total Aktivitas: %-3d jam/wk | RHR: %-3d bpm | Hobi: %-13s | Kultural: %-2d jam/wk\n", txt_tidur, data_mhs[i].total_aktivitas, data_mhs[i].rhr, txt_hobi, data_mhs[i].jam_kultural);
        printf("[Status]    | Tingkat Stres: %s\n[Saran]     | Rekomendasi untuk kamu:\n", data_mhs[i].tingkat_stres);
        cetak_rekomendasi(data_mhs[i], "              ");
        printf("========================================================================================================================\n");
    }
}

//bagian dayson

void statistik() {
    if (jumlah_data == 0) { printf("\n[Sistem] Belum ada data untuk kalkulasi statistik.\n"); return; }
    double t_tidur = 0; int t_aktivitas = 0, hobi_c = 0, r = 0, s = 0, t = 0;
    for (int i = 0; i < jumlah_data; i++) {
        t_tidur += (data_mhs[i].opsi_tidur == 0) ? 5.0 : (data_mhs[i].opsi_tidur == 1) ? 6.0 : (data_mhs[i].opsi_tidur == 2) ? 8.0 : 10.0;
        t_aktivitas += data_mhs[i].total_aktivitas;
        if (tolower(data_mhs[i].punya_hobi) == 'y') hobi_c++;
        if (strcmp(data_mhs[i].tingkat_stres, "Rendah") == 0) r++;
        else if (strcmp(data_mhs[i].tingkat_stres, "Sedang") == 0) s++;
        else t++;
    }
        printf("\n=================================================\n"
           "               STATISTIK PROGRAM                 \n"
           "=================================================\n"
           "Rata-rata Durasi Tidur (Pendekatan): %.1f jam/hari\n"
           "Rata-rata Jam Aktivitas Mingguan  : %.1f jam/minggu\n"
           "Persentase Memiliki Hobi          : %.1f%%\n"
           "-------------------------------------------------\n"
           "Persentase Tingkat Stres Mahasiswa:\n"
           "  - Stres Rendah : %.1f%%\n"
           "  - Stres Sedang : %.1f%%\n"
           "  - Stres Tinggi : %.1f%%\n"
           "=================================================\n", 
           t_tidur / jumlah_data, 
           (double)t_aktivitas / jumlah_data, 
           ((double)hobi_c / jumlah_data) * 100, 
           ((double)r / jumlah_data) * 100, 
           ((double)s / jumlah_data) * 100, 
           ((double)t / jumlah_data) * 100);
}
void referensi_jurnal() {
    printf("\n====================================================================\n"
           "                          REFERENSI JURNAL                          \n"
           "====================================================================\n"
           "[1] Rahman, A. F., Fitriyani, F., Mandala, Z., & Wirawan, A. (2024).\n"
           "    Gambaran Kualitas Tidur Pada Mahasiswa Pendidikan Profesi Dokter\n"
           "    Di Rumah Sakit Pertamina Bintang Amin.\n"
           "    JURNAL ILMU KEDOKTERAN DAN KESEHATAN, 11(6), 1244-1251.\n"
           "    https://doi.org/10.33024/jikk.v11i6.15329\n\n"
           "[2] Ramadani, K. D. (2021).\n"
           "    HUBUNGAN JAM KERJA DAN KESEHATAN PEKERJA DI INDONESIA.\n"
           "    Jurnal Kesmas (Kesehatan Masyarakat) Khatulistiwa, 8(1), 33.\n"
           "    https://doi.org/10.29406/jkmk.v8i1.2638\n\n"
           "[3] Nabilatussalma Syeftiani, Citrawati, M., Safira, L., & Melly, K. (2024).\n"
           "    HUBUNGAN ANTARA AKTIVITAS FISIK DAN TINGKAT STRES DENGAN\n"
           "    RESTING HEART RATE PADA MAHASISWA KEDOKTERAN.\n"
           "    Medika Kartika Jurnal Kedokteran Dan Kesehatan, 7(1), 1-11.\n"
           "    http://medikakartika.unjani.ac.id/medikakartika/index.php/mk/article/view/598\n"
           "====================================================================\n");
}

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
