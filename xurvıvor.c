
#include <stdio.h>
#include <stdlib.h>

void racecourse();
void numberOfBarriers();
void prime();
void finish();


int *ptrpu;  //pointer of pu
int pu;
int *ptrBarr,barr;
int *ptrBarriers,NumBarriers;
int i,hp=100;
int sayac=0;




void racecourse ()
{

    ptrpu=&pu;




    FILE *cbu=fopen("log.txt","w+");   //Open "cbu" file


    printf("------Welcome to Survivor------\n");
    fprintf(cbu,"------Welcome to Survivor------\n");


    pu=50+rand()%50;       //Random racecourse lenght (50-100)



    printf("\nContender HP=100");

    fprintf(cbu,"\nContender HP=100\n");

    fclose(cbu);      // close "cbu" file
}

void numberOfBarriers()
{


    ptrBarriers=&NumBarriers;


    FILE *cbu=fopen("log.txt","a");

    NumBarriers=2+rand()%3;   //Random number of Barriers



    fclose(cbu);
}

void prime()  //coprime control
{
    ptrBarr=&barr;

    FILE *cbu=fopen("log.txt","a");


    for(i=0; i<NumBarriers; i++)
    {
        if(hp<=0)
        {
            break;
        }
        int big,small,i,sonuc=1;
        barr=5+rand()%pu/2;

        sayac=sayac+barr;


        printf("\n\nThere is barrier at the %d meter\n",sayac);
        fprintf(cbu,"\n\nThere is barrier at the %d meter\n",sayac);





        if (barr <= hp)
        {
            big = hp;
            small = barr;


        }
        else
        {
            big = barr;
            small = hp;
        }

        for(i=1; i<=small-1; i++)
        {

            if(small % i == 0 && big % i == 0     )
            {
                sonuc = i;
            }


        }

        if(sonuc == 1)
        {


            printf ("%d ile %d is coprime \n",sayac,hp);
            fprintf(cbu,"\n%d ile %d is coprime",sayac,hp);
            hp=hp-sayac;

            printf("Contender hp: %d\n",hp);
            fprintf(cbu,"Contender hp: %d\n",hp);



        }


        else
        {



            printf ("%d ile %d is not coprime\n",sayac,hp);
            fprintf(cbu,"%d ile %d is coprime\n",sayac,hp);
            printf("Contender HP = %d",hp);
            fprintf(cbu,"Contender HP = %d",hp);




        }


    }


    fclose(cbu);
}


void finish()
{
    FILE *cbu=fopen("log.txt","a");
    if(hp>0)
    {

        printf("\nFinished with survivor;%d\n",hp);
        fprintf(cbu,"\nFinished with survivor;%d\n",hp);

    }
    else
    {
        printf("\nYou can not win\n");
        fprintf(cbu,"\nYou can not win");
    }



    fclose(cbu);


}


int main()
{



    srand(time(NULL));

    racecourse();
    numberOfBarriers();
    prime();
    finish();



    return 0;
}
