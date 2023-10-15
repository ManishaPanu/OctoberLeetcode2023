class Solution {
public:
    int n, mod = 1e9 + 7;
    int dp[501][501];
    int helper(int steps, int idx) {
        if(idx < 0 || idx >= n) return 0;
        if(steps == 0) {
            if(idx == 0)
                return 1;
            return 0;
        }

        if(dp[idx][steps] != -1) return dp[idx][steps];

        int res = helper(steps-1, idx+1);
        res = (res + helper(steps-1, idx-1)) % mod;
        res = (res + helper(steps-1, idx)) % mod;

        return dp[idx][steps] = res; 
    }
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        //n = min(arrLen, steps);
        //optimization after observation
        n = min(arrLen, (steps/2)+1);
        return helper(steps, 0);
    }
};
