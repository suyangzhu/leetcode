#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float InvSqrt (float x)
{
     float xhalf = 0.5f*x;
     int i = *(int*)&x;
     i = 0x5f3759df - (i>>1);
     x = *(float*)&i;
     x = x*(1.5f - xhalf*x*x);
     return x;
}
int main()  {
  float i;
  for (i = 0; i < 10000000; i++)
    InvSqrt(i);
  printf("%f\n", InvSqrt(i));
  for (i = 0; i < 10000000; i++)
    sqrt(i);

  printf("%f\n", sqrt(i));
  return 0;
}
