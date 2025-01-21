class Solution 
{
public:
int main(int n,vector<int>& dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1 || n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        return dp[n]=main(n-1,dp)+main(n-2,dp)+main(n-3,dp);
    }
}
    int tribonacci(int n) 
    {
        vector<int>dp(n+1,-1);
        return main(n,dp);
    }
};