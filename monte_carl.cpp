#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
double func(double x)
{
        return 1-x*x;
}
 
int main()
{
        int point_a = 1;
        int point_b = 2;
        int number_of_random=0;
        double s=0;
        printf("how much random points? ");
        scanf("%d",&number_of_random);
        srand((unsigned)time(NULL));
        for (int i=0;i<number_of_random;i++)
        {
             s+=func(point_a+((double)rand()/RAND_MAX*(point_b-point_a)));
        }
        s=s/(double)number_of_random*(point_b-point_a);
        printf("\nintegral %f \n",s);
        return 0;
}