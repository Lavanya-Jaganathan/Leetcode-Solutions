class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;
        vector<vector<int>> ans;
        if(n==0) return ans;
        vector<int> path;
        queue<vector<int>> q;
        path.push_back(0);
        q.push(path);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int node = temp.back();
            for(auto it: graph[node]){
                auto temppath = temp;
                temppath.push_back(it);
                if(it==target){
                    ans.push_back(temppath);
                }
                else{
                    q.push(temppath);
                }
            }
        }
        return ans;
    }
};