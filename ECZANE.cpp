#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <locale.h>


//SUKRU YAVUZ
//2312729015
//ECZANE OTOMASYONU



using namespace std;

void ilac_girisi();

void ilac_liste();

void ilac_Arama();

void ilac_silme();

void ilac_duzeltme();

struct Eczane{
	
	char ilac_tur[100];
	char ilac_isim[100];
	char firma[100];
    float miktar;
	float fiyat;
	
};

Eczane eczane;

int main(){
	
	setlocale(LC_ALL,"Turkish");
	
	char secim;
	
	do{
		
		
		system ("cls");
		
		cout<<"|-------------MENU--------------|"<<endl;
		cout<<"|---------SeCim Yapýnýz---------|"<<endl;
		cout<<"|---------1-ilac Girisi---------|"<<endl;
		cout<<"|---------2-Envanter Listesi----|"<<endl;
		cout<<"|---------3-ilac Arama----------|"<<endl;
		cout<<"|---------4-iaç Silme-----------|"<<endl;
		cout<<"|---------5-ilac Duzeltme-------|"<<endl;
		cout<<"|-------------------------------|"<<endl;
		
		cout<<endl;
		
		cout<<"Secim giriniz"<<endl;
		
		cout<<endl;
		
		secim=getche();
		
		switch(secim){
			
			case '1':{
				
			 ilac_girisi();
				
				
				break;
			}
			case '2':{
				
			 ilac_liste();
				
				
				break;
			}
			case '3':{
				
				
			 ilac_Arama();
				
				break;
			}
			case '4':{
				
			 ilac_silme();
				
				
				break;
			}
		    case '5':{
				
			 ilac_duzeltme();	
				
				
				break;
			}
		
		
	}   
	cout<<endl;
	cout<<"Ana Menuye Donmek Istermisin?(E/H)"<<endl;
	
	secim=getche();
}

    while(secim=='e' || secim=='E');
	
	
	return 0;
}


void ilac_girisi(){
	
	ofstream yaz("eczane.dat",ios::binary | ios::app);
	
	char secim;
	int adet=0;
	
	do{
	
	cout<<endl;
		
	cout<<"Ýlac Adi Giriniz: "<<endl;	
	cin>>eczane.ilac_isim;
	cout<<"Ýlac Türünü Giriniz: "<<endl;	
	cin>>eczane.ilac_tur;
	cout<<"Ýlac Firma Adý Giriniz: "<<endl;
	cin>>eczane.firma;	
	cout<<"Ýlac Miktarini Giriniz: "<<endl;	
	cin>>eczane.miktar;
	cout<<"Ýlac Fiyatini Giriniz: "<<endl;
	cin>>eczane.fiyat;	
		
	cout<<endl;
	
	yaz.write((char*)&eczane, sizeof(eczane));
	adet++;
	
	cout<<"Baþka Ýlac Girisi Yapmak Ýstermisiniz? (E/H)"<<endl;	
	secim=getche();
	
	cout<<endl;	
	}
	while(secim=='e' || secim=='E');
	
	cout<<adet<<"Adet Ýlaç Girisi Yapýldý."<<endl;
	
	yaz.close();	
	
}

void ilac_liste()
{

   ifstream oku("eczane.dat",ios::binary | ios::app);
   
   oku.seekg(0,ios::end);
   int liste=oku.tellg()/sizeof(eczane);
   cout<<endl;
   
   cout<<"Toplam Ýlac Sayýsý: "<<liste<<endl;
   
   if(liste>0)
   {
   	for(int i=0;i<liste;i++)
	   {
	   		oku.seekg(i*sizeof(eczane));
	   		oku.read((char*)&eczane,sizeof(eczane));
	   		
	   		cout<<"----------"<<i+1<<". Ýlac BÝlgileri----------"<<endl;
	   		
	   		cout<<"Ýlac Ad:"<<eczane.ilac_isim<<endl;
	   		
	   		cout<<"Ýlac Tür:"<<eczane.ilac_tur<<endl;
	   		
	   		cout<<"Ýlac Firma:"<<eczane.firma<<endl;
	   		
	   		cout<<"Ýlac Miktar:"<<eczane.miktar<<endl;
	   		
	   		cout<<"Ýlac Fiyat"<<eczane.fiyat<<endl;
	   }
   }
   else
   cout<<"!!KAYITLI ÝLAC BULUNAMADI!!"<<endl;
oku.close();
}

void ilac_Arama()
{
	
	ifstream oku("eczane.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(eczane);


cout <<"Aranan Ýlacýn Ýsmini Giriniz"<< endl;
char ilac_isim[100];
cin>> ilac_isim;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(eczane));
			oku.read((char*)&eczane, sizeof(eczane));
			
			if(strcmp(eczane.ilac_isim,ilac_isim)==0)
			{
			cout <<  "Bulunan Ýlacýn Bilgileri"<< endl;
			cout << "Ýlac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "Ýlac Firma: "<< eczane.firma <<endl ;
			cout << "Ýlac Tür: "<< eczane.ilac_tur<<endl ;
			cout << "Ýlac Miktar: "<<eczane.miktar<<endl;
			cout << "Ýlac Fiyat: "<<eczane.fiyat<<endl;
						
		    }
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}

void ilac_silme(){
	
	ifstream oku("eczane.dat",ios::app | ios::binary);
	
	oku.seekg(0,ios::end);
	
	int silme=oku.tellg()/sizeof(eczane);
	
	char secim;
	
	char ilac_isim[100];
	
	cout<<endl;
	
	cout<<"Silinecek Ýlacýn Ýsmini Giriniz."<<endl;
	cin>>ilac_isim;
	
	bool var=false;
	
	if(silme>0){
		
		for(int i=0; i<silme;i++){
			
			oku.seekg(i*sizeof(eczane));
			oku.read((char*)&eczane,sizeof(eczane));
			
			if(strcmp(eczane.ilac_isim,ilac_isim)==0){
				
				cout<<"Silinecek Ýlaç Bilgileri"<<endl;
				
			cout << "Ýlac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "Ýlac Firma: "<< eczane.firma <<endl ;
			cout << "Ýlac Tur: "<< eczane.ilac_tur<<endl ;
			cout << "Ýlac Miktar: "<<eczane.miktar<<endl;
			cout << "Ýlac Fiyat: "<<eczane.fiyat<<endl;
			
			cout<<"Emin Misiniz? (E/H)"<<endl;
			
			secim=getche();
			
			if(secim=='h' || secim=='H'){
				
				ofstream y_yaz("Yedek.dat",ios::app | ios::binary);
				
				y_yaz.write((char*)&eczane,sizeof(eczane));
				y_yaz.close();
			}
			else if(secim=='e' || secim=='E'){
				
				var=true;
			}
			}
			
			else{
				
				ofstream y_yaz("Yedek.dat",ios::app | ios::binary);
				
				y_yaz.write((char*)&eczane,sizeof(eczane));
				y_yaz.close();
			}
		}
		
		oku.close();
		if(var){
			
			remove("eczane.dat");
			rename("Yedek.dat","eczane.dat");
			
			cout<<"Kayýt Silindi !!!"<<endl;
			
		}
	}
	
	else{
		cout<<"Kayýt Yok!!!"<<endl;
		
	}
	
	
}

void ilac_duzeltme(){
	
	ifstream oku("eczane.dat", ios::app | ios::binary);
	
	oku.seekg(0,ios::end);
	int duzeltme=oku.tellg()/sizeof(eczane);
	
	char secim;
	
	char ilac_isim[100];
	
	cout<<endl;
	
	cout<<"Düzeltilecek Ýlacýn Ýsmini Giriniz:"<<endl;
	
	cin>>ilac_isim;
	
	bool var=false;
	
	if(duzeltme>0){
		
		for(int i=0; i<duzeltme;i++){
			
			
			oku.seekg(i*sizeof(eczane));
			
			oku.read((char*)&eczane,sizeof(eczane));
			
			if(strcmp(eczane.ilac_isim,ilac_isim)==0){
				
			cout<<"Düzeltilecek Ýlaç Bilgileri Giriniz"<<endl;
				
			cout << "Ýlac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "Ýlac Firma: "<< eczane.firma <<endl ;
			cout << "Ýlac Tür: "<< eczane.ilac_tur<<endl ;
			cout << "Ýlac Miktar: "<<eczane.miktar<<endl;
			cout << "Ýlac Fiyat: "<<eczane.fiyat<<endl;
			
			cout<<"Düzeltilecek Ýlaç Bu mu? (E/H)"<<endl;
			
			secim=getche();
		}
			
			if(secim=='h'|| secim=='H'){
				
				ofstream y_yaz("Yedek.dat",ios::app | ios::binary);
				
				y_yaz.write((char*)&eczane,sizeof(eczane));
				y_yaz.close();
				
			}
			else if(secim=='e' || secim=='E'){
				
				
				var=true;
				ofstream y_yaz("Yedek.dat",ios::app | ios::binary);
				
	            cout<<"Ýlac Adý Giriniz:"<<endl;	
	            cin>>eczane.ilac_isim;
	            cout<<"Ýlac Türünü Giriniz:"<<endl;	
	            cin>>eczane.ilac_tur;
	            cout<<"Ýlac Firma Adý Giriniz:"<<endl;
	            cin>>eczane.firma;	
	            cout<<"Ýlac Miktarýný:"<<endl;	
	            cin>>eczane.miktar;
	            cout<<"Ýlac Fiyatýný:"<<endl;
				cin>>eczane.fiyat;	
			    
			    y_yaz.write((char*)&eczane,sizeof(eczane));
			    y_yaz.close();
			    
			}	
			
			}
		oku.close();
		if(var){
			
			remove("eczane.dat");
			rename("Yedek.dat","eczane.dat");
			cout<<"Düzeltildi..."<<endl;
			
			
		}
		
	}
}

	
	
	


