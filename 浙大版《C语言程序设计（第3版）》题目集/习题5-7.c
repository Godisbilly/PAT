#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

/* 你的代码将被嵌在这里 */
double factorial(int n);

double funcos(double e,double x)
{
    double sum = 0;
    int power = 0;
    int count = 1;
    double num = 0;
    while(1)
    {
        double a = pow(x,power);
        double power_factorial = factorial(power);
        num = a / power_factorial;
        if(count % 2 == 1)
            sum += num;
        else
            sum -= num;
        if(fabs(num) < e)
            break;
        count++;
        power += 2;
    }
    return sum;
}

double factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}