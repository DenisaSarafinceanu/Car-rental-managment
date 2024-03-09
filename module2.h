/*****************************************************/
/* module2.h is the Header file for module module2   */
/*Author: Sarafincenu Denisa                         */
/*Version: 28-12-2022                                */
/*****************************************************/
#ifndef MODULE2_H_INCLUDED
#define MODULE2_H_INCLUDED
/*Headers required by the following definitions/declarations*/
#include <stdlib.h>

/*Definition of the size of the string c*/
#define MAX 10

/*Constants definitions*/

/*Types definitions*/

/*Global variables declaration*/

/*Function prototype*/
int leap(int x);
int day_of_year(int day, int month, int year);
int difference();
void discount(int p,float *price,float *t);
void invoice(char c[MAX],char name[50],char number[7],char address[40],float *t,char car1[40],float *price,int diff,char det[100]);
void text(char c[MAX],char name[50],char number[7],char address[40],float *t,char car1[40],float *price,int diff,char det[100]);
#endif // MODULE2_H_INCLUDED
