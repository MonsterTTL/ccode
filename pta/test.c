#include<stdio.h>
#include<math.h>
#include<complex.h>
#define  DDF  0.1f

int main(void)
{  
   float x1,x2,x3,x4;
   scanf("%f%f%f%f1",&x1,&x2,&x3,&x4);getchar();
   const float complex a=x1+(x2)*I,b=x3+(x4)*I;
   printf("(%.1f%+.1fi) + (%.1f%+.1fi) = ",x1,x2,x3,x4); 
    if(fabs(creal(a+b))<DDF&&fabs(cimag(a+b))<DDF)
      printf("0.0");
    else if(fabs(creal(a+b))< DDF&&fabs(cimag(a+b))>DDF)  
      printf("%.1fi",cimag(a+b));
    else if(fabs(creal(a+b))>DDF&&fabs(cimag(a+b))<DDF)
      printf("%.1f",creal(a+b));  
    else
      printf("%.1f%+.1fi",creal(a+b),cimag(a+b));  
    printf("\n");
   
   printf("(%.1f%+.1fi) - (%.1f%+.1fi) = ",x1,x2,x3,x4); 
    if(fabs(creal(a-b))<= DDF&&fabs(cimag(a-b))<DDF)
      printf("0.0");
    else if(fabs(creal(a-b))< DDF&&fabs(cimag(a-b))>DDF)  
      printf("%.1fi",cimag(a+b));
    else if(fabs(creal(a-b))>DDF&&fabs(cimag(a-b))<DDF)
      printf("%.1f",creal(a-b));  
    else
      printf("%.1f%+.1fi",creal(a-b),cimag(a-b));  
    printf("\n");

   printf("(%.1f%+.1fi) * (%.1f%+.1fi) = ",x1,x2,x3,x4); 
    if(fabs(creal(a*b))<DDF&&fabs(cimag(a*b))<DDF)
      printf("0.0");
    else if(fabs(creal(a*b))<DDF&&fabs(cimag(a*b))>DDF)  
      printf("%.1fi",cimag(a*b));
    else if(fabs(creal(a*b))>DDF&&fabs(cimag(a*b))<DDF)
      printf("%.1f",creal(a*b));  
    else
      printf("%.1f%+.1fi",creal(a*b),cimag(a*b));  
    printf("\n");    

   printf("(%.1f%+.1fi) / (%.1f%+.1fi) = ",x1,x2,x3,x4); 
    if(fabs(creal(a/b))<DDF&&fabs(cimag(a/b))<DDF)
      printf("0.0");
    else if(fabs(creal(a/b))<DDF&&fabs(cimag(a/b))>DDF)  
      printf("%.1fi",cimag(a/b));
    else if(fabs(creal(a/b))>DDF&&fabs(cimag(a/b))<DDF)
      printf("%.1f",creal(a/b));  
    else
      printf("%.1f%+.1fi",creal(a/b),cimag(a/b));   


}   