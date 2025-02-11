class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int m=nums1.length;
        int n=nums2.length;
        int a[]=new int[m+n];
        int k=0;
        for(int i=0;i<m;i++)
        {
           a[k]=nums1[i];
           k++;
        }
        for(int i=0;i<n;i++)
        {
            a[k]=nums2[i];
            k++;
        }
        int temp;
        for(int i=0;i<k-1;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        int len=a.length;
        if(len%2!=0)
        {
            int t=len/2;
            double d=a[t];
            return d;
        }
        else
        {
            int s=len/2;
            int u=s-1;
            double v=(double)(a[u]+a[s])/2;
            return v;
        }

    }
}