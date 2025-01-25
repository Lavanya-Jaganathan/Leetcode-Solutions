class Solution {
public:
    bool JumpCheck(vector<int>& stones, int index, unordered_map<int, unordered_set<int>>& dp, int jump) {
        if (index == stones.size() - 1) {
            return true;
        }

        if (dp[index].count(jump)) {
            return false;
        }

        for (int k = -1; k <= 1; ++k) {
            int next_jump = jump + k;
            if (next_jump > 0) {
                for (int next_index = index + 1; next_index < stones.size(); ++next_index) {
                    if (stones[next_index] == stones[index] + next_jump) {
                        if (JumpCheck(stones, next_index, dp, next_jump)) {
                            return true;
                        }
                        break;
                    }
                }
            }
        }

        dp[index].insert(jump);
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false; //  jump of 1 unit.
        }

        unordered_map<int, unordered_set<int>> dp;
        return JumpCheck(stones, 0, dp, 0);
    }
};