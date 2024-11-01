#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int etap_sayisi = 3;
const int yarismaci_sayisi = 30;


struct Yarismaci {
    int sureler[etap_sayisi];
    int toplam_sure;
};


void yarismaciGirisiAl(Yarismaci yarismacilar[]) {
    for (int i = 0; i < yarismaci_sayisi; ++i) {
        cout << "Yarismaci " << i + 1 << " icin etap surelerini girin: " << endl;
        for (int j = 0; j < etap_sayisi; ++j) {
            yarismacilar[i].sureler[j] = rand() % 100;
            cout << "Etap " << j + 1 << " suresi: " << yarismacilar[i].sureler[j] << endl;
        }
    }
}


void toplamSureleriHesapla(Yarismaci yarismacilar[]) {
    for (int i = 0; i < yarismaci_sayisi; ++i) {
        yarismacilar[i].toplam_sure = 0;
        for (int j = 0; j < etap_sayisi; ++j) {
            yarismacilar[i].toplam_sure += yarismacilar[i].sureler[j];
        }
    }
}


void enHizliYarismaci(Yarismaci yarismacilar[]) {
    int en_hizli_index = 0;
    for (int i = 1; i < yarismaci_sayisi; ++i) {
        if (yarismacilar[i].toplam_sure < yarismacilar[en_hizli_index].toplam_sure) {
            en_hizli_index = i;
        }
    }
    cout << "Yarismayi en hizli bitiren yarismaci: " << en_hizli_index + 1 << endl;
}


void enHizliEtaplar(Yarismaci yarismacilar[]) {
    for (int i = 0; i < etap_sayisi; ++i) {
        int en_hizli_index = 0;
        for (int j = 1; j < yarismaci_sayisi; ++j) {
            if (yarismacilar[j].sureler[i] < yarismacilar[en_hizli_index].sureler[i]) {
                en_hizli_index = j;
            }
        }
        cout << "Etap " << i + 1 << "'de en hizli yarismaci: " << en_hizli_index + 1 << endl;
    }
}


double etapOrtalamalariHesapla(Yarismaci yarismacilar[], int etap_index) {
    double toplam = 0;
    for (int i = 0; i < yarismaci_sayisi; ++i) {
        toplam += yarismacilar[i].sureler[etap_index];
    }
    return toplam / yarismaci_sayisi;
}


void etapOrtalamasininAltindaBitirenler(Yarismaci yarismacilar[]) {
    for (int i = 0; i < etap_sayisi; ++i) {
        double ortalama = etapOrtalamalariHesapla(yarismacilar, i);
        cout << "Etap " << i + 1 << "'de etap ortalamasinin altinda bitiren yarismacilar: ";
        for (int j = 0; j < yarismaci_sayisi; ++j) {
            if (yarismacilar[j].sureler[i] < ortalama) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    Yarismaci yarismacilar[yarismaci_sayisi];

    yarismaciGirisiAl(yarismacilar);
    toplamSureleriHesapla(yarismacilar);

    enHizliYarismaci(yarismacilar);
    enHizliEtaplar(yarismacilar);
    etapOrtalamasininAltindaBitirenler(yarismacilar);

    return 0;
}
