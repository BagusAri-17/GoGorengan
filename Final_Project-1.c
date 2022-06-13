#include <stdio.h>		// Nama  : Anak Agung Ngurah Mahadana Apta Gotra
#include <string.h>		// NIM   : 2108561066
#include <stdlib.h>		// Kelas : B
#define true 1			// Prodi : Teknik Informatika

void header(){
	printf("================================================\n");
	printf("                   GOGORENGAN                   \n");
	printf("             !Bukan Gorengan Biasa!             \n");
	printf("================================================\n\n");
}

int os(int a){
	int loop=0;
	while(loop < 1){
		if(a == 1){
			system("cls");	// Ini jika user = Windows.
			loop = 1;
		}						
		else if(a == 2 || a == 3){	// Yang ini untuk macOS & Linux. Karena Device yang saya gunakan dalam mengerjakan project ini
			system("clear");		// adalah Windows dan saya belum mengetesnya di macOS maupun Linux, semoga saja ini bisa bekerja
			loop = 1;				// tanpa eror di kedua OS tersebut.
		}
	}
}

void menuutama(){
	printf("     Selamat  datang  di  GoGorengan.  Kami\n     karyawan  GoGorengan,  siap  melayani.\n     Pilih apa yang ingin  kamu lakukan ya!\n\n");
	printf("     --------------------------------------     \n");
	printf("     |             Menu Utama             |     \n");
	printf("     --------------------------------------     \n");
	printf("     |         [1] Pesan Gorengan         |     \n");
	printf("     |         [2] Gopis                  |     \n");
	printf("     |         [3] Tema                   |     \n");
	printf("     --------------------------------------     \n\n");
	printf("================================================\n\n");
}

void menugorengan(){
	printf("------------------------------------------------\n");
	printf("|                 Menu Pesanan                 |\n");
	printf("------------------------------------------------\n");
	printf("|  No  |      Gorengan      |  Harga per Biji  |\n");
	printf("------------------------------------------------\n");
	printf("|  01  |  Pisang goreng     |    Rp1.000,00    |\n");
	printf("|  02  |  Tahu isi          |    Rp2.000,00    |\n");
	printf("|  03  |  Tempe goreng      |    Rp1.200,00    |\n");
	printf("|  04  |  Ote-ote           |    Rp1.600,00    |\n");
	printf("|  05  |  Ubi goreng        |    Rp1.400,00    |\n");
	printf("|  06  |  Singkong goreng   |    Rp1.800,00    |\n");
	printf("|  07  |  Tape goreng       |      Rp500,00    |\n");
	printf("------------------------------------------------\n\n");
}

int harga(int desimal, int option){
    char karakter[99999], balik[99999], penyegar[1];
    itoa(desimal,karakter,10);	// Ini untuk mengonversi integer menjadi string
	strcpy(balik,penyegar);
	int b=strlen(karakter)-1;
    while(b >= 0){
        strncat(balik,&karakter[b],1);	// Ini untuk membalik (reverse). Maka, string[0] -> string[terakhir], string[1] -> string[terakhir-1], dst.
        b--;
    }
    int c=strlen(balik)-1;
    char print[99999], titik[]=".";
	strcpy(print,penyegar);
    while(c >= 0){
        strncat(print,&balik[c],1);	// Ini sama seperti di atas yaitu untuk membalik, namun apabila sudah ada 3 digit yang di balik
        if(c % 3 == 0 && c != 0){	// maka akan ditambahkan '.' (titik) untuk menandakan ribuannya.
            strcat(print,titik);
        }
        c--;
    }
	if(option == 1){
    	printf("Total harga belanjaan kamu Rp%s,00\n", print);
		strcpy(karakter,penyegar);	// Ini diperlukan untuk menghapus isi string, agar saat function ini digunakan untuk kedua kalinya,
		strcpy(balik,penyegar);		// isi stringnya dikembalikan dulu seperti semula, sehingga input yang masuk ke string tidak
		strcpy(print,penyegar);		// menumpuk dengan input yang sudah masuk sebelumnya (pada saat function  pertama kali digunakan).
	}
	else if(option == 2){
    	printf("Kembalian kamu  : Rp%s,00\n", print);
		strcpy(karakter,penyegar);
		strcpy(balik,penyegar);
		strcpy(print,penyegar);
	}
	else if(option == 3){
		char tab[]=" ";
		int panjang=33-strlen(print);	// Ini sama seperti pada konversi_struk.
		while(panjang >= 0){
			printf("%s", tab);
			panjang--;
		}
		printf("Rp%s,00\n", print);
		strcpy(karakter,penyegar);
		strcpy(balik,penyegar);
		strcpy(print,penyegar);
	}
	else if(option == 4){
		printf("Rp%s,00\n", print);
		strcpy(karakter,penyegar);
		strcpy(balik,penyegar);
		strcpy(print,penyegar);
	}
}

int konversi(char uang[99999]){		// Ini adalah function untuk mengonversi string menjadi integer agar bisa menginput uang dengan
	char counter[99999];			// titik dan koma (contoh: 10.000,00). Namun juga bisa tanpa titik dan koma (contoh: 10000).
	int d=0, stoi=0, panjang=strlen(uang);
	if(strstr(uang,",00") != 0){	// Jika '==0' berarti tidak ada karakter ',00' dalam string.
		panjang -= 3;
		strncpy(counter,uang,panjang); // Ini untuk menyalin string sampai karakter ke-n saja.
		while(d < panjang){
			if(counter[d] != '.')	// Ini untuk melewati '.' (apabila ada), agar tidak ikut dikonversi.
				stoi = stoi * 10 + counter[d] - '0';	// Disini memanfaatkan kode ASCII. Caranya yaitu dengan mengurangi counter ke-n dengan kode
			d++;										// ASCII char "0". Maka dari situ akan didapatkan ASCII desimal dari angka yang diinput.
		}												// 'stoi * 10' berfungsi untuk membuat puluhan, ratusan, ribuan, dan seterusnya tergantung
    }													// jumlah inputan
	else if(strstr(uang,",00") == 0){
		while(d < panjang){
			if(uang[d] != '.')
				stoi = stoi * 10 + uang[d] - '0';
			d++;
		}
	}
	return stoi;
}

void header_struk(){
	printf("================================================\n");
	printf("                   GOGORENGAN                   \n");
	printf("            JALAN IN AJA DULU NO. 77            \n");
	printf("                 DENPASAR, BALI                 \n");
	printf("================================================\n\n");
}

int konversi_struk(int harga, int jml){
	char string[99999], strjml[99999], reverse[99999], refresh[99999];
    itoa(harga,string,10);
	itoa(jml,strjml,10);
	strcpy(reverse,refresh);
    int e=strlen(string)-1;
	while(e >= 0){
        strncat(reverse,&string[e],1);
        e--;
    }
    int f=strlen(reverse)-1;
    char cetak[99999], dot[]=".";
    while(f >= 0){
        strncat(cetak,&reverse[f],1);
        if(f % 3 == 0 && f != 0){
            strcat(cetak,dot);
        }
        f--;
    }
	char spasi[]=" ";
	int jarak=27-strlen(cetak)-strlen(strjml);	// Ini berfungsi untuk membuat subtotal pada struk reta kanan. Tidak menggunakan float agar
	while(jarak >= 0){							// bisa menambahkan '.' (titik). Konsepnya adalah menambahkan sejumlah spasi sebelum menyetak
		printf("%s", spasi);					// nilai subtotal. jumlah spasi tersebut didapat dari mengurangi sisa ruang ke samping
		jarak--;								// (29 - 3 karena ada ,00) dengan panjang nilai subtotal dan juga jumlah digit banyaknya pesanan.
	}
	printf("%s,00\n", cetak);
	strcpy(string,refresh);
	strcpy(reverse,refresh);
	strcpy(cetak,refresh);
}

void footer_struk(){
	printf("\n================================================\n");
	printf("  Terima kasih telah berbelanja di kedai kami.  \n");
	printf("     Pelanggan puas cuan kami tak terbatas.     \n");
	printf("       Jangan bosan ya belanja di sini :)       \n");
	printf("================================================\n");
}

void menugopis(){
	printf("\n     --------------------------------------     \n");
	printf("     |             Menu Gopis             |     \n");
	printf("     --------------------------------------     \n");
	printf("     |           (1) Buat Akun            |     \n");
	printf("     |           (2) Cek Saldo            |     \n");
	printf("     |           (3) Menu utama           |     \n");
	printf("     --------------------------------------     \n\n");
	printf("================================================\n\n");
}

int kembali_utama(){
	int tes, g=0;
	char kembali_utama;
	while(g < 1){
		printf("\nIngin kembali ke menu utama? [Y/T] : ");
		scanf("%s", &kembali_utama);
		if(kembali_utama == 'Y' || kembali_utama == 'y'){
			tes = 0;
			g = 1;
		}
		else if(kembali_utama == 'T' || kembali_utama == 't'){	
			tes = 1;
			g = 1;
		}
		else{
			printf("     --------------------------------------\n");
			printf("     | Inputan kamu salah. Tolong ulangi! |\n");
			printf("     --------------------------------------\n");
		}
	}
	return tes;
}

int kembali_gopis(){
	int ulang_gopis, h=0;
	char kembali_gopis;
	while(h < 1){
		printf("\nIngin kembali ke menu gopis? [Y/T] : ");
		scanf("%s", &kembali_gopis);
		if(kembali_gopis == 'Y' || kembali_gopis == 'y'){
			ulang_gopis = 0;
			h = 1;
		}
		else if(kembali_gopis == 'T' || kembali_gopis == 't'){
			ulang_gopis = 1;
			h = 1;
		}
		else{
			printf("     --------------------------------------\n");
			printf("     | Inputan kamu salah. Tolong ulangi! |\n");
			printf("     --------------------------------------\n");
		}
	}
	return ulang_gopis;
}

int kembali_tema(){
	int ulang_tema, looping=0;
	char kembali_tema;
	while(looping < 1){
		printf("\nIngin kembali ke menu tema? [Y/T] : ");
		scanf("%s", &kembali_tema);
		if(kembali_tema == 'Y' || kembali_tema == 'y'){
			ulang_tema = 0;
			looping = 1;
		}
		else if(kembali_tema == 'T' || kembali_tema == 't'){	
			ulang_tema = 1;
			looping = 1;
		}
		else{
			printf("     --------------------------------------\n");
			printf("     | Inputan kamu salah. Tolong ulangi! |\n");
			printf("     --------------------------------------\n");
		}
	}
	return ulang_tema;
}

int warna_sama(){
    printf("\n------------------------------------------------\n");
    printf("Warna background dan warna font yang kamu pilih\nsama. Jadi, pilih ulang!\n");
    system("pause");
}

int main(){
	int os_user, menu_utama, loop=0, tes=0, baliklagi=0, akun=0, saldo=0;
	char user_name[99999], password1[99999], passwordmasuk[99999];
	header();
	printf(" Pertama-tama pilih  OS  yang kamu gunakan pada\n perangkatmu!   Hati-hati,  kalau  salah  pilih\n bisa eror loh.\n\n");
	printf(" ---------------------------------------------- \n");
	printf(" |  1. Windows  |   2. macOS   |   3. Linux   | \n");
	printf(" ---------------------------------------------- \n\n");
	printf("================================================\n\n");
	while(loop < 1){
		printf("Pilihanmu : ");
		scanf("%d", &os_user);
		if(os_user == 1 || os_user ==  2 || os_user ==  3){
			os(os_user);
			loop = 1;
		}
		else{
			printf("------------------------------------------------\n");
			printf("| Kami  hanya  menyediakan  3  pilihan, jangan |\n");
			printf("| minta lebih  ya.  Jadi,  tolong pilih ulang! |\n");
			printf("------------------------------------------------\n\n");
		}
	}
	header();
	menuutama();
	while(tes < 1){
		if(baliklagi == 1){
			os(os_user);
			header();
			menuutama();
		}
		printf("Pilihanmu : ");
		scanf("%d", &menu_utama);
		switch(menu_utama){
			case 1:
				os(os_user);
				header();
				char pesanan[99999], patokan[99999];
				int i=0, pisang=0, tahu=0, tempe=0, ote=0, ubi=0, singkong=0, tape=0, harga_pisang=1000, harga_tahu=2000, harga_tempe=1200, harga_ote=1600, harga_ubi=1400, harga_singkong=1800, harga_tape=500, ulang_pesan=0, jml1=0, jml2=0, jml3=0, jml4=0, jml5=0, jml6=0, jml7=0;
				getchar();	// Karena gets tidak bisa digunakan apabila ada scanf di atasnya (yang dimaksud adalah scanf menu_utama), maka untuk mengakalinya bisa dilakukan dengan menambahkan getchar diantara scanf dan gets (bebas dimana saja).
				while(ulang_pesan < 1){
					os(os_user);
					header();
					menugorengan();
					int j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0;
					ulang_pesan = 0;
					printf("================================================\n");
					printf("Silahkan kamu ketik No-nya. Contoh: 01 02 03 04,\ndipisahin spasi aja.  Jangan ada yang double ya!\n------------------------------------------------\nPilihanmu : ");
					gets(pesanan);	// Menggunakan gets agar bisa langsung memesan semua janis yang diinginkan, baru setelah itu menekan enter (hanya sekali tekan).
					strcpy(patokan,pesanan);
					while(j < strlen(pesanan)){		// While loop ini berfungsi untuk memberi tanda apakah ada angka yang double dalam inputan atau tidak (kecuali spasi dan nol).
						if(pesanan[j] == ' '){}
						else if(pesanan[j] == '0'){}
						else if(pesanan[j] == '1')
							k++;
						else if(pesanan[j] == '2')
							l++;
						else if(pesanan[j] == '3')
							m++;
						else if(pesanan[j] == '4')
							n++;
						else if(pesanan[j] == '5')
							o++;
						else if(pesanan[j] == '6')
							p++;
						else if(pesanan[j] == '7')
							q++;
						else if(pesanan[j] == '8')
							r++;
						else if(pesanan[j] == '9')
							s++;
						j++;
					}
					while(t < 1){	// While loop ini berfungsi untuk mengulang mencetak kata-kata hingga inputannya tidak melanggar aturan.
						if(v == 1 && w == 1){
							printf("\n------------------------------------------------\n");
							printf("Maaf  banget,  menu yang tersedia saat ini hanya\nsebatas 7 jenis, dan  kamu  juga  memesan  jenis\nyang sama dua kali.  Jadi,  tolong  di ulang ya!\n");
							system("pause");
							v = 0;
							w = 0;
							t = 1;
						}
						if(ulang_pesan <= 0){
							if(k > 1 || l > 1 || m > 1 || n > 1 || o > 1 || p > 1 || q > 1 || r > 1 || s > 1){	// Ini berfungsi untuk mendeteksi angka double dengan memanfaatkan tanda yang diberikan oleh while loop diatas.
								if(v == 1){
									printf("\n------------------------------------------------\n");
									printf("Kayaknya kamu belum paham.  Jangan  ketik  angka\nyang sama dua kali ya, tolong ulangi.\n");
									system("pause");
									t = 1;
								}
								v = 1;
							}
						}
						while(u < strlen(pesanan)){
							if(pesanan[u] > '0' && pesanan[u+1] >= '0' || pesanan[u] == '0' && pesanan[u+1] < '0' || pesanan[u] == '8' || pesanan[u] == '9'){	// Ini berfungsi untuk mendeteksi jika ada inputan yang di luar pilihan. Disini jugga memanfaatkan
								if(w == 1){																														// kode ASCII, seperti pada 'pesanan[u] > '0' && pesanan[u+1] >= '0''. Maksudnya apabila inputan ke-n																																																																	// itu akan mendeteksi angka 10, bisa juga untuk 100,
									printf("\n------------------------------------------------\n");																// > char 0 (1,2,dst.), dan inputan ke-n+1 >= char 0 (0,1,dst.) maka if disamping akan bernilai true. 
									printf("Mohon maaf, menu yang kami miliki saat ini hanya\nsebatas 7 jenis.  Jangan pesan yang tidak ada di\nmenu ya, tolong ulangi!\n");
									system("pause");
									t = 1;
									break;
								}
								else if(true){
									w = 1;
									break;
								}
							}
							else if(pesanan[u] == '0' && pesanan[u+1] > '0' || pesanan[u] != '0' && pesanan[u+1] < '0')		// Ini berfungsi agar inputan yang berawal 0 tetapi nilainya tetap = 1/2/3/4/5/6/7, tidak dianggap
								w = 0;																						// sebagai inputan di luar pilihan (contoh: 01, 002, 0003, dst.). Fungsi dari
							u++;																							// 'pesanan[u] != '0' && pesanan[u+1] < '0'' adalah untuk mendeteksi spasi (karena ASCII spasi
						}																									// berada di bawah ASCII char 0), sehingga kode ASCII dari spasi tersebut tidak dianggap sebagai
						if(w == 1)																							// inputan di luar pilihan/menu.
							continue;
						u = 0;
						if(v == 0 && w == 0)
							t = 1;
					}
					if(v == 0 && w == 0)
						ulang_pesan = 1;
				}
				printf("\n================================================\n");
				printf("Ketik jumlah tiap jenis gorengan yang dipesan :\n");
				while(i < strlen(pesanan)){
					if(pesanan[i] == '1'){
						printf("- Pisang goreng\t   x  ");
						scanf("%d", &jml1);
						pisang = harga_pisang * jml1;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);	// Ini berfungsi untuk merubah isi pesanan agar menjadi seperti semula (inputan). Karena tadi patokan sudah menyalin isi pesanan, jadi isi pesanan bisa dipulihkan.
				while(i < strlen(pesanan)){
					if(pesanan[i] == '2'){
						printf("- Tahu isi\t   x  ");
						scanf("%d", &jml2);
						tahu = harga_tahu * jml2;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);
				while(i < strlen(pesanan)){
					if(pesanan[i] == '3'){
						printf("- Tempe goreng\t   x  ");
						scanf("%d", &jml3);
						tempe = harga_tempe * jml3;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);	
				while(i < strlen(pesanan)){
					if(pesanan[i] == '4'){
						printf("- Ote-ote\t   x  ");
						scanf("%d", &jml4);
						ote = harga_ote * jml4;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);		
				while(i < strlen(pesanan)){
					if(pesanan[i] == '5'){
						printf("- Ubi goreng\t   x  ");
						scanf("%d", &jml5);
						ubi = harga_ubi * jml5;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);
				while(i < strlen(pesanan)){
					if(pesanan[i] == '6'){
						printf("- Singkong goreng  x  ");
						scanf("%d", &jml6);
						singkong = harga_singkong * jml6;
					}
					i++;
				}
				i = 0;
				strcpy(pesanan,patokan);
				while(i < strlen(pesanan)){
					if(pesanan[i] == '7'){
						printf("- Tape goreng\t   x  ");
						scanf("%d", &jml7);
						tape = harga_tape * jml7;
					}
					i++;
				}
				printf("\n================================================\n");
				int harga_total, carabayar, x=0, y=0, z=0, uangreal, susuk, inoption1=1, inoption2=2, inoption3=3;
				char uangfake[99999];
				harga_total = pisang + tahu + tempe + ote + ubi + singkong + tape;
				harga(harga_total,inoption1);
				printf("Pilih metode pembayaran :\n1. Uang tunai\n2. Gopis\n");
				while(x < 1){
					x = 0;
					printf("------------------------------------------------\n");
					printf("Pilihan metode pembayaran : ");
					scanf("%d", &carabayar);
					getchar();
					if(carabayar == 1){
						printf("\n");
						while(y < 1){
							y = 0;
							printf("================================================\n");
							printf("Masukkan uangmu : Rp");
							gets(uangfake);
							uangreal = konversi(uangfake);
							if(uangreal < harga_total){
								printf("    ----------------------------------------\n");
								printf("    | Waduh, uangmu kurang nih. Ulangi ya! |\n");
								printf("    ----------------------------------------\n\n");
							}
							else if(uangreal > harga_total || uangreal == harga_total){
								susuk = uangreal - harga_total;
								harga(susuk,inoption2);
								y = 1;
								x = 1;
							}
						}
					}
					else if(carabayar == 2){
						if(akun == 0){
							printf(" ----------------------------------------------\n");
							printf(" | Kamu belum punya akun Gopis. Tunai aja ya! |\n");
							printf(" ----------------------------------------------\n\n");
						}
						else if(akun != 0){
							int kalaupasssalah=0;
							char password[99999];
							printf("\n");
							while(kalaupasssalah < 1){
								printf("================================================\n");
								printf("Masukkan password akun Gopismu : ");
								gets(password);
								if(strcmp(password,password1)==0)
									kalaupasssalah = 1;
								else{
									printf("  --------------------------------------------\n");
									printf("  | Password yang kamu masukkan salah.  Coba |\n");
									printf("  |                  ulangi!                 |\n");
									printf("  --------------------------------------------\n\n");
								}
							}
							if(saldo == 0){
								printf("------------------------------------------------\n");
								printf("| Oops, saldo kamu kosong.  Lain kali isi dulu |\n"); 
								printf("|        ya, sekarang pakai tunai aja!         |\n");
								printf("------------------------------------------------\n\n");
							}
							else if(saldo < harga_total){
								printf("------------------------------------------------\n");
								printf("| Yah,  saldo kamu kurang.  Lain kali cek dulu |\n");
								printf("|  sebelum belanja, sekarang pakai tunai aja!  |\n");
								printf("------------------------------------------------\n\n");
							}
							else if(saldo > harga_total){
								saldo -= harga_total;
								x = 1;
							}
						}
					}
					else{
						printf("     --------------------------------------\n");
						printf("     | Inputan kamu salah. Tolong ulangi! |\n");
						printf("     --------------------------------------\n\n");
					}
				}
				system("pause");
				os(os_user);
				header_struk();
				if(pisang != 0){
					printf("Pisang goreng\n    1.000,00  x  %d", jml1);		// Kondisi-kondisi di samping berfungsi untuk mencetak struk.
					pisang = konversi_struk(pisang,jml1);
				}
				if(tahu != 0){
					printf("Tahu isi\n    2.000,00  x  %d", jml2);
					tahu = konversi_struk(tahu,jml2);
				}
				if(tempe != 0){
					printf("Tempe goreng\n    1.200,00  x  %d", jml3);
					tempe = konversi_struk(tempe,jml3);
				}
				if(ote != 0){
					printf("Ote-ote\n    1.600,00  x  %d", jml4);
					ote = konversi_struk(ote,jml4);
				}
				if(ubi != 0){
					printf("Ubi goreng\n    1.400,00  x  %d", jml5);
					ubi = konversi_struk(ubi,jml5);
				}
				if(singkong != 0){
					printf("Singkong goreng\n    1.800,00  x  %d", jml6);
					singkong = konversi_struk(singkong,jml6);
				}
				if(tape != 0){
					printf("Tape goreng\n      500,00  x  %d", jml7);
					tape = konversi_struk(tape,jml7);
				}
				printf("------------------------------------------------\n");
				printf("Total    ");
				harga(harga_total,inoption3);
				if(carabayar == 1){
					printf("Tunai    ");
					harga(uangreal,inoption3);
					printf("Kembalian");
					harga(susuk,inoption3);
				}
				else if(carabayar == 2){
					int tengah, awal=0, putaran=0, putar=0;
					char viagopis[]="Di bayar via Gopis a.n. ", ruang[]=" ", paragraf[12];
					strcat(viagopis,user_name);
					printf("\n");
					if(strlen(viagopis) < 47){	// Kondisi ini berfungsi agar kalimat "Di bayar via Gopis ... " pada struk, menjadi center.
						if(strlen(viagopis) % 2 != 0)
							tengah = (strlen(viagopis) + 1) / 2;
						else if(strlen(viagopis) % 2 == 0)
							tengah = strlen(viagopis) / 2;
						while(awal < 24 - tengah){
							printf("%s", ruang);
							awal++;
						}
						printf("%s\n", viagopis);
					}
					else if(strlen(viagopis) == 47)		// 2 Kondisi ini berfungsi agar kalimat "Di bayar via Gopis ... " pada struk, menjadi justify.
						printf("%s\n", viagopis);
					else if(strlen(viagopis) > 47){
						while(putaran < strlen(viagopis)){
							printf("%c", viagopis[putaran]);
							if(putaran == 47 || putar == 95 || putaran == strlen(viagopis)-1){
								printf("\n");
								putar = 47;
							}
							putaran++;
							putar++;
						}
					}
				}
				footer_struk();
				tes = kembali_utama();
				if(tes == 0)
					baliklagi = 1;
				break;
			case 2:
				os(os_user);
				header();
				int menu_gopis, passwordsalah=0, passwordbeda=0, ulang_gopis=0, inoption4=4;
				char password2[99999], kembali_gopis_akun, kembali_gopis_isi, isi_saldo, tambah_saldo[99999], kembali_gopis_akunbukan0, kembali_utama_gopis;
				while(ulang_gopis < 1){
					char selamatdatang[]=" Selamat datang ";
					int panjangusername=0, bedauser=0, salahisisaldo=0;
					ulang_gopis = 0;
					os(os_user);
					header();
					if(akun == 0)
						printf("     FYI, Gopis adalah uang elektronik yang\n     bisa   kamu   pakai   untuk   membayar\n     belanjaan    kamu    di    GoGorengan.\n");
					else{
						strcat(selamatdatang,user_name);
						printf("    ");
						while(panjangusername < strlen(selamatdatang)){
							printf("%c", selamatdatang[panjangusername]);
							if(panjangusername % 38 == 0 && panjangusername != 0 || panjangusername == strlen(selamatdatang)-1){
								printf("\n");
								if(panjangusername != strlen(selamatdatang)-1)
									printf("     ");
							}
							panjangusername++;
						}
					}
					menugopis();
					printf("Pilihanmu : ");
					scanf("%d", &menu_gopis);
					getchar();
					switch(menu_gopis){
						case 1:
							os(os_user);
							header();
							if(akun == 0){
								printf("    Pakai user name yang singkat, padat, dan\n        jelas ya,  biar gampang diingat.\n\n");
								printf("Ketik user name : ");
								gets(user_name);
								while(passwordsalah < 1){
									os(os_user);
									header();
									printf(" Buat password yang rumit dengan campuran huruf\n      dan angka! Ingat minimal 8 karakter.\n\n");
									printf("Ketik password		: ");
									gets(password1);
									if(strlen(password1) < 8){
										printf("\n------------------------------------------------\n");
										printf("Jumlah karakter password kamu kurang dari 8 nih.\nCoba ulangi!\n");
										system("pause");
									}
									else
										passwordsalah = 1;
								}
								while(passwordbeda < 2){
									if(passwordbeda == 1){
										os(os_user);
										header();
										printf(" Buat password yang rumit dengan campuran huruf\n      dan angka! Ingat minimal 8 karakter.\n\n");
										printf("Ketik password		: %s\n", password1);
									}
									printf("Konfirmasi password	: ");
									gets(password2);
									if(strcmp(password1,password2)==0)
										passwordbeda = 2;
									else{
										printf("\n------------------------------------------------\n");
										printf("Konfirmasi password yang kamu ketik salah.  Coba\nulangi!\n");
										system("pause");
										passwordbeda = 1;
									}
								}
								os(os_user);
								header();
								printf("   -------------------------------------------\n");
								printf("   | Selamat, sekarang kamu punya akun Gopis |\n");
								printf("   -------------------------------------------\n");
								akun = 1;
								ulang_gopis = kembali_gopis();
								if(ulang_gopis == 1){
									tes = kembali_utama();
									if(tes == 0)
										baliklagi = 1;
								}
							}
							else if(akun != 0){
								printf("        --------------------------------\n");
								printf("        | Kamu sudah punya akun Gopis. |\n");
								printf("        --------------------------------\n");
								ulang_gopis = kembali_gopis();
								if(ulang_gopis == 1){
									tes = kembali_utama();
									if(tes == 0)
										baliklagi = 1;
								}
							}
							break;
						case 2:
							os(os_user);
							header();
							if(akun == 0){
								printf(" ----------------------------------------------\n");
								printf(" | Kamu belum punya akun Gopis. Buat dulu ya! |\n");
								printf(" ----------------------------------------------\n");
								ulang_gopis = kembali_gopis();
								if(ulang_gopis == 1){
									tes = kembali_utama();
									if(tes == 0)
										baliklagi = 1;
								}
							}
							else{
								while(bedauser < 1){
									os(os_user);
									header();
									printf("Masukkan password akun Gopismu : ");
									gets(passwordmasuk);
									if(strcmp(passwordmasuk,password1)==0)
										bedauser = 1;
									else{
										printf("\n------------------------------------------------\n");
										printf("Password yang kamu masukkan salah.  Coba ulangi!\n");
										system("pause");
									}
								}
								while(salahisisaldo < 1){
									os(os_user);
									header();
									if(saldo == 0)
										printf("Saldomu : Rp0,00\n");
									else{
										printf("Saldomu : ");
										harga(saldo,inoption4);
									}
									printf("\nMau isi saldo? [Y/T] : ");
									scanf("%s", &isi_saldo);
									if(isi_saldo == 'Y' || isi_saldo == 'y'){
										os(os_user);
										header();
										printf("Isi saldo : Rp");
										getchar();
										gets(tambah_saldo);
										saldo += konversi(tambah_saldo);
										os(os_user);
										header();
										printf("         ------------------------------\n");
										printf("         | Kamu telah  mengisi saldo. |\n");
										printf("         ------------------------------\n\n");
										printf("Saldo sekarang : ");
										harga(saldo,inoption4);
										ulang_gopis = kembali_gopis();
										if(ulang_gopis == 1){
											tes = kembali_utama();
											if(tes == 0)
												baliklagi = 1;
										}
										salahisisaldo = 1;
									}
									else if(isi_saldo == 'T' || isi_saldo == 't'){
										ulang_gopis = kembali_gopis();
										if(ulang_gopis == 1){
											tes = kembali_utama();
											if(tes == 0)
												baliklagi = 1;
										}
										salahisisaldo = 1;
									}
									else{
										printf("\n------------------------------------------------\n");
										printf("Inputan kamu salah. Tolong ulangi!\n");
										system("pause");
									}
								}
							}
							break;
						case 3:
							ulang_gopis = 1;
							tes = 0;
							baliklagi = 1;
							break;
						default:
							printf("\n------------------------------------------------\n");
							printf("Pilihanmu tidak ada dalam menu. Harap pilih yang\nada di menu saja ya!\n");
							system("pause");
					}
				}
				break;
			case 3:
				os(os_user);
				header();
				int ulang_tema=0;
				while(ulang_tema < 1){
					int font, background, tandaB=0, tandaF=0;
					os(os_user);
					header();
					printf("              -------------------\n");
					printf("              |    Menu Tema    |\n");
					printf("              -------------------\n");
					printf("              | No. |   Warna   |\n");
					printf("              -------------------\n");
					printf("              |  0  |  Hitam    |\n");
					printf("              |  1  |  Biru     |\n");
					printf("              |  2  |  Hijau    |\n");
					printf("              |  3  |  Aqua     |\n");
					printf("              |  4  |  Merah    |\n");
					printf("              |  5  |  Ungu     |\n");
					printf("              |  6  |  Kuning   |\n");
					printf("              |  7  |  Putih    |\n");
					printf("              |  8  |  Abu-abu  |\n");
					printf("              -------------------\n\n");
					printf("================================================\nPeraturannya, warna background dan warna font,\ntidak boleh sama.\n------------------------------------------------\nPilih warna background : ");
					scanf("%d", &background);
					if(background > 8 || background < 0){
						printf("\n------------------------------------------------\n");
						printf("Pilihanmu tidak ada dalam menu. Harap pilih yang\nada di menu saja ya!\n");
						system("pause");
						tandaB = 1;
					}
					if(tandaB == 0){
						printf("Pilih warna font       : ");
						scanf("%d", &font);
						if(font > 8 || font < 0){
							printf("\n------------------------------------------------\n");
							printf("Pilihanmu tidak ada dalam menu. Harap pilih yang\nada di menu saja ya!\n");
							system("pause");
							tandaF = 1;
						}
					}
					if(tandaB == 0 && tandaF == 0){
						if(background == 0){
							if(font == 0)
								warna_sama();
							else if(font == 1)
								system("color 01");
							else if(font == 2)
								system("color 02");
							else if(font == 3)
								system("color 03");
							else if(font == 4)
								system("color 04");
							else if(font == 5)
								system("color 05");
							else if(font == 6)
								system("color 06");
							else if(font == 7)
								system("color 07");
							else if(font == 8)
								system("color 08");
						}
						else if(background == 1){
							if(font == 0)
								system("color 10");
							else if(font == 1)
								warna_sama();
							else if(font == 2)
								system("color 12");
							else if(font == 3)
								system("color 13");
							else if(font == 4)
								system("color 14");
							else if(font == 5)
								system("color 15");
							else if(font == 6)
								system("color 16");
							else if(font == 7)
								system("color 17");
							else if(font == 8)
								system("color 18");
						}
						else if(background == 2){
							if(font == 0)
								system("color 20");
							else if(font == 1)
								system("color 21");
							else if(font == 2)
								warna_sama();
							else if(font == 3)
								system("color 23");
							else if(font == 4)
								system("color 24");
							else if(font == 5)
								system("color 25");
							else if(font == 6)
								system("color 26");
							else if(font == 7)
								system("color 27");
							else if(font == 8)
								system("color 28");
						}
						else if(background == 3){
							if(font == 0)
								system("color 30");
							else if(font == 1)
								system("color 31");
							else if(font == 2)
								system("color 32");
							else if(font == 3)
								warna_sama();
							else if(font == 4)
								system("color 34");
							else if(font == 5)
								system("color 35");
							else if(font == 6)
								system("color 36");
							else if(font == 7)
								system("color 37");
							else if(font == 8)
								system("color 38");
						}
						else if(background == 4){
							if(font == 0)
								system("color 40");
							else if(font == 1)
								system("color 41");
							else if(font == 2)
								system("color 42");
							else if(font == 3)
								system("color 43");
							else if(font == 4)
								warna_sama();
							else if(font == 5)
								system("color 45");
							else if(font == 6)
								system("color 46");
							else if(font == 7)
								system("color 47");
							else if(font == 8)
								system("color 48");
						}
						else if(background == 5){
							if(font == 0)
								system("color 50");
							else if(font == 1)
								system("color 51");
							else if(font == 2)
								system("color 52");
							else if(font == 3)
								system("color 53");
							else if(font == 4)
								system("color 54");
							else if(font == 5)
								warna_sama();
							else if(font == 6)
								system("color 56");
							else if(font == 7)
								system("color 57");
							else if(font == 8)
								system("color 58");
						}
						else if(background == 6){
							if(font == 0)
								system("color 60");
							else if(font == 1)
								system("color 61");
							else if(font == 2)
								system("color 62");
							else if(font == 3)
								system("color 63");
							else if(font == 4)
								system("color 64");
							else if(font == 5)
								system("color 65");
							else if(font == 6)
								warna_sama();
							else if(font == 7)
								system("color 67");
							else if(font == 8)
								system("color 68");
						}
						else if(background == 7){
							if(font == 0)
								system("color 70");
							else if(font == 1)
								system("color 71");
							else if(font == 2)
								system("color 72");
							else if(font == 3)
								system("color 73");
							else if(font == 4)
								system("color 74");
							else if(font == 5)
								system("color 75");
							else if(font == 6)
								system("color 76");
							else if(font == 7)
								warna_sama();
							else if(font == 8)
								system("color 78");
						}
						else if(background == 8){
							if(font == 0)
								system("color 80");
							else if(font == 1)
								system("color 81");
							else if(font == 2)
								system("color 82");
							else if(font == 3)
								system("color 83");
							else if(font == 4)
								system("color 84");
							else if(font == 5)
								system("color 85");
							else if(font == 6)
								system("color 86");
							else if(font == 7)
								system("color 87");
							else if(font == 8)
								warna_sama();
						}
						if(background != font && tandaB == 0 && tandaF == 0){
							os(os_user);
							header();
							printf("             ----------------------\n");
							printf("             | Tema telah diganti |\n");
							printf("             ----------------------\n");
							ulang_tema = kembali_tema();
							if(ulang_tema == 1){
								tes = kembali_utama();
								if(tes == 0)
									baliklagi = 1;
							}
						}
					}
				}
				break;
			default:
				printf("\n------------------------------------------------\n");
				printf("Pilihanmu tidak ada dalam menu. Harap pilih yang\nada di menu saja ya!\n");
				system("pause");
				tes = 0;
				baliklagi = 1;
		}
	}
	return 0;
}