/*****************************************************/
/* module1.c- See module1.h                          */
/*****************************************************/

/*System headers and application specific headers*/
#include <stdio.h>
#include <stdlib.h>
#include "module1.h"

/*Private constants*/

/*Private types*/

/*Private global variables*/

/*Public global variables*/

/*Implementation of the private functions*/

/*Implementation of the public function*/

/*********************************************************************************/
/* Function name: introduction                                                   */
/* Description: This function forms the first page that is displayed in the      */
/*              console and if the client wants to start the process he just has */
/*              to press Enter.                                                  */
/*********************************************************************************/
void introduction(void)
{
    printf("-------------------------------------------------------------------------\n");
    SetColor(3); /*function which changes the color */
    printf("                      Welcome to DD Rentals                        \n");
    SetColor(7);
    printf("-------------------------------------------------------------------------\n");
    SetColor(10);
    printf(" Please press Enter if you want to start!\n");
    SetColor(7);
    printf("-------------------------------------------------------------------------\n");
    SetColor(7);
    char as;   /*character which reads '\n\ */
    as=getchar();
    system("cls"); /*clears the screen */
}

/**********************************************************************************/
/* Function name: category_extraction                                             */
/* Description: This function displays the category available to the company and  */
/*              the client has to type exactly the category he wants from these 3.*/
/**********************************************************************************/
void category_extraction(void)
{
    char c[MAX];
    char c1[8] = "Compact";   /*these are the categories available */
    char c2[6] = "Sedan";
    char c3[4] = "SUV";
    printf("-----------------------------------------\n");
    SetColor(3);
    printf("    What Type Of Car Would You Like?     \n");
    SetColor(7);
    printf("-----------------------------------------\n");
    printf("\n");
    printf("- %s : 80$/day  -\n\n- %s   : 150$/day -\n\n- %s     : 260$/day -\n\n",c1,c2,c3);
    printf("-----------------------------------------\n");
    printf("Please enter from the keyboard your choice: ");
}

/*********************************************************************************/
/* Function name: car                                                            */
/* Description: After the client has chosen the category, each of them has       */
/*              several car models. This function checks which is the category   */
/*              chosen by the client, displays the cars available for it and     */
/*              gives him the possibility to choose the right one by pressing the*/
/*              key with its corresponding number.                               */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* char                c[MAX]             here it is the category typed by him   */
/* char                c1[8]              here it is the first category available*/
/*                                        'Compact' which has the size 8         */
/* char                c2[6]              here it is the second category         */
/*                                        available 'Sedan' which has the size 6 */
/* char                c3[4]              here it is the third category available*/
/*                                        'SUV' which has the size 4             */
/*  int                 *nr               here it is a pointer which keeps the   */
/*                                        choice made by him(1 for the first car,*/
/*                                        2 for the second car,..)               */
/* float               *price             here it is the exact price for each    */
/*                                        category and keeps the one for his     */
/*                                        choice                                 */
/*********************************************************************************/
void car(char c[MAX],char c1[8],char c2[6],char c3[4],int *nr,float *price)
{
   if(strcmp(c,c1)==0)
    {
        system("cls");
        *price=80; /*the price for first category */
        printf("--------------------------------------------------------------------\n");
        SetColor(3);
        printf("You are now at the Compact category. Please choose the car you want!\n");
        SetColor(7);
        printf("--------------------------------------------------------------------\n");
        printf("Our options are: \n");
        printf("1). Hyundai Elantra\n");
        printf("2). Toyota Corolla\n");
        printf("3). Honda Civic\n");
        printf("4). Volkswagen Golf\n");
        printf("5). Kia Forte\n");
        printf("6). Ford Focus\n");
        printf("7). Chevrolet Cruze\n");
        printf("-------------------------------------------------------------------\n");
        printf("Please enter your choice(1 for the first, 2 for the second, ...).\n");
        scanf("%d",nr);
        while(*nr>7) /*if the client entered a number bigger than the possible values */
        {
            SetColor(12);
            printf("Please enter a valid value: ");
            SetColor(7);
            scanf("%d",nr);
        }
       //system("cls");
    }

    if(strcmp(c,c2)==0)
    {
        system("cls");
        *price=150; /*the price for the second category */
        printf("------------------------------------------------------------------\n");
        SetColor(3);
        printf("You are now at the Sedan category. Please choose the car you want!\n");
        SetColor(7);
        printf("------------------------------------------------------------------\n");
        printf("Our options are: \n");
        printf("1). Toyota Camry\n");
        printf("2). BMW 7 Series\n");
        printf("3). Honda Accord\n");
        printf("4). Mercedes-Benz E-Class\n");
        printf("5). Hyundai Elantra\n");
        printf("6). Mazda 6\n");
        printf("7). Hyundai Sonata\n");
        printf("------------------------------------------------------------------\n");
        printf("Please enter your choice(1 for the first, 2 for the second, ...).\n");
        scanf("%d",nr);
        while(*nr>7)
        {
            SetColor(12);
            printf("Please enter a valid value: ");
            SetColor(7);
            scanf("%d",nr);
        }
        //system("cls");
    }

    if(strcmp(c,c3)==0)
    {
        system("cls");
        *price=260; /*the price for the third category */
        printf("----------------------------------------------------------------\n");
        SetColor(3);
        printf("You are now at the SUV category. Please choose the car you want!\n");
        SetColor(7);
        printf("----------------------------------------------------------------\n");
        printf("Our options are: \n");
        printf("1). Volkswagen Tiguan\n");
        printf("2). Mercedes-Benz GLE\n");
        printf("3). Volvo XC60\n");
        printf("4). Mercedes-Benz G-Class\n");
        printf("5). BMW X5\n");
        printf("6). Jeep Grand Cherokee\n");
        printf("7). Tesla Model X\n");
        printf("----------------------------------------------------------------\n");
        printf("Please enter your choice (1 for the first, 2 for the second, ...).\n");
        scanf("%d",nr);
        while(*nr>7)
        {
            SetColor(12);
            printf("Please enter a valid value: ");
            SetColor(7);
            scanf("%d",nr);
        }
        //system("cls");
    }
}

/*********************************************************************************/
/* Function name: decision                                                       */
/* Description: After the client has chosen the desired car, the program will    */
/*              take him to the section of this car.                             */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* char                c[MAX]             here it is the category typed by him   */
/* char                c1[8]              here it is the first category available*/
/*                                        'Compact' which has the size 8         */
/* char                c2[6]              here it is the second category         */
/*                                        available 'Sedan' which has the size 6 */
/* char                c3[4]              here it is the third category available*/
/*                                        'SUV' which has the size 4             */
/*  int                 *nr               here it is a pointer which keeps the   */
/*                                        choice made by him(1 for the first car,*/
/*                                        2 for the second car,..)               */
/*  char               car1[40]           here it is the name for the model of   */
/*                                        the car that he chose                  */
/*********************************************************************************/
void decision(char c[MAX],char c1[8],char c2[6],char c3[4],int *nr,char car1[40],char det[100])
{
    //go_back();
    system("cls");
    printf("-------------------------------------------------------------------------\n");
    SetColor(3);
    if(strcmp(c,c1)==0) /*first category: Compact */
    {
        switch(*nr)
        {
            case 1: printf("      Your decision is: Hyundai Elantra\n");
                strcpy(car1,"Hyundai Elantra");
                strcpy(det, "1.4 liter | petrol engine | 130 HP");
                break;
            case 2: printf("      Your decision is: Toyota Corolla\n");
                strcpy(car1,"Toyota Corolla");
                strcpy(det, "1.2 liter | petrol engine | 110 HP");
                break;
            case 3: printf("      Your decision is: Honda Civic\n");
                strcpy(car1,"Honda Civic");
                strcpy(det, "1.6 liter | petrol engine | 150 HP");
                break;
            case 4: printf("      Your decision is: Volkswagen Golf\n");
                strcpy(car1,"Volkswagen Golf");
                strcpy(det, "1.6 liter | petrol engine | 120 HP");
                break;
            case 5: printf("      Your decision is: Kia Forte\n");
                strcpy(car1,"Kia Forte");
                strcpy(det, "1.0 liter | petrol engine | 100 HP");
                break;
            case 6: printf("      Your decision is: Ford Focus\n");
                strcpy(car1,"Ford Focus");
                strcpy(det, "1.9 liter | petrol engine | 160 HP");
                break;
            case 7: printf("      Your decision is: Chevrolet Cruze\n");
                strcpy(car1,"Chevrolet Cruze");
                strcpy(det, "1.4 liter | petrol engine | 130 HP");
                break;
        }

    }
    if(strcmp(c,c2)==0) /*second category: Sedan */
    {
        switch(*nr)
        {
            case 1: printf("      Your decision is: Toyota Camry\n");
               strcpy(car1,"Toyota Camry");
               strcpy(det, "2.5 liter | petrol engine | 200 HP");
               break;
            case 2: printf("      Your decision is: BMW 7 Series\n");
               strcpy(car1,"BMW 7 Series");
               strcpy(det, "4.4 liter | petrol engine | 350 HP");
               break;
            case 3: printf("      Your decision is: Honda Accord\n");
               strcpy(car1,"Honda Accord");
               strcpy(det, "2.0 liter | diesel engine | 170 HP");
               break;
            case 4: printf("      Your decision is: Mercedes-Benz E-Class\n");
               strcpy(car1,"Mercedes-Benz E-Class");
               strcpy(det, "3.0 liter | petrol engine | 250 HP");
               break;
            case 5: printf("      Your decision is: Hyundai Elantra\n");
               strcpy(car1,"Hyundai Elantra");
               strcpy(det, "2.0 liter | diesel engine | 180 HP");
               break;
            case 6: printf("      Your decision is: Mazda 6\n");
               strcpy(car1,"Mazda 6");
               strcpy(det, "2.0 liter | diesel engine | 150 HP");
               break;
            case 7: printf("      Your decision is: Hyundai Sonata\n");
               strcpy(car1,"Hyundai Sonata");
               strcpy(det, "1.6 liter | petrol engine | 140 HP");
               break;
        }
    }
    if(strcmp(c,c3)==0) /*third category: SUV */
    {
        switch(*nr)
        {
            case 1: printf("      Your decision is: Volkswagen Tiguan\n");
               strcpy(car1,"Volkswagen Tiguan");
               strcpy(det, "3.0 liter | diesel engine | 220 HP");
               break;
            case 2: printf("      Your decision is: Mercedes-Benz GLE\n");
               strcpy(car1,"Mercedes-Benz GLE");
               strcpy(det, "3.0 liter | petrol engine | 260 HP");
               break;
            case 3: printf("      Your decision is: Volvo XC60\n");
               strcpy(car1,"Volvo XC60");
               strcpy(det, "2.0 liter | diesel engine | 190 HP");
               break;
            case 4: printf("      Your decision is: Mercedes-Benz G-Class\n");
               strcpy(car1,"Mercedes-Benz G-Class");
               strcpy(det, "5.0 liter | petrol engine | 450 HP");
               break;
            case 5: printf("      Your decision is: BMW X5\n");
               strcpy(car1,"BMW X5");
               strcpy(det, "3.0 liter | petrol engine | 350 HP");
               break;
            case 6: printf("      Your decision is: Jeep Grand Cherokee\n");
               strcpy(car1,"Jeep Grand Cherokee");
               strcpy(det, "3.0 liter | petrol engine | 350 HP");
               break;
            case 7: printf("      Your decision is: Tesla Model X\n");
               strcpy(car1,"Tesla Model X");
               strcpy(det, "100kW/h | electric engine | 900 HP");
               break;
        }
    }
    SetColor(7);
    printf("-------------------------------------------------------------------------\n");
}

/*********************************************************************************/
/* Function name: valid_date                                                     */
/* Description: This function calculates if the date the client entered is valid;*/
/*              it takes into consideration the month February which should have */
/*              28 days or 29 days if the year is divided by 4 and which month   */
/*              has 30 or 31 days.                                               */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/* int                 day                retain the value of the day from the   */
/*                                        input date                             */
/* int                 month              retain the value of the month from the */
/*                                        input date                             */
/* int                 year               retain the value of the year from the  */
/*                                        input date                             */
/*********************************************************************************/
int valid_date(int day,int month,int year)
{
    int sem=0,valid=1;
    if((year%4==0 && year%100!=0)||(year%400)==0)
       sem=1;
    if (year<2020)
    {
        valid = 0;
    }
    if(month>=1 && month<=12)
    {
        if(month==2)
        {
            if(sem && day==29)
                valid=1;
            else
             if(day>28)
              valid=0;
        }
        else
         if(month==4 || month==6 || month==9 || month==11)
        {
            if(day>30)
                valid=0;
        }
        else
        {
            if(day>31)
                valid=0;
        }
    }
    else
    {
        valid=0;
    }
    return valid;
}

struct Date{
   int day,month,year;
}d1,d2;

/*********************************************************************************/
/* Function name: valid_date2                                                    */
/* Description: This function verifies if the initial date is not after the final*/
/*              one and in this case you should type a valid date.               */
/*********************************************************************************/
int valid_date2(void)
{
    if(d1.day>d2.day && d1.month==d2.month)
        return 0;
    else
     if(d1.month>d2.month && d1.year==d2.year)
       return 0;
     else
      if(d1.year>d2.year)
        return 0;
    return 1;
}



