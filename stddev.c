//* Source code to calculate standard deviation. */

#include <stdio.h>
#include <math.h>
float standard_deviation(float data[], int n);
int main()
{
    int n, i;
    float data[100];
    printf("Enter number of data elements(less than 100): ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0; i<n; ++i)
        scanf("%f",&data[i]);
    printf("\n");
    printf("Standard Deviation = %.2f\n", standard_deviation(data,n));
    return 0;
}
float standard_deviation(float data[], int n)
{
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<n;++i)
    {
        mean+=data[i];
    }
    mean=mean/n;
    for(i=0; i<n;++i)
    {
      sum_deviation+=(data[i]-mean)*(data[i]-mean);
      printf("mean: %.2f sum_deviation = %.2f\n",mean, sum_deviation);
    }
    return sqrt(sum_deviation/n);           
}
