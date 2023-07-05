#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    if(numerator == 0 && denominator == 0){
        printf("Both the numerator and denominator is zero. Fraction is in indeterminate form.\n");
    }
    else if(numerator == 0 && denominator != 0){ 
        printf("0\n");
    }
    else if(denominator == 0){
        printf("Denominator is 0. Fraction is undefined.\n");
    }
    else{
        printf("%d//%d\n", numerator, denominator);
    }
    
}  /* end fraction_print */

/* 
Common denominator is found by cross multiplication, then the fractions are added and subtracted using arithmetic operators
*/
void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    int result;
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
     
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

/* 
n3 and d3 pointer variables are updated with corresponding multiplied values
*/

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * n2;
    *d3 = d1 * d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

/* Division with fractions is multiplication operation with the reciprocal of the second fraction. */
/*Similar logic as multiplication function is applied here. */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1 * d2;
    *d3 = d1 * n2; 
    fraction_simplify(n3, d3);
} /* end fraction_div */

 

/* Simplification function works for any negative or positive integer except for zeros */

void fraction_simplify(int * n, int * d) {
   int gcd,i; 

/* Negative numerator is converted to positive by multiplying it with (-1)*/

   if(*n < 0){
    *n = *n *(-1);

 /* Runs on loop until a number 'i' between *n and *d, both divisible by numerator and denominator is found */  

    for(int i=1; i<= *n && *d;i++){
        if(*n % i == 0 && *d % i==0){
            gcd = i; 
        }
    }
    *n = (*n / gcd)*(-1);
    *d = (*d / gcd);
   }
/* Numerator is multiplied by (-1) again to return to its original sign*/

    if(*n > 0){

        for(int i=1; i<= *n && *d;i++){
        if(*n % i == 0 && *d % i==0){
            gcd = i; 
        }
    }
/* n pointer variable is updated and numerator and denominator of fraction is divided by GCD each*/
    *n = (*n / gcd);
    *d = (*d / gcd);
   }

/*If both the numerator and denominator are negative values, the fraction is simplified to a positive fraction*/
   if(*n < 0 && *d < 0){
    *n = *n * (-1);
    *d = *d * (-1);
   }

}

/*Note: Mathematically, only considering the case in which numerator is negative works 
since denominators are made equal in subtraction and addition functions.*/