class Solution {
public:
    int dp[1000];
    int helper(vector<int>& cost, int idx) {
        if(idx < 0) return 0;
        if(idx == 0 || idx == 1) return cost[idx];
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = cost[idx] + min(helper(cost, idx-1), helper(cost, idx-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(helper(cost, n-1), helper(cost, n-2));
    }
};
