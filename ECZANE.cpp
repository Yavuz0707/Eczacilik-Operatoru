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
		cout<<"|---------SeCim Yap�n�z---------|"<<endl;
		cout<<"|---------1-ilac Girisi---------|"<<endl;
		cout<<"|---------2-Envanter Listesi----|"<<endl;
		cout<<"|---------3-ilac Arama----------|"<<endl;
		cout<<"|---------4-ia� Silme-----------|"<<endl;
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
		
	cout<<"�lac Adi Giriniz: "<<endl;	
	cin>>eczane.ilac_isim;
	cout<<"�lac T�r�n� Giriniz: "<<endl;	
	cin>>eczane.ilac_tur;
	cout<<"�lac Firma Ad� Giriniz: "<<endl;
	cin>>eczane.firma;	
	cout<<"�lac Miktarini Giriniz: "<<endl;	
	cin>>eczane.miktar;
	cout<<"�lac Fiyatini Giriniz: "<<endl;
	cin>>eczane.fiyat;	
		
	cout<<endl;
	
	yaz.write((char*)&eczane, sizeof(eczane));
	adet++;
	
	cout<<"Ba�ka �lac Girisi Yapmak �stermisiniz? (E/H)"<<endl;	
	secim=getche();
	
	cout<<endl;	
	}
	while(secim=='e' || secim=='E');
	
	cout<<adet<<"Adet �la� Girisi Yap�ld�."<<endl;
	
	yaz.close();	
	
}

void ilac_liste()
{

   ifstream oku("eczane.dat",ios::binary | ios::app);
   
   oku.seekg(0,ios::end);
   int liste=oku.tellg()/sizeof(eczane);
   cout<<endl;
   
   cout<<"Toplam �lac Say�s�: "<<liste<<endl;
   
   if(liste>0)
   {
   	for(int i=0;i<liste;i++)
	   {
	   		oku.seekg(i*sizeof(eczane));
	   		oku.read((char*)&eczane,sizeof(eczane));
	   		
	   		cout<<"----------"<<i+1<<". �lac B�lgileri----------"<<endl;
	   		
	   		cout<<"�lac Ad:"<<eczane.ilac_isim<<endl;
	   		
	   		cout<<"�lac T�r:"<<eczane.ilac_tur<<endl;
	   		
	   		cout<<"�lac Firma:"<<eczane.firma<<endl;
	   		
	   		cout<<"�lac Miktar:"<<eczane.miktar<<endl;
	   		
	   		cout<<"�lac Fiyat"<<eczane.fiyat<<endl;
	   }
   }
   else
   cout<<"!!KAYITLI �LAC BULUNAMADI!!"<<endl;
oku.close();
}

void ilac_Arama()
{
	
	ifstream oku("eczane.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(eczane);


cout <<"Aranan �lac�n �smini Giriniz"<< endl;
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
			cout <<  "Bulunan �lac�n Bilgileri"<< endl;
			cout << "�lac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "�lac Firma: "<< eczane.firma <<endl ;
			cout << "�lac T�r: "<< eczane.ilac_tur<<endl ;
			cout << "�lac Miktar: "<<eczane.miktar<<endl;
			cout << "�lac Fiyat: "<<eczane.fiyat<<endl;
						
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
	
	cout<<"Silinecek �lac�n �smini Giriniz."<<endl;
	cin>>ilac_isim;
	
	bool var=false;
	
	if(silme>0){
		
		for(int i=0; i<silme;i++){
			
			oku.seekg(i*sizeof(eczane));
			oku.read((char*)&eczane,sizeof(eczane));
			
			if(strcmp(eczane.ilac_isim,ilac_isim)==0){
				
				cout<<"Silinecek �la� Bilgileri"<<endl;
				
			cout << "�lac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "�lac Firma: "<< eczane.firma <<endl ;
			cout << "�lac Tur: "<< eczane.ilac_tur<<endl ;
			cout << "�lac Miktar: "<<eczane.miktar<<endl;
			cout << "�lac Fiyat: "<<eczane.fiyat<<endl;
			
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
			
			cout<<"Kay�t Silindi !!!"<<endl;
			
		}
	}
	
	else{
		cout<<"Kay�t Yok!!!"<<endl;
		
	}
	
	
}

void ilac_duzeltme(){
	
	ifstream oku("eczane.dat", ios::app | ios::binary);
	
	oku.seekg(0,ios::end);
	int duzeltme=oku.tellg()/sizeof(eczane);
	
	char secim;
	
	char ilac_isim[100];
	
	cout<<endl;
	
	cout<<"D�zeltilecek �lac�n �smini Giriniz:"<<endl;
	
	cin>>ilac_isim;
	
	bool var=false;
	
	if(duzeltme>0){
		
		for(int i=0; i<duzeltme;i++){
			
			
			oku.seekg(i*sizeof(eczane));
			
			oku.read((char*)&eczane,sizeof(eczane));
			
			if(strcmp(eczane.ilac_isim,ilac_isim)==0){
				
			cout<<"D�zeltilecek �la� Bilgileri Giriniz"<<endl;
				
			cout << "�lac Adi: "<< eczane.ilac_isim <<endl ;
			cout << "�lac Firma: "<< eczane.firma <<endl ;
			cout << "�lac T�r: "<< eczane.ilac_tur<<endl ;
			cout << "�lac Miktar: "<<eczane.miktar<<endl;
			cout << "�lac Fiyat: "<<eczane.fiyat<<endl;
			
			cout<<"D�zeltilecek �la� Bu mu? (E/H)"<<endl;
			
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
				
	            cout<<"�lac Ad� Giriniz:"<<endl;	
	            cin>>eczane.ilac_isim;
	            cout<<"�lac T�r�n� Giriniz:"<<endl;	
	            cin>>eczane.ilac_tur;
	            cout<<"�lac Firma Ad� Giriniz:"<<endl;
	            cin>>eczane.firma;	
	            cout<<"�lac Miktar�n�:"<<endl;	
	            cin>>eczane.miktar;
	            cout<<"�lac Fiyat�n�:"<<endl;
				cin>>eczane.fiyat;	
			    
			    y_yaz.write((char*)&eczane,sizeof(eczane));
			    y_yaz.close();
			    
			}	
			
			}
		oku.close();
		if(var){
			
			remove("eczane.dat");
			rename("Yedek.dat","eczane.dat");
			cout<<"D�zeltildi..."<<endl;
			
			
		}
		
	}
}

	
	
	


