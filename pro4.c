#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 2 * x - log10(x) - 7;
}
float g(float x)
{
    return (log10(x) + 7) / 2;
}
float g1(float x)
{
    return fabs(1 / (2 * x * log(10)));
}
int main()
{
    printf("eq-2*x-log10(x)-7\n");
    int steps = 1, N, flag = 0;
    float x0, x1, e;
    printf("Enter initial value: ");
    scanf("%f", &x0);
    printf("Enter no. of iterations: ");
    scanf("%d", &N);
    printf("Enter Error: ");
    scanf("%f", &e);
    if (fabs(g1(x0) < 1))
    {
        do
        {
            x1 = g(x0);
            printf("%d Iteration, value of x is %f then value of(%f) is %f \n", steps, x0, x0, x1);
            steps = steps + 1;
            if (fabs(x1 - x0) <= e)
            {
                printf("root = %f", x1);
                flag = 1;
            }
            else
            {
                x0 = x1;
            }
        } while (flag < 1);
    }
    else
    {
        printf("Incorrect function!!");
    }
}
