class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1)
        {
            return n;
        }
        int p1=0;
        int p2=1;
        int p3=1;
        int c=0;
        for(int i=3;i<=n;i++)
        {
            c=p1+p2+p3;
            p1=p2;
            p2=p3;
            p3=c;
        }
        return p3;
        
    }
};