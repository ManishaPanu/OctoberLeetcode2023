class Solution {
public:
    int dp[501][501];
    int helper(int idx, int remain, vector<int>& cost, vector<int>& time) {
        if(remain <= 0) return 0;
        if(idx >= cost.size()) return 1e9;
        if(dp[idx][remain] != -1) return dp[idx][remain];

        int paint = cost[idx] +  helper(idx+1, remain-1-time[idx], cost, time);
        int no_paint = helper(idx+1, remain, cost, time);

        return dp[idx][remain] = min(paint, no_paint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, n, cost, time);
    }
};
