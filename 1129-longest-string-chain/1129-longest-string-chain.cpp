class Solution {
public:
bool compare(string &s, string &t){
    if(s.size() != t.size() + 1) return false;
    int first = 0, second = 0;
    while(first < s.size()){
        if(s[first] == t[second]){
            first++; second++;
        }
        else
        first++;
    }
    if(first == s.size() && second == t.size()) return true;
    return false;
}
static bool comp(string &s, string &t){
    return s.size() < t.size();
}
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n,1); int maxi = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(compare(words[i], words[j]) == true && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};