class Solution {
public:
    int count=0;

    void dfs(vector<vector<int>>& adj, int src, vector<bool>& visited){
        visited[src]=true;
        for(auto connectedCity: adj[src]){
            if(!visited[abs(connectedCity)]){
                if(connectedCity>0){
                    count++;
                }
                dfs(adj,abs(connectedCity),visited);
            }
        }
        

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        vector<bool> visited(n,false);

        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);

        }
        dfs(adj, 0, visited);

        return count;
        
    }
};