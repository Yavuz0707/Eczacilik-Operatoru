# 💊 Eczane Otomasyon Sistemi

Bu proje, bir eczanenin ilaç envanterini yönetmek için **C++** dili ile geliştirilmiş, dosya tabanlı bir yönetim sistemidir. Kullanıcıların ilaç eklemesine, listelemesine, aramasına, silmesine ve verileri güncellemesine olanak tanır.

---

## 🚀 Özellikler

Sistem aşağıdaki temel fonksiyonları yerine getirmektedir:

* **İlaç Girişi:** Yeni ilaç bilgilerini (Ad, Tür, Firma, Miktar, Fiyat) sisteme kaydeder.
* **Envanter Listesi:** Kayıtlı tüm ilaçları toplam sayı ile birlikte ekrana basar.
* **İlaç Arama:** İsim üzerinden spesifik bir ilacın detaylarına ulaşılmasını sağlar.
* **İlaç Silme:** Artık stokta bulunmayan ilaçları veritabanından kalıcı olarak kaldırır.
* **İlaç Düzeltme:** Kayıtlı ilaç bilgilerini güncel bilgilerle revize eder.

---

## 🛠 Kullanılan Teknolojiler

| Bileşen | Açıklama |
| :--- | :--- |
| **Dil** | C++ |
| **Dosya Yönetimi** | `fstream` (Binary modda `.dat` dosyası) |
| **Veri Yapısı** | `struct` (Eczane Nesne Yapısı) |
| **Kütüphaneler** | `iostream`, `cstring`, `conio.h`, `iomanip` |

---

## 📖 Kullanım Kılavuzu

### 1. Derleme ve Çalıştırma
Kodu herhangi bir C++ derleyicisinde (Dev-C++, Code::Blocks vb.) derleyip çalıştırın. Program ilk çalıştığında otomatik olarak `eczane.dat` veritabanı dosyasını oluşturacaktır.

### 2. Menü Navigasyonu
Program açıldığında aşağıdaki ana menü üzerinden işlemlerinizi yapabilirsiniz:

```text
|-------------MENU--------------|
|---------Secim Yapiniz---------|
|---------1-ilac Girisi---------|
|---------2-Envanter Listesi----|
|---------3-ilac Arama----------|
|---------4-ilac Silme----------|
|---------5-ilac Duzeltme-------|
|-------------------------------|
