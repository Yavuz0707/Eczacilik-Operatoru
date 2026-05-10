# Eczacilik Operatoru

Eczacilik Operatoru, temel eczane envanter islemlerini komut satiri uzerinden yonetmek icin hazirlanmis bir C++ otomasyon projesidir. Proje; ilac kaydi ekleme, kayitlari listeleme, ilac arama, kayit silme, kayit guncelleme ve kayitlari binary dosyaya aktarma gibi temel stok takip adimlarini sade bir menu yapisi ile sunar.

Bu README, projenin amacini, calisma mantigini, kullanilan veri yapisini, derleme adimlarini ve gelistirme notlarini aciklar.

## Projenin Amaci

Eczanelerdeki ilac bilgilerinin basit ve anlasilir bir sistem uzerinden takip edilebilmesini saglamak hedeflenmistir. Uygulama ozellikle C++ dilinde dosya islemleri, struct kullanimi, menu tabanli programlama ve temel CRUD mantigini ogrenmek isteyenler icin egitici bir ornektir.

## Temel Ozellikler

- Ilac kaydi ekleme
- Mevcut ilac envanterini listeleme
- Ilac adina gore arama yapma
- Kayitli ilac bilgisini silme
- Ilac bilgilerini guncelleme
- Ilac bilgilerini `eczane.bin` dosyasina aktarma
- `eczane.bin` dosyasindan kayitlari tekrar listeye alma
- Menu tabanli konsol arayuzu

## Kayit Altina Alinan Bilgiler

Her ilac kaydi icin asagidaki bilgiler tutulur:

| Alan | Aciklama |
| --- | --- |
| ID | Ilacin benzersiz kayit numarasi |
| Ilac adi | Ilacin sistemde gorunen adi |
| Etken madde | Ilacin etken madde bilgisi |
| Uretici firma | Ilaci ureten veya dagitan firma |
| Fiyat | Ilacin satis fiyati |
| Stok | Stoktaki ilac adedi |
| Raf omru | Ilacin raf omru veya son kullanim tarihi bilgisi |

## Kullanilan Teknolojiler

| Teknoloji | Aciklama |
| --- | --- |
| C++ | Ana programlama dili |
| Struct | Ilac kayitlarini modellemek icin kullanilir |
| Bagli liste | Kayitlari bellekte sirali sekilde tutmak icin kullanilir |
| Binary dosya islemleri | Dosya okuma ve yazma islemleri icin kullanilir |
| Binary dosyalama | Kayitlarin kalici olarak saklanmasini saglar |
| Konsol arayuzu | Kullanicinin menu uzerinden islem yapmasini saglar |

## Calisma Mantigi

Uygulama acildiginda kullaniciya bir ana menu gosterilir. Kullanici bu menu uzerinden yapmak istedigi islemi secer.

Ornek menu akisinda su islemler bulunur:

```text
1 - Ilac Girisi
2 - Envanter Listesi
3 - Ilac Arama
4 - Ilac Silme
5 - Ilac Duzeltme
6 - Kayitlari Dosyaya Aktar
7 - Kayitlari Dosyadan Al
0 - Cikis
```

Kayit ekleme isleminde kullanicidan ilac ID'si, adi, etken maddesi, uretici firma bilgisi, fiyat, stok adedi ve raf omru alinir. Bu bilgiler bagli liste yapisina aktarilir. Kullanici isterse kayitlari `eczane.bin` dosyasina yazabilir veya daha once kaydedilen verileri dosyadan tekrar okuyabilir.

## Kurulum

Projeyi bilgisayariniza almak icin:

```bash
git clone https://github.com/Yavuz0707/Eczacilik-Operatoru.git
cd Eczacilik-Operatoru
```

## Derleme

Proje C++ ile yazildigi icin bir C++ derleyicisine ihtiyac vardir. Kaynak kod repo kok dizininde `Untitled1.cpp` dosyasinda bulunur.

### g++ ile derleme

```bash
g++ Untitled1.cpp -o EczacilikOperatoru
```

Windows uzerinde calistirmak icin:

```bash
EczacilikOperatoru.exe
```

Linux veya macOS uzerinde calistirmak icin:

```bash
./EczacilikOperatoru
```

> Not: Proje Windows konsol ortaminda gelistirilmistir ve `windows.h` uzerinden konsol kod sayfasi ayari yapar. Linux veya macOS uzerinde derleme icin bu kisimda kucuk uyarlamalar gerekebilir.

## Kullanim

1. Programi calistirin.
2. Ana menuden yapmak istediginiz islemi secin.
3. Ilac bilgilerini istenen alanlara girin.
4. Listeleme ve arama secenekleriyle kayitlari kontrol edin.
5. Gerekirse silme veya duzeltme seceneklerini kullanarak envanteri guncelleyin.

## Dosya Tabanli Kayit Sistemi

Uygulama kayitlari dosya tabanli olarak saklar. Bu yapi sayesinde program kapatilsa bile kaydedilen ilac bilgileri sonraki calistirmalarda tekrar okunabilir.

Dosya tabanli yaklasimin avantajlari:

- Veriler program kapandiktan sonra da korunur.
- Harici bir veritabani kurulumu gerektirmez.
- C++ dosya islemlerini ogrenmek icin sade bir ornek sunar.

## Proje Kazanimlari

Bu proje ile asagidaki konular pratik edilir:

- C++ temel giris/cikis islemleri
- Struct ile veri modelleme
- Bagli liste mantigi
- Fonksiyonlara bolunmus program tasarimi
- Dosya okuma ve yazma
- Binary dosya kullanimi
- CRUD islemleri
- Menu tabanli konsol uygulamasi gelistirme

## Gelistirme Fikirleri

Projeyi daha ileri tasimak icin su ozellikler eklenebilir:

- Ilac ID sistemi
- Stok azalinca uyari verme
- Son kullanma tarihi takibi
- Firma bazli filtreleme
- Fiyat araligina gore arama
- Daha guclu hata kontrolleri
- Verileri CSV olarak disa aktarma
- Kullanici girisi ve yetkilendirme
- Grafik arayuz
- SQLite veya benzeri bir veritabani entegrasyonu

## Lisans

Bu proje egitim amacli hazirlanmistir. Kullanim, gelistirme ve inceleme amaciyla serbestce degerlendirilebilir.
