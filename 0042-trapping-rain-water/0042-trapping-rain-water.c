#include <stdlib.h>

int trap(int* height, int heightSize) 
{
   int l=1,r=heightSize-2,lm=height[0],rm=height[heightSize-1],res=0;
   while(l<=r)
   {
    if(height[l]>=lm)
    {
        lm=height[l];
        l++;
    }
    else if(height[r]>=rm)
    {
        rm=height[r];
        r--;
    }
    else if(lm<=rm && height[l]<lm)
    {
        res += lm-height[l];
        l++;
    }
    else
    {
        res += rm-height[r];
        r--;
    }
   }
   return res;
}
