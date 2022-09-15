#include<stdio.h>
#include<math.h>
#define f(x) x*x*x-1
#define d 1000
int check(double a,double b){
    int n1=a*d;
    int n2=b*d;
    if(n1==n2)
        return 1;
    else
        return 0;
}
double solve(double a,double b,double fx1,double fx2){
    double num=a*fx2 - b*fx1;
    double den=fx2-fx1;
    return num/den;
}
void getroots(double prev,double a,double b,double fx1,double fx2){
    double x=solve(a,b,fx1,fx2);
    // Calulating the new point
    double fx=f(x);
    // changing the range on the base of sign
    if(fx1*fx<0.0){
        b=x;
        fx2=fx;
    }
    else{
        a=x;
        fx1=fx;
    }
    printf("x = %0.3f     f(x)=%0.3f\n",x,f(x));
    // if prev value is same to 3 decimal place
    if(check(x,prev))
        printf("The root is %0.3f",x);
    else
        getroots(x,a,b,fx1,fx2);
}
int main(){
    double fx1,fx2,x1=0,x2=0;
    //Calculating points where sign of function is changing
    while(f(x1)>=0 || f(x2)<=0){
        if(f(x1)>=0)
            x1--;
        if(f(x2)<=0)
            x2++;
    }
    while(f(x1)<0)
        x1++;
    while(f(x2)>0)
        x2--;
    x1--,x2++;
    printf("The roots lie in between %f and %f\n",x1,x2);
     fx1=f(x1);
     fx2=f(x2);
     getroots(0,x1,x2,fx1,fx2);
    return 0;
}
