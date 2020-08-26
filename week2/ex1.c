#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("Sizes and values of integer, float and double respectively:\n");
    printf("%d bytes %d\n%d bytes %f\n%d bytes %f", sizeof(a), a, sizeof(b), b, sizeof(c), c);
    return 0;
}
