#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
    Section in which input is taken from user using scanf functions
    */
   
    printf("Please enter the Numerator and Denominator of the first fraction. ");
    scanf("%d %d", &num1, &den1);
    
    printf("Please enter the Numerator and Denominator of the second fraction. ");
    scanf("%d %d", &num2, &den2);
    
    /*Each function is called and printed in the given format*/

    printf("First number: ");
	fraction_print(num1, den1);
	printf("\n");

	printf("Second number: ");
	fraction_print(num2, den2);
	printf("\n");

	printf("Addition: ");
	fraction_add(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Subtraction: ");
	fraction_sub(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Multiplication: ");
	fraction_mul(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	printf("Division: ");
	fraction_div(num1, den1, num2, den2, &num3, &den3);
	fraction_print(num3, den3);
	printf("\n");

	return(0);
}
