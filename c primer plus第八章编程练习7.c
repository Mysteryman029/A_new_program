#include <stdio.h>
#include <ctype.h>
#define EXTRA_HOUR 1.5f
#define BASE_TAX 0.15f
#define EXTRA_TAX 0.2f
#define EXCEED_TAX 0.25f

int show_menu(void);
void show_salary(float base_salary, float hours);
int get_choice(void);
void eatline(void);

int main(void)
{
    int ch;
    float n;

    while ((ch = show_menu()) != 'q')
    {
        printf("Enter the working hours a week:");
        while ((!scanf_s("%f", &n)) || (n < 0))
        {
            eatline();
            printf("Enter a positive number:");
        }
        eatline();
        switch (ch)
        {
        case 'a':
        {
            show_salary(8.75f, n);
            break;
        }
        case 'b':
        {
            show_salary(9.33f, n);
            break;
        }
        case 'c':
        {
            show_salary(10.00f, n);
            break;
        }
        case 'd':
        {
            show_salary(11.20f, n);
            break;
        }
        }
        putchar('\n');
    }
    printf("Done!\n");

    return 0;
}

int get_choice(void)
{
    int ch = 0;

    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    eatline();

    return ch;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
    return;
}

int show_menu(void)
{
    int ch;

    printf("**********************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                  b) $9.33/hr\n");
    printf("c) $10.00/hr                 d) $11.20/hr\n");
    printf("q) Quit\n");
    printf("**********************************************************************\n");
    printf("Please you choose:");
    ch = get_choice();

    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'q')
    {
        printf("Please enter a,b,c,d or q:");
        ch = get_choice();
    }
    return ch;
}

void show_salary(float base_salary, float hours)
{
    float salary, tax, taxed_salary;

    if (hours <= 30)
    {
        salary = hours * base_salary;
        tax = salary * BASE_TAX;
        taxed_salary = salary - tax;
    }
    else if (hours <= 40)
    {
        salary = hours * base_salary;
        tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
        taxed_salary = salary - tax;
    }
    else
    {
        salary = (40 + (hours - 40) * EXTRA_HOUR) * base_salary;
        if (salary <= 450)
        {
            tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
        }
        else
        {
            tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
        }
        taxed_salary = salary - tax;
    }
    printf("salary(before tax):$%g\n", salary);
    printf("tax:$%g\n", tax);
    printf("salary(after tax):$%g\n", taxed_salary);
    return;
}
