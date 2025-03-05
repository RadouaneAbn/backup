#include <stdio.h>

void rec()
{
    int i;

    i = 0;
    i++;
    printf("%d", i);
    rec();
}

int main()
{

    rec();
}