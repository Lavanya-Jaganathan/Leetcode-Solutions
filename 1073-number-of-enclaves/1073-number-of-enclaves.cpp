class Solution {
void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int n,int m,int &cnt){
    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0 || vis[row][col]==1){
        return;
    }
    vis[row][col]=1;
    cnt+=1;
    dfs(row+1,col,vis,grid,n,m,cnt);
    dfs(row,col-1,vis,grid,n,m,cnt);
    dfs(row-1,col,vis,grid,n,m,cnt);
    dfs(row,col+1,vis,grid,n,m,cnt);
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && (grid[i][j]==1 && !vis[i][j])){
                    dfs(i,j,vis,grid,n,m,cnt);
                }
                tot+=grid[i][j];
            }
        }
        return tot-cnt;
    }
};