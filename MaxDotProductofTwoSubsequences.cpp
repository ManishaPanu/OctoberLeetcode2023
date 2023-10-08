class Solution {
public:
    int dp[501][501];
    int solverMaxProduct(int idx, int jdx, int n, int m, vector<int>& nums1, vector<int>& nums2) {
        if(idx == n || jdx == m) {
            return INT_MIN/2;
        }

        if(dp[idx][jdx] != -1) return dp[idx][jdx];

        int take = (nums1[idx] * nums2[jdx]) + max(0, solverMaxProduct(idx+1, jdx+1, n, m, nums1, nums2));

        int nottake = max(solverMaxProduct(idx, jdx+1, n, m, nums1, nums2), solverMaxProduct(idx+1, jdx, n, m, nums1, nums2));

        return dp[idx][jdx] = max(take, nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solverMaxProduct(0, 0, n, m, nums1, nums2);
    }
};
