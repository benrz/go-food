#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Variabel Global */
int input;
int position_x;
int position_y;
int i; //variabel counter dalam looping
int j; //variabel counter dalam looping
int user_sekarang;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Struct */
struct SYSTEM{
    WORD wYear; //untuk tahun
    WORD wMonth; //untuk bulan
    WORD wDayOfWeek; //untuk hari keberapa dalam 1 minggu
    WORD wDay; //untuk tgl
    WORD wHour; //untuk jam
    WORD wMinute; //untuk menit
    WORD wSecond; //untuk detik
    WORD wMilliseconds; //untuk milidetik
};

struct rincian{
    int jumlah_order;
    char menu_order[100];
    int harga_order;
    char notes[100];
};

struct list{ //berisi keterangan menu-menu dari tiap restoran
    int nomor;
    int jenis; //kalau makanan 0, kalau minuman 1
    char nama[100];
    int harga;
};

struct RatingPromoSeller{
    int nomor;
    int rating;
    int best_seller;
};

struct data{ //berisi daftar restoran beserta keterangan-keterangannya
    int nomor;
    char nama[100];
    char alamat[300];
    char daerah[300];
    int jam_buka;
    int menit_buka;
    int jam_tutup;
    int menit_tutup;
    struct list menu[100]; // menunya apa aja
    struct RatingPromoSeller RPS;
    char promo[5];
    int byk_promo;
    char kategori[5];
    float jarak;
    int banyak_menu;
    int sama_kata;
    int status; //kalau restoran sedang buka 0, tutup 1
};

struct user{
    char nama[100];
    char alamat[200];
    char email[100];
    char noHP[15];
    char password[100];
    int go_pay;
};

struct driver{
    int nomor;
    char nama[100];
    float rating_driver;
    char komentar_user[100];
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function Prototype */
void home();
void logoAnimasi();
void logo();
void setcolor(int x);
void waktu(int *jam, int *menit, int *tgl, int *bln, int *thn);
void sorting_namaAscending(struct data restoran[], int banyak_restoran);
void login();
void signup();
void line(int i, int j, int position);
void index();
void header1(int position_y, int position_x);
void header2(position_y);
void prevnext(position_y, position_x);
void topup_gopay();
void searching(struct data restoran[], int banyak_restoran, int jenis_pilihan);
void newthisweek(struct data restoran[], int banyak_restoran);
void promotions(struct data restoran[], int banyak_restoran);
void nearme(struct data restoran[], int banyak_restoran);
void bestseller(struct data restoran[], int banyak_restoran);
void category(struct data restoran[], int banyak_restoran, char kodeCategory[]);
void twentyfourhours(struct data restoran[], int banyak_restoran);
void budgetmeal(struct data restoran[], int banyak_restoran, int harga_termurah[]);
void healthyfoods(struct data restoran[], int banyak_restoran);
void mostloved(struct data restoran[], int banyak_restoran);
void list_resto(struct data restoran[], int banyak_restoran, int jenis_pilihan);
void payment_detail(struct data restoran[], int total, int delivery_fee, int no_resto, int jenis_pembayaran);
void confirmation(struct data restoran[], int banyak_restoran, int *jumlah[], int total, int no_resto);
void RatingStar(int position_x);
void picking_up(int k, struct rincian order[], int banyak_restoran, int total, struct data restoran[], int no_resto, int delivery_fee, char alamat[], int jenis_pembayaran);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    system("title GO-FOOD");
    //home();
    while(1){
        index(); //halaman utama dari GO-FOOD
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void home(){
    system("cls");
    logoAnimasi();
    int jam, menit, tgl, bln, thn;
    input = 0; position_x = 0;
    while(input != 13){
        system("cls");
        logo();
        for(i = 0; i < 54; i++) printf(" ");
        waktu(&jam, &menit, &tgl, &bln, &thn);
        printf("%02d/%02d/%4d, %02d:%02d\n",tgl,bln,thn,jam,menit); //tampilin + passing jam&menit

        printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		if(position_x == 0)
		{
		    for(i = 0; i < 40; i++)
            {
                printf(" ");
            }
		    printf("%c", 186);
		    setcolor(10); printf("  >>  ");
		    printf(" "); setcolor(7); printf("Login");
		}
        else if(position_x == 1)
        {
            for(i = 0; i < 40; i++) printf(" ");
            printf("%c       ",186);
            printf("Login");
            printf("        %c ",186);
            setcolor(10); printf("  >>  ");
        }

        if(position_x == 0)
        {
            setcolor(7); printf("        %c",186); printf("       ");
            setcolor(7); printf("SignUp      %c\n",186);
        }
        else if(position_x == 1)
        {
            setcolor(7); printf("SignUp"); setcolor(7); printf("      %c\n",186);
        }
        setcolor(7); printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

		input = _getch();
        if(input == 77 && position_x != 1) position_x++; //Right Arrow
		else if(input == 75 && position_x != 0) position_x--; //Left Arrow
    }
    if(position_x == 0) login(0);//index();
    else signup();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Menampilkan logo pertama kali saat program dijalankan */
void logoAnimasi(){
    printf("\n"); setcolor(15);
    printf("########################################################################################################################## \n"); Sleep(100);
    printf("########################################################################################################################## \n"); Sleep(100);
    printf("#########    ########         ############");setcolor(12);printf("*");setcolor(15);printf("#");setcolor(12);printf("***");setcolor(15);printf("#####");setcolor(12);printf("**");setcolor(15);printf("########       #######         #######         #####          ###### \n"); Sleep(100);
    printf("#####           ####           ###########");setcolor(12);printf("*");setcolor(15);printf("#");setcolor(12);printf("***");setcolor(15);printf("####");setcolor(12);printf("****");setcolor(15);printf("#####          #####           #####           ####            #### \n"); Sleep(100);
    printf("####    ###########     ###     ##########");setcolor(12);printf("*****");setcolor(15);printf("####");setcolor(12);printf("****");setcolor(15);printf("#####    ##########     ###     ###     ###    ####    ####     ### \n"); Sleep(100);
    printf("###    ############    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n"); Sleep(100);
    printf("###    ############    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######          ####    #####    ###    #####    ###    #####    ### \n"); Sleep(100);
    printf("###    #####    ###    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n"); Sleep(100);
    printf("####    ####    ###    #####    #########___");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n"); Sleep(100);
    printf("####      ###   ####    ###    #########____");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ###########    ###    ####     ###    ####    ####    #### \n"); Sleep(100);
    printf("######          #####         ########______");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ############         #######         #####           ##### \n"); Sleep(100);
    printf("########################################################################################################################## \n");
    printf("########################################################################################################################## \n");
    printf("\n"); setcolor(7);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Menampilkan logo */
void logo(){
    printf("\n"); setcolor(15);
    printf("########################################################################################################################## \n");
    printf("########################################################################################################################## \n");
    printf("#########    ########         ############");setcolor(12);printf("*");setcolor(15);printf("#");setcolor(12);printf("***");setcolor(15);printf("#####");setcolor(12);printf("**");setcolor(15);printf("########       #######         #######         #####          ###### \n");
    printf("#####           ####           ###########");setcolor(12);printf("*");setcolor(15);printf("#");setcolor(12);printf("***");setcolor(15);printf("####");setcolor(12);printf("****");setcolor(15);printf("#####          #####           #####           ####            #### \n");
    printf("####    ###########     ###     ##########");setcolor(12);printf("*****");setcolor(15);printf("####");setcolor(12);printf("****");setcolor(15);printf("#####    ##########     ###     ###     ###    ####    ####     ### \n");
    printf("###    ############    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n");
    printf("###    ############    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######          ####    #####    ###    #####    ###    #####    ### \n");
    printf("###    #####    ###    #####    ############");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n");
    printf("####    ####    ###    #####    #########___");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ##########    #####    ###    #####    ###    #####    ### \n");
    printf("####      ###   ####    ###    #########____");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ###########    ###    ####     ###    ####    ####    #### \n");
    printf("######          #####         ########______");setcolor(12);printf("**");setcolor(15);printf("######");setcolor(12);printf("**");setcolor(15);printf("######    ############         #######         #####           ##### \n");
    printf("########################################################################################################################## \n");
    printf("########################################################################################################################## \n");
    printf("\n"); setcolor(7);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function dari setcolor */
void setcolor(int x){
     WORD c;
     HANDLE outs = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO cc;
     if(GetConsoleScreenBufferInfo(outs, &cc)){
          c = (cc.wAttributes & 0xF0) + (x & 0x0F);
          SetConsoleTextAttribute(outs, c);
     }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk mengambil waktu sekarang */
void waktu(int *jam, int *menit, int *tgl, int *bln, int *thn)
{
     struct SYSTEM str_t;
     GetSystemTime(&str_t);
     *jam = str_t.wHour+7;
     *menit = str_t.wMinute;
     *tgl = str_t.wDay;
     *bln = str_t.wMonth;
     *thn = str_t.wYear;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sorting_namaAscending(struct data restoran[], int banyak_restoran)
{
    int i,j;
    struct data temp;

    /* Sorting restoran berdasarkan nama secara ascending */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(strcmp(restoran[j].nama, restoran[j-1].nama) < 0)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk user login */
void login()
{
    system("cls");
    char email_login[100]; //Inputan email user
    char password_login[100]; //Inputan password user
    int flag = 0; //Penanda email & password inputan user sama atau berbeda dengan txt
    int jum_data; //Banyak data di txt
    int topUp; //Banyak saldo awal user
    struct user data_login[100];

    logo(); //Memamnggil Logo
    printf("Verifikasi data anda\n");

    /* Membaca inputan dari txt data_user */
    FILE *flogin = fopen("data_user.txt","r");
    jum_data = 0;
    while(!feof(flogin))
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[jum_data].nama, data_login[jum_data].alamat, data_login[jum_data].email, data_login[jum_data].noHP, data_login[jum_data].password, &data_login[jum_data].go_pay);
        jum_data++;
    }
    fclose(flogin);

    /* Menerima inputan email dan password login dari user */
    printf("Email        : ");
    scanf("%[^\n]",email_login); getchar(); //Menerima inputan email login dari user
    printf("Password     : ");
    i = 0;
    while(i<=99)
    {
        password_login[i] = getch(); //Menerima inputan password login dari user
        if(password_login[i] == 13)
        {
            password_login[i] = '\0'; //Keluar dari inputan password apabila user menekan ENTER
            break;
        }
        if(i >= 0 && password_login[i] == '\b') //Menghapus kata yang diketik user apabila user menekan BACKSPACE
        {
            if(i==0)
            {
                putch(' ');
                putch('\b');
            }
            else
            {
                putch('\b');
                putch(' ');
                putch('\b');
                i--;
            }
        }
        else
        {
            putch('*');
            i++;
        }
    }

    /* Mencari data dari txt yang sama dengan email & password login inputan user */
    for(i=0;i<jum_data;i++)
    {
        if(strcmp(password_login,data_login[i].password)==0 && strcmp(email_login,data_login[i].email)==0)
        {
            user_sekarang = i; //Menetapkan User yang sedang online
            flag = 1; //Penanda bahwa email & password login inputan user cocok dengan txt
        }
    }

    printf("\n");
    srand(time(NULL));
    int bil1, bil2, hasil;
    int flag1 = 0;

    /* CAPTCHA */
    while(1)
    {
        if(flag1 == 1) // flag == 1 penanda kalo inputan salah
        {
            printf("\nCaptcha yang Anda masukkan salah\n");

        }
        printf("CAPTCHA\n");

        /* Random bil1 dan bil2 */
        bil1 = rand() % 10;
        bil2 = rand() % 10;
        printf("%d + %d = ", bil1, bil2);
        scanf("%d", &hasil); //Inputan hasil dari penjumlahan 2 bilangan random oleh user

        if(hasil == bil1+bil2) //Apabila inputan benar, keluar dari looping
            break;
        else //Apabila inputan salah, user diminta memasukkan captcha ulang
        {
            system("cls");
            logo();
            printf("Masukkan data anda\n");
            printf("Email    : %s\n",email_login);
            printf("Password : ");
            i = 0;
            while(i<strlen(password_login))
            {
                putch('*');
                i++;
            }
            flag1 = 1;
        }
    }

    if(flag == 1) //Apabila inputan email, password, dan captcha benar, kembali ke home
    {
        Sleep(1000); printf("\nVerifikasi berhasil.");
        getchar();
        return;
    }
    else //Apabila inputan email dan password salah
    {
        printf("Email/Password tidak terdaftar\n");
        printf("Daftar sekarang ?\n");
        getch();
        int input = 0;
        int position = 0;
        while(input != 13)
        {
            system("cls");
            logo();
            printf("Masukkan data anda\n");
            printf("Email             : %s\n",email_login);
            printf("Password          : ");
            i = 0;
            while(i<strlen(password_login))
            {
                putch('*');
                i++;
            }
            printf("\n");
            line(0,0,position);printf("SIGN UP");line(0,1,position);
            printf("\n");
            line(1,0,position);printf("RESET");line(1,1,position);
            input = getch(); fflush(stdin);

            if(input == 80 && position != 1) position++;
            else if(input == 72 && position != 0) position--;
        }
        if(position == 0) signup(); //Memanggil Void Sign Up
        else if(position == 1) login(); //Kembali ke login
        getchar();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk user signup */
void signup()
{
    int byk_digit;
    struct user data_user;
    FILE *fdata = fopen("data_user.txt","a");
    while(1)
    {
        int flag_email = 0, pjg_email;
        int flag_hp = 1;
        system("cls");
        logo();
        printf("Masukkan data anda yang valid :\n");
        printf("-------------------------------\n");
        printf("Nama     : ");
        scanf("%[^\n]",data_user.nama); getchar();
        printf("Alamat   : ");
        scanf("%[^\n]",data_user.alamat); getchar();
        printf("Email    : ");
        scanf("%[^\n]",data_user.email); getchar();
        printf("No HP    : ");
        scanf("%[^\n]",data_user.noHP); getchar();
        byk_digit = strlen(data_user.noHP);
        if((data_user.noHP[0] != '0' && data_user.noHP[1] != '8') || byk_digit > 12 || byk_digit < 11) flag_hp = 0;
        printf("Password : ");
        int i=0;
        while(i<=99)
        {
            data_user.password[i] = getch();
            if(data_user.password[i] == 13)
            {
                data_user.password[i] = '\0';
                break;
            }
            if(i >= 0 && data_user.password[i] == '\b')
            {
                if(i==0)
                {
                    putch(' ');
                    putch('\b');
                }
                else
                {
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    i--;
                }
            }
            else
            {
                putch('*');
                i++;
            }
        }
        pjg_email = strlen(data_user.email);
        for(i = 0 ; i < pjg_email ; i++)
        {
            if(data_user.email[i] == '@')
            {
                if(data_user.email[pjg_email-1] == 'm' && data_user.email[pjg_email-2] == 'o' && data_user.email[pjg_email-3] == 'c' && data_user.email[pjg_email-4] == '.' && data_user.email[pjg_email-5] != '@')
                    flag_email = 1;
            }
        }
        if(flag_hp == 1 && data_user.password[0] != '\0' && flag_email == 1)
        {
            break;
        }
        else
        {
            int input = 0;
            int position = 0;
            while(input != 13)
            {
                system("cls");
                logo();
                printf("Masukkan data anda yang valid :\n");
                printf("-------------------------------\n");
                printf("Nama     : %s\n", data_user.nama);
                printf("Alamat   : %s\n", data_user.alamat);
                printf("Email    : %s\n", data_user.email);
                printf("No HP    : %s\n", data_user.noHP);
                printf("Password : ");
                i = 0;
                while(i<strlen(data_user.password))
                {
                    putch('*');
                    i++;
                }
                printf("\nNo Hp/password/email anda tidak valid.");
                printf("Ingin melanjutkan ?\n");
                line(0,0,position);printf("EXIT");line(0,1,position); //Kembali ke home
                printf("\n");
                line(1,0,position);printf("RESET");line(1,1,position); //Kembali ke signup
                input = getch(); fflush(stdin);

                if(input == 80 && position != 1) position++;
                else if(input == 72 && position != 0) position--;
            }
            if(position == 0) break; //Kembali ke home
            else if(position == 1) continue; //Kembali ke signup
            getchar();
        }
    }
    data_user.go_pay = 0; //Inisialisasi saldo gopay awal user = 0
    fprintf(fdata,"%s#%s#%s#%s#%s#%d\n", data_user.nama, data_user.alamat, data_user.email, data_user.noHP, data_user.password, data_user.go_pay);
    fclose(fdata);
    home();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk mengatur posisi arrow di login dan signgup */
void line(i,j,position)
{
    if(i == position)
    {
        if(j == 0) printf(">>");
        else printf("<<");
    }
    else printf("  ");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Halaman utama */
void index(){
    system("cls");
    input = 0, position_x = 0, position_y = 0; //reset var input, position_x, dan position_y
    struct data restoran[100];
    struct list menu[100];
    struct RatingPromoSeller RPS;
    struct user data_login[100];

    /* Membaca list restoran */
    FILE *f1 = fopen("List_Restoran.txt", "r");
    i = 0;
    while(!feof(f1)){
        fscanf(f1, "%d#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d.%d-%d.%d\n", &restoran[i].nomor, restoran[i].kategori, restoran[i].promo, restoran[i].nama, restoran[i].alamat, restoran[i].daerah, &restoran[i].jam_buka, &restoran[i].menit_buka, &restoran[i].jam_tutup, &restoran[i].menit_tutup);
        /* Membaca list menu */
        FILE *f2 = fopen("List_Menu.txt", "r");
        j = 0;
        while(!feof(f2)){
            fscanf(f2, "%d#%d#%[^#]#%d\n", &restoran[i].menu[j].nomor, &restoran[i].menu[j].jenis, &restoran[i].menu[j].nama, &restoran[i].menu[j].harga);
            if(restoran[i].nomor != restoran[i].menu[j].nomor) continue;
            j++;
        }
        restoran[i].banyak_menu = j;
        fclose(f2);
        /* Membaca list rating dan bestseller */
        FILE *f3 = fopen("List_Rating&BestSeller.txt", "r");
        j = 0;
        while(!feof(f3)){
            fscanf(f3, "%d#%d#%d\n", &restoran[i].RPS.nomor, &restoran[i].RPS.rating, &restoran[i].RPS.best_seller);
            if(restoran[i].nomor == restoran[i].RPS.nomor) break;
            j++;
        }
        fclose(f3);
        i++;
    }
    int banyak_restoran = i;
    fclose(f1);

    /* Random Jarak Restoran */
    srand(time(NULL));
    int jarak1, jarak2;
    for(i = 0; i < banyak_restoran; i++){
        jarak1 = (rand() % 9) + 1; //Jarak paling jauh 10 km, paling dekat 1 km
        jarak2 = (rand() % 9) + 1; //Jarak paling jauh 10 km, paling dekat 1 km
        restoran[i].jarak = (float)jarak1 / jarak2;
    }

    /* Random Besar Promo yang diberikan */
    for(i = 0; i < banyak_restoran; i++){
        if(strcmp(restoran[i].promo, "PRM") == 0)
            restoran[i].byk_promo = ((rand() % 9) + 1) * 5; //Promo paling besar 50%, paling kecil 5%
        else
            restoran[i].byk_promo = 0;
    }

    /* Menampilkan halaman index */
    while(input != 13){
        system("cls");
        header1(position_y, position_x);
        header2(position_y);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *** ***          %c %c       ##########      %c %c         ******         %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c    *** ***      (#)  %c %c     ##          ##    %c %c       **  **  **       %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *** ***    (##)  %c %c   ##  ***    /    ##  %c %c      ** **  ** **      %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c      *** ***  (##)   %c %c  ##  *****  /      ## %c %c      **  ****  **      %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *** ***  (##)    %c %c  ##   ***  / ***   ## %c %c      **  ----  **      %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c #################### %c %c  ##       / *****  ## %c %c       **      **       %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c ###              ### %c %c  ##      /  *****  ## %c %c     ___**    **___     %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c  ###            ###  %c %c   ##    /    ***  ##  %c %c   /     **  **     \\   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c    ###        ###    %c %c     ##          ##    %c %c  /        **        \\  %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     ############     %c %c       ##########      %c %c /____________________\\ %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c", 186); if(position_x == 0 && position_y == 0){setcolor(10);printf("  >> ");setcolor(7);} else printf("     ");
        printf("New This Week    %c ", 186, 186);
        printf("%c", 186); if(position_x == 1 && position_y == 0){setcolor(10);printf("  >>  ");setcolor(7);} else printf("      ");
        printf(" Promotions      %c ", 186, 186);
        printf("%c", 186); if(position_x == 2 && position_y == 0){setcolor(10);printf("  >>  ");setcolor(7);} else printf("      ");
        printf("   Near Me        %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c          **          %c %c  ########   ########  %c %c       **********       %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c         *  *         %c %c  ##    ##   ##    ##  %c %c     **    /\\   **      %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c        *    *        %c %c  ##    ##   ##    ##  %c %c   **      ||     **    %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c * * * *   #  * * * * %c %c  ########   ########  %c %c  **       ||      **   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c  *      ###       *  %c %c          \\ /          %c %c  **       ||      **   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c   *      ##      *   %c %c          / \\          %c %c  **9      **     3**   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c    *     ##     *    %c %c  ########   ########  %c %c  **               **   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *   ####   *     %c %c  ##    ##   ##    ##  %c %c   **             **    %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c      **********      %c %c  ##    ##   ##    ##  %c %c     **    6     **     %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     ************     %c %c  ########   ########  %c %c      ***********       %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c", 186); if(position_x == 0 && position_y == 1) {setcolor(10);printf("  >>  ");setcolor(7);} else printf("      ");
        printf("Best Seller     %c ", 186, 186);
        printf("%c  ", 186); if(position_x == 1 && position_y == 1){setcolor(10);printf(">>    ");setcolor(7);} else printf("      ");
        printf("Category       %c ", 186, 186);
        printf("%c  ", 186); if(position_x == 2 && position_y == 1){setcolor(10);printf(">>    ");setcolor(7);} else printf("      ");
        printf("24 Hours        %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c          ##          %c %c     ***       ***     %c %c         **             %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *****##****      %c %c   **   **   **   **   %c %c        *  |            %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c   ****   ##  ****    %c %c **      ** **      ** %c %c       *   |            %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c  ****    ##          %c %c **        *        ** %c %c  ###**     \\________   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c    ******##*         %c %c **                 ** %c %c  ###          _______) %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c         *##******    %c %c  **               **  %c %c  ###          _______) %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c          ##    ***   %c %c    **            **   %c %c  ###          _______) %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c   ****   ##   ****   %c %c     **        **      %c %c  ###          ______)  %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c     *****##****      %c %c       **    **        %c %c  ###          _____)   %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c          ##          %c %c          **           %c %c  ###_____________)     %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c                      %c %c                       %c %c                        %c\n", 186, 186, 186, 186, 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c", 186); if(position_x == 0 && position_y == 2) {setcolor(10);printf("  >>  ");setcolor(7);} else printf("      ");
        printf("Budget Meal     %c ", 186, 186);
        printf("%c", 186); if(position_x == 1 && position_y == 2) {setcolor(10);printf("  >>  ");setcolor(7);} else printf("      ");
        printf("Healthy Foods    %c ", 186, 186);
        printf("%c ", 186); if(position_x == 2 && position_y == 2){setcolor(10);printf(" >>   ");setcolor(7);} else printf("      ");
        printf("Most Loved       %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        input = _getch();
        /* Arrow */
        if(input == 77 && position_y == -3 && position_x != 1) position_x++; //Right Arrow untuk header
        else if(input == 80 && position_y == -2) position_y = position_y + 2, position_x = 0; //Down Arrow untuk header
        else if(input == 72 && position_y == -2) position_y--, position_x = 0; //Up Arrow untuk header
        else if(input == 72 && position_y == 0) position_y = position_y - 2, position_x = 0; //Up Arrow untuk header
        else if(input == 77 && position_x != 2 && position_y >= 0) position_x++; //Right Arrow
        else if(input == 75 && position_x != 0) position_x--; //Left Arrow
        else if(input == 80 && position_y != 2) position_y++; //Down Arrow
        else if(input == 72 && position_y == -1) position_y--, position_x = 0; //Up Arrow
        else if(input == 72 && position_y != -3) position_y--; //Up Arrow
    }

    /* Link ke halaman yang dipilih */
    if(position_y == -3 && position_x == 0) home(); //kembali ke home
    else if(position_y == -3 && position_x == 1) topup_gopay(); //mengisi saldo go-pay
    else if(position_y == -2) searching(restoran, banyak_restoran, 0); //searching restaurant
    else if(position_x == 0 && position_y == 0) list_resto(restoran, banyak_restoran, 1); //newthisweek();
    else if(position_x == 1 && position_y == 0) list_resto(restoran, banyak_restoran, 2); //promotions();
    else if(position_x == 2 && position_y == 0) list_resto(restoran, banyak_restoran, 3); //nearme();
    else if(position_x == 0 && position_y == 1) list_resto(restoran, banyak_restoran, 4); //bestseller();
    else if(position_x == 1 && position_y == 1) list_resto(restoran, banyak_restoran, 5); //category();
    else if(position_x == 2 && position_y == 1) list_resto(restoran, banyak_restoran, 6); //twentyfourhours();
    else if(position_x == 0 && position_y == 2) list_resto(restoran, banyak_restoran, 7); //budgetmeal();
    else if(position_x == 1 && position_y == 2) list_resto(restoran, banyak_restoran, 8); //healthyfoods();
    else list_resto(restoran, banyak_restoran, 9); //mostloved();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk menampilkan header back dan saldo go_pay */
void header1(int position_y, int position_x)
{
    struct user data_login[100];
    FILE *flogin = fopen("data_user.txt","r");
    int i = 0;
    while(!feof(flogin))
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[i].nama, data_login[i].alamat, data_login[i].email, data_login[i].noHP, data_login[i].password, &data_login[i].go_pay);
        i++;
    }
    fclose(flogin);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    if(position_y == -3 && position_x == 0)      {printf("%c",186);setcolor(10);printf(">>");setcolor(7);printf("  BACK    %c               GO-FOOD               %c   GO-PAY: Rp %8d  %c\n", 186, 186, data_login[user_sekarang].go_pay, 186);}
    else if(position_y == -3 && position_x == 1) {printf("%c    BACK    %c               GO-FOOD               ",186,186);printf("%c",186);setcolor(10);printf(">>");setcolor(7);printf(" GO-PAY: Rp %8d  %c\n", data_login[user_sekarang].go_pay, 186);}
    else                                         printf("%c    BACK    %c               GO-FOOD               %c   GO-PAY: Rp %8d  %c\n", 186, 186, 186, data_login[user_sekarang].go_pay, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk menampilkan header searching */
void header2(position_y)
{
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c", 186);if(position_y == -2) {setcolor(10);printf(">>");setcolor(7);} else printf("  ");
    printf(" Search   %c  Hungry? Let's eat!                                          %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk previous dan next */
void prevnext(position_y, position_x)
{
    printf("%c%c%c%c%c%c%c%c%c%c                                                         %c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    if(position_y == -1 && position_x == 0) {printf("%c",186);setcolor(10);printf(" <-");setcolor(7);printf("Prev %c                                                         %c   Next %c \n", 186, 186, 186);}
    else if(position_y == -1 && position_x == 1) {printf("%c   Prev %c                                                         %c", 186, 186, 186);setcolor(10);printf(" ->");setcolor(7);printf("Next %c \n", 186);}
    else printf("%c   Prev %c                                                         %c   Next %c \n", 186, 186, 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c                                                         %c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Function untuk mengisi saldo go-pay */
void topup_gopay()
{
    int topup;
    struct user data_login[100];
    FILE *flogin = fopen("data_user.txt","r");
    int byk_user = 0;
    while(!feof(flogin))
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[byk_user].nama, data_login[byk_user].alamat, data_login[byk_user].email, data_login[byk_user].noHP, data_login[byk_user].password, &data_login[byk_user].go_pay);
        byk_user++;
    }
    fclose(flogin);

    printf("Mau TOP UP berapa ? Rp ");
    scanf("%d", &topup);

    data_login[user_sekarang].go_pay += topup;


    FILE *flogin_overwrite = fopen("data_user.txt","w");
    for(i = 0; i < byk_user; i++)
    {
        fprintf(flogin_overwrite,"%s#%s#%s#%s#%s#%d\n", data_login[i].nama, data_login[i].alamat, data_login[i].email, data_login[i].noHP, data_login[i].password, data_login[i].go_pay);
    }
    fclose(flogin_overwrite);

    printf("Top Up berhasil!\n"); getch();
    return;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Melakukan searching restoran */
void searching(struct data restoran[], int banyak_restoran, int jenis_pilihan)
{
    char cari[100][100];
    int i,j,k,l;
    struct data temp;

    sorting_namaAscending(restoran, banyak_restoran);

    for(i = 0; i < banyak_restoran; i++)
    {
        restoran[i].sama_kata = 0;
    }

    printf("Search : ");
    i = 0, j = 0;
    while(1)
    {
        scanf("%c",&cari[i][j]);
        if(cari[i][j] == '\n') break;
        if(cari[i][j] == 32)
        {
            i++;
            j = 0;
            continue;
        }
        j++;
    }
    fflush(stdin);
    /* Searching */
    j = 0;
    for(i = 0; i < banyak_restoran; i++)
    {
        k = 0;
        l = 0;
        for(j = 0; j < strlen(restoran[i].nama); j++)
        {
            if(cari[k][l] == '\n') break;
            else if(cari[k][l] == 32)
            {
                k++;
                l = 0;
            }
            else if(restoran[i].nama[j] == 32) l = 0;

            else if(restoran[i].nama[j] >= 65 && restoran[i].nama[j] <= 90) //Kalau huruf dari nama restoran berupa Uppercase
            {
                if(restoran[i].sama_kata == 0)
                {
                    if(cari[k][l] == restoran[i].nama[j] || cari[k][l] == restoran[i].nama[j]+32)
                    {
                        if(cari[k][l+1] == restoran[i].nama[j+1] || cari[k][l+1] == restoran[i].nama[j+1]+32)
                            {
                                restoran[i].sama_kata++;
                                l++;
                            }
                    }
                }
                else
                {
                    if(cari[k][l] == restoran[i].nama[j] || cari[k][l] == restoran[i].nama[j]+32)
                    {
                        restoran[i].sama_kata++;
                        l++;
                    }
                    else l = 0;
                }
            }
            else if(restoran[i].nama[j] >= 97 && restoran[i].nama[j] <= 122) //Kalau huruf dari nama restoran berupa Lowercase
            {
                if(restoran[i].sama_kata == 0)
                {
                    if(cari[k][l] == restoran[i].nama[j] || cari[k][l] == restoran[i].nama[j]-32)
                    {
                        if(cari[k][l+1] == restoran[i].nama[j+1] || cari[k][l+1] == restoran[i].nama[j+1]-32)
                        {
                            restoran[i].sama_kata++;
                            l++;
                        }
                    }
                }
                else
                {
                    if(cari[k][l] == restoran[i].nama[j] || cari[k][l] == restoran[i].nama[j]-32)
                    {
                        restoran[i].sama_kata++;
                        l++;
                    }
                    else l = 0;
                }
            }
            else
            {
                if(restoran[i].sama_kata == 0)
                {
                    if(cari[k][l] == restoran[i].nama[j])
                    {
                        if(cari[k][l+1] == restoran[i].nama[j+1])
                        {
                            restoran[i].sama_kata++;
                            l++;
                        }
                    }
                }
                else
                {
                    if(cari[k][l] == restoran[i].nama[j])
                    {
                        restoran[i].sama_kata++;
                        l++;
                    }
                    else l = 0;
                }
            }
        }
    }
    /* BUBBLE SORT Descending kesamaan kata */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran;j>i;j--)
        {
            if(restoran[j].sama_kata > restoran[j-1].sama_kata)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;

            }
        }
    }
    list_resto(restoran, banyak_restoran, jenis_pilihan);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void newthisweek(struct data restoran[], int banyak_restoran){
    int i, j;
    struct data temp;

    /* Sorting Descending nomor restoran */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(restoran[j].nomor > restoran[j-1].nomor)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void promotions(struct data restoran[], int banyak_restoran){
    int i, j;
    struct data temp;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting Descending nama restoran berdasarkan Promo */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(restoran[j].byk_promo > restoran[j-1].byk_promo)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }

    /*//untuk cek besar promo yang diperoleh
    for(i=0;i<banyak_restoran;i++)
    {
        printf("%d. %s : %d\n",i, restoran[i].nama, restoran[i].byk_promo);
    }
    getch();*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void nearme(struct data restoran[], int banyak_restoran){
    int i,j;
    struct data temp;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting Ascending nama restoran berdasarkan Jarak */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(restoran[j].jarak < restoran[j-1].jarak)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }

    for(i=0;i<banyak_restoran;i++) //Menampilkan jarak random tiap restoran
    {
        printf("Restoran %s : %0.2f\n",restoran[i].nama, restoran[i].jarak);
    }getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bestseller(struct data restoran[], int banyak_restoran){
    int i,j;
    struct data temp;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting Descending nama restoran Best Seller*/
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(restoran[j].RPS.best_seller > restoran[j-1].RPS.best_seller)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void category(struct data restoran[], int banyak_restoran, char kodeCategory[]){
    struct data temp;
    int i, j;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting nama restoran berdasarkan kode Category */
    for(i = 0; i < banyak_restoran; i++)
    {
        if(strcmp(restoran[i].kategori, kodeCategory) != 0)
        {
            for(j = i+1; j < banyak_restoran; j++)
            {
                if(strcmp(restoran[j].kategori, kodeCategory) == 0)
                {
                    temp = restoran[j];
                    restoran[j] = restoran[i];
                    restoran[i] = temp;
                    break;
                }
            }
        }
    }
    /*for(i=0;i<banyak_restoran;i++)
        printf("%s - %s\n", restoran[i].nama, restoran[i].kategori);
    getch();*/
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void twentyfourhours(struct data restoran[], int banyak_restoran){

    struct data temp;
    int i, j;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting nama restoran 24 Jam */
    for(i = 0; i < banyak_restoran; i++)
    {
        if(((restoran[i].jam_tutup * 60) + restoran[i].menit_tutup) - ((restoran[i].jam_buka * 60) + restoran[i].menit_buka) != 0)
        {
            for(j = i+1; j < banyak_restoran; j++)
            {
                if(((restoran[j].jam_tutup * 60) + restoran[j].menit_tutup) - ((restoran[j].jam_buka * 60) + restoran[j].menit_buka) == 0)
                {
                    temp = restoran[j];
                    restoran[j] = restoran[i];
                    restoran[i] = temp;
                    break;
                }
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void budgetmeal(struct data restoran[], int banyak_restoran, int harga_termurah[])
{
    struct data temp;
    int i,j;

    /* Sorting Ascending nama restoran dari restoran yang memiliki harga menu paling murah */
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran;j>i;j--)
        {
            if(harga_termurah[j] < harga_termurah[j-1])
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void healthyfoods(struct data restoran[], int banyak_restoran){
    struct data temp;
    int i, j;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting nama restoran berdasarkan kode HEA */
    for(i = 0; i < banyak_restoran; i++)
    {
        if(strcmp(restoran[i].kategori, "HEA") != 0)
        {
            for(j = i+1; j < banyak_restoran; j++)
            {
                if(strcmp(restoran[j].kategori, "HEA") == 0)
                {
                    temp = restoran[j];
                    restoran[j] = restoran[i];
                    restoran[i] = temp;
                    break;
                }
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostloved(struct data restoran[], int banyak_restoran){
    int i,j;
    struct data temp;

    sorting_namaAscending(restoran, banyak_restoran);

    /* Sorting Descending nama restoran Most Loved*/
    for(i=0;i<banyak_restoran;i++)
    {
        for(j=banyak_restoran-1;j>i;j--)
        {
            if(restoran[j].RPS.rating > restoran[j-1].RPS.rating)
            {
                temp = restoran[j];
                restoran[j] = restoran[j-1];
                restoran[j-1] = temp;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* List Restaurant */
void list_resto(struct data restoran[], int banyak_restoran, int jenis_pilihan){
    awal : system("cls");
    struct user data_login[100];
    input = 0, position_y = 0; //reset var input dan position_y
    int pilihan = jenis_pilihan; //berisi pilihan user untuk menampilkan restaurant apa saja
    int harga_termurah[banyak_restoran]; //harga termurah untuk budget meal
    char kodeCategory[5]; //berisi kode kategori dari restauran yang dipilih
    int byk_restobaru = 0; //berisi banyak restoran yang akan ditampilkan setelah sorting

    /* Sorting jenis pilihan secara Bubble Sort */
    switch(jenis_pilihan)
    {
        case 0 : //searching
        {
            for(i = 0; i < banyak_restoran; i++) //akan menampilkan restaurant dengan sama kata > 2 dengan inputan user
                if(restoran[i].sama_kata > 2)
                byk_restobaru++;
            break;
        }
        case 1 :
        {
            newthisweek(restoran, banyak_restoran);
            byk_restobaru = banyak_restoran;
            break;
        }
        case 2 :
        {
            promotions(restoran, banyak_restoran);
            for(i = 0; i < banyak_restoran; i++)
                if(restoran[i].byk_promo > 0)
                    byk_restobaru++;
            break;
        }
        case 3 :
        {
            nearme(restoran, banyak_restoran);
            for(i = 0; i < banyak_restoran; i++)
                if(restoran[i].jarak < 3)
                    byk_restobaru++;
            break;
        }
        case 4 :
        {
            bestseller(restoran, banyak_restoran);
            byk_restobaru = banyak_restoran;
            break;
        }
        case 5 :
        {
            input = 0; position_x = 0; position_y = 0; //reset var position_x dan position_y
            while(input != 13 || (position_x == 1 && position_y == -3)){ //jika input tidak sama dengan enter atau top up go-pay
                system("cls");
                header1(position_y, position_x);
                header2(position_y);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                if(position_x == 0 && position_y == 0)      {printf("%c");setcolor(10);printf(">>");setcolor(7);printf("     Indonesian      %c %c        Western        %c %c         Europe        %c\n", 186, 186, 186, 186, 186);}
                else if(position_x == 1 && position_y == 0) {printf("%c       Indonesian      %c %c",186,186,186);setcolor(10);printf(">>");setcolor(7);printf("      Western        %c %c         Europe        %c\n", 186, 186, 186);}
                else if(position_x == 2 && position_y == 0) {printf("%c       Indonesian      %c %c        Western        %c %c",186,186,186,186,186);setcolor(10);printf(">>");setcolor(7);printf("       Europe        %c\n", 186);}
                else                                        printf("%c       Indonesian      %c %c        Western        %c %c         Europe        %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188);

                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                if(position_x == 0 && position_y == 1)      {printf("%c");setcolor(10);printf(">>");setcolor(7);printf("        Thai         %c %c        Japanese       %c %c         Indian        %c\n", 186, 186, 186, 186, 186, 186);}
                else if(position_x == 1 && position_y == 1) {printf("%c          Thai         %c %c");setcolor(10);printf(">>");setcolor(7);printf("      Japanese       %c %c         Indian        %c\n", 186, 186, 186, 186, 186, 186);}
                else if(position_x == 2 && position_y == 1) {printf("%c          Thai         %c %c        Japanese       %c %c");setcolor(10);printf(">>");setcolor(7);printf("       Indian        %c\n", 186, 186, 186, 186, 186, 186);}
                else                                        printf("%c          Thai         %c %c        Japanese       %c %c         Indian        %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188);

                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187, 201,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 187);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                if(position_x == 0 && position_y == 2)      {printf("%c");setcolor(10);printf(">>");setcolor(7);printf("       Korean        %c %c        Chinese        %c %c  Desserts & Beverages %c\n", 186, 186, 186, 186, 186, 186);}
                else if(position_x == 1 && position_y == 2) {printf("%c         Korean        %c %c");setcolor(10);printf(">>");setcolor(7);printf("      Chinese        %c %c  Desserts & Beverages %c\n", 186, 186, 186, 186, 186, 186);}
                else if(position_x == 2 && position_y == 2) {printf("%c         Korean        %c %c        Chinese        %c %c");setcolor(10);printf(">>");setcolor(7);printf("Desserts & Beverages %c\n", 186, 186, 186, 186, 186, 186);}
                else                                        printf("%c         Korean        %c %c        Chinese        %c %c  Desserts & Beverages %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c                       %c %c                       %c %c                       %c\n", 186, 186, 186, 186, 186, 186);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188, 200,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 188);

                input = _getch();
                if(input == 13){
                    /* Kategori yang dipilih akan dimasukkan ke kodeCategory*/
                    if(position_x == 0 && position_y == 0) strcpy(kodeCategory, "IDN");
                    else if(position_x == 1 && position_y == 0) strcpy(kodeCategory, "WST");
                    else if(position_x == 2 && position_y == 0) strcpy(kodeCategory, "ERP");
                    else if(position_x == 0 && position_y == 1) strcpy(kodeCategory, "THA");
                    else if(position_x == 1 && position_y == 1) strcpy(kodeCategory, "JPN");
                    else if(position_x == 2 && position_y == 1) strcpy(kodeCategory, "IND");
                    else if(position_x == 0 && position_y == 2) strcpy(kodeCategory, "KOR");
                    else if(position_x == 1 && position_y == 2) strcpy(kodeCategory, "CNY");
                    else if(position_x == 2 && position_y == 2) strcpy(kodeCategory, "D&B");
                    else if(position_x == 0 && position_y == -3) return; //balik ke halaman index
                    else if(position_x == 1 && position_y == -3) {
                        topup_gopay();
                        continue;
                    }
                    else if(position_y == -2)
                    {
                        searching(restoran, banyak_restoran, 0); goto awal; //balik ke list_resto
                    }
                }
                /* Arrow */
                else if(input == 77 && position_y == -3 && position_x != 1) position_x++; //Right Arrow untuk header
                else if(input == 80 && position_y == -2) position_y = position_y + 2, position_x = 0; //Down Arrow untuk header
                else if(input == 72 && position_y == -2) position_y--, position_x = 0; //Up Arrow untuk header
                else if(input == 72 && position_y == 0) position_y = position_y - 2, position_x = 0; //Up Arrow untuk header
                else if(input == 80 && position_y != 2) position_y++; //Down Arrow
                else if(input == 72 && position_y != -3) position_y--; //Up Arrow
                else if(input == 77 && position_y >= 0 && position_x != 2) position_x++; //Right Arrow
                else if(input == 75 && position_x != 0) position_x--; //Left Arrow
            }
            category(restoran, banyak_restoran, kodeCategory);
            for(i = 0; i < banyak_restoran; i++){
                if(strcmp(restoran[i].kategori, kodeCategory) == 0) byk_restobaru++; //Jumlah restoran baru yang ingin ditampilkan sesuai dengan kode kategori yang dipilih
            }
            input = 0; position_y = 0; //reset var input dan position_y
            break;
        }
        case 6 :
        {
            twentyfourhours(restoran, banyak_restoran);
            for(i = 0; i < banyak_restoran; i++)
                if(((restoran[i].jam_tutup * 60) + restoran[i].menit_tutup) - ((restoran[i].jam_buka * 60) + restoran[i].menit_buka) == 0)
                    byk_restobaru++; //Jumlah restoran baru yang buka 24 jam
            break;
        }
        case 7 :
        {
            /* Menentukan harga termurah dari tiap restoran */
            for(i=0;i<banyak_restoran;i++)
            {
                harga_termurah[i] = restoran[i].menu[0].harga;
                for(j=0;j<restoran[i].banyak_menu;j++)
                {
                    if(restoran[i].menu[j].harga < harga_termurah[i])
                        harga_termurah[i] = restoran[i].menu[j].harga;
                }
            }
            budgetmeal(restoran, banyak_restoran, harga_termurah);
            byk_restobaru = banyak_restoran;
            break;
        }
        case 8 :
        {
            healthyfoods(restoran, banyak_restoran);
            for(i = 0; i < banyak_restoran; i++)
                if(strcmp(restoran[i].kategori, "HEA") == 0)
                    byk_restobaru++; //Jumlah restoran healthy yang ingin ditampilkan
            break;
        }
        case 9 :
        {
            mostloved(restoran, banyak_restoran);
            byk_restobaru = banyak_restoran;  //Jumlah restoran dari rating user yang tertinggi yang ingin ditampilkan
            break;
        }
    }

    /* Menampilkan list restoran */

    /*Var pembatas untuk previous next */
    int index_awal = 0, index_akhir = 6;
    int byk_page, byk_tampilanRestoran = 7; //banyak halaman & byk restoran max pada 1 halaman
    int sisa_byk_restobaru, selisih_index;
    int halaman_saatini = 1;
    int jam, menit, tgl, bln, thn; //berisi waktu sekarang

    menu_resto :
    byk_page = (byk_restobaru / byk_tampilanRestoran) + 1;
    sisa_byk_restobaru = byk_restobaru % byk_tampilanRestoran;

    if(byk_restobaru != 0)
    {
        while(1){
            system("cls");
            header1(position_y, position_x);
            header2(position_y);
            prevnext();

            if(byk_restobaru <= index_akhir)
                index_akhir = byk_restobaru-1; //index akhir mengikuti jumlah resto baru -1 jika byk_restobaru lebih kecil atau sama dengan index akhir

            for(i = index_awal; i <= index_akhir; i++) //looping untuk previous next
            {
                if(i == index_awal) printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
                if(i == position_y) {printf("%c",186);setcolor(10);printf(" >> ");setcolor(7);}
                else printf("%c    ", 186);
                printf("%c %-69s%c\n", 186, restoran[i].nama, 186); //Menampilkan nama restoran di center
                printf("%c    %c %-69s%c\n", 186, 186, restoran[i].alamat, 186); //Menampilkan alamat restoran di center
                printf("%c    %c %-69s%c\n", 186, 186, restoran[i].daerah, 186); //Menampilkan daerah restoran di center
                if(strcmp(restoran[i].kategori, "IDN") == 0)     printf("%c    %c Indonesian                                                           %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "ERP") == 0)printf("%c    %c European                                                             %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "IND") == 0)printf("%c    %c Indian                                                               %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "KOR") == 0)printf("%c    %c Korean                                                               %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "JPN") == 0)printf("%c    %c Japanese                                                             %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "THA") == 0)printf("%c    %c Thai                                                                 %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "HEA") == 0)printf("%c    %c Healthy                                                              %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "WST") == 0)printf("%c    %c Western                                                              %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "D&B") == 0)printf("%c    %c Desserts & Beverages                                                 %c\n", 186, 186, 186);
                else if(strcmp(restoran[i].kategori, "CNY") == 0)printf("%c    %c Chinese                                                              %c\n", 186, 186, 186);
                waktu(&jam, &menit, &tgl, &bln, &thn); //Memanggil void waktu
                if(restoran[i].jam_tutup != 00 && restoran[i].jam_buka != 00){ //Jika restoran tidak 24 jam buka
                    if((((restoran[i].jam_tutup*60) + restoran[i].menit_tutup) < ((jam*60)+menit)) //Jika waktu sekarang lebih besar waktu buka dan tutup restoran
                        && (((restoran[i].jam_buka*60) + restoran[i].menit_buka) < ((jam*60)+menit))){
                        restoran[i].status = 1;
                        printf("%c    %c %.2d:%.2d-%.2d:%.2d . %4.2f km                                         Closed %c\n", 186, 186, restoran[i].jam_buka, restoran[i].menit_buka, restoran[i].jam_tutup, restoran[i].menit_tutup, restoran[i].jarak, 186);
                    }
                    else{
                        if((((restoran[i].jam_tutup*60) + restoran[i].menit_tutup) - ((jam*60)+menit)) <= 60){ //Jika waktu tutup restoran kurang dari 60 menit lagi
                            restoran[i].status = 0;
                            printf("%c    %c %.2d:%.2d-%.2d:%.2d . %4.2f km                             Closing in %2d mins %c\n", 186, 186, restoran[i].jam_buka, restoran[i].menit_buka, restoran[i].jam_tutup, restoran[i].menit_tutup, restoran[i].jarak, (((restoran[i].jam_tutup*60) + restoran[i].menit_tutup) - ((jam*60)+menit)), 186);
                        }
                        else{
                        restoran[i].status = 0;
                        printf("%c    %c %.2d:%.2d-%.2d:%.2d . %4.2f km                                         Opened %c\n", 186, 186, restoran[i].jam_buka, restoran[i].menit_buka, restoran[i].jam_tutup, restoran[i].menit_tutup, restoran[i].jarak,186);
                        }
                    }
                }
                else{ //Jika restoran buka 24 jam maka open
                    restoran[i].status = 0;
                    printf("%c    %c %.2d:%.2d-%.2d:%.2d . %4.2f km                                         Opened %c\n", 186, 186, restoran[i].jam_buka, restoran[i].menit_buka, restoran[i].jam_tutup, restoran[i].menit_tutup, restoran[i].jarak,186);
                }
                if(i == index_akhir) printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
                else printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
            }

            input = _getch();
            if(input == 77 && position_y == -3 && position_x != 1) position_x++; //Right Arrow untuk header
            else if(input == 72 && position_y == index_awal) position_y = -1, position_x = 0; // Up Arrow untuk header
            else if(input == 72 && position_y == -2) position_y--, position_x = 0; // Up Arrow untuk header
            else if(input == 80 && position_y == -2) position_y++, position_x = 0; //Down Arrow untuk header
            else if(input == 80 && position_y == -1) position_y = index_awal; //Down Arrow untuk header
            else if(input == 80 && position_y != index_akhir) position_y++; //Down Arrow
            else if(input == 72 && position_y != -3) position_y--; //Up Arrow
            else if(input == 77 && position_y == -1 && position_x != 1) position_x++; //Right Arrow
            else if(input == 75 && (position_y == -1 || position_y == -3) && position_x != 0) position_x--; //Left Arrow
            else if(input == 13 && position_y == -1 && position_x == 1) //Next page
            {
                if(halaman_saatini < byk_page) //Saat halaman saat ini lebih kecil banyak page tiap resto untuk prev next
                {
                    if(index_akhir < byk_restobaru-1) index_awal += 7, index_akhir += 7;
                    if(index_akhir >= byk_restobaru-1)
                    {
                        selisih_index = index_akhir - (byk_restobaru-1);
                        index_akhir -= selisih_index;
                    }
                    halaman_saatini++;
                }
            }
            else if(input == 13 && position_y == -1 && position_x == 0) //Previous page
            {
                if(halaman_saatini > 1) //Selama halaman sekarang bukan halaman paling awal
                {
                    if(index_awal > 0)
                    {
                        index_awal-=byk_tampilanRestoran;
                        if(halaman_saatini == byk_page) index_akhir -= sisa_byk_restobaru;
                        else index_akhir -= byk_tampilanRestoran;
                    }
                    else
                    {
                        selisih_index = index_awal;
                        index_awal += selisih_index;
                    }
                    halaman_saatini--;
                }
            }
            else if(input == 13 && position_y != -1){
                if(restoran[position_y].status == 1){ //Jika restoran sedang tutup
                    printf("Sorry, the restaurant is closed! Please choose another one."); Sleep(1000);
                    goto menu_resto;
                }
                else if(restoran[position_y].status == 0) break;
            }
        }
        if(position_y == -3 && position_x == 0){
            if(jenis_pilihan == 5) goto awal; //kembali ke list_resto
            else return; //kembali ke index
        }
        else if(position_y == -3 && position_x == 1) topup_gopay();
        else if(position_y == -2){ //Searching
            jenis_pilihan = 0;
            searching(restoran, banyak_restoran, jenis_pilihan);
            goto awal;
        }
        else
        {
            /* List Menu dari restoran yang dipilih */
            j = position_y;
            int no_resto = position_y;  //berisi restoran mana yang dipilih oleh user
            input = 0;
            int total = 0, jumlah[100];
            int position_x_prevnext = 0;
            for(i=0; i<restoran[j].banyak_menu; i++){
                jumlah[i] = 0;
            }
            int banyak_makanan = 0, banyak_minuman = 0;
            for(i = 0; i < restoran[j].banyak_menu; i++){ //Menentukan jumlah makanan dan minuman di tiap restoran
                if(restoran[j].menu[i].jenis == 0) banyak_makanan++;
                else banyak_minuman++;
            }
            int byk_pesananBaru = 0; //untuk input order manual

            /* Menampilkan list menu */
            while(1)
            {
                position_x = 0; position_y = 0; //reset position_x dan position_y

                /* Var untuk previous next */
                int index_menu_awal=0, index_menu_akhir=6;
                byk_tampilanRestoran = 7; //banyak halaman & byk restoran max pada 1 halaman
                int byk_page_makanan, byk_page_minuman;
                int sisa_byk_makanan, sisa_byk_minuman;
                int halaman_Menu_saatini = 1;
                byk_page_makanan = (banyak_makanan / byk_tampilanRestoran) + 1;
                byk_page_minuman = (banyak_minuman / byk_tampilanRestoran) + 1;
                sisa_byk_makanan = banyak_makanan % byk_tampilanRestoran;
                sisa_byk_minuman = banyak_minuman % byk_tampilanRestoran;

                int flag = 1; //Penanda restoran belum dipilih
                while(1){
                    order:
                    system("cls");
                    header1(position_y, position_x_prevnext);
                    prevnext(position_y, position_x_prevnext);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
                    i = 0;
                    for(j=0; j<77; j++){
                        if(j == 0) printf("%c", 186);
                        else if(j == 76) printf("%c\n", 186);
                        else if(j < (77-strlen(restoran[no_resto].nama))/2) printf(" "); //Menampilkan nama resto di tengah
                        else printf("%c", restoran[no_resto].nama[i]), i++;
                    }
                    i = 0;
                    for(j=0; j<77; j++){
                        if(j == 0) printf("%c", 186);
                        else if(j == 76) printf("%c\n", 186);
                        else if(j < (77-strlen(restoran[no_resto].alamat))/2) printf(" "); //Menampilkan alamat resto di tengah
                        else printf("%c", restoran[no_resto].alamat[i]), i++;
                    }
                    i = 0;
                    for(j=0; j<77; j++){
                        if(j == 0) printf("%c", 186);
                        else if(j == 76) printf("%c\n", 186);
                        else if(j < (77-strlen(restoran[no_resto].daerah))/2) printf(" "); //Menampilkan alamat resto di tengah
                        else printf("%c", restoran[no_resto].daerah[i]), i++;
                    }
                    printf("%c", 186);
                    printf("                                 %.2d:%.2d-%.2d:%.2d                               %c\n", restoran[no_resto].jam_buka, restoran[no_resto].menit_buka, restoran[no_resto].jam_tutup, restoran[no_resto].menit_tutup, 186);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
                    printf("%c                  ", 186);
                    if(position_x == 0) printf("%c---------%c                                              %c\n", 218, 191, 186);
                    else if(position_x == 1)printf("              %c---------%c                                %c\n", 218, 191, 186);
                    else if(position_x == 2)printf("                            %c----------%c                 %c\n", 218, 191, 186);
                    printf("%c                  ", 186);
                    if(position_x == 0) printf("| Makanan |   "); else printf("  Makanan     ");
                    if(position_x == 1) printf("| Minuman |   "); else printf("  Minuman     ");
                    if(position_x == 2) printf("| Manually |                 %c\n", 186); else printf("  Manually                   %c\n", 186);
                    printf("%c                  ", 186);
                    if(position_x == 0) printf("%c---------%c                                              %c\n", 192, 217, 186);
                    else if(position_x == 1) printf("              %c---------%c                                %c\n", 192, 217, 186);
                    else if(position_x == 2) printf("                            %c----------%c                 %c\n", 192, 217, 186);

                    if(position_x != 2) //Selama tidak order manually
                    {
                        /* Jika banyak makanan atau minuman tidak nol */
                        if((position_x == 0 && banyak_makanan != 0) || (position_x == 1 && banyak_minuman != 0))
                            printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 203,205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 203, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 187, 186);

                        /* Mengatur jumlah index menu_akhir */
                        if(halaman_Menu_saatini == byk_page_makanan && byk_page_makanan == 1 && banyak_makanan > 0) index_menu_akhir = sisa_byk_makanan - 1;
                        else if(halaman_Menu_saatini == byk_page_minuman && byk_page_minuman == 1 && banyak_minuman > 0) index_menu_akhir = sisa_byk_minuman - 1;

                        /* Jika banyak makanan atau minuman tidak nol */
                        if((position_x == 0 && banyak_makanan != 0) || (position_x == 1 && banyak_minuman != 0))
                        {
                            for(i = index_menu_awal; i <= index_menu_akhir; i++) //Menampilkan daftar menu dari restoran yang dipilih
                            {
                                printf("%c  %c", 186, 186);
                                if(position_y == i) {setcolor(10);printf(" >> ");setcolor(7);printf("%c %3d ", 186, jumlah[i]);}
                                else printf("    %c %3d ", 186, jumlah[i]); //Menampilkan jumlah orderan dari tiap menu
                                printf("%c %-43s%c Rp %6d,- %c  %c\n", 186, restoran[no_resto].menu[i].nama, 186, restoran[no_resto].menu[i].harga, 186, 186);
                                if(i!= banyak_makanan-1 && i != restoran[no_resto].banyak_menu-1 && i != index_menu_akhir) printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 204, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 206,205,205, 205, 205, 205, 205,205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 206, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 185, 186);
                                if(i == index_menu_akhir) printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 202,205, 205, 205, 205, 205,205, 205, 205, 205,205, 205, 205, 205, 205,205, 205,205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 202, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 188, 186);
                            }
                        }
                    }
                    else if(position_x == 2){ //Halaman order manually
                        int temp; //Var sementara untuk orderan manul
                        if(byk_pesananBaru>0)printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 203,205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 203, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 187, 186);

                        /* Menampilkan orderan manual yang telah diinput */
                        for(temp = 0; temp < byk_pesananBaru; temp++){
                            if(jumlah[restoran[no_resto].banyak_menu+temp] > 0){ /* Menampilkan orderan manual yang lebih besar dari nol */
                                printf("%c  %c", 186, 186);
                                if(position_y == temp) {setcolor(10);printf(" >>");setcolor(7);printf(" %c %3d ", 186, jumlah[restoran[no_resto].banyak_menu+temp]);}
                                else printf("    %c %3d ", 186, jumlah[restoran[no_resto].banyak_menu+temp]);
                                printf("%c %-43s%c Rp %6d,- %c  %c\n",  186, restoran[no_resto].menu[restoran[no_resto].banyak_menu+temp].nama, 186, restoran[no_resto].menu[restoran[no_resto].banyak_menu+temp].harga, 186, 186);
                                if(temp!= byk_pesananBaru-1) printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 204, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 206,205,205, 205, 205, 205, 205,205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 206, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 185, 186);
                                else printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 202,205, 205, 205, 205, 205,205, 205, 205, 205,205, 205, 205, 205, 205,205, 205,205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 202, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 188, 186);
                            }
                        }

                        /* Menampilkan kotak input order manually */
                        printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 201, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 187, 186);
                        if(position_y == byk_pesananBaru){printf("%c  %c ",186,186);setcolor(10);printf(">>");setcolor(7);printf(" %c Input Order Manually                                           %c  %c\n",186, 186, 186);}
                        else printf("%c  %c    %c Input Order Manually                                           %c  %c\n",  186, 186, 186, 186, 186);
                        printf("%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c\n", 186, 200, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205,205, 205, 205, 205, 205,205, 205,205, 205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205,205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 205, 205, 205,205, 205, 188, 186);

                        /* Menampilkan total*/
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
                        if(position_y == byk_pesananBaru+1)  {printf("%c                     ");setcolor(10);printf(">>");setcolor(7);printf("  Estimated Price: Rp %6d,-                      %c\n", total, 186);}
                        else printf("%c                         Estimated Price: Rp %6d,-                      %c\n", 186, total, 186);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

                        /* Menampilkan how to use */
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
                        printf("%c   How to use:   -  Press Enter to add the number of orders                %c\n", 186, 186);
                        printf("%c                 -  Press Backspace to decrease the number of orders       %c\n", 186, 186);
                        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
                        if(flag == 0) printf("You have not choosen anything to order!"); //jika flag = 0 maka user tidak bisa lanjut ke halaman berikutnya

                        input = _getch();
                        if(input == 13 && position_y == byk_pesananBaru){ //Menerima input orderan secara manual
                            printf("Dish name        : "); fflush(stdin); //Nama makanan
                            scanf("%[^\n]", restoran[no_resto].menu[restoran[no_resto].banyak_menu+byk_pesananBaru].nama); fflush(stdin);
                            printf("Price estimation : Rp "); //Perkiraan harga
                            scanf("%d", &restoran[no_resto].menu[restoran[no_resto].banyak_menu+byk_pesananBaru].harga); fflush(stdin);
                            printf("Amount           : "); //Jumlah
                            scanf("%d", &jumlah[restoran[no_resto].banyak_menu+byk_pesananBaru]); fflush(stdin);
                            total += restoran[no_resto].menu[restoran[no_resto].banyak_menu+byk_pesananBaru].harga * jumlah[restoran[no_resto].banyak_menu+byk_pesananBaru];
                            byk_pesananBaru++;
                            position_y = 0; //Reset var position_y
                        }
                        else if(input == 13 && position_y == byk_pesananBaru+1) break;
                        else if(input == 13 && position_y == -3 && position_x_prevnext == 0) goto menu_resto;
                        else if(input == 13 && position_y == -3 && position_x_prevnext == 1) topup_gopay();
                        else if(input == 13){ //Menambah jumlah dan estimated price
                            jumlah[restoran[no_resto].banyak_menu+position_y]++;
                            total += restoran[no_resto].menu[restoran[no_resto].banyak_menu+position_y].harga;
                        }
                        else if(input == 8){ //Jika input = backspace
                            jumlah[restoran[no_resto].banyak_menu+position_y]--;
                            total -= restoran[no_resto].menu[restoran[no_resto].banyak_menu+position_y].harga;
                            if(jumlah[restoran[no_resto].banyak_menu+position_y] == 0){
                                j = 0;
                                for(i=0; i < byk_pesananBaru; i++){ //Menyusun ulang jumlah orderan yang lebih besar dari nol
                                    if(jumlah[restoran[no_resto].banyak_menu+i]>0){
                                        jumlah[restoran[no_resto].banyak_menu+j] = jumlah[restoran[no_resto].banyak_menu+i];
                                        strcpy(restoran[no_resto].menu[restoran[no_resto].banyak_menu+j].nama, restoran[no_resto].menu[restoran[no_resto].banyak_menu+i].nama);
                                        restoran[no_resto].menu[restoran[no_resto].banyak_menu+j].harga = restoran[no_resto].menu[restoran[no_resto].banyak_menu+i].harga;
                                        j++;
                                    }
                                }
                                byk_pesananBaru--;
                                if(position_y > 0) position_y--;
                            }
                        }
                        else if(input == 80 && position_y == -3) position_y = position_y + 2, position_x_prevnext = 0; //Down Arrow untuk header
                        else if(input == 80 && position_y != byk_pesananBaru+1) position_y++; //Down Arrow
                        else if(input == 72 && position_y == -1) position_y = position_y - 2, position_x_prevnext = 0; //Up Arrow untuk header
                        else if(input == 72 && position_y != -3) position_y--, position_x_prevnext = 0; //Up Arrow
                        else if(input == 77 && position_y == -3 && position_x_prevnext != 1) position_x_prevnext++; //Right Arrow untuk header
                        else if(input == 77 && position_y == -1 && position_x_prevnext != 1) position_x_prevnext++; //Right Arrow untuk header
                        else if(input == 77 && position_y == -3 && position_x_prevnext != 0) position_x_prevnext--; //Right Arrow untuk header
                        else if(input == 75 && (position_y == -1 || position_y == -3) && position_x_prevnext != 0) position_x_prevnext--; //Left Arrow
                        else if(input == 75 && position_x == 2 && position_y != -1) { //Left Arrow
                                position_x--; position_y = banyak_makanan;
                        }
                        if(jumlah[restoran[no_resto].banyak_menu+position_y] == 0){
                            i=0, j =0;
                            for(i=0; i < byk_pesananBaru; i++){
                                if(jumlah[restoran[no_resto].banyak_menu+i]>0){
                                    jumlah[restoran[no_resto].banyak_menu+j] = jumlah[restoran[no_resto].banyak_menu+i];
                                    j++;
                                }
                            }
                        }
                        continue;
                    }

                    /* Menampilkan estimated price*/
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
                    if(position_x == 1 && position_y == restoran[no_resto].banyak_menu) {printf("%c                     ",186);setcolor(10);printf(">>");setcolor(7);printf("  Estimated Price: Rp %6d,-                      %c\n", total, 186);}
                    else if(position_x == 0 && position_y == banyak_makanan)  {printf("%c                     ",186);setcolor(10);printf(">>");setcolor(7);printf("  Estimated Price: Rp %6d,-                      %c\n", total, 186);}
                    else printf("%c                         Estimated Price: Rp %6d,-                      %c\n", 186, total, 186);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
                    /*Menampilkan how to use */
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
                    printf("%c   How to use:   -  Press Enter to add the number of orders                %c\n", 186, 186);
                    printf("%c                 -  Press Backspace to decrease the number of orders       %c\n", 186, 186);
                    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
                    if(flag == 0) { //Jika user belum memesan apapun
                        printf("You have not choosen anything to order!"); Sleep(1000);
                        flag = 1;
                        continue;
                    }
                    /* Menampilkan jumlah pesanan*/
                    input = _getch();

                    /* Previous Next */
                    if(input == 13 && position_y == -1 && position_x == 0) //Untuk makanan
                    {
                        if(position_x_prevnext == 1) //Right Arrow
                        {
                            if(halaman_Menu_saatini < byk_page_makanan)
                            {
                                if(index_menu_akhir < banyak_makanan-1) index_menu_awal += 7, index_menu_akhir += 7;
                                if(index_menu_akhir >= banyak_makanan-1)
                                {
                                    selisih_index = index_menu_akhir - (banyak_makanan-1);
                                    index_menu_akhir -= selisih_index;
                                }
                                halaman_Menu_saatini++;}
                        }
                        else if(position_x_prevnext == 0) //Left Arrow
                        {
                            if(halaman_Menu_saatini > 1)
                            {
                                if(index_menu_awal > 0)
                                {
                                    index_menu_awal-=byk_tampilanRestoran;
                                    if(halaman_Menu_saatini == byk_page_makanan) index_menu_akhir -= sisa_byk_makanan;
                                    else index_menu_akhir -= byk_tampilanRestoran;
                                }
                                else if(index_menu_awal <= 0)
                                {
                                    selisih_index = index_menu_awal;
                                    index_menu_awal += selisih_index;
                                }
                                halaman_Menu_saatini--;
                                //position_y = index_awal;
                            }
                        }
                    }
                    else if(input == 13 && position_y == -1 && position_x == 1)//Untuk minuman
                    {
                        if(position_x_prevnext == 1) //Right Arrow
                        {
                            if(halaman_Menu_saatini < byk_page_minuman)
                            {
                                if(index_menu_akhir < banyak_makanan + banyak_minuman-1) index_menu_awal += 7, index_menu_akhir += 7;
                                if(index_menu_akhir >= banyak_makanan + banyak_minuman-1)
                                {
                                    selisih_index = index_menu_akhir - (banyak_makanan + banyak_minuman-1);
                                    index_menu_akhir -= selisih_index;
                                }
                                halaman_Menu_saatini++;
                            }
                        }
                        else if(position_x_prevnext == 0) //Left Arrow
                        {
                            if(halaman_Menu_saatini > 1)
                            {
                                if(index_menu_awal > banyak_makanan)
                                {
                                    index_menu_awal-=byk_tampilanRestoran;
                                    if(halaman_Menu_saatini == byk_page_minuman) index_menu_akhir -= sisa_byk_minuman;
                                    else index_menu_akhir -= byk_tampilanRestoran;
                                }
                                else if(index_menu_awal <= banyak_makanan)
                                {
                                    selisih_index = index_menu_awal;
                                    index_menu_awal += selisih_index;
                                }
                                halaman_Menu_saatini--;
                            }
                        }
                    }
                    else // Mengubah jumlah pesanan dan total
                    {
                        if(input == 13){
                            if((position_x == 0 && position_y != banyak_makanan)^(position_x == 1 && position_y != restoran[no_resto].banyak_menu)){
                                total += restoran[no_resto].menu[position_y].harga;
                                jumlah[position_y]++;
                            }
                            else break;
                        }
                        else if(input == 8 && jumlah[position_y] > 0){
                            if((position_x == 0 && position_y != banyak_makanan)^(position_x == 1 && position_y != restoran[no_resto].banyak_menu)){
                                total -= restoran[no_resto].menu[position_y].harga;
                                jumlah[position_y]--;
                            }
                        }
                    }

                    /* Arrow */
                    //Enter Header 1 & 2
                    if(input == 13 && position_y == -3 && position_x_prevnext == 0) goto menu_resto;
                    else if(input == 13 && position_y == -3&& position_x_prevnext == 1) topup_gopay();
                    else if(input == 13 && position_y == -2) searching(restoran, banyak_restoran, jenis_pilihan);

                    if(input == 80 && position_y == -3) position_y = position_y + 2, position_x_prevnext = 0; //Down Arrow dari header 1 ke header 2
                    else if(input == 72 && position_y == -1) position_y = position_y - 2, position_x_prevnext = 0; //Up Arrow dari header 2 ke header 1

                    else if(input == 77 && position_y == -3 && position_x_prevnext != 1) position_x_prevnext++; //Right Arrow di header 1
                    else if(input == 75 && position_y == -3 && position_x_prevnext != 0) position_x_prevnext--; //Left Arrow di header 1

                    else if(input == 77 && position_y == -1 && position_x_prevnext != 1) position_x_prevnext++; //Right Arrow di header 2
                    else if(input == 75 && position_y == -1 && position_x_prevnext != 0) position_x_prevnext--; //Left Arrow di header 2

                    else if(input == 77 && position_x == 1 && position_y != -1 && position_y != -3) position_x++, position_y = 0; //Right Arrow dari Minuman ke Order Manually
                    else if(input == 77 && position_x != 2 && position_y != -1 && position_y != -3) //Right Arrow dari Makanan ke Minuman
                    {
                        if(position_x == 0) position_x++, position_y = banyak_makanan, index_menu_awal = banyak_makanan, index_menu_akhir = banyak_makanan + byk_tampilanRestoran - 1; //Right Arrow untuk makanan
                        else position_x++, position_y = 0, index_menu_awal = 0, index_menu_akhir = 0;
                    }
                    else if(input == 75 && position_x != 0 && position_y != -1 && position_y != -3){ //Left Arrow dari Minuman ke Makanan
                        if(position_x == 2) position_y = banyak_makanan, position_x--, index_menu_awal = banyak_makanan, index_menu_akhir = banyak_makanan + byk_tampilanRestoran - 1;
                        else position_x--, position_y = 0, index_menu_awal = 0, index_menu_akhir = byk_tampilanRestoran - 1;
                    }
                    else if(input == 80 && position_x == 0 && position_y == -1) position_y = index_menu_awal, position_x_prevnext = 0; //Down Arrow dari Header 2 ke Index Awal Makanan
                    else if(input == 80 && position_x == 0 && position_y == index_menu_akhir) position_y = banyak_makanan; //Down Arrow dari Index Akhir Makanan ke Estimated Price
                    else if(input == 72 && position_x == 0 && position_y == banyak_makanan && banyak_makanan == 0) position_y = -1, position_x_prevnext = 0; //Up Arrow dari Index Awal Makanan ke Header 2 saat Banyak Makanan = 0
                    else if(input == 72 && position_x == 0 && position_y == banyak_makanan) position_y = index_menu_akhir; //Up Arrow dari Estimated Price ke Index Akhir Makanan
                    else if(input == 80 && position_x == 0 && position_y != index_menu_akhir && position_y != banyak_makanan) position_y++, position_x_prevnext = 0; //Down Arrow untuk Makanan
                    else if(input == 72 && position_x == 0 && position_y == index_menu_awal) position_y = -1, position_x_prevnext = 0; //Up Arrow dari Index Awal Makanan ke Header 2 saat Banyak Makanan != 0
                    else if(input == 72 && position_x == 0 && position_y != -3) position_y--, position_x_prevnext = 0; //Up Arrow untuk Makanan

                    else if(input == 80 && position_x == 1 && position_y == -1) position_y = index_menu_awal, position_x_prevnext = 0; //Down Arrow dari Header 2 ke  Index Awal Minuman
                    else if(input == 80 && position_x == 1 && position_y == index_menu_akhir) position_y = banyak_makanan + banyak_minuman; //Down Arrow dari Index Akhir Minuman ke Estimated Price
                    else if(input == 72 && position_x == 1 && position_y == banyak_makanan + banyak_minuman && banyak_minuman == 0) position_y = -1; //Up Arrow dari Index Awal Minuman ke Header 2 saat Banyak Minuman = 0
                    else if(input == 72 && position_x == 1 && position_y == banyak_makanan + banyak_minuman) position_y = index_menu_akhir; //Up Arrow dari Estimated Price ke Index Akhir Minuman
                    else if(input == 80 && position_x == 1 && position_y != index_menu_akhir && position_y != banyak_makanan + banyak_minuman) position_y++; //Down Arrow untuk Minuman
                    else if(input == 72 && position_x == 1 && position_y == index_menu_awal) position_y = -1; //Up Arrow dari Index Awal Minuman ke Header 2 saat Banyak Minuman != 0
                    else if(input == 72 && position_x == 1 && position_y != -3) position_y--, position_x_prevnext = 0; //Up Arrow untuk Minuman
                }
                restoran[no_resto].banyak_menu += byk_pesananBaru; //Ditambah dengan pesanan baru order manually
                flag = 0;
                for(i=0; i < restoran[no_resto].banyak_menu; i++){
                    if(jumlah[i]>0){
                        flag = 1; break; //Jika ada yang dipesan
                    }
                }
                if(flag == 0) goto order; //Jika tidak ada yang dipesan maka user tidak bisa lanjut ke halaman berikutnya
                confirmation(restoran, banyak_restoran, &jumlah, total, no_resto);
                return;

            }
        }
    }
    else //jika tidak ada restoran baru yang ditampilkan
    {
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                           Results not found!                              %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        Sleep(1500);
    }
 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void payment_detail(struct data restoran[], int total, int delivery_fee, int no_resto, int jenis_pembayaran)
{
    struct user data_login[100];
    FILE *flogin = fopen("data_user.txt","r");
    int jum_data = 0;
    while(!feof(flogin)) //Membaca data user untuk informasi go-pay
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[jum_data].nama, data_login[jum_data].alamat, data_login[jum_data].email, data_login[jum_data].noHP, data_login[jum_data].password, &data_login[jum_data].go_pay);
        jum_data++;
    }
    fclose(flogin);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c Payment details                                                           %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("%c Price (Estimated)                                            Rp %7d,- %c\n", 186, total, 186);
    printf("%c Promo %2d%%                                                   -Rp %7d,- %c\n", 186, restoran[no_resto].byk_promo, total*restoran[no_resto].byk_promo/100, 186);
    printf("%c Delivery Fee                                                 Rp %7d,- %c\n", 186, delivery_fee, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("%c Total Price                                                  Rp %7d,- %c\n", 186, (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee, 186);
    if(jenis_pembayaran == 0){ //Metode pembayaran sama dengan go-pay
        if(data_login[user_sekarang].go_pay <= (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee)
            printf("%c Pay with GO-PAY                                              Rp %7d,- %c\n", 186, data_login[user_sekarang].go_pay, 186);
        else printf("%c Pay with GO-PAY                                              Rp %7d,- %c\n", 186, (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee, 186);
    }
    else if(jenis_pembayaran == 1) //Metode pembayaran sama dengan cash
        printf("%c Pay with GO-PAY                                              Rp       0,- %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    if(jenis_pembayaran == 0){
        if(data_login[user_sekarang].go_pay <= (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee)
            printf("%c Pay with Cash                                                Rp %7d,- %c\n", 186, (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee - data_login[user_sekarang].go_pay, 186);
        else printf("%c Pay with Cash                                                 Rp      0,- %c\n", 186, 186);
    }
    else if(jenis_pembayaran == 1)
        printf("%c Pay with Cash                                                Rp %7d,- %c\n", 186, (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void confirmation(struct data restoran[], int banyak_restoran, int *jumlah[], int total, int no_resto)
{
    int position_x_header;
    int jenis_pembayaran = 0;
    struct user data_login[100];
    struct rincian order[100];
    int delivery_fee = 4000*restoran[no_resto].jarak; //Awalnya diset bayar pakai go-pay
    int byk_order, k;

    /* Membaca orderan user */
    j=0;
    for(i=0; i < restoran[no_resto].banyak_menu; i++){
        if(jumlah[i]>0){
            order[j].jumlah_order = jumlah[i];
            strcpy(order[j].menu_order, restoran[no_resto].menu[i].nama);
            order[j].harga_order = restoran[no_resto].menu[i].harga;
            j++;
        }
    }
    /* Set position_x untuk arrow = -1*/
    int position_x[j];
    for(i=0; i < j; i++){
        position_x[i] = -1;
    }
    /* Membaca data user */
    FILE *flogin = fopen("data_user.txt","r");
    int jum_data = 0;
    while(!feof(flogin))
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[jum_data].nama, data_login[jum_data].alamat, data_login[jum_data].email, data_login[jum_data].noHP, data_login[jum_data].password, &data_login[jum_data].go_pay);
        jum_data++;
    }
    fclose(flogin);
    /* Menampung alamat yang ingin diubah */
    char alamat[100];
    strcpy(alamat, data_login[user_sekarang].alamat);
    input = 0, position_y = 0; //Reset var input dan position_y

    /* Menampilkan halaman confirmation */
    while(1){
        byk_order = j;
        system("cls");
        header1(position_y, position_x_header);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c Items to order                                                            %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);

        /* Menampilkan items to order */
        for(i=0; i < j; i++){
            printf("%c", 186);
            if(position_y == i) {setcolor(10);printf("  >> ");setcolor(7);printf("%c", 186);} else printf("     %c", 186);
            printf(" %3d %c %-47s %c Rp %6d,- %c\n", order[i].jumlah_order, 186, order[i].menu_order, 186, order[i].harga_order, 186);
            printf("%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 186, 204, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
            if(position_x[i] == -1)     printf("%c     %c    (+)    (-)   %c    Notes: %-40s%c\n", 186, 186, 186, order[i].notes, 186);
            else if(position_x[i] == 0) {printf("%c     %c",186,186);setcolor(10);printf(" >>");setcolor(7);printf(" (+)    (-)   %c    Notes: %-40s%c\n", 186, order[i].notes, 186);}
            else if(position_x[i] == 1) {printf("%c     %c    (+) ",186,186);setcolor(10);printf(">>");setcolor(7);printf(" (-)   %c    Notes: %-40s%c\n", 186, order[i].notes, 186);}
            else if(position_x[i] == 2) {printf("%c     %c    (+)    (-)   %c",186,186,186);setcolor(10);printf(" >>");setcolor(7);printf(" Notes: %-40s%c\n", order[i].notes, 186);}
            if(i == j-1) printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
            else printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        }

        /* Menampilkan delivery to */
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c Delivery to                                                               %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        if(position_y == j) {printf("%c  ",186);setcolor(10);printf(">>");setcolor(7);printf(" %c %-68s%c\n", 186, alamat, 186);}
        else printf("%c     %c %-68s%c\n", 186, 186, alamat, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        /* Menampilkan how to pay */
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c How do you want to pay?                                                   %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 186, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        if(position_y == j+1) {printf("%c  ",186);setcolor(10);printf(">>");setcolor(7);printf(" %c GO-PAY                                                              %c\n", 186, 186);}
        else printf("%c     %c GO-PAY                                                              %c\n", 186, 186, 186);
        printf("%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 186, 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        if(position_y == j+2) {printf("%c  ",186);setcolor(10);printf(">>");setcolor(7);printf(" %c Cash                                                                %c\n", 186, 186);}
        else printf("%c     %c Cash                                                                %c\n", 186, 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        payment_detail(restoran, total, delivery_fee, no_resto, jenis_pembayaran);

         /* Menampilkan order now*/
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        if(position_y == j+3) {printf("%c                             ",186);setcolor(10);printf(">>");setcolor(7);printf("  Order Now                                 %c\n", 186);}
        else                  printf("%c                                 Order Now                                 %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        input = _getch();
        if(input == 13) {
            if(position_y == -3 && position_x_header == 0)
            {
                for(i=0; i < restoran[no_resto].banyak_menu; i++){
                    for(k = 0; k < byk_order; k++)
                    {
                        if(strcmp(restoran[no_resto].menu[i].nama, order[k].menu_order) == 0)
                        {
                            jumlah[i] = order[k].jumlah_order;
                            break;
                        }
                        else
                        {
                            jumlah[i] = 0;
                        }
                    }
                }
                return;
            }
            else if(position_y == -3 && position_x_header == 1) topup_gopay();
            else if(position_x[position_y] == -1) position_x[position_y]++;
            else if(position_x[position_y] == 0) order[position_y].jumlah_order++, total += order[position_y].harga_order;
            else if(position_x[position_y] == 2) scanf("%[^\n]", order[position_y].notes), fflush(stdin); //Untuk mengedit
            else if(position_x[position_y] == 1) order[position_y].jumlah_order--, total -= order[position_y].harga_order;
            if(order[position_y].jumlah_order == 0){ //Jika ada orderan yang dihapus, maka array order akan menyusun ulang
                j = 0;
                int k = i;
                for(i=0; i < k; i++){
                    if(order[i].jumlah_order>0){
                        order[j].jumlah_order = order[i].jumlah_order;
                        strcpy(order[j].menu_order, order[i].menu_order);
                        order[j].harga_order = order[i].harga_order;
                        strcpy(order[j].notes, order[i].notes);
                        j++;
                    }
                }
                if(j == 0)
                {
                    for(i=0; i < restoran[no_resto].banyak_menu; i++){
                        jumlah[i] = 0;
                    }
                    return;
                } //Kembali ke list_resto
                for(i=0; i < j+1; i++){ //Set ulang variable arrow position_x[i] menjadi -1;
                    position_x[i] = -1;
                }
                if(position_y == j) position_y--, order[j].jumlah_order = -1;
            }
            if(position_y == j) fflush(stdin), scanf("%[^\n]", alamat), fflush(stdin);
            else if(position_y == j+1) jenis_pembayaran = 0, delivery_fee = 4000*restoran[no_resto].jarak; //jika yang dipilih go-pay
            else if(position_y == j+2) jenis_pembayaran = 1,delivery_fee = 10000*restoran[no_resto].jarak; //jika yang dipilih cash
            else if(position_y == j+3) {
                picking_up(j, order, banyak_restoran, total, restoran, no_resto, delivery_fee, alamat, jenis_pembayaran);
                return;
            }
        }
        else if(input == 75 && position_y == -3 && position_x_header != 0) position_x_header--; //Left Arrow
        else if(input == 77 && position_y == -3 && position_x_header != 1) position_x_header++; //Left Arrow
        else if(input == 77 && position_x[position_y] != 2 && position_x[position_y] > -1) position_x[position_y]++; //Right Arrow
        else if(input == 75 && position_x[position_y] != 0 && position_x[position_y] > -1) position_x[position_y]--; //Left Arrow
        else if(input == 80 && position_y == -3) position_y = position_y + 3; //Down Arrow
        else if(input == 80 && position_y != j+3) position_x[position_y] = -1, position_y++; //Down Arrow
        else if(input == 72 && position_y == 0) position_y = position_y - 3, position_x_header = 0; //Up Arrow
        else if(input == 72 && position_y != -3) position_x[position_y] = -1, position_y--; //Up Arrow
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RatingStar(int position_x)
{
    setcolor(14);
    if(position_x == 0){
        printf("       *       \n");
        printf("      ***      \n");
        printf(" ************* \n");
        printf("   *********   \n");
        printf("    *******    \n");
        printf("    *** ***    \n");
        printf("    *     *    \n");
    }
    else if(position_x == 1){
        printf("       *               *        \n");
        printf("      ***             ***       \n");
        printf(" *************   *************  \n");
        printf("   *********       *********    \n");
        printf("    *******         *******     \n");
        printf("    *** ***         *** ***     \n");
        printf("    *     *         *     *     \n");
    }
    else if(position_x == 2){
        printf("       *               *               *        \n");
        printf("      ***             ***             ***       \n");
        printf(" *************   *************   *************  \n");
        printf("   *********       *********       *********    \n");
        printf("    *******         *******         *******     \n");
        printf("    *** ***         *** ***         *** ***     \n");
        printf("    *     *         *     *         *     *     \n");
    }
    else if(position_x == 3){
        printf("       *               *               *               *        \n");
        printf("      ***             ***             ***             ***       \n");
        printf(" *************   *************   *************   *************  \n");
        printf("   *********       *********       *********       *********    \n");
        printf("    *******         *******         *******         *******     \n");
        printf("    *** ***         *** ***         *** ***         *** ***     \n");
        printf("    *     *         *     *         *     *         *     *     \n");
    }
    else if(position_x == 4){
        printf("       *               *               *               *               *        \n");
        printf("      ***             ***             ***             ***             ***       \n");
        printf(" *************   *************   *************   *************   *************  \n");
        printf("   *********       *********       *********       *********       *********    \n");
        printf("    *******         *******         *******         *******         *******     \n");
        printf("    *** ***         *** ***         *** ***         *** ***         *** ***     \n");
        printf("    *     *         *     *         *     *         *     *         *     *     \n");
    }
    setcolor(7);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void picking_up(int k, struct rincian order[], int banyak_restoran, int total, struct data restoran[], int no_resto, int delivery_fee, char alamat[], int jenis_pembayaran){
    struct driver driver[100];
    struct user data_login[100];
    position_x = 0;

    /* Memasukkan waktu dr sistem */
    int jam, menit, tgl, bln, thn;
    waktu(&jam, &menit, &tgl, &bln, &thn);

    /* Membaca data user */
    FILE *flogin = fopen("data_user.txt","r");
    int jum_data = 0;
    while(!feof(flogin))
    {
        fscanf(flogin,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d\n", data_login[jum_data].nama, data_login[jum_data].alamat, data_login[jum_data].email, data_login[jum_data].noHP, data_login[jum_data].password, &data_login[jum_data].go_pay);
        jum_data++;
    }
    fclose(flogin);

    /* Membaca data driver */
    FILE *f6 = fopen("data_driver.txt", "r");
    int i = 0;
    while(!feof(f6)){
        fscanf(f6, "%d#%[^#]#%f\n", &driver[i].nomor, driver[i].nama, &driver[i].rating_driver);
        i++;
    }
    int acak_driver, byk_driver = i;
    fclose(f6);
    acak_driver = rand() % byk_driver;

    /*Menampilkan picking up*/
    while(1){
        system("cls");
        srand(time(NULL));
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c From: %-68s%c\n",186,restoran[no_resto].nama,186);
        printf("%c       %-68s%c\n",186,restoran[no_resto].alamat,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c To  : %-68s%c\n",186,alamat,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,188);printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c Order Details                                           %02d/%02d/%4d, %02d:%02d %c\n", 186,tgl,bln,thn,jam,menit, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,185);

        for(i=0; i < k; i++){
            printf("%c %-48s       %c %-2d%c Rp %6d,-  %c\n",186, order[i].menu_order,186, order[i].jumlah_order,186,order[i].harga_order,186);
            if(i!=k-1)
            {
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
            }
        }
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,188);printf("\n");

        /* Menampilkan payment_detail */
        payment_detail(restoran, total, delivery_fee, no_resto, jenis_pembayaran);

        /* Menampilkan driver dan statusnya */
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c             %c      \t\t\t\t\t\t\t    %c \n",186,186,186);
        printf("%c   ^_____^   %c    %-20s\t\t\t\t\t    %c \n",186,186, driver[acak_driver].nama,186);
        if(input == 1) printf("%c             %c    Status: Delivering Food\t\t\t\t    %c \n",186,186,186);
        else printf("%c             %c    Status: Picking Up Food\t\t\t\t    %c \n",186,186,186);
        printf("%c             %c      \t\t\t\t\t\t\t    %c \n",186,186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        /* Menampilkan kotak wait order */
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        if(position_x == 0)    {printf("%c\t      ",186);setcolor(10);printf(">>");setcolor(7);printf("  WAIT ORDER          %c          CANCEL ORDER\t\t    %c\n",186,186);}
        else if(position_x == 1) {printf("%c\t          WAIT ORDER          %c      ",186,186);setcolor(10);printf(">>");setcolor(7);printf("  CANCEL ORDER\t\t    %c\n",186);}
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        /* Jika user sudah siap untuk menunggu orderan */
        if(input == 1){
            Sleep(1000); printf("Your food will be arrived in a few minutes . "); Sleep(1000); printf(" . "); Sleep(1000); printf(" .\n");
            break;
        }

        input = _getch();
        if(input == 13 && position_x == 0){
            input = 1; //User ingin menunggu orderan
            Sleep(1000);
            continue;
        }
        else if(input == 13 && position_x == 1) return;
        else if(input == 77 && position_x != 1) position_x++;
        else if(input == 75 && position_x !=0) position_x--;
    }

    /* Menambah history pembelian +1 ke restoran yang dipilih */
    restoran[no_resto].RPS.best_seller++;
    FILE *f5 = fopen("List_Rating&BestSeller.txt","w");
    for(i = 0; i < banyak_restoran; i++)
    {
        fprintf(f5, "%d#%d#%d\n",restoran[i].RPS.nomor, restoran[i].RPS.rating, restoran[i].RPS.best_seller);
    }
    fclose(f5);

    /* Print Struk pembelian ke struk.txt */
    FILE *f4 = fopen("struk.txt", "w");
    fprintf(f4, "  From: %s\n", restoran[no_resto].nama);
    fprintf(f4, "        %s\n", restoran[no_resto].alamat);
    fprintf(f4, "  Today, at %d:%d\n", jam, menit);
    fprintf(f4, "\nPayment details\n");
    fprintf(f4, "  Price (Estimated)                       Rp %d,-\n", total);
    fprintf(f4, "  Promo %2d%%                              -Rp %d,-\n", restoran[no_resto].byk_promo, total*restoran[no_resto].byk_promo/100);
    fprintf(f4, "  Delivery Fee                            Rp %d,-\n", delivery_fee);
    fprintf(f4, "----------------------------------------------------------------\n");
    fprintf(f4, "  Total Price                             Rp %d,-\n", (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee);

    /* Mencetak struct */
    if(jenis_pembayaran == 0){
        if(data_login[user_sekarang].go_pay <= (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee)
            fprintf(f4, "  Pay with GO-PAY                         Rp %6d,- %c\n", data_login[user_sekarang].go_pay);
        else fprintf(f4, "  Pay with GO-PAY                          Rp %6d,- %c\n", (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee);
    }
    else if(jenis_pembayaran == 1)
        fprintf(f4, "  Pay with GO-PAY                                               Rp      0,- \n");
    fprintf(f4, "------------------------------------------------------------------\n");
    if(jenis_pembayaran == 0){
        if(data_login[user_sekarang].go_pay <= (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee)
            fprintf(f4, "  Pay with Cash                           Rp %6d,- %c\n", (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee - data_login[user_sekarang].go_pay);
        else fprintf(f4, "  Pay with Cash                                                 Rp      0,- \n");
    }
    else if(jenis_pembayaran == 1)
        fprintf(f4, "  Pay with Cash                           Rp %6d,- %c\n", (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee);
    fclose(f4);

    position_x = 4; //untuk rating awalnya bintang 5

    /* Rating driver */
    while(1){
        system("cls");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                        Thank you for using GO-FOOD!                       %c\n", 186, 186);
        printf("%c                                                                           %c\n", 186, 186);
        printf("%c                              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                              %c\n", 186, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 186);
        printf("%c                              %c             %c                              %c \n",186,186,186,186);
        printf("%c                              %c   ^_____^   %c                              %c \n",186,186,186,186);
        printf("%c                              %c             %c                              %c \n",186,186,186,186);
        printf("%c                              %c             %c                              %c \n",186,186,186,186);
        printf("%c                              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                              %c\n", 186, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 186);
        int m=0;
        for(i=0; i<77; i++){
            if(i == 0) printf("%c", 186);
            else if(i == 76) printf("%c\n", 186);
            else if( i < (77-strlen(driver[acak_driver].nama))/2 ) printf(" ");
            else printf("%c", driver[acak_driver].nama[m]), m++;
        }
        printf("%c                                                                           %c\n", 186, 186);
        printf("%c                                 Rp %6d,-                               %c\n", 186,  (total-(total*restoran[no_resto].byk_promo/100))+delivery_fee, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,188);printf("\n");
        printf("                              How was the service?\n\n");
        RatingStar(position_x);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                                  ",186);setcolor(10);printf(">>");setcolor(7);printf(" Submit                                %c\n", 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        input = _getch();
        if(input == 75 && position_x !=0) position_x--;
        else if(input == 77 && position_x !=4) position_x++;
        else if(input == 13){
            driver[acak_driver].rating_driver = ((float)driver[acak_driver].rating_driver + position_x+1) / 2;
            break;
        }
    }

    /* Overwrite data_driver.txt */
    FILE *f7 = fopen("data_driver.txt","w");
    for(i = 0; i < byk_driver; i++)
    {
        fprintf(f7, "%d#%s#%0.f\n", driver[i].nomor, driver[i].nama, driver[i].rating_driver);
    }
    fclose(f7);

    position_x = 4;
    /* Halaman rating restoran */
    while(1){
        system("cls");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                                  Delicious!                               %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c From: %-68s%c\n",186, restoran[no_resto].nama,186);
        printf("%c       %-68s%c\n",186, restoran[no_resto].alamat,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
        printf("%c To  : %-68s%c\n",186, alamat,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,188);printf("\n");
        printf("                     Give us your rating to the restaurant: \n\n");
        RatingStar(position_x);
        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("%c                                  ",186);setcolor(10);printf(">>");setcolor(7);printf(" Submit                                %c\n", 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

        input = _getch();
        if(input == 75 && position_x !=0) position_x--;
        else if(input == 77 && position_x !=4) position_x++;
        else if(input == 13){
            /* Overwrite List_Rating&BestSeller.txt */
            restoran[no_resto].RPS.best_seller++;
            restoran[no_resto].RPS.rating = ((float)restoran[no_resto].RPS.rating + position_x + 1) / 2;
            FILE *f5 = fopen("List_Rating&BestSeller.txt","w");
            for(i = 0; i < banyak_restoran; i++)
            {
                fprintf(f5, "%d#%d#%d\n",restoran[i].RPS.nomor, restoran[i].RPS.rating, restoran[i].RPS.best_seller);
            }
            fclose(f5);
            break;
        }
    }
    return;
}
