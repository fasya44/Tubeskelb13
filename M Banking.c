//=====================================================================================// includes
#include <stdio.h> 											//header i/o
#include <windows.h> 										//header system(cls), getch(), etc
#include <time.h>

//=====================================================================================// prototype setiap fungsi
void welcome();
void logo();
int verifikasiLogin();
void verifikasi_login_choice();
int menu_login();
int menu();
void header();
void header_help();
void header_menu();
void create_new_account();
void update_account_information();
void my_account();
int transfer();
void payment();
void history();
void help();
void help_create_new_account();
void help_update_account_information();
void help_my_account();
void help_transfer();
void help_payment();
void help_history();
void help_exit();
void help_logout();
int logoutAwal();
int logout();
void ketik(char* a, int b);
void fordelay(int y);

struct tanggal{
	char tempat[20];
	int tanggal;
	int bulan;
	int tahun;
};

struct id_password{
	char id[50];
	char pass[20];
	char tranpass[20];
};

struct identitas{
    char ndepan[100]; 
    char nbelakang[100];
	char alamat[100];
	char noKTP[100];
	char noRekening[100];
	int setoranAwal;
	char noTelepon[100];
	char noVA[100], noPLN[100], noTelp[100];
	char email[100];
	int tambahSaldo;
	int kurangSaldo;
	struct tanggal ttl;
	struct tanggal transaksi;
	struct id_password identity;
	int pilihan;
	char pilihan_ch[2];
	int nominal;
	char s1[20], s2[20], s3[20], s4[20];
}user, input, current, transact, update, uji;
//=====================================================================================// main

int main()
{
	memset(current.ndepan, 0, strlen(current.ndepan));
	system("title Bank NEO17");
	system("COLOR 0B");
	logo();
	welcome();
    menu_login();
	menu();return 0;
}

//============================================================================================================

void welcome()
{
	system("pause");
	system("cls");
	Sleep(50);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                        ");
	ketik("BANK NEO17 MOBILE",30);
	printf("\n                                        ");
	ketik("The Best Choice for Mobile Banking", 30);
	Sleep(1000);
	printf("\n\n\t\t\t\t        ");
    system("pause");
    system("cls");
}

//============================================================================================================

int verifikasiLogin()
{
	system("cls");
	FILE *view;
	int x=0;
	view = fopen("IDPass.txt", "r");
	printf("Masukan id anda: ");
	scanf("%s", input.identity.id);
	printf("Masukan password anda: ");
	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\
    
    
    
	while(fscanf(view, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id, user.identity.pass, user.identity.tranpass)!=EOF){
       	if(strcmp(input.identity.id, user.identity.id)==0&&strcmp(password, user.identity.pass)==0)
		{
			system("cls");
			printf("User dikenali!\n");
			printf("Selamat datang, %s!", user.ndepan);
			strcpy(current.ndepan, user.ndepan);
			sleep(2);
			x=1;
			break;
		}
		else{
			continue;
		}
		}
		if(x==0)
		{
			printf("\nUser tidak dikenali, mohon cek kembali nama dan password akun anda\n");
			printf("    Pilih 1 untuk mencoba kembali\n");
			printf("    Pilih 2 untuk kembali ke menu\n");
			printf("    Pilih 0 untuk keluar dari program\n");
			printf("Select Your Choice : ");
			switch(getch())											//switch case berdasarkan getch()
		    {
			    case '1':
					verifikasiLogin();												
			        break;
			    case '2':
					menu_login();
			        break;
				case '0':
			        logout();
					system("cls");
					printf("\t\t\t\t\t\t\t");
					ketik("End of Program\n",30);
					printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
					printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
					ketik("^.^ Have a Nice Day ^.^\n\n",30);	
			        exit(0);															//program berkahir jika ditekan 0
				default:																//jika user menginput selain opsi
			    	printf("\n\n\t\t\t\t   Wrong input!\n");
			    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
			    	printf("\t\t\t\t   ");
			    	system("pause");
					verifikasi_login_choice();
			}
			sleep(2);
		}
		x=0;
		fclose(view);
}

//==================================================================================

void verifikasi_login_choice()
{
	printf("    Pilih 1 untuk mencoba kembali\n");
	printf("    Pilih 2 untuk kembali ke menu\n");
	printf("    Pilih 0 untuk keluar dari program\n");
	printf("Select Your Choice : ");
	switch(getch())											//switch case berdasarkan getch()
    {
	    case '1':
			verifikasiLogin();												
	        break;
	    case '2':
			menu_login();
	        break;
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			verifikasi_login_choice();
		}
}


//==================================================================================
void logo()
{
	printf("\n\n\n");
	printf("                                  				                                             \n");
	printf("                              								                                 \n");
	printf("                                                                                             \n");
	printf("  NEO17NEO17                      	NEO17								                 \n");
	printf("  NEO17 NEO17                    	NEO17                   							 \n");
	printf("  NEO17  NEO17                  	NEO17										         \n");
	printf("  NEO17   NEO17               		NEO17									             \n");
	printf("  NEO17    NEO17             		NEO17										         \n");
	printf("  NEO17     NEO17                       NEO17                                                \n");
	printf("  NEO17      NEO17            	        NEO17									             \n");
	printf("  NEO17       NEO17       	        NEO17								  	             \n");
	printf("  NEO17        NEO17     		NEO17												 \n");
	printf("  NEO17         NEO17    		NEO17												 \n");
	printf("  NEO17          NEO17  		NEO17												 \n");
	printf("  NEO17           NEO17 	        NEO17												 \n");
    printf("  NEO17      	   NEO17	        NEO17											     \n");
	printf("  NEO17             NEO17	        NEO17												 \n");
	printf("  NEO17              NEO17		NEO17												 \n");
	printf("  NEO17               NEO17		NEO17											     \n");
	printf("  NEO17                NEO17		NEO17										         \n");
	printf("  NEO17                 NEO17		NEO17								                 \n");
	printf("  NEO17                  NEO17	        NEO17											     \n");
	printf("  NEO17                   NEO17	        NEO17												 \n");
	printf("  NEO17              	   NEO17        NEO17												 \n");
	printf("  NEO17              	    NEO17	NEO17												 \n");
	printf("  NEO17               	     NEO17	NEO17  												 \n");
	printf("  NEO17             	      NEO17	NEO17   											 \n");
	printf("  NEO17                        NEO17    NEO17												 \n");
	printf("  NEO17                   	NEO17   NEO17    							                 \n");
	printf("  NEO17                    	 NEO17 	NEO17										         \n");
	printf("  NEO17                           NEO17	NEO17											     \n");
	printf("  NEO17                            NEO17NEO17											     \n");
	printf("                             										                         \n");
	printf("                                 								                             \n");
	printf("                                      						                                 \n");
	printf("\n");
}

//=====================================================================================// void header
void header()				
{
	printf("\t\t\t================================================================\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                     BANK NEO17 MOBILE                      ||\n");   
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t================================================================\n\n");
}

//=====================================================================================// void header_menu
void header_menu()
{
	printf("\t\t\t\t        ================================\n");
    printf("\t\t\t\t        |           Main Menu          |\n");
    printf("\t\t\t\t        ================================\n\n");
}

//=====================================================================================// void header_help
void header_help()
{
	printf("\t\t\t\t        ================================\n");
    printf("\t\t\t\t        |         Help Section         |\n");
    printf("\t\t\t\t        ================================\n\n");
}

int menu_login()
{
	system("cls");
	printf("Welcome to Bank Krut Online\n");
	printf("Silahkan pilih menu di bawah ini :\n");
	printf("    1. Log in (jika sudah memiliki akun)\n");
	printf("    2. Sign up (jika belum memiliki akun))\n");
	printf("    0. Close the Program\n");
	printf("Select Your Choice : ");
	switch(getch())											//switch case berdasarkan getch()
    {
	    case '1':
			verifikasiLogin();												
	        break;
	    case '2':
			create_new_account();
	        verifikasiLogin();
	        break;
		case '0':
			logoutAwal();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			menu_login();
	}
}

//=====================================================================================// menu
int menu()
{
    system("cls");											//clear screen setiap pemanggilan fungsi menu
    header();												//memanggil fungsi header
	header_menu();											//memanggil fungsi header menu
    printf("\t\t\t\t   =========================================\n");
    printf("\t\t\t\t   | 1) Create a New Account               |\n");
    printf("\t\t\t\t   | 2) Update Account Information         |\n");
    printf("\t\t\t\t   | 3) My Account                         |\n");
    printf("\t\t\t\t   | 4) Transfer                           |\n");
    printf("\t\t\t\t   | 5) Payment                            |\n");
    printf("\t\t\t\t   | 6) Transaction History                |\n");
    printf("\t\t\t\t   | 7) Help                               |\n");
    printf("\t\t\t\t   | 8) Exit                               |\n");
    printf("\t\t\t\t   | 0) Log Out                            |\n");
    printf("\t\t\t\t   =========================================\n");
    printf("\t\t\t\t   Select Your Choice : ");
    switch(getch())											//switch case berdasarkan getch()
    {
    case '1':
        create_new_account();												//masuk ke fungsi create_new_account() jika ditekan 1
        break;
    case '2':
        update_account_information();										//masuk ke fungsi update_account_information() jika ditekan 2
        break;
    case '3':
        my_account();														//masuk ke fungsi my_account() jika ditekan 3
        break;
    case '4':
        transfer();															//masuk ke fungsi transfer() jika ditekan 4
        break;
    case '5':
        payment();															//masuk ke fungsi payment() jika ditekan 5
        break;
    case '6':
    	history();															//masuk ke fungsi history() jika ditekan 6
    	break;
    case '7':
		help();																//masuk ke fungsi help() jika ditekan 7
		break;
	case '9':
		logout();
		system("cls");
		printf("\t\t\t\t\t\t\t");
		ketik("End of Program\n",30);
		printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
		printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
		ketik("^.^ Have a Nice Day ^.^\n\n",30);	
        exit(0);															//program berkahir jika ditekan 0
    case '0':
    	logout();
    	system("cls");
    	main();
    default:																//jika user menginput selain opsi
    	printf("\n\n\t\t\t\t   Wrong input!\n");
    	printf("\t\t\t\t   Please input choice between 0 to 9 only!\n\n");
    	printf("\t\t\t\t   ");
    	system("pause");
		menu();
    }
}

//=====================================================================================// void help
void help()
{
	system("cls");
	header();
	header_help();
    printf("\t\t\t\t   ");
    ketik("Which section needs explaination?",20);
    printf("\n\t\t\t\t   =========================================\n");		//menu help section
    printf("\t\t\t\t   | 1) Create a New Account               |\n");
    printf("\t\t\t\t   | 2) Update Account Information         |\n");
    printf("\t\t\t\t   | 3) My Account                         |\n");
    printf("\t\t\t\t   | 4) Transfer                           |\n");
    printf("\t\t\t\t   | 5) Payment                            |\n");
    printf("\t\t\t\t   | 6) Transaction History                |\n");
    printf("\t\t\t\t   | 7) Exit                               |\n");
    printf("\t\t\t\t   | 8) Log Out                            |\n");
    printf("\t\t\t\t   | 0) Back to Main Menu                  |\n");
    printf("\t\t\t\t   =========================================\n");
    printf("\t\t\t\t   Select your choice : ");
    switch(getch())												//switch case berdasarkan getch()
    {	
    case '1':
        help_create_new_account();											//masuk ke fungsi help_create_new_account() jika ditekan 1
        break;
    case '2':
        help_update_account_information();									//masuk ke fungsi help_update_account_information() jika ditekan 2
        break;
    case '3':
        help_my_account();													//masuk ke fungsi help_my_account() jika ditekan 3
        break;
    case '4':
        help_transfer();													//masuk ke fungsi help_transfer() jika ditekan 4
        break;
    case '5':
        help_payment();														//masuk ke fungsi help_payment() jika ditekan 5
        break;
    case '6':
    	help_history();														//masuk ke fungsi help_history() jika ditekan 6
    	break;
	case '7':	
        help_exit();														//masuk ke fungsi help_exit() jika ditekan 7
        break;
    case '8':
    	help_logout();
    case '0':
    	menu();																//masuk ke fungsi menu() jika ditekan 0
    	break;
    default:																//jika user menginput selain opsi
    	printf("\n\n\t\t\t\t   Wrong input!\n");
    	printf("\t\t\t\t   Please input choice between 0 to 9 only!");
    	printf("\n\n\t\t\t\t   ");
    	system("pause");
		help();
    }
}

void create_new_account()
{
	time_t currentTime;
	time (&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *fp, *entry, *entry2;
    fp=fopen("contact.txt","a+");
    entry2 = fopen("dataTransaksiDebet.txt", "a+");
    system("cls");
    printf("Masukan nama depan anda: ");
    scanf("%s", user.ndepan);
    printf("Masukan nama belakang anda: ");
    scanf("%s", user.nbelakang);
    printf("Masukan nomor kartu identitas anda: ");
    scanf("%s", user.noKTP);
    printf("Masukan kota kelahiran anda: ");
    scanf("%s", user.ttl.tempat);
	printf("Masukan tanggal kelahiran anda [contoh: 26/06/2000]: ");
	scanf("%d/%d/%d", &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun);
    printf("Masukan Alamat anda [memakai '_' jika ingin melakukan spasi]: ");
    scanf("%s", user.alamat);
    printf("Masukan alamat email anda: ");
    scanf("%s", user.email);
    printf("Masukan nomor telepon anda: ");
    scanf("%s", user.noTelepon);
    printf("Masukan nominal setoran awal anda: Rp ");
    scanf("%d", &user.setoranAwal);
    fprintf(entry2, "Nama: %s  Debet: Rp. %d  Keterangan: Dapat (SetoranAwal) ke (rekening)  Tanggal: %d/%d/%d\n", user.ndepan, 
	user.setoranAwal,myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
    fclose(entry2);
    fprintf(fp, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP,
			user.ttl.tempat, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, user.alamat, user.email, user.noTelepon, user.setoranAwal);
	fclose(fp);
	system("cls");
	printf("Catatan telah di rekam, mohon menunggu sejenak untuk ke tahap selanjutnya!\n");
	system("Pause");
	system("cls");
    printf("Masukan id baru: ");
	scanf("%s", &user.identity.id);
	printf("Masukan password baru: ");
	scanf("%s", &user.identity.pass);
	printf("Masukan kode transaksi anda: ");
	scanf("%s", &user.identity.tranpass);
	entry = fopen("IDPass.txt", "a+");
	fprintf(entry, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id, user.identity.pass, user.identity.tranpass);
	printf("Akun berhasil dibuat!!\nNikmati kemudahan dengan menggunakan m-Banking Bank NEO17.\n");
	fclose(entry);
	system("pause");
	system("cls");
}
//======================================================================================

void update_account_information()
{
	system("cls");
	int choice, test=0;
    FILE *old,*newrec;
    old=fopen("contact.txt","r");
    newrec=fopen("rename.txt","a+");
    system("cls");
    printf("Masukkan Kode Transaksi Anda : ");
    scanf("%s", &update.identity.tranpass);
    while(fscanf(old,"Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP, user.ttl.tempat, &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun, user.alamat, user.email, user.noTelepon, &user.setoranAwal)!=EOF)
    {
        if (strcmp(current.ndepan, user.ndepan)==0)
        {   
        	test = 1;
        	input:
            printf("\nWhich information do you want to change?\n");
			printf("    1. E-mail\n");
			printf("    2. No. Telepon\n");
			printf("    3. Exit\n");
			printf("Select your choice : ");
            switch(getch())
            {
            	
            	case '1':
                	system("cls");
					printf("Masukan E-Mail Anda : ");
	                scanf("%s", update.email);
	                fprintf(newrec,"Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP, user.ttl.tempat, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, user.alamat, update.email, user.noTelepon, user.setoranAwal);
	                system("cls");
	                printf("Changes saved!\n");
	                system("pause");
	                goto input;
	                break;
            	
            	
            	case '2':
                	system("cls");
					printf("Masukan No. Telepon Anda : ");
	                scanf("%s", update.noTelepon);
	                fprintf(newrec,"Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP, user.ttl.tempat, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, user.email, user.alamat, update.noTelepon, user.setoranAwal);
	                system("cls");
	                printf("Changes saved!\n");
	                system("pause");
	                goto input;
	                break;
	                
            	case '3':
                	goto kelar;
				
				default:
					printf("\n\n\t\t\t\t   Wrong input!\n");
			    	printf("\t\t\t\t   Please input choice between 1 to 3 only!\n\n");
			    	printf("\t\t\t\t   ");
			    	system("pause");
					goto input;
        	}
        }
        else{
        	fprintf(newrec,"Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP, user.ttl.tempat, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, user.email, user.alamat, user.noTelepon, user.setoranAwal);
		}        
    }
    kelar:
    fclose(old);
    fclose(newrec);
    remove("contact.txt");
    rename("rename.txt", "contact.txt");
        	lagi:
			printf("\n\n\nEnter 1 to go to the main menu and 2 to exit\n");
			printf("Select Your Choice : ");
			switch(getch())											//switch case berdasarkan getch()
		    {
			    case '1':
					menu();												
			        break;
			    case '2':
					logout();
					system("cls");
					printf("\t\t\t\t\t\t\t");
					ketik("End of Program\n",30);
					printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
					printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
					ketik("^.^ Have a Nice Day ^.^\n\n",30);	
			        exit(0);															//program berkahir jika ditekan 0
			    default:																//jika user menginput selain opsi
			    	printf("\n\n\t\t\t\t   Wrong input!\n");
			    	printf("\t\t\t\t   Please input choice between 1 to 2 only!\n\n");
			    	printf("\t\t\t\t   ");
			    	system("pause");
					goto lagi;
		}
}

//======================================================================================


void my_account()
{
	system("cls");
	FILE *view;
	view=fopen("contact.txt", "r");
	while(fscanf(view, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", user.ndepan, user.noKTP,
			user.ttl.tempat, &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun, user.alamat, user.email, user.noTelepon, &user.nominal)!=EOF)
		{
			if(strcmp(current.ndepan, user.ndepan)==0){
				printf("Nama: %s\nKTP: %s\nTTL: %s , %d - %d - %d\nAlamat: %s\nE-mail: %s\nNo. Telp: %s\nSaldo: Rp. %d \n", user.ndepan, user.noKTP,
			user.ttl.tempat, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, user.alamat, user.email, user.noTelepon, user.nominal);
				break;
			}
		}
	fclose(view);
	system("pause");
	system("cls");
	menu();	
}

//======================================================================================
int transfer()
{
	system("cls");
	printf("Daftar Bank yang tersedia:\n    1. Bank BRI\n    2. Bank BCA\n    3. Bank Mandiri\n    4. Bank BNI\n      0. Exit to Main Menu");
	printf("Masukan kode bank yang dituju: ");
	switch(getch())
	{
		case '1':
			transferBRI();
            break;
        case '2':
        	transferBCA();
            break;
        case '3':
        	transferMandiri();
            break;
        case '4':
        	transferBNI();
            break;
        case '0':
			menu();
			break;
        default:
            cek:
            printf("Tidak terdapat kode bank tersebut, mohon periksa ulang kode bank anda!\n");
            printf("Input 1 untuk mengulang atau input 0 untuk kemblai ke menu.\nInput: ");
            switch(getch())
        	{
        		case '1':
        			transfer();
        			break;
        			
        		case '0':
        			menu();
        			break;
        			
        		default:
        			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	        printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	        printf("\t\t\t\t   ");
	    	        system("pause");
        			goto cek;
        			break;
			}
	}
}

int transferBRI(){
	system("cls");
	int adm = 2500, x=0, i=0, y=0, saldoBaru=0;;
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor rekening yang dituju: ");
	scanf("%s", transact.noRekening);
	printf("Masukan nominal angka yang ingin ditransfer: Rp. ");
	scanf("%d", &transact.nominal);
	printf("Masukan Kode Transaksi: ");
	
	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\
	
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF){
		if(uji.nominal>=transact.nominal+adm && strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - transact.nominal - adm;
	}
	
	tanya:
	system("cls");
	printf("Nomor Rekening yang Dituju : %s\nNominal Angka yang Ingin Ditransfer : %d\n", transact.noRekening, transact.nominal);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
			break;
		case '2':
			transferBRI();
			break;
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Transfer (BRI) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, transact.nominal,
			transact.noRekening, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
				fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
				uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
				uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
	
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);

	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}
	
	x=0;
	y=0;
	
	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//======================================================================

int transferBCA()
{
	system("cls");
	int adm = 2500, x=0, i=0, y=0, saldoBaru=0;;
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor rekening yang dituju: ");
	scanf("%s", transact.noRekening);
	printf("Masukan nominal angka yang ingin ditransfer: Rp. ");
	scanf("%d", &transact.nominal);
	printf("Masukan Kode Transaksi: ");

	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\

	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.noTelepon, uji.email, &uji.nominal )!=EOF){
		if(uji.nominal>=transact.nominal+adm && strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - transact.nominal - adm;
	}
	
	tanya:
	system("cls");
	printf("Nomor Rekening yang Dituju : %s\nNominal Angka yang Ingin Ditransfer : %d\n", transact.noRekening, transact.nominal);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			transferBCA();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Transfer (BCA) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, transact.nominal,
			transact.noRekening, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
		{
		cek1 = fopen("contact.txt", "r");
		cek3 = fopen("rename.txt", "a+");
		while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
				uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
				{
					if(strcmp(current.ndepan, uji.ndepan)==0)
					{
						fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
						uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
					}
					
					else
					{
						fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
						uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
					}
				}
			}
		
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}
	
	x=0;
	y=0;
	
	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//=====================================================================================================

int transferMandiri()
{
	system("cls");
	int adm = 2500, x=0, i=0, y=0, saldoBaru=0;;
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor rekening yang dituju: ");
	scanf("%s", transact.noRekening);
	printf("Masukan nominal angka yang ingin ditransfer: Rp. ");
	scanf("%d", &transact.nominal);
	printf("Masukan Kode Transaksi: ");

	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\

	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.noTelepon, uji.email, &uji.nominal )!=EOF){
		if(uji.nominal>=transact.nominal+adm && strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - transact.nominal - adm;
	}
	
	tanya:
	system("cls");
	printf("Nomor Rekening yang Dituju : %s\nNominal Angka yang Ingin Ditransfer : %d\n", transact.noRekening, transact.nominal);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			transferMandiri();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Transfer (Mandiri) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, transact.nominal,
			transact.noRekening, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
		
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}
	
	x=0;
	y=0;
	
	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//===========================================================================

int transferBNI()
{
	system("cls");
	int adm = 2500, x=0, i=0, y=0, saldoBaru=0;;
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor rekening yang dituju: ");
	scanf("%s", transact.noRekening);
	printf("Masukan nominal angka yang ingin ditransfer: Rp. ");
	scanf("%d", &transact.nominal);
	printf("Masukan Kode Transaksi: ");

	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\

	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji. email, uji.noTelepon, &uji.nominal )!=EOF){
		if(uji.nominal>=transact.nominal+adm && strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - transact.nominal - adm;
	}
	
	tanya:
	system("cls");
	printf("Nomor Rekening yang Dituju : %s\nNominal Angka yang Ingin Ditransfer : %d\n", transact.noRekening, transact.nominal);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			transferBNI();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Transfer (BNI) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, transact.nominal,
			transact.noRekening, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
		
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}

	x=0;
	y=0;

	transferCek:
	system("cls");	
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//=============================================================================================

void payment()
{
	pay:
	system("cls");
	printf("Jenis tagihan:\n    1. Virtual Account\n    2. PLN\n   3.Telepon\n   0. Exit to Main Menu\n");
	printf("Pilih menu yang ingin dibayar: ");
	switch(getch())
	{
		case '1':
			paymentVA();
			break;
		case '2':
			paymentPLN();
			break;
		case '3':
			paymentTelp();
			break;	
		case '0':
			menu();
			break;
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 3 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto pay;
	}	
}

//============================================================================================

int paymentVA()
{
	system("cls");
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	int x=0, i=0, y=0, saldoBaru=0, biaya=65000;
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor ID VA yang ingin dibayar: ");
	scanf("%s", transact.noVA);
	printf("Mohon tunggu sejenak");
	for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
	printf("Biaya yang perlu dibayar adalah: %d\n", biaya);
	printf("Masukan Kode Transaksi : ");
	
	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\
	
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF){
		if(uji.nominal>=biaya&&strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - biaya;
	}
	
	tanya:
	system("cls");
	printf("ID VA yang ingin dibayar : %s\nBiaya yang perlu dibayar : %d\n", transact.noVA, biaya);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			paymentVA();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Bayar (VA) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, biaya,
			transact.noVA, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}

	x=0;
	y=0;

	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//==============================================================================
int paymentPLN()
{
	system("cls");
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	int x=0, i=0, y=0, saldoBaru=0, biaya=50000;
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor ID PLN yang ingin dibayar: ");
	scanf("%s", transact.noPLN);
	printf("Mohon tunggu sejenak");
	for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
	printf("Biaya yang perlu dibayar adalah: %d\n", biaya);
	printf("Masukan Kode Transaksi : ");
	
	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\
	
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF){
		if(uji.nominal>=biaya&&strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - biaya;
	}
	
	tanya:
	system("cls");
	printf("ID PLN yang ingin dibayar : %s\nBiaya yang perlu dibayar : %d\n", transact.noPLN, biaya);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			paymentPLN();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Bayar (PLN) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, biaya,
			transact.noPLN, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
		printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
		
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}
	
	x=0;
	y=0;
	
	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}
//===========================================================================
int paymentTelp()
{
	system("cls");
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	int x=0, i=0, y=0, saldoBaru=0, biaya=40000;
	FILE *cek, *cek1, *cek2, *cek3;
	cek = fopen("IDPass.txt", "r");
	cek1 = fopen("contact.txt", "r");
	cek2 = fopen("dataTransaksiKredit.txt", "a+");
	printf("Masukan nomor telepon anda yang ingin dibayar: ");
	scanf("%s", transact.noTelp);
	printf("Mohon tunggu sejenak");
	for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
	printf("Biaya yang perlu dibayar adalah: %d\n", biaya);
	printf("Masukan Kode Transaksi : ");
	
	char password[55]; 
    int p=0; 
    do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*");
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';\
	
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP, uji.ttl.tempat
	,&uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF){
		if(uji.nominal>=biaya&&strcmp(uji.ndepan, current.ndepan)==0){
			y = 1;
			break;
		}
	}
	if(y==0){
		system("cls");
		printf("Uang yang anda miliki tidak cukup, transaksi gagal.\n");
		system("pause");
		goto kelar;
	}else if(y==1){
		saldoBaru = uji.nominal - biaya;
	}
	
	tanya:
	system("cls");
	printf("nomor telepon anda yang ingin dibayar : %s\nBiaya yang perlu dibayar : %d\n", transact.noTelepon, biaya);
	printf("\nApakah Informasi Tersebut Benar?\n    1. Ya (Lanjutkan Proses Transaksi)\n    2. Tidak (Kembali ke Pengisian Informasi)\n    0. Kembali ke Main Menu");
	switch(getch())
	{
		case '1':
			goto benar;
		case '2':
			paymentTelp();
		case '0':
			menu();
			break;
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 2 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto tanya;
			break;
	}
	
	benar:
	while(fscanf(cek, "Nama: %s  Id: %s  Pass: %s  Tranpass: %s\n", user.ndepan, user.identity.id,
	user.identity.pass, user.identity.tranpass)!= EOF){
		if(strcmp(user.identity.tranpass, password)==0&&strcmp(current.ndepan, user.ndepan)==0){
			system("cls");
			printf("Mohon Tunggu sejenak\n");
			for(i=0; i<=6; i++)
			{
				fordelay(100000000);
				printf(". ");
			}
			printf("\n");
			system("pause");
			system("cls");
			ketik("TRANSAKSI BERHASIL", 50);
			x = 1;
			fprintf(cek2,"Nama: %s  Kredit: %d  Keterangan: Bayar (telepon) ke (%s)  Tanggal: %d/%d/%d\n", user.ndepan, biaya,
			transact.noTelp, myTime->tm_mday, myTime->tm_mon+1, myTime->tm_year+1900);
			fclose(cek1);
			break;
		}
	}
	
	if(x==0)
	{
	    printf("\n\nTransaksi dibatalkan karena kode transaksi salah!");
		printf("\nTekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
		printf ("\nPlease Input Your Choice : ");
		switch(getch())
		{
			case '1':
				menu();
				break;
			
			case '0':
				logout();
				system("cls");
				printf("\t\t\t\t\t\t\t");
				ketik("End of Program\n",30);
				printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
				printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
				ketik("^.^ Have a Nice Day ^.^\n\n",30);	
		        exit(0);															//program berkahir jika ditekan 0
		    
			default:																//jika user menginput selain opsi
		    	printf("\n\n\t\t\t\t   Wrong input!\n");
		    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
		    	printf("\t\t\t\t   ");
		    	system("pause");
				menu();
		}
	}
	if(x==1)
	{
	cek1 = fopen("contact.txt", "r");
	cek3 = fopen("rename.txt", "a+");
	while(fscanf(cek1, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n", uji.ndepan, uji.noKTP,
			uji.ttl.tempat, &uji.ttl.tanggal, &uji.ttl.bulan, &uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, &uji.nominal )!=EOF)
			{
				if(strcmp(current.ndepan, uji.ndepan)==0)
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, saldoBaru);
				}
				
				else
				{
					fprintf(cek3, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d \n",
					uji.ndepan, uji.noKTP, uji.ttl.tempat, uji.ttl.tanggal, uji.ttl.bulan, uji.ttl.tahun, uji.alamat, uji.email, uji.noTelepon, uji.nominal);
				}
			}
		}
		
		
	kelar:
	fclose(cek3);
	fclose(cek2);
	fclose(cek1);
	fclose(cek);
	
	if(y==1 && x==1)
	{
	remove("contact.txt");
	rename("rename.txt", "contact.txt");
	}
	
	x=0;
	y=0;
	
	transferCek:
	system("cls");
	printf("Tekan 1 untuk kambali ke menu\nTekan 0 untuk keluar dari program");
	printf ("\nPlease Input Your Choice : ");
	switch(getch())
	{
		case '1':
			menu();
			break;
		
		case '0':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    
		default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 1 and 0 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			goto transferCek;
	}
}

//======================================================================================

void history()
{
	system("cls");
	FILE *view, *view1, *view2;
	
	view = fopen("dataTransaksiDebet.txt", "r");
	while(fscanf(view, "Nama: %s  Debet: Rp. %d  Keterangan: %s %s %s %s  Tanggal: %d/%d/%d\n", user.ndepan, &transact.nominal,
			uji.s1, uji.s2, uji.s3, uji.s4, &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun)!=EOF)
			{
				if(strcmp(current.ndepan, user.ndepan)==0){
					printf("Pendapatan: %d  Tanggal: %d/%d/%d  Keterangan: %s %s %s %s\n", transact.nominal, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, uji.s1, uji.s2, uji.s3, uji.s4);
					break;
				}
			}
	fclose(view);
	
	view1 = fopen("dataTransaksiKredit.txt", "r");
	while(fscanf(view1, "Nama: %s  Kredit: %d  Keterangan: %s %s %s %s  Tanggal: %d/%d/%d\n", user.ndepan, &transact.nominal,
			uji.s1, uji.s2, uji.s3, uji.s4, &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun)!=-1)
			{
				if(strcmp(current.ndepan, user.ndepan)==0){
					printf("Pengeluaran: %d  Tanggal: %d/%d/%d  Keterangan: %s %s %s %s\n", transact.nominal, user.ttl.tanggal, user.ttl.bulan, user.ttl.tahun, uji.s1, uji.s2, uji.s3, uji.s4);
				}
			}
	fclose(view1);
	
	view2 = fopen("contact.txt", "r");
	while(fscanf(view2, "Nama: %s  KTP: %s  TTL: %s , %d - %d - %d  Alamat: %s  E-mail: %s  No.Telp: %s  Saldo: Rp. %d\n", user.ndepan, user.noKTP,
			user.ttl.tempat, &user.ttl.tanggal, &user.ttl.bulan, &user.ttl.tahun, user.alamat, user.email, user.noTelepon, &user.nominal)!=EOF)
			{
				if(strcmp(current.ndepan, user.ndepan)==0){
					printf("Saldo Sekarang: %d\n", user.nominal);
					break;
				}
			}
	fclose(view2);
	
	system("pause");
	system("cls");
	menu();
}

//============================================================================

void help_choice()
{
	system("cls");
	printf("Pilih 1 untuk kembali ke Help Section\n");
	printf("Pilih 2 untuk kembali ke Main Menu\n");
	printf("Pilih 3 untuk keluar dari program\n");
	printf("Select Your Choice : ");
	switch (getch())
	{
		case '1':
			help();
			break;
		case '2':
			menu();
			break;
		case '3':
			logout();
			system("cls");
			printf("\t\t\t\t\t\t\t");
			ketik("End of Program\n",30);
			printf("\t\t\t\t\t Terima Kasih Sudah Menggunakan Program Ini\n");
			printf("\t\t\t\t\t\t      Sampai Jumpa Lagi\n\t\t\t\t\t\t   ");
			ketik("^.^ Have a Nice Day ^.^\n\n",30);	
	        exit(0);															//program berkahir jika ditekan 0
	    default:																//jika user menginput selain opsi
	    	printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 to 9 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			help_choice();
	}
}

//===============================================================================
void help_create_new_account()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Create a New Account\n\n");
	printf("Pada menu ini Anda dapat menambahkan akun baru pada aplikasi m-banking ini\n");
	printf("Dalam menu ini, Anda akan memasukan sejumlah data diri untuk membuat akun baru, yaitu :\n");
	printf("    1. Nama depan\n");
	printf("    2. Nama belakang\n");
	printf("    3. Nomor KTP\n");
	printf("    4. Tempat lahir\n");
	printf("    5. Tanggal Lahir\n");
	printf("    6. Alamat\n");
	printf("    7. E-mail\n");
	printf("    8. No. Telepon\n");
	printf("    9. Setoran Awal\n");
	printf("Setelah itu, Anda akan membuat ID, Password, dan kode transaksi\n\n");
	system("pause");
    help_choice();
}

//=============================================================================================

void help_update_account_information()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Update Account Information\n\n");
	printf("Pada menu ini Anda dapat mengedit beberapa informasi mengenai data diri yang telah disimpan sebelumnya\n\n");
	system("pause");
	help_choice();
}
//===============================================================================================
void help_my_account()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu My Account\n\n");
	printf("Pada menu ini, Anda dapat melihat informasi mengenai rekening Anda\n\n");
	system("pause");
	help_choice();
}

//===========================================================================================================

void help_transfer()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Transfer\n\n");
	printf("Pada menu ini, Anda dapat melakukan proses pengiriman uang ke rekening lain\n\n");
	system("pause");
	help_choice();
}

//=============================================================================================

void help_payment()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Payment\n\n");
	printf("Pada menu ini, Anda dapat melakukan proses pembayaran, seperti :");
	printf("    1. 	Virtual Account\n");
	printf("    2. PLN\n");
	printf("    3. Telepon \n\n");
	system("pause");
	help_choice();
}


//===============================================================================================================

void help_history()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu History\n\n");
	printf("Pada menu ini, Anda dapat melihat berbagai transaksi yang telah Anda lakukan,\n");
	printf("baik transfer, pembayaran, maupun top up\n\n");
	system("pause");
	help_choice();
}

//============================================================================================================

void help_exit()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Exit\n\n");
	printf("Pada menu ini, program akan berhenti berjalan dan Anda akan keluar dari program\n\n");
	system("pause");
	help_choice();
}

//============================================================================================================

void help_logout()
{
	system("cls");
	printf("~~~~~HELP~~~~~\n");
	printf("Menu Log Out\n\n");
	printf("Pada menu ini, user bisa menutup akun yang sedang digunakan dan masuk kembali dengan akun lain yang dimilikinya\n\n");
	system("pause");
	help_choice();
}

int logoutAwal()
{
	system("cls");
	printf("Apakah kamu yakin ingin keluar?\nTekan 1 untuk Ya\nTekan 0 untuk kembali ke menu\n");
	printf("Please Input Your Choice : ");
	switch(getch())
	{
		case'1':
			break;
			
		case'0':
			menu_login();
			
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 and 1 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			logoutAwal();
	}
}

int logout()
{
	system("cls");
	printf("Apakah kamu yakin ingin keluar?\nTekan 1 untuk Ya\nTekan 0 untuk kembali ke menu\n");
	printf("Please Input Your Choice : ");
	switch(getch())
	{
		case'1':
			break;
			
		case'0':
			menu();
			
		default:
			printf("\n\n\t\t\t\t   Wrong input!\n");
	    	printf("\t\t\t\t   Please input choice between 0 and 1 only!\n\n");
	    	printf("\t\t\t\t   ");
	    	system("pause");
			logout();
	}
}

//=====================================================================================// fungsi passing parameters
void ketik(char* a, int b)
{
	int i;
	for(i=0;i<strlen(a);i++)
	{
		printf("%c",a[i]);
		Sleep(b);
	}
}

//=============================================================================================

void fordelay(int y)
{   int x,z;
    for(x=0;x<y;x++)
         z=x;
}
