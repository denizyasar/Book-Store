#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct users
{
    char username[30];
    char password[30];
};
struct Bookinfo
{
    char book_name[20];
    char author[20];
    char type[15];
    char printing[15];
    int pagecount;
};
struct Newspaperinfo
{
    char name[20];
    double price;
    int pagecount;
};
struct Magazineinfo
{
    char name[20];
    char author[20];
    char type[15];
    char printing[15];
    int pagecount;
    double price;
};

int Login(struct users user_login)
{
    puts("..::: LOGIN PAGE :::..");
    int returntype=0;
    printf("USERNAME:");
    gets(user_login.username);
    printf("PASSWORD:");
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
void Register(struct users user)
{
    puts("..::: REGISTER  PAGE :::..");
    printf("USERNAME:");
    gets(user.username);

    printf("PASSWORD:");
    gets(user.password);

    FILE *userDB;
    userDB=fopen("users.txt","a");
    fprintf(userDB,"%s %s\n",user.username,user.password);
    fclose(userDB);
}

void newspaperAra(struct Newspaperinfo newspaperinfo)
{
    puts("..::: SEARCH  NEWSPAPER :::..");
    char name[20];
    char temp[20]="";
    printf("Newspaper name:");
    gets(name);

    int i=1;
    puts("ID   NAME              pagecount price");
    FILE *newspaperDB;
    newspaperDB=fopen("newspaper.txt","r");
    while(!feof(newspaperDB))
    {
        fscanf(newspaperDB,"%s %d %lf\n",newspaperinfo.name,&newspaperinfo.pagecount,&newspaperinfo.price);
        strncpy(temp, newspaperinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-6d %.2lf\n",i,newspaperinfo.name,newspaperinfo.pagecount,newspaperinfo.price);
            i++;
        }
    }
    fclose(newspaperDB);
}
void newspaperList(struct Newspaperinfo newspaperinfo)
{
    puts("..::: LIST NEWSPAPERS :::..");
    int i=1;
    puts("ID   NAME              pagecount price");
    FILE *newspaperDB;
    newspaperDB=fopen("newspaper.txt","r");
    while(!feof(newspaperDB))
    {
        fscanf(newspaperDB,"%s %d %lf\n",newspaperinfo.name,&newspaperinfo.pagecount,&newspaperinfo.price);
        printf("%-4d %-20s %-6d %.2lf\n",i,newspaperinfo.name,newspaperinfo.pagecount,newspaperinfo.price);
        i++;
    }
    fclose(newspaperDB);
    puts("");
}
void newspaperAdd(struct Newspaperinfo newspaperinfo)
{
    puts("..::: ADD  NEWSPAPER :::..");
    printf("Newspaper name:");
    gets(newspaperinfo.name);
    printf("pagecount:");
    scanf("%d",&newspaperinfo.pagecount);
    printf("price:");
    scanf("%lf",&newspaperinfo.price);

    FILE *newspaperDB;
    newspaperDB=fopen("newspaper.txt","a");
    fprintf(newspaperDB,"%s %d %lf\n",newspaperinfo.name,newspaperinfo.pagecount,newspaperinfo.price);
    fclose(newspaperDB);
}

void magazineAra(struct Magazineinfo magazineinfo)
{
    puts("..::: SEARCH MAGAZINE :::..");
    char name[20];
    char temp[20]="";
    printf("name:");
    gets(name);

    int i=1;
    puts("ID   NAME              author               type            printing        pagecount price");
    FILE *magazineDB;
    magazineDB=fopen("magazine.txt","r");
    while(!feof(magazineDB))
    {
        fscanf(magazineDB,"%s %s %s %s %d %lf\n",magazineinfo.name,magazineinfo.author,magazineinfo.type,magazineinfo.printing,&magazineinfo.pagecount,&magazineinfo.price);
        strncpy(temp, magazineinfo.name,strlen(name));
        if(strcmp(name,temp)==0)
        {
            printf("%-4d %-20s %-20s %-15s %-15s %d %.2lf\n",i,magazineinfo.name,magazineinfo.author,magazineinfo.type,magazineinfo.printing,magazineinfo.pagecount,magazineinfo.price);
            i++;
        }
    }
    fclose(magazineDB);
}
void magazineList(struct Magazineinfo magazineinfo)
{
    puts("..::: LIST MAGAZINES :::..");
    int i=1;
    puts("ID   NAME              author               type            printing        pagecount price");
    FILE *magazineDB;
    magazineDB=fopen("magazine.txt","r");
    while(!feof(magazineDB))
    {
        fscanf(magazineDB,"%s %s %s %s %d %lf\n",magazineinfo.name,magazineinfo.author,magazineinfo.type,magazineinfo.printing,&magazineinfo.pagecount,&magazineinfo.price);
        printf("%-4d %-20s %-20s %-15s %-15s %-4d %.2lf\n",i,magazineinfo.name,magazineinfo.author,magazineinfo.type,magazineinfo.printing,magazineinfo.pagecount,magazineinfo.price);
        i++;
    }
    fclose(magazineDB);
    puts("");
}
void magazineAdd(struct Magazineinfo magazineinfo)
{
    puts("..::: ADD MAGAZINE :::..");
    printf("Magazine name:");
    gets(magazineinfo.name);
    printf("author:");
    gets(magazineinfo.author);
    printf("type:");
    gets(magazineinfo.type);
    printf("printing:");
    gets(magazineinfo.printing);
    printf("pagecount:");
    scanf("%d",&magazineinfo.pagecount);
    printf("price:");
    scanf("%lf",&magazineinfo.price);

    FILE *magazineDB;
    magazineDB=fopen("magazine.txt","a");
    fprintf(magazineDB,"%s %s %s %s %d %lf\n",magazineinfo.name,magazineinfo.author,magazineinfo.type,magazineinfo.printing,magazineinfo.pagecount,magazineinfo.price);
    fclose(magazineDB);
}
void bookAra(struct Bookinfo bookinfo)
{
    puts("..::: SERACH BOOK :::..");

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
    puts("..::: LIST BOOKS :::..");

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
    puts("..::: ADD BOOK :::..");
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
    int magazine_page=0;
    int newspaper_page=0;
    int durumlogin=0;
    char temp;

    struct users user;
    struct Bookinfo bookinfo;
    struct Magazineinfo magazineinfo;
    struct Newspaperinfo newspaperinfo;

    ///////////////////////////////////
    FILE *b,*u,*d,*g;
    b=fopen("books.txt","at");
    fclose(b);
    u=fopen("users.txt","at");
    fclose(u);
    d=fopen("magazine.txt","at");
    fclose(d);
    g=fopen("newspaper.txt","at");
    fclose(g);
    //.txt files generated in same folder
    //////
    puts("	..::: BOOK STORE MANAGEMENT SYSTEM :::..");
    //////////////////////////////////////////////////////////////////////
    do
    {
        puts("LOGIN    =1");
        puts("REGISTER =2");
        printf("Choice=");
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
                printf("Wrong Password !\n");
            }
            break;
        case 2 :
            Register(user);
            page=0;
            break;
        }
    }
    while(page==0);
    page=0;
/////////////////////////////////////////////////////////////////

    do
    {
        puts("	..::: BOOK STORE MANAGEMENT SYSTEM :::..");
        puts("Book......=1");
        puts("Magazine..=2");
        puts("Newspaper.=3");

        printf("Choice=");
        scanf("%d",&cevap);
        scanf("%c",&temp);
        switch(cevap)
        {
        case 1 :
            kitap_page=0;
            do
            {
                puts("Main Menu...=0");
                puts("Add Book....=1");
                puts("List Books..=2");
                puts("Search Book.=3");
                printf("Choice=");
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
            }
            while(kitap_page==0);
            break;
        case 2 :
            magazine_page=0;
            do
            {
                puts("Main Menu.......=0");
                puts("Add Magazine....=1");
                puts("List Magazines..=2");
                puts("Search Magazine.=3");
                printf("Choice=");
                scanf("%d",&cevap);
                scanf("%c",&temp);
                switch(cevap)
                {
                case 0 :
                    magazine_page=1;
                    break;
                case 1 :
                    magazineAdd(magazineinfo);
                    break;
                case 2 :
                    magazineList(magazineinfo);
                    break;
                case 3 :
                    magazineAra(magazineinfo);
                    break;
                }
            }
            while(magazine_page==0);
            break;
        case 3 :
            newspaper_page=0;
            do
            {
                puts("Main Menu........=0");
                puts("Add Newspaper....=1");
                puts("List Newspapers..=2");
                puts("Search Newspaper.=3");
                printf("Choice=");
                scanf("%d",&cevap);
                scanf("%c",&temp);
                switch(cevap)
                {
                case 0 :
                    newspaper_page=1;
                    break;
                case 1 :
                    newspaperAdd(newspaperinfo);
                    break;
                case 2 :
                    newspaperList(newspaperinfo);
                    break;
                case 3 :
                    newspaperAra(newspaperinfo);
                    break;
                }
            }
            while(newspaper_page==0);
            break;
        }
    }
    while(menu_page==0);

    puts("	end");
    system("PAUSE");
    return(0);
}

