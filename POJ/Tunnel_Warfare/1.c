#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    {
        double *a = (double *)malloc(sizeof(double)*100);
        *a = 100;
        printf("%f\n", *a);
        free(a);
    }
    {
        double *a = (double *)malloc(sizeof(double)*100);
        printf("%f\n", *a);
        free(a);
    }

    return 0;
}

