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