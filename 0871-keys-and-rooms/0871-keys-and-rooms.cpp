class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> vis;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            vis.insert(top);
            
            for (auto it : rooms[top]) {
                if (vis.find(it) == vis.end()) 
                    q.push(it);
            }
        }

        return vis.size() == n;
    }
};