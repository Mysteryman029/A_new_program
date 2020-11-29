#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int get_first(void);
int get_choice(void);
float get_float(void);

int main(void)
{
    int ct;
    float i, j;

    while ((ct = get_choice()) != 'q')
    {
        switch (ct)
        {
        case 'a'://加法
        {
            printf("Enter first number: ");
            i = get_float();
            printf("Enter second number: ");
            j = get_float();
            printf("%g + %g = %g\n", i, j, i + j);
            break;
        }
        case 's'://减法
        {
            printf("Enter first number: ");
            i = get_float();
            printf("Enter second number: ");
            j = get_float();
            printf("%g - %g = %g\n", i, j, i - j);
            break;
        }
        case 'm'://乘法
        {
            printf("Enter first number: ");
            i = get_float();
            printf("Enter second number: ");
            j = get_float();
            printf("%g * %g = %g\n", i, j, i * j);
            break;
        }
        case 'd'://除法
        {
            printf("Enter first number: ");
            i = get_float();
            printf("Enter second number: ");
            while (fabs(j = get_float()) <= 1e-6)
            {
                //↑判断float型浮点数是否为0;
                printf("Enter a number other than 0: ");
            }
            printf("%g / %g = %g\n", i, j, i / j);
            break;
        }
        }
    }
    printf("Bye.\n");

    return 0;
}

int get_first(void)
{
    int ch;

    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;

    return ch;
}

int get_choice(void)
{
    int ch;

    printf("******************************************\n");
    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");
    printf("******************************************\n");
    ch = get_first();

    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please enter with a,s,m,d or q :");
        ch = get_first();
    }
    return ch;
}

float get_float(void)
{
    int ch;
    float input;

    while (scanf_s("%f", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an number.\n");
        printf("Please enter a number such as 2.5, -1.78E8 or 3: ");
    }
    return input;
}
