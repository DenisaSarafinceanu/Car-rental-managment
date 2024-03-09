/*****************************************************/
/* module2.c- See module2.h                          */
/*****************************************************/

/*System headers and application specific headers*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "module2.h"

/*Private constants*/

/*Private types*/

/*Private global variables*/

/*Public global variables*/

/*Implementation of the private functions*/

/*Implementation of the public function*/

struct Date{
  int day,month,year;
}d1,d2;

/*********************************************************************************/
/* Function name: leap                                                           */
/* Description: This function verifies if the year is leap or not.               */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/*  int                 x                 here it is the year which will be      */
/*                                        verified if it is leap                 */
/*********************************************************************************/
int leap(int x)
{
    if(x%400 == 0 || (x%4 == 0 && x%100 != 0))
        return 1;
    return 0;
}

/*********************************************************************************/
/* Function name: day_of_year                                                    */
/* Description: This function finds out the number of days in the current year is*/
/*              the date from the input.                                         */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/*   int                day               here it is the day of the date         */
/*   int               month              here it is the month of the date       */
/*   int                year              here it is the year of the date        */
/*********************************************************************************/
int day_of_year(int day, int month, int year)
{
    int days[]={0, 31, 28 + leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = day;
    for(int i = 1; i < month; i++)
    {
        sum += days[i];
    }
    return sum;
}

/*********************************************************************************/
/* Function name: difference                                                     */
/* Description: This function calculates the number of days between the initial  */
/*              date and the final date in order to apply the discount in case of*/
/*              there are more than 7 days.                                      */
/*********************************************************************************/
int difference()
{
  int days[]={0, 31, 28 + leap(d1.year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int dif=0;
  if(d1.year==d2.year)
  {
      if(d1.month==d2.month)
        dif=d2.day-d1.day;
      else
      {
          int i;
          dif=dif+days[d1.month]-d1.day;
          for(i=d1.month+1;i<d2.month;i++)
            dif=dif+days[i];
          dif=dif+d2.day;
      }
   }
   else
    {
        dif=dif+(365+leap(d1.year)-day_of_year(d1.day,d1.month,d1.year));
        for(int i=d1.year+1;i<d2.year;i++)
          dif=dif+365+leap(i);
        dif=dif+day_of_year(d2.day,d2.month,d2.year);
    }
    return dif+1;
}

/*********************************************************************************/
/* Function name: discount                                                       */
/* Description: This function generates a discount in case the period the client */
/*              rented the car is longer than 7 days.                            */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* int                  p                 this represents the period of time     */
/*                                        between the initial date and the       */
/*                                        final one                              */
/* float              *price              this is the price for every category   */
/*                                        of cars and it is a pointer because the*/
/*                                        value for every category is memorized  */
/*                                        in another function                    */
/* float                *t                this is the actual total even if there */
/*                                        is a discount or not                   */
/*********************************************************************************/
void discount(int p,float *price,float *t)
{
    float total=*price*p;
    if(p>7)
    {
        printf("------------------------------------------------------------\n");
        SetColor(3);
        printf("We are happy to inform you that you have a 10%% discount because the period\
        \nyou selected to rent the car is longer than 7 days.\n");
        SetColor(7);
        printf("------------------------------------------------------------\n");
        total=total-(0.1*total);
        SetColor(3);
        printf("The total is: %.2f$\n",total);
        SetColor(7);
        printf("------------------------------------------------------------\n");
    }
    else
    {
        printf("------------------------------------------------------------\n");
        SetColor(3);
        printf("   The total is: %.2f$\n",total);
        SetColor(7);
        printf("------------------------------------------------------------\n");
    }

    *t=total;
}

/*********************************************************************************/
/* Function name: invoice                                                        */
/* Description: This function generates the invoice which includes all the       */
/*              information that you typed for registering.                      */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* char                c[MAX]             here it is the category typed by him   */
/* char               name[50]            here it is the first and last name     */
/*                                        combined in one variable               */
/* char               number[7]           here it is the phone number typed      */
/*                                        by him                                 */
/* char              address[100]         here it is the address typed by him    */
/* float                *t                here it is a pointer which represents  */
/*                                        the total.It is a pointer because it is*/
/*                                        known its value from main              */
/* char                car1[40]           here it is the exact model of car chose*/
/*                                        by him                                 */
/* float              *price              here it is the regular price for each  */
/*                                        category which differs from the total  */
/* int                  diff              here it is the difference in days      */
/*                                        between the initial date and the final */
/*                                        one                                    */
/* char                det[40]            here there are the details for every   */
/*                                        car available                          */
/*********************************************************************************/
void invoice(char c[MAX],char name[50],char number[7],char address[100],float *t,char car1[40],float *price,int diff,char det[100])
{
    int width = 49;
    SetColor(9);
    printf("-------------------------------------------------\n");
    SetColor(14);

    char str[] = "INVOICE";
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;
    printf("%*.*s%s\n", pad, pad, " ", str);

    SetColor(9);
    printf("-------------------------------------------------\n"); //49
    SetColor(14);
    //printf("Number of the invoice: %d",)
    printf("Provider: \t %32s\n","DD Rentals Co.");
    printf("Place: \t %40s\n","Cluj-Napoca");
    printf("Phone Number: \t %32s\n","0265108362");
    printf("Customer Name: \t %32s\n",name);
    printf("Customer Phone Number: \t %24s\n",number);
    printf("Customer Address: \t %24s\n\n",address);

    char str1[] = "- Car Details -";
    int length1 = sizeof(str1) - 1;
    int pad1 = (length1 >= width) ? 0 : (width - length1) / 2;
    printf("%*.*s%s\n", pad1, pad1, " ", str1);

    int length2 = strlen(car1) - 1;
    int pad2 = (length2 >= width) ? 0 : (width - length2) / 2;
    printf("%*.*s%s\n", pad2, pad2, " ", car1);

    int length3 = strlen(c);
    int pad3 = (length3 >= width) ? 0 : (width - length3) / 2;
    printf("%*.*s%s\n", pad3, pad3, " ", c);

    printf("        %s       \n\n",det);

    printf("The initial date:  %*d.%d.%d\n",22,d1.day,d1.month,d1.year);
    printf("The final date:  %*d.%d.%d\n\n\n",24,d2.day,d2.month,d2.year);

    printf("Regular Price without discount: \t %7.2f$\n",*price*diff);
    if (diff > 7){
    printf("Price with discount: \t %23.2f$\n",*t);
    }
    SetColor(9);
    printf("-------------------------------------------------\n");
    SetColor(14);
    float vat = *t*0.19;
    printf("V.A.T. %*.2f$\n",41,vat);
    printf("Total %*.2f$\n\n\n",42,*t+vat);
    SetColor(7);
    printf("You can also find the invoice in: invoice.txt\n");
    SetColor(0);
}


/*********************************************************************************/
/* Function name: text                                                           */
/* Description: This function generates a file 'invoice.txt' which is located in */
/*              this project's folder and in this is the invoice that was shown  */
/*              above.                                                           */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* char                c[MAX]             here it is the category typed by you   */
/* char               name[50]            here it is the first and last name     */
/*                                        combined in one variable               */
/* char               number[7]           here it is the phone number typed      */
/*                                        by you                                 */
/* char              address[40]          here it is the address typed by you    */
/* float                *t                here it is a pointer which represents  */
/*                                        the total.It is a pointer because it is*/
/*                                        known its value from main              */
/* char                car1[40]           here it is the exact model of car chose*/
/*                                        by you                                 */
/* float              *price              here it is the regular price for each  */
/*                                        category which differs from the total  */
/* int                  diff              here it is the difference in days      */
/*                                        between the initial date and the final */
/*                                        one                                    */
/* char                det[40]            here there are the details for every   */
/*                                        car available                          */
/*********************************************************************************/
void text(char c[MAX],char name[50],char number[7],char address[40],float *t,char car1[40],float *price,int diff,char det[100])
{
    char *filename = "invoice.txt";
    FILE *fp = fopen(filename, "w");
    fprintf(fp,"-------------------------------------------------\n");

    int width = 49;
    char str[] = "INVOICE";
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;
    fprintf(fp,"%*.*s%s\n", pad, pad, " ", str);

    fprintf(fp,"-------------------------------------------------\n");
    fprintf(fp,"Provider: \t %36s\n","DD Rentals Co.");
    fprintf(fp,"Place: \t %36s\n","Cluj-Napoca");
    fprintf(fp,"Phone Number: \t %30s\n","0265108362");
    fprintf(fp,"Customer Name: \t %30s\n",name);
    fprintf(fp,"Customer Phone Number: \t %19s\n",number);
    fprintf(fp,"Customer Address: \t %24s\n\n",address);

    char str1[] = "- Car Details -";
    int length1 = sizeof(str1) - 1;
    int pad1 = (length1 >= width) ? 0 : (width - length1) / 2;
    fprintf(fp,"%*.*s%s\n", pad1, pad1, " ", str1);

    int length2 = strlen(car1) - 1;
    int pad2 = (length2 >= width) ? 0 : (width - length2) / 2;
    fprintf(fp,"%*.*s%s\n", pad2, pad2, " ", car1);

    int length3 = strlen(c);
    int pad3 = (length3 >= width) ? 0 : (width - length3) / 2;
    fprintf(fp,"%*.*s%s\n", pad3, pad3, " ", c);

    fprintf(fp,"       %s       \n\n",det);

    fprintf(fp,"The initial date: %*d.%d.%d\n",22,d1.day,d1.month,d1.year);
    fprintf(fp,"The final date: %*d.%d.%d\n\n\n",24,d2.day,d2.month,d2.year);

    fprintf(fp,"Regular Price without discount: \t %13.2f$\n",*price*diff);
    if (diff > 7){
        fprintf(fp,"Price with discount: \t %24.2f$\n",*t);
    }
    fprintf(fp,"-------------------------------------------------\n");
    float vat = *t*0.19;
    fprintf(fp,"V.A.T. %*.2f$\n",41,vat);
    printf(fp,"Total %*.2f$\n\n\n",42,*t+vat);
    fclose(fp);
}
