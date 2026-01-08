#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Karekök işlemleri için

#define PI 3.14159

// --- FONKSİYONLAR ---
// Tüm deneyler ayrı fonksiyon olacak şekilde ve yerçekimi dizisi pointer olarak girilmiştir.
void serbestDusme(double *g_ptr, char (*isimler)[15]);
void yukariAtis(double *g_ptr, char (*isimler)[15]);
void agirlikHesapla(double *g_ptr, char (*isimler)[15]);
void potansiyelEnerji(double *g_ptr, char (*isimler)[15]);
void hidrostatikBasinc(double *g_ptr, char (*isimler)[15]);
void arsimetKaldirma(double *g_ptr, char (*isimler)[15]);
void basitSarkac(double *g_ptr, char (*isimler)[15]);
void ipGerilmesi(double *g_ptr, char (*isimler)[15]);
void asansorDeneyi(double *g_ptr, char (*isimler)[15]);

int main() {
    // Yerçekimi ivmeleri bir dizi içinde tutulmuştur (Güneş'e yakınlık sırasıyla).
    // Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün
    double g_ivmeleri[8] = {3.7, 8.87, 9.80, 3.71, 24.79, 10.44, 8.69, 11.15};

    // Gezegen isimlerini yazdırmak için ek dizi oluşturulmuştur.
    char gezegenler[8][15] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

    char bilimInsani[50];
    int secim;

    printf("--- UZAY SIMULASYONU BASLIYOR ---\n");
    printf("Lutfen bilim insaninin adini ve soyadini giriniz: ");

    scanf(" %[^\n]", bilimInsani);

    do {
        printf("\n-------------------------------------------------\n");
        printf("Sayin %s, lutfen yapmak istediginiz deneyi seciniz:\n", bilimInsani);
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("-1. Cikis\n");
        printf("\n\n");
        printf("Seciminiz: ");

        // Tek bir scanf ile veri hem okuyor hem kontrol ediliyor.
        // Eğer sayı girilmezse (harf yada sembol girilirse) if'in içine girip temizliyor
        if (scanf("%d", &secim) != 1) {
            while(getchar() != '\n'); // Tampon belleği temizle (enter'a kadar olan harfleri yutar)
            secim = 0; // Programın kırılmaması için geçersiz bir sayı verilmiştir
        }

        printf("-------------------------------------------------\n");

        switch (secim) {
            case 1: serbestDusme(g_ivmeleri, gezegenler); break;
            case 2: yukariAtis(g_ivmeleri, gezegenler); break;
            case 3: agirlikHesapla(g_ivmeleri, gezegenler); break;
            case 4: potansiyelEnerji(g_ivmeleri, gezegenler); break;
            case 5: hidrostatikBasinc(g_ivmeleri, gezegenler); break;
            case 6: arsimetKaldirma(g_ivmeleri, gezegenler); break;
            case 7: basitSarkac(g_ivmeleri, gezegenler); break;
            case 8: ipGerilmesi(g_ivmeleri, gezegenler); break;
            case 9: asansorDeneyi(g_ivmeleri, gezegenler); break;
            case -1: printf("Simulasyondan cikiliyor. Iyi gunler dileriz!\n"); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }

    } while (secim!= -1); // -1 girilene kadar döngü devam eder

    return 0;
}

// --- FONKSIYON GÖVDELERI ---

// 1. Serbest Düşme
void serbestDusme(double*g_ptr, char(*isimler)[15]){
    double t,h;
    printf("Dusme suresini (t) saniye cinsinden giriniz: ");
    scanf("%lf",&t);

    // Negatif kontrolü Ternary Operator ile yapılmıştır.
    t=(t<0)?-t:t;

    printf("\n--- Serbest Dusme Sonuclari ---\n");
    for(int i=0;i<8;i++){
        // Dizi elemanlarına pointer aritmetiği ile ulaşılmıştır *(g_ptr+i)
        double g=*(g_ptr+i);
        h=0.5*g*t*t;
        printf("%-10s gezegeninde dusulen yol (h): %.2f m\n",*(isimler+i),h);
    }
}

// 2. Yukarı Atış
void yukariAtis(double *g_ptr, char (*isimler)[15]){
    double v0, h_max;
    printf("Firlatma hizini (v0) m/s cinsinden giriniz: ");
    scanf("%lf",&v0);

    // Hızın karesi alndığı için sonuç değişmese de, ternary ile ek kontrol sağlanmıştır.
     v0=(v0<0)?-v0:v0;

    printf("\n--- Yukari Atis Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g =*(g_ptr+i);
        h_max =(v0*v0)/(2*g);
        printf("%-10s gezegeninde max yukseklik (h_max): %.2f m\n", *(isimler + i),h_max);
    }
}

// 3. Ağırlık Deneyi
void agirlikHesapla(double *g_ptr, char (*isimler)[15]) {
    double m, G;
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);

    //Negatif kütle kontrolü ternary ifadesi ile sağlanmıştır.
    m=(m<0)?-m:m;

    printf("\n--- Agirlik Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g=*(g_ptr+i);
        G=m*g;
        printf("%-10s gezegeninde agirlik (G): %.2f Newton\n", *(isimler +i),G);
    }
}

// 4. Kütleçekimsel Potansiyel Enerji
void potansiyelEnerji(double*g_ptr, char(*isimler)[15]){
    double m,h,Ep;
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf",&m);
    printf("Yuksekligi (h) metre cinsinden giriniz: ");
    scanf("%lf",&h);

    m=(m<0)?-m:m;
    h=(h<0)?-h:h;

    printf("\n--- Potansiyel Enerji Sonuclari ---\n");
    for(int i=0;i<8;i++) {
        double g=*(g_ptr+i);
        Ep=m*g*h;
        printf("%-10s gezegeninde enerji (Ep): %.2f Joule\n", *(isimler + i),Ep);
    }
}

// 5. Hidrostatik Basınç
void hidrostatikBasinc(double *g_ptr, char (*isimler)[15]) {
    double ro,h,P;
    printf("Sivinin yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    scanf("%lf",&ro);
    printf("Derinligi (h) metre cinsinden giriniz: ");
    scanf("%lf",&h);

    ro=(ro<0)?-ro:ro;
    h=(h<0)?-h:h;

    printf("\n--- Hidrostatik Basinc Sonuclari ---\n");
    for(int i=0;i<8;i++) {
        double g=*(g_ptr+i);
        P=ro*g*h;
        printf("%-10s gezegeninde basinc (P): %.2f Pascal\n", *(isimler+i),P);
    }
}

// 6. Arşimet Kaldırma Kuvveti
void arsimetKaldirma(double *g_ptr, char (*isimler)[15]){
    double ro,V,Fk;
    printf("Sivinin yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    scanf("%lf",&ro);
    printf("Batan hacmi (V) m^3 cinsinden giriniz: ");
    scanf("%lf",&V);

    ro=(ro<0)?-ro:ro;
    V=(V<0)?-V:V;

    printf("\n--- Kaldirma Kuvveti Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g=*(g_ptr+i);
        Fk=ro*g*V;
        printf("%-10s gezegeninde kaldirma kuvveti (Fk): %.2f Newton\n", *(isimler + i),Fk);
    }
}

// 7. Basit Sarkaç
void basitSarkac(double *g_ptr, char (*isimler)[15]) {
    double L,T;
    printf("Sarkacin uzunlugunu (L) metre cinsinden giriniz: ");
    scanf("%lf", &L);

    L=(L<0)?-L:L;

    printf("\n--- Basit Sarkac Periyodu Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g=*(g_ptr+i);
        // T=2*pi*sqrt(L / g)
        T=2*PI*sqrt(L/g);
        printf("%-10s gezegeninde periyot (T): %.2f saniye\n", *(isimler+i),T);
    }
}

// 8. Sabit Ip Gerilmesi
void ipGerilmesi(double *g_ptr, char (*isimler)[15]) {
    double m,T;
    printf("Asili cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);

    m=(m<0)?-m:m;

    printf("\n--- Ip Gerilmesi Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g=*(g_ptr+i);
        T=m*g;// F = m*g
        printf("%-10s gezegeninde ip gerilmesi (T): %.2f Newton\n", *(isimler + i),T);
    }
}

// 9. Asansör Deneyi
void asansorDeneyi(double *g_ptr, char (*isimler)[15]) {
    double m,a,N;
    int durum;

    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf",&m);
    printf("Asansorun ivmesini (a) m/s^2 cinsinden giriniz: ");
    scanf("%lf",&a);

    m=(m<0)?-m:m;
    a=(a<0)?-a:a;

    printf("Asansorun hareket durumunu seciniz:\n");
    printf("1. Yukari Hizlanan VEYA Asagi Yavaslayan (mg + ma)\n");
    printf("2. Asagi Hizlanan VEYA Yukari Yavaslayan (mg - ma)\n");
    printf("Secim: ");
    scanf("%d",&durum);

    printf("\n--- Asansor Deneyi Sonuclari ---\n");
    for(int i=0;i<8;i++){
        double g=*(g_ptr+i);

        if (durum==1) {
            // N=m(g+a)
            N=m*(g+a);
        } else {
            // N=m(g-a)
            N=m*(g-a);
            // Fiziksel olarak yüzey tepkisi negatif olamaz ama formül gereği direkt yazdırıyoruz.
        }

        printf("%-10s gezegeninde hissedilen agirlik (N): %.2f Newton\n", *(isimler + i),N);
    }
}
