#include <stdio.h>
#include <string.h>

#include "my_snprintf.h"

#define SIZE 50

int main(void)
{
    int d = -111;
    char buff[SIZE];
    char buff_2[SIZE];
    
    int i = my_snprintf(buff, 10, "%hd", 333);
    int j = snprintf(buff_2, 10, "%hd", 333);
    
    printf("i - %d\n", i);
    printf("str1 - %s\n", buff);

    printf("j - %d\n", j);
    printf("str2 - %s\n", buff_2);

    printf("cmp - %d\n", strcmp(buff, buff_2));

    return 0;
}
