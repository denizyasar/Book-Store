#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct musteri{
	char tcno[11];
	char ad[50];
	char soyad[50];
	char adres[100];
};
struct users{
	char username[30];
	char password[30];
};
struct Bookinfo{
	char book_name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
};
struct Gazeteinfo{
	char name[20];
	double fiyat;
	int pagecount;
};
struct Dergiinfo{
	char name[20];
	char author[20];
	char type[15];
	char printing[15];
	int pagecount;
	double fiyat;
};
struct Kirtasiyeinfo{
	char name[20];
	double fiyat;
	char type[15];
};
 int Login(struct users user_login)
 {
     puts("..::: LOGIN PAGE :::..");
     int returntype=0;
 	printf("USERNAME:");
 	gets(user_login.username);
 	printf("password:");
 	gets(user_login.password);

    char username[30];
 	char password[30];
 	FILE *users;
 	users=fopen("users.txt","r");
 	while(!feof(users))
    {
        fscanf(users,"%s %s\n",username,password);
        if(strcmp(username,user_login.username)==0 &&strcmp(password,user_login.password)==0)
        {
            returntype=1;
            break;
        }
    }
 	fclose(users);
 	return returntype;
 }
 void Kaydol(struct users user)
 {
     puts("..::: KAYDOL  PAGE :::..");
 	printf("USERNAME:");
 	gets(user.username);

 	printf("password:");
 	gets(user.password);

 	FILE *userDB;
 	userDB=fopen("users.txt","a");
 	fprintf(userDB,"%s %s\n",user.username,user.password);
 	fclose(userDB);
 }

   void gazeteAra(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete ARA PAGE :::..");
    char name[20];
    char temp[20]="";
    printf("Gazete name:");
 	gets(name);

 	int i=1;
   puts("ID   NAME              pagecount Fiyat");
   FILE *gazeteDB;
   gazeteDB=fopen("gazete.txt","r");
   while(!feof(gazeteDB))
    {
        fscanf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,&gazeteinfo.pagecount,&gazeteinfo.fiyat);
        strncpy(temp, gazeteinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-6d %.2lf\n",i,gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
            i++;
        }
    }
 	fclose(gazeteDB);
}
 void gazeteList(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete LIST PAGE :::..");
    int i=1;
   puts("ID   NAME              pagecount Fiyat");
   FILE *gazeteDB;
   gazeteDB=fopen("gazete.txt","r");
   while(!feof(gazeteDB))
    {
        fscanf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,&gazeteinfo.pagecount,&gazeteinfo.fiyat);
            printf("%-4d %-20s %-6d %.2lf\n",i,gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
        i++;
    }
 	fclose(gazeteDB);
 	puts("");
}
void gazeteAdd(struct Gazeteinfo gazeteinfo)
{
    puts("..::: Gazete ADD PAGE :::..");
    printf("Gazete name:");
 	gets(gazeteinfo.name);
    printf("pagecount:");
 	scanf("%d",&gazeteinfo.pagecount);
 	printf("fiyat:");
 	scanf("%lf",&gazeteinfo.fiyat);

 	FILE *gazeteDB;
 	gazeteDB=fopen("gazete.txt","a");
 	fprintf(gazeteDB,"%s %d %lf\n",gazeteinfo.name,gazeteinfo.pagecount,gazeteinfo.fiyat);
 	fclose(gazeteDB);
}

   void dergiAra(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI ARA PAGE :::..");
    char name[20];
    char temp[20]="";
    printf("name:");
 	gets(name);

 	int i=1;
   puts("ID   NAME              author               type            printing        pagecount Fiyat");
   FILE *dergiDB;
   dergiDB=fopen("dergi.txt","r");
   while(!feof(dergiDB))
    {
        fscanf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,&dergiinfo.pagecount,&dergiinfo.fiyat);
        strncpy(temp, dergiinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-20s %-15s %-15s %d %.2lf\n",i,dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
            i++;
        }
    }
 	fclose(dergiDB);
}
 void dergiList(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI LIST PAGE :::..");
    int i=1;
   puts("ID   NAME              author               type            printing        pagecount Fiyat");
   FILE *dergiDB;
   dergiDB=fopen("dergi.txt","r");
   while(!feof(dergiDB))
    {
        fscanf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,&dergiinfo.pagecount,&dergiinfo.fiyat);
        printf("%-4d %-20s %-20s %-15s %-15s %-4d %.2lf\n",i,dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
        i++;
    }
 	fclose(dergiDB);
 	puts("");
}
void dergiAdd(struct Dergiinfo dergiinfo)
{
    puts("..::: DERGI ADD PAGE :::..");
    printf("dergi name:");
 	gets(dergiinfo.name);
 	printf("author:");
 	gets(dergiinfo.author);
    printf("type:");
 	gets(dergiinfo.type);
    printf("printing:");
 	gets(dergiinfo.printing);
    printf("pagecount:");
 	scanf("%d",&dergiinfo.pagecount);
 	printf("fiyat:");
 	scanf("%lf",&dergiinfo.fiyat);

 	FILE *dergiDB;
 	dergiDB=fopen("dergi.txt","a");
 	fprintf(dergiDB,"%s %s %s %s %d %lf\n",dergiinfo.name,dergiinfo.author,dergiinfo.type,dergiinfo.printing,dergiinfo.pagecount,dergiinfo.fiyat);
 	fclose(dergiDB);
}
  void bookAra(struct Bookinfo bookinfo)
{
        puts("..::: KITAP ARA PAGE :::..");

    char bookname[20];
    char temp[20]="";
    printf("bookname:");
 	gets(bookname);

 	int i=1;
   puts("ID   BOOK NAME            author               type            printing        pagecount");
   FILE *bookDB;
   bookDB=fopen("books.txt","r");
   while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,&bookinfo.pagecount);
        strncpy(temp, bookinfo.book_name,strlen(bookname));
        printf("%s_______\n",temp);
        if(strcmp(bookname,temp)==0)
        {
        printf("%-4d %-20s %-20s %-15s %-15s %d\n",i,bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
            i++;
        }
    }
 	fclose(bookDB);
}
 void bookList(struct Bookinfo bookinfo)
{
            puts("..::: KITAP LIST PAGE :::..");

    int i=1;
   puts("ID   BOOK NAME            author               type            printing        pagecount");
   FILE *bookDB;
   bookDB=fopen("books.txt","r");
   while(!feof(bookDB))
    {
        fscanf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,&bookinfo.pagecount);
        printf("%-4d %-20s %-20s %-15s %-15s %d\n",i,bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
        i++;
    }
 	fclose(bookDB);
 	puts("");
}
void bookAdd(struct Bookinfo bookinfo)
{
    puts("..::: BOOK ADD PAGE :::..");
    printf("book name:");
 	gets(bookinfo.book_name);
 	printf("author:");
 	gets(bookinfo.author);
    printf("type:");
 	gets(bookinfo.type);
    printf("printing:");
 	gets(bookinfo.printing);
    printf("pagecount:");
 	scanf("%d",&bookinfo.pagecount);

 	FILE *bookDB;
 	bookDB=fopen("books.txt","a");
 	fprintf(bookDB,"%s %s %s %s %d\n",bookinfo.book_name,bookinfo.author,bookinfo.type,bookinfo.printing,bookinfo.pagecount);
 	fclose(bookDB);
}
int main()
{
    int cevap;
    int page=0;
    int kitap_page=0;
    int menu_page=0;
    int dergi_page=0;
    int gazete_page=0;
    int durumlogin=0;
    char temp;

    struct users user;
    struct Bookinfo bookinfo;
    struct Dergiinfo dergiinfo;
    struct Gazeteinfo gazeteinfo;

    ///////////////////////////////////
    FILE *b,*u,*d,*g;
 	b=fopen("books.txt","at");
 	fclose(b);
 	u=fopen("users.txt","at");
    fclose(u);
 	d=fopen("dergi.txt","at");
    fclose(d);
    g=fopen("gazete.txt","at");
    fclose(g);
    //.txt dosyalarýný .exe nin çalýþtýðý klasörde oluþturur.
    //////
	puts("	..::: KITAP MAGZASI YONETÝM SISTEMI  :::..");
  //////////////////////////////////////////////////////////////////////
    do
    {
        puts("LOGIN=1");
        puts("KAYDOL=2");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
            case 1 :
                 durumlogin=Login(user);
                if(durumlogin==1)
                    page=1;
                else
                {
                    printf("Parola hatalý\n");
                }
                break;
            case 2 :
                Kaydol(user);
                page=0;
                break;
        }

    }while(page==0);
    page=0;
/////////////////////////////////////////////////////////////////

       do{
            puts("	..::: KITAP MAGZASI YONETIM SISTEMI  :::..");
        puts("Kitap Page=1");
        puts("Dergi Page=2");
        puts("Gazete Page=3");
        //puts("Kirtasiye Page=4");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
            case 1 :
                kitap_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Kitap Ekle=1");
        puts("Kitap Listele=2");
        puts("Kitap Ara=3");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            kitap_page=1;
            break;
            case 1 :
                bookAdd(bookinfo);
                break;
            case 2 :
                bookList(bookinfo);
                break;
            case 3 :
                bookAra(bookinfo);
                break;
        }

    }while(kitap_page==0);
                break;
            case 2 :
                dergi_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Dergi Ekle=1");
        puts("Dergi Listele=2");
        puts("Dergi Ara=3");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            dergi_page=1;
            break;
            case 1 :
                dergiAdd(dergiinfo);
                break;
            case 2 :
                dergiList(dergiinfo);
                break;
            case 3 :
                dergiAra(dergiinfo);
                break;
        }

    }while(dergi_page==0);
                break;
            case 3 :

                gazete_page=0;
                 do{
                      puts("Ana menu=0");
        puts("Gazete Ekle=1");
        puts("Gazete Listele=2");
        puts("Gazete Ara=3");
        printf("Secim=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 0 :
            gazete_page=1;
            break;
            case 1 :
                gazeteAdd(gazeteinfo);
                break;
            case 2 :
                gazeteList(gazeteinfo);
                break;
            case 3 :
                gazeteAra(gazeteinfo);
                break;
        }

    }while(gazete_page==0);



                break;
        }

    }while(menu_page==0);

	puts("	end");
	system("PAUSE");
	return(0);
}

