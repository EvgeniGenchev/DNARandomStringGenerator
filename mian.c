/******************
*Author: Evgeni Genchev
*Description: Sign Off 5.2
*Date 10/7/2019
*Student number: 474103
**********************/
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

int size, flag=0;
int arrayDNA1[100];
int arrayDNA2[100];
const char adenine='A', thymine='T', guanine='G', cytosine='C';


void userInput();
int dnaRandomizer();
void arrayPrinter();
void arrayChecker();

int main()
{
int flag=0;
    do
    {
        system("color F0");
        userInput();
        if(flag<0)
        {
            printf("Error");
            printf("...");
            return 0;
        }
        dnaRandomizer();
        arrayPrinter();
        arrayChecker();
        printf("Do you want to continue \n(1/0)\n");
        scanf("%d", &flag);

    } while( flag>0);
    return 0;
}


void userInput()
{
    printf("Enter DNA chain length: ");
    scanf("%d", &size);
    if(size<=0)
    {
        flag=1;
    }

}
int dnaRandomizer()
{
    int i=0, poll;
    srand(time(0));
    while(i<size)
    {
        poll=(rand()%4 );
        if(poll==0)
        {
            arrayDNA1[i]=adenine;
            arrayDNA2[i]=thymine;
        }
        else if(poll==1)
        {
            arrayDNA1[i]=thymine;
            arrayDNA2[i]=adenine;
        }
        else if(poll==2)
        {
            arrayDNA1[i]=guanine;
            arrayDNA2[i]=cytosine;

        }
        else
        {
            arrayDNA1[i]=cytosine;
            arrayDNA2[i]=guanine;
        }
        i++;
    }
    return;
}
void arrayPrinter()
{
    int i=0;
    printf("DNA String 1: ");
    while(i<size)
    {
        printf("%c", arrayDNA1[i]);
        i++;
    }
    printf("\n");
    printf("DNA String 2: ");
    i=0;
    while(i<size)
    {
        printf("%c", arrayDNA2[i]);
        i++;
    }
    printf("\n");
}
void arrayChecker()
{
    char c = 'R', d='E';
    for(int i = 0; i < size; i++)
    {
        if(arrayDNA1[i] == 'A' || arrayDNA1[i] == 'T')
        {
            if(c == 'R')
                c = arrayDNA1[i];
            else if(arrayDNA1[i] == c)
            {
                printf("DNA not viable for life\n");
                return;
            }
            else
            {
                c = arrayDNA1[i];
            }
        }
        if(arrayDNA1[i] == 'G' || arrayDNA1[i] == 'C')
        {
            if(d == 'E')
                d = arrayDNA1[i];
            else if(arrayDNA1[i] == d)
            {
                printf("DNA not viable for life\n");
                return;
            }
            else
            {
                d = arrayDNA1[i];
            }
        }
    }
    printf("DNA viable for life\n");


}
