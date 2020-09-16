#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp_read = fopen("input.txt", "r");
    FILE *fp_write = fopen("ouput.txt", "w");
    char buffer[100];

    while(fscanf(fp_read, "%s", buffer) != EOF)
        fprintf(fp_write, "%s", buffer);

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}
