class Solution {
public:
int solve(int i,int j,vector<vector<int>>&tri,vector<vector<int>>&dp)
{
    if(i>=tri.size()-1)
    {
        return tri[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
     return dp[i][j]=tri[i][j] + min(solve(i+1,j,tri,dp),solve(i+1,j+1,tri,dp));
    }

}
    int minimumTotal(vector<vector<int>>& tri)
    {
        int m=tri.size();
        int n=tri[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,0,tri,dp);
    }
};