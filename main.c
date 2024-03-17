#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
void separator()
{
    for(int i = 1; i < 9*13; i++)
        printf("-");
    printf("\n");
}
void out_file(FILE *f,int n,int k)
{
    float out;
    int f1;
    printf("file%d:\t",k);
    while(fread(&out,sizeof(float),1,f))
        printf("%.3f\t",out);
    printf("\n");
}
float function1(int n)
{
    float f=0;
    int i,factorial=1;
    for(i=1; i<=n; i++)
        factorial*=i;
    f=sqrt(n)+factorial;
    return f;
}
float function2(int i)
{
    float f=0;
    f=i*pow(sin(i),3);
    return f;
}
float function3(int i)
{
    float f=0;
    f=i*pow(tan(i-1),i);
    return f;
}
float function4(int i)
{
    float f=0;
    f=i*pow(cos(i+1),i+1);
    return f;
}

void block_1()
{
    FILE *f,*g,*k,*l,*ob;
    int n=1,f1;
    float medium;

    //in count N
    while(n)
    {
        printf("Count columns from 7 to 40:");
        scanf("%d",&n);
        if( n>=7 && n<=40)
        {
            break;
        }
        else
        {
            printf("The entered text is not conditional.\n");
            fflush (stdin); // fflush == clean cache-
        }
    }
    //

    //in
    separator();

    printf("Started:\n\n");

    if((f=fopen("file_1.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((g=fopen("file2.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((k=fopen("file3.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    if((l=fopen("file4.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(4);
    }

    for(f1=n; f1>0; f1--)
    {
        medium = function1(f1);//1
        fwrite(&medium,sizeof(float),1,f);
        medium = function2(f1);
        fwrite(&medium,sizeof(float),1,g);
        medium = function3(f1);//3
        fwrite(&medium,sizeof(float),1,k);
        medium = function4(f1);//4
        fwrite(&medium,sizeof(float),1,l);
    }
    fclose(f);
    fclose(g);
    fclose(k);
    fclose(l);

    if((f=fopen("file_1.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((g=fopen("file2.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((k=fopen("file3.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    if((l=fopen("file4.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(4);
    }

    out_file(f,n,1);
    printf("\n");
    out_file(g,n,2);
    printf("\n");
    out_file(k,n,3);
    printf("\n");
    out_file(l,n,4);
    printf("\n");

    fclose(f);
    fclose(g);
    fclose(k);
    fclose(l);

    //obmin

    if((ob=fopen("obmin.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(5);
    }
    if((k=fopen("file3.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    while(fread(&medium,sizeof(float),1,k))
        fwrite(&medium,sizeof(float),1,ob);
    fclose(ob);
    fclose(k);

    if((k=fopen("file3.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    if((f=fopen("file_1.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    while(fread(&medium,sizeof(float),1,f))
        fwrite(&medium,sizeof(float),1,k);
    fclose(f);
    fclose(k);

    if((f=fopen("file_1.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((l=fopen("file4.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(4);
    }
    while(fread(&medium,sizeof(float),1,l))
        fwrite(&medium,sizeof(float),1,f);
    fclose(f);
    fclose(l);

    if((l=fopen("file4.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(4);
    }
    if((g=fopen("file2.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    while(fread(&medium,sizeof(float),1,g))
        fwrite(&medium,sizeof(float),1,l);
    fclose(l);
    fclose(g);

    if((g=fopen("file2.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((ob=fopen("obmin.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(5);
    }
    while(fread(&medium,sizeof(float),1,ob))
        fwrite(&medium,sizeof(float),1,g);
    fclose(g);
    fclose(ob);

    //out
    separator();
    printf("Finish:\n\n");

    if((f=fopen("file_1.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((g=fopen("file2.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((k=fopen("file3.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    if((l=fopen("file4.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(4);
    }

    out_file(f,n,1);
    printf("\n");
    out_file(g,n,2);
    printf("\n");
    out_file(k,n,3);
    printf("\n");
    out_file(l,n,4);
    printf("\n");

    fclose(f);
    fclose(g);
    fclose(k);
    fclose(l);
    separator();
    fflush (stdin); // fflush == clean cache-

}
void block_2()
{
    FILE *c;
    const int vowels_count = 12;
    const int consonants_count = 40;
    int position_ch2,position_end,i,j,k,f;
    char vowel,ch,ch1,rch1,rch2;
    char scan;
    char vowels[12]= {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    char consonants[40]= {'B','b','C','c','D','d','F','f','G','g','H','h',
                          'J','j','K','k','L','l','M','m','N','n','P','p','Q','q',
                          'R','r','S','s','T','t','V','v','W','w','X','x','Z','z'
                         };



    //in
    if((c = fopen("string.dat","wb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(6);
    }
    fclose(c);
    if((c = fopen("string.dat","rb+"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(6);
    }
    printf("Input text:");
    for(int i=1; i<= 20; i++)
    {
        scanf("%c",&scan);
        fwrite(&scan,sizeof(scan),1,c);
    }

    fclose(c);

    //change
    if((c = fopen("string.dat","rb+"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(6);
    }

    while(fread(&rch1,sizeof(rch1),1,c));
    position_end = ftell(c);
    fseek(c,0,SEEK_SET);

    k=0,f=-1;
    while(!feof(c) && k<=position_end-3 && f==-1)
    {
        fseek(c,k,SEEK_SET);
        fread(&rch1,sizeof(rch1),1,c);
        fread(&vowel,sizeof(vowel),1,c);
        position_ch2 = ftell(c);
        fread(&rch2,sizeof(rch2),1,c);

        for(i=0; i<=consonants_count; i++)
            if(rch1==consonants[i] )
            {
                for(j=0; j<=vowels_count; j++)
                    if(vowel==vowels[j])
                        for(int p=0; p<=consonants_count; p++)
                            if(rch2==consonants[p])
                            {
                                f=1;
                                break;
                            }
            }
        k++;
    }
    for(i=position_ch2-1; i<=position_end-1; i++)
    {
        fseek(c,i+1,SEEK_SET);
        fread(&ch1,sizeof(ch),1,c);
        fseek(c,i,SEEK_SET);
        fwrite(&ch1,sizeof(ch1),1,c);
    }
    fseek(c,position_end-1,SEEK_SET);
    fwrite(&vowel,sizeof(vowel),1,c);

    fclose(c);

    //out
    printf("Final\n");
    if((c = fopen("string.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(6);
    }
    while (fread(&ch,sizeof(ch),1,c))
        printf("%c",ch);
    fclose(c);
    fflush (stdin); // fflush == clean cache-

}
void block_3()
{
    FILE *text1,*text2,*h;
    char ch;

    if((text1 = fopen("textfile1.txt","r"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((text2 = fopen("textfile2.txt","r"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    h = fopen("h.txt","w");

    int c,flag=0;

    while((ch=fgetc(text1))!=EOF && (ch=='\n'));

    if((ch!=EOF) && (ch!='\n'))
    {
        do
        {
            if ((flag==0) && (!isspace(ch)))
                fputc(ch,h);
            else if((flag==0) && (ch=='\n'))
            {
                fputc(ch,h);
                flag=1;
            }
            else if ((flag==1) && (ch=='\n'));
            else if ((flag==1)  && (isalpha(ch)) )
            {
                fputc(ch,h);
                flag=0;
            }
            else if (isspace(ch))
                fputc(ch,h);
        }
        while((ch=fgetc(text1))!=EOF);
    }

    fputc('\n',h);

    while((ch=fgetc(text2))!=EOF && (ch=='\n'));

    if((ch!=EOF) && (ch!='\n'))
    {
        do
        {
            if ((flag==0) && (!isspace(ch)))
                fputc(ch,h);
            else if((flag==0) && (ch=='\n'))
            {
                fputc(ch,h);
                flag=1;
            }
            else if ((flag==1) && (ch=='\n'));
            else if ((flag==1)  && (isalpha(ch)) )
            {
                fputc(ch,h);
                flag=0;
            }
            else if (isspace(ch))
                fputc(ch,h);
        }
        while((ch=fgetc(text2))!=EOF);
    }

    fclose(text1);
    fclose(text2);
    fclose(h);

    //out
    if((h = fopen("h.txt","r"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }
    printf("Final h:\n");
    while (fread(&ch,sizeof(ch),1,h))
        printf("%c",ch);
    fclose(h);
    fflush (stdin); // fflush == clean cache-

}
void GotoXY(int X, int Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleTextAttribute(hStdOut,4);
    SetConsoleCursorPosition(hStdOut, coord);
}

void colour(int i)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,i);
}

void ConsoleCursorVisible(int show, short size)//the visibility of the cursor
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
void about_blocks()
{
    FILE *about;
    char c;
    if ((about=fopen("about.txt", "r"))==NULL)
    {
        perror("This situation is bad because of:\t");
    }
    while(fread(&c,sizeof(c),1,about))
        printf("%c",c);
    fclose(about);
    fflush (stdin); // fflush == clean cache-
}
void menu()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    ConsoleCursorVisible(0, 100);
    //меню
    const char* menuOptions[] = {"About blocks","Block 1","Block 2","Block 3","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        GotoXY(38, 8);
        printf("To switch to another mode,\n");
        GotoXY(30, 9);
        printf("switch using the left and right arrows on keyboard.\n");
        int x = 0, y = 12;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x+=18, y);
            if (i == active_menu)
            {
                colour(8);
                printf("[ %s ] ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 75://Left
            if (active_menu > 0)
                active_menu--;
            break;
        case 77://Right
            if (active_menu < numOptions - 1)
                active_menu++;
            break;

        case 13://enter
            switch (active_menu)
            {
            case 0:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                GotoXY(0, 0);
                about_blocks();
                _getch();
                system("CLS");
                break;
            case 1:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                GotoXY(24, 0);
                block_1();
                _getch();
                system("CLS");
                break;
            case 2:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                block_2();
                _getch();
                system("CLS");
                break;
            case 3:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                system("CLS");
                block_3();
                _getch();
                system("CLS");
                break;
            case 4:
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
                exit(0);
                break;
            }
            break;

        }
    }

}
int main()
{
    menu();
    return 0;
}
