/*
Austin Polak
ajpolak@purdue.edu
Factorials, Fibonacci numbers, Towers of Hanoi, Reversing a string, Conversion to ASCII
CNIT 31500 Lab 3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int factorial(int num);
int fibonacci(int num);
void runHanoi(int num, char x, char y, char z);
void print_reverse(char *w);
void conversion(char *stt);

int main()
{
    int output, i = 0, ii, number, dec, length;
    char contin = 'y', string[20];

    do
    {
        printf("Enter #1 for Factorials.\nEnter #2 for Fibonacci numbers.\nEnter #3 for Towers of Hanoi\nEnter #4 for Reversing a String\nEnter #5 for Conversion to ASCII\n");
        printf("Enter your decision: ");
        scanf("%d", &dec);

        if (dec == 1)
        {
            printf("Enter an integer to calculate its factorial: ");
            scanf("%d", &number);
            printf("Factorial of %d is %d", number, factorial(number));
            printf("\n");
        }
        if (dec == 2)
        {
            printf("Enter the number of terms: ");
            scanf("%d", &number);
            for (ii = 0; ii < number; ii++)
            {
                printf("%d, ", fibonacci(i));
                i++;
            }
            printf("\n");
        }
        if (dec == 3)
        {
            printf("Enter the number of disks: ");
            scanf("%d", &number);
            runHanoi(number, 'A', 'B', 'C');
            printf("\n");
        }
        if (dec == 4)
        {
            char s[30];
            printf("Enter a string to reverse: ");
            scanf("%s", s);
            print_reverse(s);
            printf("\n");
        }
        if (dec == 5)
        {
            printf("Please enter a string: ");
            scanf("%s", string);
            conversion(string);
            printf("\n");
        }

        printf("\nWould you like to continue? [y/n] ");
        scanf("%s", &contin);
    } 
    while (contin == 'y');
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return (fibonacci(num - 1) + fibonacci(num - 2));
}

void runHanoi(int num, char x, char y, char z)
{
    if (num > 0)
    {
        runHanoi(num - 1, x, z, y);
        printf("\nMove disk %d from rod %c to rod %c", num, x, z);
        runHanoi(num - 1, y, x, z);
    }
}

void print_reverse(char *w)
{
    if (*w != '\0')
    {
        print_reverse(w + 1);
        printf("%c", *w);
    }
}

void conversion(char *stt)
{
    int i, a, b;
    printf("The binary format of %s is: ", stt);
    for (i = 0; stt[i] != '\0'; i++)
    {
        b = stt[i];
        for (a = 7; a + 1 > 0; a--)
        {
            if (b >= (1 << a))
            {
                b = b - (1 << a);
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf(" ");
    }
    
}