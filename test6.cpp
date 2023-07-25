#include <iostream>
#include <stdlib.h>
using namespace std;
int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
int isInteger(char str[])
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (;str[i] != '\0'; i++){
                if (isDigit(str[i]) == 0)
            return 0;
    }
    return 1;
}

int isFloat(char str[])
{
    char *ptr;
    strtof(str, &ptr);
    if (*ptr == '\0')
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Insufficient arguments\n");
        exit(0);
    }
    for (int i = 1; i < argc; i++)
    {
        if (isInteger(argv[i]))
        {
            printf("Integer\n");
            int n = atoi(argv[i]);
            if (n > 0)
            {
                printf("+ve Integer\n");
            }
            else
                printf("-ve Integer\n");
        }
        else if (isFloat(argv[i]))
        {
            printf("Float\n");
            char *ptr;
            float x = strtof(argv[i], &ptr);
            if (x > 0)
                printf("+ve \n");
            else
                printf("-ve \n");
        }
        else
            printf("String\n");
    }
}