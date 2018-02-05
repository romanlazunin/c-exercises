#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;
    int digit;

    printf("Hello world!\n");
    printf("C Example Console Application 1 v0.1 build 20180126-2\n");
    input = getchar();

    while (1) {
        scanf("%d", &digit);
        printf("You entered %d", digit);
    }

    return 0;
}
