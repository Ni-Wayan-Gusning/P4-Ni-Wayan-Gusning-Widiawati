#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//deklarasi
char barang[17][20]= {"AIR MINERAL","ES MILO","CAPPUCINO ","ES CAMPUR","ICE CREAM ","ES JERUK","JUS JERUK","JUS MANGGA","JUS ALPUKAT","KOPI SENJA","KOPI STANDAR","KOPI MOKACINO","KOPI KAPUCINO","KOPI SUSU","BOBA MILK","MILKSHAKE",};
int harga[]={4,6,8,20,7,5,5,12,12,14,25,15,17,18,20,23,};
int stok[]={55,30,30,30,25,26,27,32,0,26,46,33,24,28,36,16,};
char cart_barang[100][20];
int cart_harga[100];
int jumlah,indeks=-1;
char nama[20];
//tampilan menu utama
void menuawal(char barang[16][20],int harga[],int stok[]){
printf (" ============== SELAMAT DATANG ===============\n");
	printf (" =======================================================================\n");
printf ("| KODE\t|\tLIST MENU\t|\tHARGA MENU\t|   PERSEDIAAN  | \n");
    printf (" =======================================================================\n");
	for(int i=0;i<17;i++){
        printf ("| %d \t|\t%s\t|\tRp.%d.000\t|\t%d\t| \n", i,barang[i],harga[i],stok[i]);
		}
    printf (" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void namapembeli(){
	printf("MASUKKAN NAMA PEMBELI : ");
    scanf ("%s",&nama);
    printf("\n");
}
//transksaksi pembelian
int beli(){
    char lagi;
    
    do{
int kode;
        printf ("MASUKKAN KODE MENU : ");
        scanf ("%d", &kode);
        if (kode>16){
        	printf ("KODE YANG ANDA MASUKKAN SALAH\n");	
	} else if(stok[kode]==0){
            printf ("MENU YANG ANDA PILIH SEDANG KOSONG\n");
        } else{
printf ("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf (" |NAMA MENU  \t: %s\t|\n",barang[kode]);
        printf (" |HARGA MENU \t: %d.000 \t|\n",harga[kode]);
        printf (" |STOK MENU  \t: %d\t\t|\n",stok[kode]-1);
        indeks=indeks+1;
        cart_barang[indeks][20]=barang[kode][20];
        
        cart_harga[indeks]=harga[kode];
        stok[kode]=stok[kode]-1;
        jumlah=jumlah+harga[kode];
        printf(" |TOTAL HARGA \t: %d.000 \t|\n",jumlah);
        printf ("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
printf ("INGIN MEMESAN LAGI? (Y/N) : ");
        scanf ("%s", &lagi);
        printf("\n");
    }while(lagi=='Y' || lagi=='y');
   
}
//daftar belanjaan
void belanja(int maks,char cart_barang[100][20],int cart_harga[]){
	system("cls");
	printf (">> Hayy, Kak %s Pesanan Anda Telah Diproses . . .\n",nama);
	printf ("\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    printf ("\t|======================= STRUK  PESANAN ========================|\n");
    printf ("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf ("\t|CUSTOMER : %s\t\t\t\t\t\t|\n", nama);
printf ("\t|DAFTAR MENU YANG DI PESAN :\t\t\t\t\t|\n");
    for(int i=0;i<=maks;i++){
        printf ("\t|\t %d. %s \t\tRp. %d.000\t\t\t|\n",i+1,cart_barang[i],cart_harga[i]);
    }
	printf ("\t|---------------------------------------------------------------|\n");
    printf ("\t|TOTAL YANG HARUS ANDA BAYAR ADALAH : Rp.");
    printf ("%d.000\t\t\t|\n",jumlah);
    printf ("\t|---------------------------------------------------------------|\n");
    printf ("\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf ("\t|======================== TERIMA KASIH =========================|\n");
    printf ("\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
} int main(){
    menuawal(barang,harga,stok);
    namapembeli();
    beli();
	belanja(indeks,cart_barang,cart_harga);
       
}
