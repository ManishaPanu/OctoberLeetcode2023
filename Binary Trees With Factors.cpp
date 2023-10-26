class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        unordered_map<int, long long> mp;

        mp[arr[0]] = 1;
        for(int i=1; i<n; i++) {
            int root = arr[i];
            mp[root] = 1;
            for(int j=0; j<i; j++) {
                int left_child = arr[j];

                if(root % left_child == 0 && mp.find(arr[i]/left_child) != mp.end()) {
                    mp[root] += mp[left_child] * mp[arr[i]/left_child];
                } 
            }
        }

        long result = 0;
        for(auto &it : mp) {
            result = (result+it.second) % mod;
        }

        return result;
    }
};
