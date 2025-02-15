#include<math.h>
int candy(int* ratings, int ratingsSize) 
{
    int a[ratingsSize];
    int sum=0;
    for(int i=0;i<ratingsSize;i++)
    {   
        a[i]=1;
    }
    for(int i=1;i<ratingsSize;i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            a[i]=a[i-1]+1;
        }
    }
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if(ratings[i]>ratings[i+1])
        {
            a[i]=fmax(a[i],a[i+1]+1);
        }
    
    }
    for(int i=0;i<ratingsSize;i++)
    {
        sum=sum+a[i];
    }
    return sum;

}