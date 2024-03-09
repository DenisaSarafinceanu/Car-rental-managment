/*****************************************************/
/* module4.c- See module4.h                          */
/*****************************************************/

/*System headers and application specific headers*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "module4.h"

/*Private constants*/

/*Private types*/

/*Private global variables*/

/*Public global variables*/

/*Implementation of the private functions*/

/*Implementation of the public function*/


/*********************************************************************************/
/* Function name: SetColor                                                       */
/* Description: This function changes the color of the text displayed.           */
/*********************************************************************************/
void SetColor(int ForgC)
{
     WORD wColor; /*this gets the current background */

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

/*********************************************************************************/
/* Function name: execution_program                                              */
/* Description: This function includes the two parts of the project, car rental  */
/*              and the chat with the technical team about the problems          */
/*              encountered with the car. This function is also in main because  */
/*              the first time choosing the option is different than if he       */
/*              wants to go back and repeat the process.                         */
/*********************************************************************************/
void execution_program()
{
    char s;
    rent_team();
    //SetColor(12);
    char b,a;
    b=getchar();
    s=getchar();
    if(s=='r')
      rental();
    else
      if(s=='t')
        questions();
      else
       while(s!='r' && s!='t')
      {
         SetColor(12);
         printf("This is not one of our options. Please enter a valid one: ");
         SetColor(7);
         char as; /*character which reads '\n' */
         as=getchar();
         s=getchar();
         if(s=='r')
            rental();
         else
           if(s=='t')
             questions();
      }
}

/*********************************************************************************/
/* Function name: finish                                                         */
/* Description: This function is used at the end of each process and asks the    */
/*              client if he wants to go back to the first page that asks him to */
/*              choose between renting a car or talking to the technical team.   */
/*********************************************************************************/
void finish()
{
    printf("\n-------------------------------------------------\n");
    printf("Please press 1 if you go back to the first page\n");
    printf("Please press 2 if you want to exit\n");
    printf("-------------------------------------------------\n");
    int d=0;
    scanf("%d",&d);
    if(d==1)
    {
        system("cls");
        execution_program();
    }

    else
     if(d==2)
     {
       SetColor(0);
       exit(0);
     }

    else
    {
        while(d!=1 && d!=2)
        {
           SetColor(12);
           printf("This is not a valid operation. Please try again.\n");
           SetColor(7);
           scanf("%d",&d);
        }
        if(d==1)
        {
            system("cls");
            execution_program();
        }

        else
         if(d==2)
         {
           SetColor(0);
           exit(0);
         }


    }
}

/*********************************************************************************/
/* Function name: damage                                                         */
/* Description: This function is used in the case the client damaged the car and */
/*              he has to pay for what he broke. Here it is a list of some       */
/*              components that can be broken and the client choose for his case.*/
/*********************************************************************************/
void damage_(){

    printf("----------------------------------------------------------------------\n");
    printf("We regret to inform you that you have to pay what you broke.\n");
    printf("Here it is a list of prices for every item that you could have broken.\n");
    printf("----------------------------------------------------------------------\n");
    printf("1. Damage to the front of the car\n");
    printf("2. Damage to the rear of the car\n");
    printf("3. Damage to the sides of the car\n");
    printf("4. Damage to the tyres of the car\n");
    printf("5. Damage to the engine of the car\n");
    printf("6. Damage to the interior of the car\n");
    printf("----------------------------------------------------------------------\n");
    printf("For the respective damage caused, enter the coresponding number: ");

}

/*********************************************************************************/
/* Function name: back_payment                                                   */
/* Description: This function is used in the case the client has to pay for the  */
/*              damage and with this function the client has the opportunity to  */
/*              continue, to go back or to exit from this process.               */
/*********************************************************************************/
void back_payment()
{
    int x,prc;
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
      payment(prc);
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
            payment(prc);
         else
            if(x==3)
            {
              SetColor(0);
              exit(0);
            }

     }
}

void rent_team()
{
    printf("-------------------------------------------------------------------------\n");
    SetColor(3);
    printf("We are here to help you with any problem. Do you want to rent a car or\
            \ntalk to the technical team?\n");
    SetColor(7);
    printf("-------------------------------------------------------------------------\n");
    SetColor(12);
    printf("-->");
    SetColor(7);
    printf("If you want to rent a car, press ");
    SetColor(12);
    printf("r");
    SetColor(7);
    printf(" and we will show you our options.\n");
    SetColor(12);
    printf("-->");
    SetColor(7);
    printf("If you want to talk to the technical team, press ");
    SetColor(12);
    printf("t");
    SetColor(7);
    printf(".\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Enter your decision: ");
}
