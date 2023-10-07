class Solution {
public:
    int n, m, k; 
    int dp[51][51][101];

    int solve(int idx, int lenLIS, int large) {
        if(idx == n) {
            if(k == lenLIS) return 1;
            return 0;
        }

        int ans = 0;
        if(dp[idx][lenLIS][large] != -1) return dp[idx][lenLIS][large];

        for(int i=1; i<=m; i++) {
            if(large < i) {
                ans += solve(idx+1, lenLIS+1, i);
            }
            else ans += solve(idx+1, lenLIS, large);

            ans = ans % 1000000007;
        }
        return dp[idx][lenLIS][large] = ans;
    }

    int numOfArrays(int N, int M, int K) {
        n = N;
        m = M;
        k = K; 
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
