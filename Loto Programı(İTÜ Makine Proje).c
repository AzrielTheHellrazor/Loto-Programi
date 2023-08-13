#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#define KUPON_SATIRI 500
#define KOLON_SAYISI 6

void kure(int kolon[KOLON_SAYISI]) {
    int i, j, sayi;
    bool tekrar;

    for (i = 0; i < KOLON_SAYISI; i++) {
        do {
            sayi = rand() % 49 + 1;
            tekrar = false;

            for (j = 0; j < i; j++) {
                if (kolon[j] == sayi) {
                    tekrar = true;
                    break;
                }
            }
        } while (tekrar);

        kolon[i] = sayi;
    }
}

void olustur(int kupon[KUPON_SATIRI][KOLON_SAYISI], int satir) {
    int i, j;
    for (i = 0; i < satir; i++) {
        int kolon[KOLON_SAYISI];
        kure(kolon);

        for (j = 0; j < KOLON_SAYISI; j++) {
            kupon[i][j] = kolon[j];
        }
    }
}

void bubbleSort(int dizi[], int boyut) {
    int i, j;
    for (i = 0; i < boyut - 1; i++) {
        for (j = 0; j < boyut - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

bool lineerArama(int dizi[], int boyut, int aranan) {
    int i;
    for (i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            return true;
        }
    }
    return false;
}

void raporla(int kupon[KUPON_SATIRI][KOLON_SAYISI], int sonuc[KOLON_SAYISI], int satir) {
    FILE* dosya = fopen("sonuc_rapor.txt", "w");
    if (dosya == NULL) {
        printf("Dosya oluşturulamadı.");
        return;
    }

    fprintf(dosya, "Oynanan Sayısal Loto Kuponu:\n");
    fprintf(dosya, "Kolon Sayı 1 Sayı 2 Sayı 3 Sayı 4 Sayı 5 Sayı 6\n");

    int i, j;
    for (i = 0; i < satir; i++) {
        fprintf(dosya, "%d ", i + 1);
        for (j = 0; j < KOLON_SAYISI; j++) {
            fprintf(dosya, "%d ", kupon[i][j]);
        }
        fprintf(dosya, "\n");
    }

    fprintf(dosya, "\n\nBilinenler Çıktısı:\n");
    fprintf(dosya, "Kolon Bilinen Sayısı\n");

    int bilinen[KUPON_SATIRI + 1] = { 0 };
    for (i = 0; i < satir; i++) {
        int sayac = 0;
        for (j = 0; j < KOLON_SAYISI; j++) {
            if (lineerArama(sonuc, KOLON_SAYISI, kupon[i][j])) {
                sayac++;
            }
        }
        fprintf(dosya, "%d %d\n", i + 1, sayac);
        bilinen[sayac]++;
    }

    fprintf(dosya, "\nHaftanın Çekiliş Sonucu:\n");
    fprintf(dosya, "Sayı 1 Sayı 2 Sayı 3 Sayı 4 Sayı 5 Sayı 6\n\n");

    for (i = 0; i < KOLON_SAYISI; i++) {
        fprintf(dosya, "%d ", sonuc[i]);
    }

    fprintf(dosya, "\n\nSonuç Dizi Çıktısı:\n");
    fprintf(dosya, "Bilinenler Sayısı\n");

    bubbleSort(bilinen, KOLON_SAYISI + 1);
    int toplam = 0;
    for (i = 0; i < KOLON_SAYISI; i++) {
        fprintf(dosya, "%d %d\n", i + 1, bilinen[KOLON_SAYISI - i]);
        toplam += bilinen[KOLON_SAYISI - i];
    }
    fprintf(dosya, "Toplam %d\n", toplam);

    fclose(dosya);

    printf("Raporlama tamamlandı. Sonuçlar sonuc_rapor.txt dosyasına kaydedildi.\n");
}


int main() {
    setlocale(LC_ALL, "Turkish");
    srand(time(NULL));

    int kupon[KUPON_SATIRI][KOLON_SAYISI];
    olustur(kupon, KUPON_SATIRI);
        int cekilis[KOLON_SAYISI];
    int sonuc[KOLON_SAYISI] = {cekilis[1],cekilis[2],cekilis[3],cekilis[4],cekilis[5],cekilis[6]};


    // Rastgele sayılarla çekiliş sonucunu oluşturma
int i, j;
for (i = 0; i < KOLON_SAYISI; i++) {
    int sayi;
    bool tekrar;
    
    do {
        sayi = rand() % 49 + 1;
        tekrar = false;
        
        for (j = 0; j < i; j++) {
            if (cekilis[j] == sayi) {
                tekrar = true;
                break;
            }
        }
    } while (tekrar);
    
    cekilis[i] = sayi;
}

    printf("Oynanan Sayısal Loto Kuponu:\n");
    printf("Kolon Sayı 1 Sayı 2 Sayı 3 Sayı 4 Sayı 5 Sayı 6\n");

    for (i = 0; i < KUPON_SATIRI; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < KOLON_SAYISI; j++) {
            printf("%d ", kupon[i][j]);
        }
        printf("\n");
    }

  
    printf("\n\nBilinenler Çıktısı:\n");
    printf("Kolon Bilinen Sayısı\n");

    int bilinen[KUPON_SATIRI] = {0};
    for (i = 0; i < KUPON_SATIRI; i++) {
        int sayac = 0;
        for (j = 0; j < KOLON_SAYISI; j++) {
            if (lineerArama(cekilis, KOLON_SAYISI, kupon[i][j])) {
                sayac++;
            }
        }
        printf("%d %d\n", i + 1, sayac);
        bilinen[sayac]++;
    }
    printf("\nHaftanın Çekiliş Sonucu:\n");
    printf("Sayı 1 Sayı 2 Sayı 3 Sayı 4 Sayı 5 Sayı 6\n");

    for (i = 0; i < KOLON_SAYISI; i++) {
        printf("%d ", cekilis[i]);
    }
    printf("\n\nSonuç Dizi Çıktısı:\n");
    printf("Bilinenler Sayısı\n");

    bubbleSort(bilinen, KOLON_SAYISI + 1);
    int toplam = 0;
    int satir=6;
        for (i = 1; i <= satir; i++) {
        int sayac = 0;
        for (j = 0; j < KOLON_SAYISI; j++) {
            if (lineerArama(sonuc, KOLON_SAYISI, kupon[i][j])) {
                sayac++;
            }
        }
        bilinen[sayac]++;
    }

    for (i = 0; i < KOLON_SAYISI; i++) {
        printf("%d %d\n", i+1, bilinen[6-i]);
            toplam += bilinen[6-i];
    }

    printf("Toplam %d\n", toplam);

    raporla(kupon, cekilis, KUPON_SATIRI);

    return 0;
}