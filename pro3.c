#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - 5 * x + 1);
}
int main()
{
    float a, b, x, allow_err;
    int itr = 1;
    printf("Enter the values of a and b : ");
    scanf("%f%f", &a, &b);

    if ((f(a) * f(b)) < 0)
    {
        printf("Roots lies b/w a & b\n");
    }
    else
    {
        printf("Wrong interval!!...Try again");
    }
    printf("enter the allowed error : ");
    scanf("%f", &allow_err);

    x = a - ((b - a) / (f(b) - f(a)) * f(a));

    while (fabs(f(x)) > allow_err)
    {
        x = a - ((b - a) / (f(b) - f(a)) * f(a));
        printf("%d iteration for %f & %f , the value of x is : %f \n", itr, a, b, x);
        if (fabs(f(x)) <= allow_err)
            printf("Root=%f", x);
        else if ((f(a) * f(x)) < 0)
            b = x;
        else if (f(x) * f(b) < 0)
            a = x;
        itr++;
    }
}
