/*****************************************************/
/* module1.h is the Header file for module module1   */
/*Author: Sarafinceanu Denisa                        */
/*Version: 12-02-2022                                */
/*****************************************************/
#ifndef MODULE1_H_INCLUDED
#define MODULE1_H_INCLUDED
/*Headers required by the following definitions/declarations*/
#include <stdlib.h>

/*Definition of the size of the string c*/
#define MAX 10

/*Constants definitions*/

/*Types definitions*/

/*Global variables declaration*/

/*Function prototype*/
void introduction();
void category_extraction();
void car(char c[MAX],char c1[8],char c2[6],char c3[4],int *nr,float *price);
void decision(char c[MAX],char c1[8],char c2[6],char c3[4],int *nr,char car1[40],char det[100]);
int valid_date(int day,int month,int year);
int valid_date2();

#endif // MODULE1_H_INCLUDED
