#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

// ============================================================
//  ECZANE OTOMASYONU
//  Bagli Dogrusal Liste + Binary Dosyalama
// ============================================================

struct Ilac {
    int   id;
    char  ad[50];
    char  etkenMadde[50];
    char  uretici[50];
    float fiyat;
    int   stok;
    char  rafOmru[15];
};

struct Node {
    Ilac  veri;
    Node* sonraki;
};

Node* bas = NULL;

// ============================================================
void cizgi() {
    cout << "------------------------------------------------------------" << endl;
}

// ============================================================
//  1) KAYIT EKLEME
// ============================================================
void kayitEkle() {
    Node* yeni = new Node();

    cout << "\n[KAYIT EKLE]" << endl;
    cizgi();

    cout << "Ilac ID             : "; cin >> yeni->veri.id;
    cin.ignore();
    cout << "Ilac Adi            : "; cin.getline(yeni->veri.ad, 50);
    cout << "Etken Madde         : "; cin.getline(yeni->veri.etkenMadde, 50);
    cout << "Uretici Firma       : "; cin.getline(yeni->veri.uretici, 50);
    cout << "Fiyat (TL)          : "; cin >> yeni->veri.fiyat;
    cout << "Stok Adedi          : "; cin >> yeni->veri.stok;
    cin.ignore();
    cout << "Raf Omru (GG/AA/YYYY): "; cin.getline(yeni->veri.rafOmru, 15);

    yeni->sonraki = NULL;

    if (bas == NULL) {
        bas = yeni;
    } else {
        Node* tmp = bas;
        while (tmp->sonraki != NULL)
            tmp = tmp->sonraki;
        tmp->sonraki = yeni;
    }

    cout << "\n>> Ilac basariyla eklendi!" << endl;
}

// ============================================================
//  2) KAYIT LISTELEME
// ============================================================
void kayitListele() {
    cout << "\n[KAYIT LISTELE]" << endl;
    cizgi();

    if (bas == NULL) {
        cout << ">> Listede kayit bulunmamaktadir." << endl;
        return;
    }

    Node* tmp = bas;
    int   sira = 1;

    while (tmp != NULL) {
        cout << sira << ". ILAC" << endl;
        cout << "   ID             : " << tmp->veri.id         << endl;
        cout << "   Ad             : " << tmp->veri.ad         << endl;
        cout << "   Etken Madde    : " << tmp->veri.etkenMadde << endl;
        cout << "   Uretici        : " << tmp->veri.uretici    << endl;
        cout << "   Fiyat          : " << tmp->veri.fiyat << " TL" << endl;
        cout << "   Stok           : " << tmp->veri.stok       << endl;
        cout << "   Raf Omru       : " << tmp->veri.rafOmru    << endl;
        cizgi();
        tmp = tmp->sonraki;
        sira++;
    }
}

// ============================================================
//  3) KAYIT ARAMA
// ============================================================
void kayitAra() {
    cout << "\n[KAYIT ARAMA]" << endl;
    cizgi();
    cout << "1) ID ile ara" << endl;
    cout << "2) Ad ile ara" << endl;
    cout << "Seciminiz: ";

    int sec; cin >> sec; cin.ignore();

    Node* tmp    = bas;
    bool  bulundu = false;

    if (sec == 1) {
        int arananId;
        cout << "Aranacak ID: "; cin >> arananId;

        while (tmp != NULL) {
            if (tmp->veri.id == arananId) {
                bulundu = true;
                cout << "\n>> KAYIT BULUNDU:" << endl;
                cout << "   ID          : " << tmp->veri.id         << endl;
                cout << "   Ad          : " << tmp->veri.ad         << endl;
                cout << "   Etken Madde : " << tmp->veri.etkenMadde << endl;
                cout << "   Uretici     : " << tmp->veri.uretici    << endl;
                cout << "   Fiyat       : " << tmp->veri.fiyat << " TL" << endl;
                cout << "   Stok        : " << tmp->veri.stok       << endl;
                cout << "   Raf Omru    : " << tmp->veri.rafOmru    << endl;
                break;
            }
            tmp = tmp->sonraki;
        }

    } else if (sec == 2) {
        char arananAd[50];
        cout << "Aranacak Ilac Adi: "; cin.getline(arananAd, 50);

        while (tmp != NULL) {
            if (strcmp(tmp->veri.ad, arananAd) == 0) {
                bulundu = true;
                cout << "\n>> KAYIT BULUNDU:" << endl;
                cout << "   ID          : " << tmp->veri.id         << endl;
                cout << "   Ad          : " << tmp->veri.ad         << endl;
                cout << "   Etken Madde : " << tmp->veri.etkenMadde << endl;
                cout << "   Uretici     : " << tmp->veri.uretici    << endl;
                cout << "   Fiyat       : " << tmp->veri.fiyat << " TL" << endl;
                cout << "   Stok        : " << tmp->veri.stok       << endl;
                cout << "   Raf Omru    : " << tmp->veri.rafOmru    << endl;
                break;
            }
            tmp = tmp->sonraki;
        }

    } else {
        cout << ">> Gecersiz secim!" << endl;
        return;
    }

    if (!bulundu)
        cout << ">> Kayit bulunamadi." << endl;
}

// ============================================================
//  4) KAYIT GUNCELLEME
// ============================================================
void kayitGuncelle() {
    cout << "\n[KAYIT GUNCELLEME]" << endl;
    cizgi();

    if (bas == NULL) {
        cout << ">> Listede kayit bulunmamaktadir." << endl;
        return;
    }

    int arananId;
    cout << "Guncellenecek ilacin ID'si: "; cin >> arananId;
    cin.ignore();

    Node* tmp    = bas;
    bool  bulundu = false;

    while (tmp != NULL) {
        if (tmp->veri.id == arananId) {
            bulundu = true;
            char tampon[50];

            cout << "\nYeni bilgileri giriniz (Enter = degistirme):" << endl;

            cout << "Yeni Ad        [" << tmp->veri.ad << "]: ";
            cin.getline(tampon, 50);
            if (strlen(tampon) > 0) strcpy(tmp->veri.ad, tampon);

            cout << "Yeni Etken     [" << tmp->veri.etkenMadde << "]: ";
            cin.getline(tampon, 50);
            if (strlen(tampon) > 0) strcpy(tmp->veri.etkenMadde, tampon);

            cout << "Yeni Uretici   [" << tmp->veri.uretici << "]: ";
            cin.getline(tampon, 50);
            if (strlen(tampon) > 0) strcpy(tmp->veri.uretici, tampon);

            cout << "Yeni Fiyat  (0=degistirme) [" << tmp->veri.fiyat << "]: ";
            float yeniFiyat; cin >> yeniFiyat; cin.ignore();
            if (yeniFiyat > 0) tmp->veri.fiyat = yeniFiyat;

            cout << "Yeni Stok  (-1=degistirme) [" << tmp->veri.stok << "]: ";
            int yeniStok; cin >> yeniStok; cin.ignore();
            if (yeniStok >= 0) tmp->veri.stok = yeniStok;

            cout << "Yeni Raf Omru  [" << tmp->veri.rafOmru << "]: ";
            cin.getline(tampon, 15);
            if (strlen(tampon) > 0) strcpy(tmp->veri.rafOmru, tampon);

            cout << "\n>> Kayit basariyla guncellendi!" << endl;
            break;
        }
        tmp = tmp->sonraki;
    }

    if (!bulundu)
        cout << ">> Belirtilen ID'ye sahip kayit bulunamadi." << endl;
}

// ============================================================
//  5) KAYIT SILME
// ============================================================
void kayitSil() {
    cout << "\n[KAYIT SILME]" << endl;
    cizgi();

    if (bas == NULL) {
        cout << ">> Listede kayit bulunmamaktadir." << endl;
        return;
    }

    int arananId;
    cout << "Silinecek ilacin ID'si: "; cin >> arananId;

    Node* tmp    = bas;
    Node* onceki = NULL;

    while (tmp != NULL) {
        if (tmp->veri.id == arananId) {
            if (onceki == NULL)
                bas = tmp->sonraki;
            else
                onceki->sonraki = tmp->sonraki;

            delete tmp;
            cout << "\n>> Kayit basariyla silindi!" << endl;
            return;
        }
        onceki = tmp;
        tmp    = tmp->sonraki;
    }

    cout << ">> Belirtilen ID'ye sahip kayit bulunamadi." << endl;
}

// ============================================================
//  6) DOSYAYA AKTAR  (binary)
// ============================================================
void dosyayaAktar() {
    cout << "\n[DOSYAYA AKTAR]" << endl;
    cizgi();

    if (bas == NULL) {
        cout << ">> Aktarilacak kayit bulunmamaktadir." << endl;
        return;
    }

    FILE* dosya = fopen("eczane.bin", "wb");
    if (dosya == NULL) {
        cout << ">> Dosya acilamadi!" << endl;
        return;
    }

    Node* tmp  = bas;
    int   adet = 0;

    while (tmp != NULL) {
        fwrite(&tmp->veri, sizeof(Ilac), 1, dosya);
        tmp = tmp->sonraki;
        adet++;
    }

    fclose(dosya);
    cout << ">> " << adet << " kayit 'eczane.bin' dosyasina basariyla yazildi!" << endl;
}

// ============================================================
//  7) DOSYADAN AL  (binary)
// ============================================================
void dosyadanAl() {
    cout << "\n[DOSYADAN AL]" << endl;
    cizgi();

    FILE* dosya = fopen("eczane.bin", "rb");
    if (dosya == NULL) {
        cout << ">> Dosya bulunamadi! Once 'Dosyaya Aktar' yapiniz." << endl;
        return;
    }

    // Mevcut listeyi temizle
    Node* tmp = bas;
    while (tmp != NULL) {
        Node* sil = tmp;
        tmp = tmp->sonraki;
        delete sil;
    }
    bas = NULL;

    Ilac okunan;
    int  adet = 0;

    while (fread(&okunan, sizeof(Ilac), 1, dosya) == 1) {
        Node* yeni    = new Node();
        yeni->veri    = okunan;
        yeni->sonraki = NULL;

        if (bas == NULL) {
            bas = yeni;
        } else {
            Node* son = bas;
            while (son->sonraki != NULL)
                son = son->sonraki;
            son->sonraki = yeni;
        }
        adet++;
    }

    fclose(dosya);
    cout << ">> " << adet << " kayit dosyadan basariyla okundu ve listeye aktarildi!" << endl;
}

// ============================================================
//  ANA MENU
// ============================================================
void menuGoster() {
    cout << "\n============================================================" << endl;
    cout << "         ECZANE OTOMASYON SISTEMI  -  ANA MENU"              << endl;
    cout << "============================================================" << endl;
    cout << "  1) Ilac Kaydi Ekle"          << endl;
    cout << "  2) Ilac Kayitlarini Listele"  << endl;
    cout << "  3) Ilac Kaydi Ara"            << endl;
    cout << "  4) Ilac Kaydi Guncelle"       << endl;
    cout << "  5) Ilac Kaydi Sil"            << endl;
    cout << "  6) Kayitlari Dosyaya Aktar"   << endl;
    cout << "  7) Kayitlari Dosyadan Al"     << endl;
    cout << "  0) Cikis"                     << endl;
    cout << "============================================================" << endl;
    cout << "Seciminiz: ";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);

    int secim;

    do {
        menuGoster();
        cin >> secim;
        cin.ignore();

        switch (secim) {
            case 1: kayitEkle();     break;
            case 2: kayitListele();  break;
            case 3: kayitAra();      break;
            case 4: kayitGuncelle(); break;
            case 5: kayitSil();      break;
            case 6: dosyayaAktar();  break;
            case 7: dosyadanAl();    break;
            case 0: cout << "\n>> Sistemden cikiliyor. Gorusmek uzere!" << endl; break;
            default: cout << "\n>> Gecersiz secim, lutfen tekrar deneyiniz." << endl;
        }

    } while (secim != 0);

    // Bellek temizligi
    Node* tmp = bas;
    while (tmp != NULL) {
        Node* sil = tmp;
        tmp = tmp->sonraki;
        delete sil;
    }

    return 0;
}

