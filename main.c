/*****************************************************/
/* Name of the project: Car rental management        */
/* Authors: Sarafinceanu Denisa, Toasca Darius       */
/* Version: 12-02-2022                               */
/*****************************************************/

/*Include standard headers*/
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

/*Include modules header that are directly invoked*/
#include "module1.h"
#include "module2.h"
#include "module3.h"
#include "module4.h"

int main() {

    introduction();
    char s;
    rent_team();
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
    //execution_program();
    return 0;
}
