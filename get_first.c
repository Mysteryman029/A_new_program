#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int get_first(void);

int main(void)
{
    int ch;

    printf("(本程序返回读取的第1个非空白字符)\n");
    printf("请您输入一些字符(单独按#退出):\n");
    while ((ch = get_first()) != STOP)
    {
        printf("结果是:%c\n", ch);
        printf("请您再次输入(单独按#退出):\n");
    }
    printf("本程序完成!\n");

    return 0;
}

int get_first(void)
{
    int ch;

    do
    {
        ch = getchar();
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;

    return ch;//返回第一个非空白字符
}
