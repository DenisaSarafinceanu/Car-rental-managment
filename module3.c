/*****************************************************/
/* module3.c- See module3.h                          */
/*****************************************************/

/*System headers and application specific headers*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "module3.h"

#define MAX 10
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
/* Function name: rental                                                         */
/* Description: This function includes all the previous functions that are the   */
/*              basis of the first option in the project, car rental.            */
/*              I chose to make a function that includes everything to make it   */
/*              easier to repeat the executions if you want to go to the initial */
/*              page.                                                            */
/*********************************************************************************/
void rental()
{
    char c[MAX];     /* c is the category selected by the client */
    char c1[8] = "Compact";   /* c1,c2,c3 are the categories */
    char c2[6] = "Sedan";
    char c3[4] = "SUV";
    char car1[40],det[100];
    int *nr;
    float *price;
    system("cls");
    category_extraction();
    scanf("%s", &c);
    while (strcmp(c,c1) && strcmp(c,c2) && strcmp(c,c3)){
        SetColor(12);
        printf("Please enter a valid category: ");
        SetColor(7);
        scanf("%s", &c);
    }
    go_back();
    car(c,c1,c2,c3,&nr,&price);
    decision(c,c1,c2,c3,&nr,car1,det);
    char f_name[50],l_name[50],number[7],address[100];
    printf("Now please register with your data.\n\n");
    printf("First name: ");
    scanf("%s",f_name);
    printf("\nLast name: ");
    scanf("%s",l_name);
    printf("\nYour contact number: ");
    scanf("%s",number);
    printf("\nYour address: ");
    char as; /*character which reads '\n' */
    as=getchar();
    gets(address);
    printf("\nThe initial date (DD.MM.YY): ");
    scanf("%d.%d.%d",&d1.day,&d1.month,&d1.year);
    printf("\nThe final date (DD.MM.YY): ");
    scanf("%d.%d.%d",&d2.day,&d2.month,&d2.year);
    printf("\n");
    while(valid_date(d1.day,d1.month,d1.year)==0)
    {
        SetColor(12);
        printf("The initial date you entered is not a valid one. \nPlease insert a new one.\n");
        SetColor(7);
        printf("The initial date: ");
        scanf("%d.%d.%d",&d1.day,&d1.month,&d1.year);
    }
    while(valid_date(d2.day,d2.month,d2.year)==0)
    {
        SetColor(12);
        printf("The final date you entered is not a valid one. \nPlease insert a new one.\n");
        SetColor(7);
        printf("The final date: ");
        scanf("%d.%d.%d",&d2.day,&d2.month,&d2.year);
    }
    while(valid_date2()==0)
    {
       SetColor(12);
       printf("This is not a possible period of time.Please try again.\n");
       SetColor(7);
       printf("\nThe initial date: ");
       scanf("%d.%d.%d",&d1.day,&d1.month,&d1.year);
       printf("\nThe final date: ");
       scanf("%d.%d.%d",&d2.day,&d2.month,&d2.year);
    }

    float *t;
    int diff=difference();
    discount(diff,&price,&t);
    go_back();
    system("cls");
    SetColor(7);
    char name[50] = "";
    strcat(f_name," ");
    strcat(f_name,l_name);
    strcat(name,f_name);
    invoice(c,name,number,address,&t,car1,&price,diff,det);
    text(c,name,number,address,&t,car1,&price,diff,det);
    SetColor(7);
    finish();
}

/*********************************************************************************/
/* Function name: payment                                                        */
/* Description: This function sets the price to be paid by the customer in case  */
/*              he damaged the car.                                              */
/* Argument list:                                                                */
/* Argument            Type               Description                            */
/*  float               prc               here it is the price for every damaged */
/*                                        in depth                               */
/*********************************************************************************/
void payment(float prc)
{
    system("cls");
    int dmg;
    char c[MAX];
    char c1[8] = "Compact";
    char c2[6] = "Sedan";
    char c3[4] = "SUV";
    char f_name[50],l_name[50],number[7],address[100];
    int *nr;
    char damage[9];
    char car1[40],det[100];
    float *price;
    damage_();
    scanf("%d",&dmg);
    if (dmg == 1){
        prc = 2500;
        strcpy(damage,"front");
    }
    if (dmg == 2){
        prc = 2000;
        strcpy(damage,"rear");
    }
    if (dmg == 3){
        prc = 3000;
        strcpy(damage,"sides");
    }
    if (dmg == 4){
        prc = 1500;
        strcpy(damage,"tyres");
    }
    if (dmg == 5){
        prc = 5000;
        strcpy(damage,"engine");
    }
    if (dmg == 6){
        prc = 1800;
        strcpy(damage,"interior");
    }
    back_payment();
    system("cls");
    printf("----------------------------------------------------------------------\n");
    SetColor(3);
    printf("Please select the car that you rented:\n");
    SetColor(7);
    printf("----------------------------------------------------------------------\n\n");
    printf("1. Compact \n\n2. Sedan\n\n3. SUV\n\n");
    printf("----------------------------------------------------------------------\n\n");
    printf("Type the car category: ");
    scanf("%s", &c);
    while (strcmp(c,c1) && strcmp(c,c2) && strcmp(c,c3)){
        SetColor(12);
        printf("Please enter a valid category: ");
        SetColor(7);
        scanf("%s", &c);
    }
    back_payment();
    car(c,c1,c2,c3,&nr,&price);
    decision(c,c1,c2,c3,&nr,car1,det);
    printf("Now please register with your data.\n\n");
    printf("First name: ");
    scanf("%s",f_name);
    printf("\nLast name: ");
    scanf("%s",l_name);
    printf("\nYour contact number: ");
    scanf("%s",number);
    printf("\nYour address: ");
    char as; /*character which reads '\n' */
    as=getchar();
    gets(address);
    char name[50] = "";
    strcat(f_name," ");
    strcat(f_name,l_name);
    strcat(name,f_name);
    if (c == "Sedan"){
        prc = prc*1.5;
    }
    else{
        if (c == "SUV"){
            prc = prc*2;
        }
    }
    float vat = 0.19*prc;
    back_payment();

//**********************************************************************************************************************************

    system("cls");
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
    SetColor(2);

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
    printf("%*.*s%s\n\n", pad3, pad3, " ", c);

    int length5 = strlen(damage)+ 26;
    int pad5 = (length5 >= width) ? 0 : (width - length5) / 2;
    printf("%*.*sdamage to the %s of the car\n\n", pad5, pad5, " ", damage);

    SetColor(9);
    printf("-------------------------------------------------\n");
    SetColor(14);

    printf("V.A.T. %*.2f$\n",41,vat);
    printf("Damaged elements %*.2f$\n\n",31,prc);
    printf("Total %*.2f$\n\n\n",42,prc+vat);
    SetColor(7);
    printf("You can also find the invoice in: damage.txt\n\n");
    SetColor(0);

//**********************************************************************************************************************************

    char *filename = "damage.txt";
    FILE *fp = fopen(filename, "w");
    fprintf(fp,"-------------------------------------------------\n");

    char strf[] = "INVOICE";
    int lengthf = sizeof(strf) - 1;
    int padf = (lengthf >= width) ? 0 : (width - lengthf) / 2;
    fprintf(fp,"%*.*s%s\n", padf, padf, " ", strf);

    fprintf(fp,"-------------------------------------------------\n");

    fprintf(fp,"Provider: \t %36s\n","DD Rentals Co.");
    fprintf(fp,"Place: \t %36s\n","Cluj-Napoca");
    fprintf(fp,"Phone Number: \t %30s\n","0265108362");
    fprintf(fp,"Customer Name: \t %30s\n",name);
    fprintf(fp,"Customer Phone Number: \t %19s\n",number);
    fprintf(fp,"Customer Address: \t %24s\n\n",address);

    char str1f[] = "- Car Details -";
    int length1f = sizeof(str1f) - 1;
    int pad1f = (length1f >= width) ? 0 : (width - length1f) / 2;
    fprintf(fp,"%*.*s%s\n", pad1f, pad1f, " ", str1f);

    int length2f = strlen(car1) - 1;
    int pad2f = (length2f >= width) ? 0 : (width - length2f) / 2;
    fprintf(fp,"%*.*s%s\n", pad2f, pad2f, " ", car1);

    int length3f = strlen(c);
    int pad3f = (length3f >= width) ? 0 : (width - length3f) / 2;
    fprintf(fp,"%*.*s%s\n\n", pad3f, pad3f, " ", c);
    fprintf(fp,"-------------------------------------------------\n");
    fprintf(fp,"V.A.T. %*.2f$\n",41,vat);
    fprintf(fp,"Damaged elements %*.2f$\n\n",31,prc);
    fprintf(fp,"Total %*.2f$\n\n\n",42,prc+vat);
    fclose(fp);
    SetColor(7);
    finish();
}

/*********************************************************************************/
/* Function name: questions                                                      */
/* Description: This function generates a chat with the technical team in case   */
/*              the client encounters a problem. This chat contains 3 questions  */
/*              if the car is broken, if the problem is from the rental or if the*/
/*              customer damaged it.                                             */
/*********************************************************************************/
void questions()
{
    system("cls");
    char q1,q2,q3;
    int prc;
    SetColor(7);
    printf("---------------------------------------------------------------------\n");
    SetColor(13);
    printf("-->Hello! I'm DiDi Robot and I'm here to help you with any problem!\n");
    printf("Please answer the following questions.\n");
    SetColor(7);
    printf("----------------------------------------\n");
    printf("It is something broken to the car? (y/n) \n");
    printf("----------------------------------------\n");
    char as; /*character which reads '\n' */
    as=getchar();
    q1=getchar();

    if(q1!='y' && q1!='n')
     while(q1!='y' && q1!='n')
    {
        SetColor(12);
        printf("This is not a valid information. Please try again: \n");
        SetColor(7);
        as=getchar();
        q1=getchar();
    }
    if(q1=='y')
    {
    printf("----------------------------------------\n");
    printf("Was this problem our fault? (y/n) \n");
    printf("----------------------------------------\n");
    as=getchar();
    q2=getchar();
    if(q2!='y' && q2!='n')
     while(q2!='y' && q2!='n')
    {
        SetColor(12);
        printf("This is not a valid information. Please try again: \n");
        SetColor(7);
        as=getchar();
        q2=getchar();
    }
    printf("----------------------------------------\n");
    printf("Was this problem your fault? (y/n) \n");
    printf("----------------------------------------\n");
    as=getchar();
    q3=getchar();
    if(q3!='y' && q3!='n')
     while(q3!='y' && q3!='n')
    {
        SetColor(12);
        printf("This is not a valid information. Please try again: \n");
        SetColor(7);
        as=getchar();
        q3=getchar();
    }
    }


    if(q1=='n')
    {
        printf("\nWe are happy that you don't have any problem!\n");
        questions_back();
        finish();
    }
    else
    {
       if(q1=='y' && q2=='y' && q3=='y')
        while(q1=='y' && q2=='y' && q3=='y')
        {
        SetColor(12);
        printf("\nThis is not a possible situation, please try again.\n");
        SetColor(7);
        printf("----------------------------------------\n");
        printf("It is something broken to the car? (y/n) \n");
        printf("----------------------------------------\n");
        char as; /*character which reads '\n' */
        as=getchar();
        q1=getchar();
        if(q1=='y')
        {
        printf("----------------------------------------\n");
        printf("Was this problem was fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q2=getchar();
        printf("----------------------------------------\n");
        printf("Was this problem your fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q3=getchar();
        }
        else
        {
            printf("\nWe are happy that you don't have any problem!\n");
            questions_back();
            finish();
        }
        if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
        else
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
        if(q1=='y' && q2=='n' && q3=='n')
          while(q1=='y' && q2=='n' && q3=='n')
          {
        SetColor(12);
        printf("\nThis is not a possible situation, please try again.\n");
        SetColor(7);
        printf("----------------------------------------\n");
        printf("It is something broken to the car? (y/n) \n");
        printf("----------------------------------------\n");
        char as;
        as=getchar();
        q1=getchar();
        if(q1=='y')
        {
        printf("----------------------------------------\n");
        printf("Was this problem was fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q2=getchar();
        printf("----------------------------------------\n");
        printf("Was this problem your fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q3=getchar();
        }
        else
        {
        printf("\nWe are happy that you don't have any problem!\n");
        questions_back();
        finish();
        }
        if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
          else
          {
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
          }

          }
        else
          if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
          else
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
        }
      else
        if(q1=='y' && q2=='n' && q3=='n')
          while(q1=='y' && q2=='n' && q3=='n')
          {
        SetColor(12);
        printf("\nThis is not a possible situation, please try again.\n");
        SetColor(7);
        printf("----------------------------------------\n");
        printf("It is something broken to the car? (y/n) \n");
        printf("----------------------------------------\n");
        char as;
        as=getchar();
        q1=getchar();
        if(q1=='y')
        {
        printf("----------------------------------------\n");
        printf("Was this problem our fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q2=getchar();
        printf("----------------------------------------\n");
        printf("Was this problem your fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q3=getchar();
        }
        else
        {
          printf("\nWe are happy that you don't have any problem!\n");
          questions_back();
        }
        if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
          else
          {
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
          }

          }
        else
          if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
          else
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
        if(q1=='y' && q2=='y' && q3=='y')
          while(q1=='y' && q2=='y' && q3=='y')
        {
        SetColor(12);
        printf("\nThis is not a possible situation, please try again.\n");
        SetColor(7);
        printf("----------------------------------------\n");
        printf("It is something broken to the car? (y/n) \n");
        printf("----------------------------------------\n");
        char as;
        as=getchar();
        q1=getchar();
        if(q1=='y')
        {
        printf("----------------------------------------\n");
        printf("Was this problem our fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q2=getchar();
        printf("----------------------------------------\n");
        printf("Was this problem your fault? (y/n) \n");
        printf("----------------------------------------\n");
        as=getchar();
        q3=getchar();
        }
        else
        {
        printf("\nWe are happy that you don't have any problem!\n");
        questions_back();
        finish();
        }
        if(q1=='y' && q2=='y' && q3=='n')
            {
                printf("\nWe regret that this happened. We give you the option to rent another car.\n");
                questions_back();
                printf("Please press c if you want to choose another car: ");
                char p;
                char as;
                as=getchar();
                p=getchar();
                if(p=='c')
                {
                    rental();
                }
            }
        else
            if(q1=='y' && q2=='n' && q3=='y')
          {
              printf("\nUnfortunately you will have to pay what you broke.\n");
              //questions_back();
              payment(prc);
          }
        }
    }

}

/*********************************************************************************/
/* Function name: go_back                                                        */
/* Description: This function gives to the client the opportunity to go back     */
/*              during the first part of the project which is renting a car. His */
/*              options are: to continue, to go back, to exit.                   */
/*********************************************************************************/
void go_back()
{
    int x;
    SetColor(8);
    printf("--------------------------------------------------------\n");
    printf("If you want to continue, please press 1.\n");
    printf("If you want to go back to the menu page, please press 2.\n");
    printf("If you want to exit, please press 3.\n");
    printf("--------------------------------------------------------\n");
    SetColor(7);
    printf("Please press your option: ");
    scanf("%d",&x);
    if(x==2)
      rental();
    else
      if(x==3)
      {
         SetColor(0);
         exit(0);
      }

      else
        while(x!=1 && x!=2 && x!=3)
      {
          SetColor(12);
          printf("This is not a possible option. Please try again: ");
          SetColor(7);
          scanf("%d",&x);
          if(x==2)
            rental();
          else
            if(x==3)
            {
              SetColor(0);
              exit(0);
            }

      }
}

/*********************************************************************************/
/* Function name: questions_back                                                 */
/* Description: This function is used in the second part of the project when the */
/*              client has the chance to talk to the robot and after every step  */
/*              he is asked if he wants to continue, to go back or to exit.      */
/*********************************************************************************/
void questions_back()
{
    int x;
    SetColor(8);
    printf("-----------------------------------------------------------\n");
    printf("If you want to continue, please press 1.\n");
    printf("If you want to go back to the initial page, please press 2.\n");
    printf("If you want to exit, please press 3.\n");
    printf("-----------------------------------------------------------\n");
    SetColor(7);
    printf("Please press your option: ");
    scanf("%d",&x);
    if(x==2)
      questions();
    else
      if(x==3)
      {
        SetColor(0);
        exit(0);
      }

      else
        while(x!=1 && x!=2 && x!=3)
      {
          SetColor(12);
          printf("This is not a possible option. Please try again: ");
          SetColor(7);
          scanf("%d",&x);
          if(x==2)
            questions();
          else
           if(x==3)
           {
             SetColor(0);
             exit(0);
           }

      }
}

