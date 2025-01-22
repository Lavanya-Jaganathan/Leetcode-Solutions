class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp, string &t1, string &t2)
    {
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j]!=-1)
           return dp[i][j];
        if(t1[i]==t2[j])
            return dp[i][j] = 1+ solve(i+1,j+1,m,n,dp,t1,t2);
        else
            return dp[i][j] = max(solve(i+1,j,m,n,dp,t1,t2), solve(i,j+1,m,n,dp,t1,t2));

    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2,-1));
        return solve(0,0,n1,n2,dp,text1,text2);
    }
};