#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("input.txt", "r");
    char buffer[100];

    while(fscanf(fp, "%s", buffer) != EOF)
        printf(buffer, "%s");

    fclose(fp);

    return 0;
}