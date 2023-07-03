#include<stdio.h>

int main()
{
 float weight, height,bmi;
  

  printf("Please enter your weight in kg: \n");
  scanf("%d",&weight);
  printf("Please enter your height in meters: \n");
  scanf("%d", &height);

   bmi = height / (weight *weight );

  printf("Your bmi is %f\n", bmi);
    return 0;
}

